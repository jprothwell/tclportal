/*
 * Created on 2006-5-29
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.action;

import cn.funstar.wap.db.dao.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class LogAction {
	/*��ҳ���ʼ�¼*/
	protected static void indexLog(String page, String mobile,String ip,String language){
		new LogDAO().insertAccessLog(page, mobile,ip,language);
	}

	/*��Ŀ���ʼ�¼*/
	protected static void channelLog(String channel, String mobile){
		if(channel != null && !channel.equals("")){
			new LogDAO().insertChannelLog(channel, mobile);
		}
	}

	/*ҵ����ʼ�¼*/
	protected static void serviceLog(String service, String mobile,String url){
		if(service != null && !service.equals("")){
			new LogDAO().insertServiceLog(service, mobile,url);
		}
	}
}
