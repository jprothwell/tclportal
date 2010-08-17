package com.tcl.portal.util;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.Map;
import java.util.Set;

import javax.servlet.http.HttpServletRequest;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;

public class PagerBuilder
{
	private final static Logger log = Logger.getLogger(PagerBuilder.class);
	public static final String PARAM_PAGE = "pageNo";

	public static final String PARAM_SIZE = "pageSize";

	public static Pager build(HttpServletRequest req)
	{
		return new PagerBuilder(req).build();
	}

	private HttpServletRequest request;

	public PagerBuilder()
	{
	}

	@SuppressWarnings("unchecked")
	public static Pager build(HttpServletRequest req, ActionForm form)
	{
		Pager<Map> pager = PagerBuilder.build(req);
		Map<String, Object> map = BeanHandler.getPropertyValueMap(form);
		pager.setCondition(map);
		Set<String> ks = map.keySet();
		for (String k : ks)
		{
			Object v = map.get(k);
			//忽略�?
			if (v == null)
			{
				continue;
			}

			//忽略String的null && "null"
			if (v instanceof String)
			{
				if (v.toString().trim().length() == 0)
				{
					log.info("���Բ���:null�ַ�");
					continue;
				}

				if ("null".equals(v))
				{
					continue;
				}
			}

			//按照UTF-8编码
			String pValue = null;
			try
			{
				pValue = URLEncoder.encode(v.toString(), "utf-8");
			} catch (UnsupportedEncodingException e)
			{
				e.printStackTrace();
			}
			pager.addParam(k, pValue);
		}
		return pager;
	}

	public PagerBuilder(HttpServletRequest req)
	{
		request = req;
	}

	public Pager build()
	{
		int page = 1;
		int size = 20;
		try
		{
			String pageStr = request.getParameter(PARAM_PAGE);
			String sizeStr = request.getParameter(PARAM_SIZE);
			page = Integer.valueOf((pageStr == null || pageStr.length() == 0) ? String.valueOf(page) : pageStr);
			size = Integer.valueOf((sizeStr == null || sizeStr.length() == 0) ? String.valueOf(size) : sizeStr);
		} catch (Exception e)
		{
			e.printStackTrace();
		}
		StringBuilder sb = new StringBuilder();
		sb.append(request.getServletPath());
		sb.append("?");
		Pager pager = new Pager(sb.toString(), page, size);
		request.setAttribute("pager", pager);
		return pager;
	}

}
