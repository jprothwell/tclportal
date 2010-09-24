package com.tcl.paypal.action;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.paypal.domain.Goods;
import com.tcl.paypal.service.GoodsService;
import com.tcl.paypal.util.Constants;

public class GoodsAction extends DispatchAction {
	
	public Logger logger = Logger.getLogger(GoodsAction.class);
	
	private GoodsService goodsService;
	
	public void setGoodsService(GoodsService goodsService) {
		this.goodsService = goodsService;
	}

	public ActionForward list(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
	
//		int start = (pager.getPageNo()-1) * pager.getPageSize();
//		int end = pager.getPageSize();
		Map map = new HashMap();
	
		List<Goods> list = goodsService.findGoods(map);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
	public ActionForward view(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id =  request.getParameter("id");
		Goods good = goodsService.queryGoods(Integer.parseInt(id));
		request.setAttribute("obj", good);
		return mapping.findForward("view");
	}
	
	public ActionForward download(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		//下载
		String filePath = session.getServletContext().getRealPath("game");
		//下载文件
		Goods goods = goodsService.queryGoods(Integer.parseInt((String)session.getAttribute(Constants.GOODS_ID)));
		String fileName = goods.getJarname();
		fileName = URLDecoder.decode(fileName,"UTF-8");
		fileName = URLEncoder.encode(fileName, "UTF-8");
		response.setContentType("application/txt"); 
		response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
		//获取文件输入流和输出流
		InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
		OutputStream os = new BufferedOutputStream(response.getOutputStream());
		int bufferSize = 1024*8;
		byte[] buffer = new byte[bufferSize];
		int len = 0;
		while((len = is.read(buffer, 0, bufferSize))!=-1){
			os.write(buffer, 0, len);
		}
		is.close();
		os.close();
		return mapping.findForward("");
	}
	
	
}
