package com.tcl.onetouch.action;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.onetouch.domain.GameLanguage;
import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.Language;
import com.tcl.onetouch.form.GameLanguageForm;
import com.tcl.onetouch.service.GameLanguageService;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.service.LanguageService;

public class GameLanguageAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameLanguageAction.class);
	
	private GameLanguageService gameLanguageService;
	
	private LanguageService languageService;
	
	private GameinfoService gameinfoService;
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	public void setLanguageService(LanguageService languageService) {
		this.languageService = languageService;
	}
	public void setGameLanguageService(GameLanguageService gameLanguageService) {
		this.gameLanguageService = gameLanguageService;
	}
	//列表
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		//按照游戏id 获取游戏的语言列表
		String gameId = request.getParameter("gameId");
		List<GameLanguage> list = gameLanguageService.findListByGameId(Integer.parseInt(gameId));
		for(GameLanguage gameLanguage:list){
			Language language = languageService.queryLanguage(gameLanguage.getLanguage());
			if(language!=null){
				gameLanguage.setLanguageName(language.getLanguage());
			}
		}
		
		//根据id获取游戏名称
		Gameinfo gameinfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		request.setAttribute("name",gameinfo.getGamename());
		request.setAttribute("gameId", gameId);
		request.setAttribute("list",list);
		return mapping.findForward("list");
	}
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String gameId = request.getParameter("gameId");
		request.setAttribute("gameId", gameId);
		//根据id获取游戏名称
		Gameinfo gameinfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		request.setAttribute("name", gameinfo.getGamename());
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gameId = request.getParameter("gameId");
		GameLanguageForm gameLanguageForm = (GameLanguageForm)form;
		GameLanguage gameLanguage = new GameLanguage();
		BeanUtils.copyProperties(gameLanguage,gameLanguageForm);
		gameLanguageService.save(gameLanguage);
		request.setAttribute("gameId", gameId);
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String gameId = request.getParameter("gameId");
		GameLanguageForm gameLanguageForm = (GameLanguageForm)form;
		GameLanguage gameLanguage = new GameLanguage();
		BeanUtils.copyProperties(gameLanguage,gameLanguageForm);
		gameLanguageService.update(gameLanguage);
		request.setAttribute("gameId", gameId);
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gameId = request.getParameter("gameId");
		String id = request.getParameter("id");
		request.setAttribute("gameId", gameId);
		//根据id获取游戏名称
		Gameinfo gameinfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		GameLanguage gamelanguage = gameLanguageService.queryGameLanguage(Integer.parseInt(id));
		
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		request.setAttribute("name", gameinfo.getGamename());
		request.setAttribute("obj", gamelanguage);
		request.setAttribute("gameId",gameId);
		return mapping.findForward("edit");
	}

}
