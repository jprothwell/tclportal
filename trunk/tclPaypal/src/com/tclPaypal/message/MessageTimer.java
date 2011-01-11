package com.tclPaypal.message;

import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TimerTask;

import com.tclPaypal.domain.Business;
import com.tclPaypal.service.BusinessService;
import com.tclPaypal.service.MessageStatuService;
/**
 * spring定时器
 * @author kun.shen
 *
 */
public class MessageTimer extends  TimerTask{
	
	private MessageStatuService messageStatuService;
	
	private BusinessService businessService;
	
	public void setBusinessService(BusinessService businessService) {
		this.businessService = businessService;
	}
	public void setMessageStatuService(MessageStatuService messageStatuService) {
		this.messageStatuService = messageStatuService;
	}
	@Override
	public void run() {
		
		//list操作
		List<Business> list = messageStatuService.getResendMessage();
	
		//重发
		for(int i =0;i<list.size();i++){
			Business business =  list.get(i);
			String statue = GetResponse.getShangmailResponse(business.getOrdernum(),"");
			//收到回复后更改数据库状态，没收到回复，放入容器中，不断重发。
			System.out.println("orderId:"+business.getToken()+",status:"+business.getStatute());
			if("ok".equals(statue)){
				business.setStatute(1);//paypal支付成功，shangmail反馈成功
				businessService.update(business);
			}else{
				int sta = business.getStatute();
				if(sta<30&&sta>=20){
					business.setStatute(sta+1);//paypal支付成功，尚邮反馈不成功.
				}else if(sta==30){
					business.setStatute(sta);//paypal支付成功，尚邮反馈不成功,且重发失败
					businessService.update(business);
					//保存在内存中
					messageStatuService.remove(business);//重发达到10次，不继续重发
				}
			}
		}
	}

}
