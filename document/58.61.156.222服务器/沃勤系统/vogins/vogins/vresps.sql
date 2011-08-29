SET NAMES utf8; 

CREATE DATABASE `vresps` DEFAULT CHARACTER SET utf8;
USE `vresps`;

DROP TABLE IF EXISTS `bs_b_menu`;
CREATE TABLE `bs_b_menu` (
  `MenuId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) NOT NULL DEFAULT '0',
  `SeqNo` int(11) NOT NULL DEFAULT '0',
  `MenuName` char(50) NOT NULL DEFAULT '',
  `HaveSubMenu` char(1) NOT NULL DEFAULT '',
  `ImageName` char(50) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `LinkPage` char(100) DEFAULT NULL,
  `MenuDesc` char(200) DEFAULT NULL,
  PRIMARY KEY (`MenuId`)
) ENGINE=MyISAM AUTO_INCREMENT=201096 DEFAULT CHARSET=utf8;

LOCK TABLES `bs_b_menu` WRITE;
INSERT INTO `bs_b_menu` VALUES (1,0,1,'系统管理','1','images/menu_bg.gif','','',''),(101,1,1,'用户管理','0','','','system/user.htm',''),(102,1,2,'角色管理','0','','','system/role.htm',''),(103,1,3,'菜单管理','0','','','system/menu.htm',''),(104,1,4,'Servlet管理','0','','','system/servlet.htm',''),(105,1,5,'用户角色','0','','','system/userrole.htm',''),(106,1,6,'菜单操作','0','','','system/menuservlet.htm',''),(107,1,7,'权限控制','0','','','system/access.htm',''),(108,1,8,'操作日志','0','',NULL,'system/actionlog.htm',''),(2,0,2,'机型管理','1','images/menu_bg.gif',NULL,'',''),(3,0,3,'产品管理','1','images/menu_bg.gif',NULL,'',''),(4,0,4,'计费管理','1','images/menu_bg.gif',NULL,'',''),(5,0,5,'统计报表','1','images/menu_bg.gif',NULL,'',''),(6,0,6,'客服系统','1','images/menu_bg.gif',NULL,'',''),(7,0,7,'结算系统','1','images/menu_bg.gif',NULL,'',''),(8,0,8,'SP查询系统','1','images/menu_bg.gif',NULL,'',''),(9,0,9,'手机厂商管理系统','1','images/menu_bg.gif',NULL,'',''),(10,0,10,'CP查询系统','1','images/menu_bg.gif',NULL,'',''),(109,1,9,'系统监控','0','',NULL,'',''),(201,2,1,'厂商管理','0','',NULL,'mobile/mf.jsp',''),(202,2,2,'机型管理','0','',NULL,'mobile/phonemodel.jsp',''),(203,2,3,'授权列表','0','',NULL,'mobile/perm.jsp',''),(401,4,1,'SP管理','0','',NULL,'fee/Sp.jsp',''),(402,4,2,'计费通道','0','',NULL,'fee/FeeChannel.jsp',''),(403,4,3,'计费通道组','0','',NULL,'fee/FeeGroup.jsp',''),(301,3,1,'CP管理','0','',NULL,'app/cp.jsp',''),(302,3,2,'AppStore管理','1','images/menu_bg.gif',NULL,'',''),(303,3,3,'产品管理','0','',NULL,'app/app.jsp',''),(304,3,4,'产品目录','0','',NULL,'app/appfolder.jsp',''),(305,3,5,'厂商专区','0','',NULL,'app/mfarea.jsp',''),(306,3,6,'产品总表','0','',NULL,'app/default.jsp',''),(307,3,7,'黑名单管理','1','',NULL,'',''),(30701,307,1,'CP黑名单','0','',NULL,'app/cpblack.jsp',''),(30702,307,2,'禁用产品','0','',NULL,'app/appblack.jsp',''),(30703,307,3,'机型禁止产品','0','',NULL,'app/mobileblack.jsp',''),(601,6,1,'付费查询','0','',NULL,'users/user_record.jsp',''),(602,6,2,'用户投诉','0','',NULL,'users/user_touse.jsp',''),(701,7,1,'SP结算','0','',NULL,'account/SpBill.htm',''),(702,7,2,'CP结算查询','0','',NULL,'account/CpBill.htm',''),(703,7,3,'MF结算查询','0','',NULL,'account/MfBill.htm',''),(704,7,4,'结算总表查询','0','',NULL,'account/TotalBill.htm',''),(501,5,1,'SP计费查询','0','',NULL,'report/reportFee_sp.jsp',''),(502,5,2,'CP计费查询','0','',NULL,'report/reportFee_cp.jsp',''),(503,5,3,'区域计费查询','0','',NULL,'report/reportFee_Area.jsp',''),(504,5,4,'下载查询','0','',NULL,'report/report_download.jsp',''),(505,5,5,'用户统计','0','',NULL,'report/report_usr.jsp',''),(801,8,1,'计费统计','0','',NULL,'preport/sp_report.jsp',''),(802,8,2,'账单查询','0','',NULL,'preport/sp_bill.jsp',''),(308,3,8,'产品打包','0','',NULL,'app/pack.jsp',''),(901,9,1,'UA编码','1','0',NULL,'',''),(902,9,4,'机型列表','0','',NULL,'mobile/MobileReport.jsp',''),(1001,10,1,'计费统计','0','',NULL,'preport/cp_report.jsp',''),(1002,10,2,'下载统计','0','',NULL,'preport/cp_dld.jsp',''),(1003,10,3,'账单查询','0','',NULL,'preport/cp_bill.jsp',''),(506,5,6,'APPSTORE下载查询','0','',NULL,'report/report_AppStory.jsp',''),(20,0,11,'工作台','1','images/menu_bg.gif',NULL,'',''),(2010,20,1,'站内信息','1','',NULL,'',''),(201010,2010,1,'收件箱','0','',NULL,'message/inputbox.htm',''),(201020,2010,2,'发件箱','0','',NULL,'message/waitbox.htm',''),(201030,2010,3,'已发信息','0','',NULL,'message/outputbox.htm',''),(201040,2010,4,'已删信息','0','',NULL,'message/deletebox.htm',''),(201050,2010,5,'草稿箱','0','',NULL,'message/editbox.htm',''),(905,9,7,'账单查询','0','',NULL,'preport/mf_bill.jsp',''),(904,9,6,'计费统计','0','',NULL,'preport/mf_report.jsp',''),(903,9,5,'UA查询','0','',NULL,'mobile/UAQuery.jsp',''),(90101,901,1,'新建申请','0','',NULL,'mobile/mfwf.jsp',''),(90102,901,2,'申请状态','0','',NULL,'workflow/view.jsp',''),(2020,20,3,'待办工作','0','',NULL,'workflow/wait.jsp',''),(2030,20,4,'工作监控','0','',NULL,'workflow/view.jsp',''),(2040,20,5,'工作查询','0','',NULL,'workflow/search.jsp',''),(90103,901,3,'已批申请','0','',NULL,'workflow/search.jsp',''),(90104,901,4,'驳回申请','0','',NULL,'workflow/wait.jsp',''),(906,9,8,'预置应用下载','0','',NULL,'preport/mf_app.jsp',''),(30,0,12,'内容管理AS3','1','images/menu_bg.gif',NULL,'',''),(3010,30,1,'更多下载','0','',NULL,'app30/more.jsp',''),(3020,30,2,'热门下载','0','',NULL,'app30/topdld.jsp',''),(3030,30,3,'最新上架','0','',NULL,'app30/new.jsp',''),(3040,30,4,'精品推荐','0','',NULL,'app30/recommend.jsp',''),(3041,30,5,'站内信息','0','',NULL,'as30/webmessage.jsp',''),(3042,30,6,'搜索引擎','0','',NULL,'as30/mobilesearch.jsp',''),(3043,30,7,'手机酷站','0','',NULL,'as30/waplist.jsp',''),(4044,30,8,'广告配置','0','',NULL,'as30/mobileadv.jsp',''),(3108,31,5,'技术答疑TS','0','',NULL,'cpworkflow/question_ts.jsp',''),(507,5,7,'厂商查询','0','',NULL,'report/reportFee_mf.jsp',''),(31,0,13,'CP工作流','1','images/menu_bg.gif',NULL,'',''),(3107,31,4,'项目列表','0','',NULL,'cpworkflow/projectlist.jsp',''),(3109,31,6,'BUG管理','0','',NULL,'cpworkflow/buglist.jsp',''),(4040,40,4,'项目测试','0','',NULL,'cpwf_cp/projecttest.jsp',''),(3112,31,7,'待上线项目','0','',NULL,'cpworkflow/waitonline.jsp',''),(3190,31,8,'沃勤联系人管理','0','',NULL,'cpworkflow/vogins_contact.jsp',''),(40,0,14,'产品开发','1','images/menu_bg.gif',NULL,'',''),(4010,40,1,'合作流程','0','',NULL,'cpwf_cp/doc.jsp',''),(4020,40,2,'产品评估','0','',NULL,'cpwf_cp/eva.jsp',''),(4030,40,3,'项目管理','0','',NULL,'cpwf_cp/project.jsp',''),(3104,31,3,'等待立项','0','',NULL,'cpworkflow/passeva.jsp',''),(3101,31,1,'合作流程管理','0','',NULL,'cpworkflow/bucodocument_ops.jsp',''),(2015,20,2,'未提交工作','0','',NULL,'workflow/edit.jsp',''),(3103,31,2,'产品评估','0','',NULL,'cpworkflow/evalist.jsp',''),(201085,302,1,'3.0版','0','',NULL,'app/appstore3.jsp',''),(201051,1,10,'控制面板','0','',NULL,'system/control.htm',''),(201052,3,9,'预置产品','1','',NULL,'',''),(201053,201052,1,'预置产品配置','0','',NULL,'app/preapp.jsp',''),(201054,201052,2,'预置产品下载','0','',NULL,'app/preappdld.jsp',''),(201055,9,2,'子厂商管理','1','',NULL,'',''),(201056,201055,1,'子厂商','0','',NULL,'mobile/submf.jsp',''),(201057,201055,2,'子厂商机型','0','',NULL,'mobile/submfmobile.jsp',''),(201058,1,11,'国家管理','0','images/menu_bg.gif',NULL,'','国家管理顶级菜单'),(201076,30,9,'热门总表','0','',NULL,'app30/topdldDef.jsp','热门下载总表'),(201061,1,12,'国家管理','0','images/menu_bg.gif',NULL,'','管理国家'),(201081,0,17,'厂商计费管理','1','images/menu_bg.gif',NULL,'',''),(201065,0,15,'开发者论坛','1','images/menu_bg.gif',NULL,'',''),(201067,201065,1,'项目新建','0','',NULL,'prodevelop/projectNew.jsp','新建状态项目列表'),(201068,201065,2,'项目测试Leader','0','',NULL,'prodevelop/projectTLeader.jsp','项目列表测试Leader界面'),(201069,201065,3,'项目测试Tester','0','',NULL,'prodevelop/projectTTester.jsp','测试项目测试人员界面'),(201070,201065,4,'项目驳回','0','',NULL,'prodevelop/projectReject.jsp','查看驳回项目'),(201071,201065,5,'项目通过','0','',NULL,'prodevelop/projectPass.jsp','查看通过项目列表'),(201072,201065,6,'项目上线','0','',NULL,'prodevelop/projectOnline.jsp','查看上线项目列表'),(201080,201074,2,'计费提示语','0','',NULL,'international/FeeTipsManagement.jsp',''),(201074,0,16,'国家管理','1','images/menu_bg.gif',NULL,'','国家管理'),(201075,201074,1,'国家管理','0','',NULL,'international/Country.jsp','国家管理'),(201077,30,10,'精品总表','0','',NULL,'app30/recommendDef.jsp','精品推荐总表'),(201079,3,10,'越南产品','0','',NULL,'fsproduct/fsproduct.jsp','越南产品管理'),(201082,201081,1,'SP管理','0','',NULL,'cfee/CSp.jsp',''),(201083,201081,2,'计费通道','0','',NULL,'cfee/CFeeChannel.jsp',''),(201084,201081,3,'计费通道组','0','',NULL,'cfee/CFeeGroup.jsp',''),(201086,302,2,'2.0版','0','',NULL,'app/appstore2.jsp',''),(201087,302,3,'测试版','0','',NULL,'app/appstore.jsp',''),(201088,4,4,'运营商管理','0','',NULL,'fee/Operator.jsp',''),(201089,201081,4,'厂商自定义通道','0','',NULL,'cfee/customChannel.jsp',''),(201090,4,5,'短信中心号码','0','',NULL,'fee/Smsca.jsp',''),(201091,9,3,'计费通道管理','1','',NULL,'',''),(201092,201091,1,'SP管理','0','',NULL,'cfee/CSp.jsp',''),(201093,201091,2,'计费通道','0','',NULL,'cfee/CFeeChannel.jsp',''),(201094,201091,3,'计费通道组','0','',NULL,'cfee/CFeeGroup.jsp',''),(201095,201091,4,'默认计费通道','0','',NULL,'cfee/customChannel.jsp','');
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_b_role`;
CREATE TABLE `bs_b_role` (
  `RoleName` varchar(20) NOT NULL DEFAULT '',
  `RoleDesc` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`RoleName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

LOCK TABLES `bs_b_role` WRITE;
INSERT INTO `bs_b_role` VALUES ('admin','管理员'),('sp','代计费提供商（SP）'),('mf','手机厂商'),('cp','内容提供商'),('bd','BD'),('ops','运营'),('qa','测试组'),('submf','子厂商'),('ts','技术支持'),('tsman','技术负责人'),('qateam','测试Team');
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_b_servlet`;
CREATE TABLE `bs_b_servlet` (
  `ServletId` int(11) NOT NULL AUTO_INCREMENT,
  `ServletName` varchar(20) NOT NULL DEFAULT '',
  `OperateName` varchar(20) NOT NULL DEFAULT '0',
  `Package` varchar(100) NOT NULL DEFAULT '00',
  `ServletClass` varchar(100) NOT NULL DEFAULT '',
  `ServletDesc` varchar(200) DEFAULT NULL,
  `LogOut` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ServletId`,`ServletName`(1))
) ENGINE=MyISAM AUTO_INCREMENT=533 DEFAULT CHARSET=utf8;

LOCK TABLES `bs_b_servlet` WRITE;
INSERT INTO `bs_b_servlet` VALUES (1,'login.do','登录','system.user','org.jwdf.framework.actions.user.SystemLogin','','1'),(2,'AddUser.do','添加系统用户','system.user','org.jwdf.framework.actions.user.AddUser','','2'),(3,'GetUserInfo.do','0','system.user','org.jwdf.framework.actions.user.GetUserInfo',NULL,'0'),(4,'GetSubUser.do','0','system.user','org.jwdf.framework.actions.user.GetSubUser','','0'),(5,'DeleteUser.do','0','system.user','org.jwdf.framework.actions.user.DeleteUser',NULL,'0'),(6,'ClearPassword.do','0','system.user','org.jwdf.framework.actions.user.ClearPassword',NULL,'0'),(7,'GetSubServlet.do','0','system.servlet','org.jwdf.framework.actions.servlet.GetSubServlet',NULL,'0'),(8,'AddServlet.do','0','system.servlet','org.jwdf.framework.actions.servlet.AddServlet',NULL,'0'),(9,'UpdateServlet.do','0','system.servlet','org.jwdf.framework.actions.servlet.UpdateServlet',NULL,'0'),(10,'DeleteServlet.do','0','system.servlet','org.jwdf.framework.actions.servlet.DeleteServlet',NULL,'0'),(11,'GetServletInfo.do','0','system.servlet','org.jwdf.framework.actions.servlet.GetServletInfo',NULL,'0'),(13,'GetSubMenuList.do','0','system.menu','org.jwdf.framework.actions.menu.GetSubMenuList',NULL,'0'),(14,'GetMenuInfo.do','0','system.menu','org.jwdf.framework.actions.menu.GetMenuInfo',NULL,'0'),(15,'AddMenu.do','0','system.menu','org.jwdf.framework.actions.menu.AddMenu',NULL,'0'),(16,'UpdateMenu.do','0','system.menu','org.jwdf.framework.actions.menu.UpdateMenu',NULL,'0'),(17,'DeleteMenu.do','0','system.menu','org.jwdf.framework.actions.menu.DeleteMenu',NULL,'0'),(18,'GetSystemMenu.do','0','system.menu','org.jwdf.framework.actions.menu.GetSystemMenu','','0'),(19,'GetUserSubMenu.do','0','system.access','org.jwdf.framework.actions.access.GetUserSubMenu',NULL,'0'),(20,'logout.do','退出','system.user','org.jwdf.framework.actions.user.SystemLogout','','1'),(21,'AddRole.do','0','system.role','org.jwdf.framework.actions.role.AddRole',NULL,'0'),(22,'UpdateRole.do','0','system.role','org.jwdf.framework.actions.role.UpdateRole',NULL,'0'),(23,'DeleteRole.do','0','system.role','org.jwdf.framework.actions.role.DeleteRole',NULL,'0'),(24,'GetRoleInfo.do','0','system.role','org.jwdf.framework.actions.role.GetRoleInfo',NULL,'0'),(25,'GetRoleList.do','0','system.role','org.jwdf.framework.actions.role.GetRoleList',NULL,'0'),(28,'UpdateUser.do','修改用户','system.user','org.jwdf.framework.actions.user.UpdateUser','','0'),(29,'GetAllRoles.do','读取所有角色','system.role','org.jwdf.framework.actions.role.GetAllRoles','','0'),(30,'GetUserRoles.do','读取用户角色','system.userrole','org.jwdf.framework.actions.userrole.GetUserRoles','','0'),(31,'GetRoleUsers.do','读取角色用户','system.userrole','org.jwdf.framework.actions.userrole.GetRoleUsers','','0'),(32,'AddUserRole.do','添加用户角色','system.userrole','org.jwdf.framework.actions.userrole.AddUserRole','','0'),(33,'DeleteUserRole.do','删除用户角色','system.userrole','org.jwdf.framework.actions.userrole.DeleteUserRole','','0'),(34,'GetMenuServlets.do','读取菜单操作','system.menuservlet','org.jwdf.framework.actions.menuservlet.GetMenuServlets','','0'),(35,'AddMenuServlet.do','添加菜单操作','system.menuservlet','org.jwdf.framework.actions.menuservlet.AddMenuServlet','','0'),(36,'DeleteMenuServlet.do','删除菜单操作','system.menuservlet','org.jwdf.framework.actions.menuservlet.DeleteMenuServlet','','0'),(37,'GetAccSubMenu.do','读取权限子菜单','system.access','org.jwdf.framework.actions.access.GetAccSubMenu','','0'),(38,'AddMenuAcc.do','添加菜单权限','system.access','org.jwdf.framework.actions.access.AddMenuAcc','','0'),(39,'DeleteMenuAcc.do','删除菜单权限','system.access','org.jwdf.framework.actions.access.DeleteMenuAcc','','0'),(40,'AddServletAcc.do','添加操作权限','system.access','org.jwdf.framework.actions.access.AddServletAcc','','0'),(41,'DeleteServletAcc.do','删除操作权限','system.access','org.jwdf.framework.actions.access.DeleteServletAcc','','0'),(42,'GetAccServlet.do','读取操作权限','system.access','org.jwdf.framework.actions.access.GetAccServlet','','0'),(43,'GetLoginInfo.do','取登录信息','system.user','org.jwdf.framework.actions.user.GetLoginInfo','','0'),(47,'UpdatePassword.do','修改密码','system.user','org.jwdf.framework.actions.user.UpdatePassword','','0'),(48,'GetActionLogInfo.do','取操作日志信息','system.actionlog','org.jwdf.framework.actions.actionlog.GetActionLogInfo','','0'),(49,'GetActionLogList.do','取操作日志','system.actionlog','org.jwdf.framework.actions.actionlog.GetActionLogList','','0'),(50,'AddCP.do','添加CP','app.cp','com.vogins.sps.action.app.cp.AddCP','','2'),(51,'UpdateCP.do','修改CP','app.cp','com.vogins.sps.action.app.cp.UpdateCP','','2'),(52,'DeleteCP.do','删除CP','app.cp','com.vogins.sps.action.app.cp.DeleteCP','','2'),(53,'GetCPInfo.do','取CP信息','app.cp','com.vogins.sps.action.app.cp.GetCPInfo','','0'),(54,'GetCPList.do','取CP列表','app.cp','com.vogins.sps.action.app.cp.GetCPList','','0'),(55,'AddContact.do','添加联系人','publicinfo.contact','com.vogins.sps.action.publicinfo.contact.AddContact','','2'),(56,'UpdateContact.do','修改联系人','publicinfo.contact','com.vogins.sps.action.publicinfo.contact.UpdateContact','','2'),(57,'DeleteContact.do','删除联系人','publicinfo.contact','com.vogins.sps.action.publicinfo.contact.DeleteContact','','2'),(58,'GetContactInfo.do','取联系人信息','publicinfo.contact','com.vogins.sps.action.publicinfo.contact.GetContactInfo','','0'),(59,'GetContactList.do','取联系人列表','publicinfo.contact','com.vogins.sps.action.publicinfo.contact.GetContactList','','0'),(60,'AddMobile.do','添加机型','mobile.mobile','com.vogins.sps.action.mobile.mobile.AddMobile','','0'),(61,'DeleteMobile.do','删除机型','mobile.mobile','com.vogins.sps.action.mobile.mobile.DeleteMobile','','0'),(62,'GetAllMobile.do','所有机型','mobile.mobile','com.vogins.sps.action.mobile.mobile.GetAllMobile','','0'),(63,'GetAllMobileList.do','得到机型列表','mobile.mobile','com.vogins.sps.action.mobile.mobile.GetAllMobileList','','0'),(64,'GetMobileInfo.do','机型信息','mobile.mobile','com.vogins.sps.action.mobile.mobile.GetMobileInfo','','0'),(65,'GetMobileList.do','根据厂商取机型列表','mobile.mobile','com.vogins.sps.action.mobile.mobile.GetMobileList','','0'),(66,'UpdateMobile.do','更新机型','mobile.mobile','com.vogins.sps.action.mobile.mobile.UpdateMobile','','0'),(67,'AddMF.do','添加厂商','mobile.mf','com.vogins.sps.action.mobile.mf.AddMF','','0'),(68,'GetAllMF.do','所有厂商','mobile.mf','com.vogins.sps.action.mobile.mf.GetAllMF','','0'),(69,'GetMFInfo.do','厂商信息','mobile.mf','com.vogins.sps.action.mobile.mf.GetMFInfo','','0'),(70,'GetMFList.do','厂商列表','mobile.mf','com.vogins.sps.action.mobile.mf.GetMFList','','0'),(71,'UpdateMF.do','更新厂商','mobile.mf','com.vogins.sps.action.mobile.mf.UpdateMF','','0'),(72,'AddGroupConfig.do','配置通道组','mobile.groupconfig','com.vogins.sps.action.mobile.feeGroupConfig.AddGroupConfig','','0'),(73,'channeldown.do','下移','mobile.groupconfig','com.vogins.sps.action.mobile.feeGroupConfig.channeldown','','0'),(74,'channelUp.do','上移','mobile.groupconfig','com.vogins.sps.action.mobile.feeGroupConfig.channelUp','','0'),(75,'GetChannelList.do','得到通道列表','mobile.groupconfig','com.vogins.sps.action.mobile.feeGroupConfig.GetChannelList','','0'),(76,'GetFeeGroupInfo.do','通道组信息','fee.feegroup','com.vogins.sps.action.fee.feegroup.GetFeeGroupInfo','','0'),(77,'GetFeeGroupList.do','通道组列表','fee.feegroup','com.vogins.sps.action.fee.feegroup.GetFeeGroupList','','0'),(78,'UpdateFeeGroup.do','更新通道组','fee.feegroup','com.vogins.sps.action.fee.feegroup.UpdateFeeGroup','','0'),(79,'AddFee.do','增加sp','fee.fee','com.vogins.sps.action.fee.fee.AddFee','','0'),(80,'GetAllFee.do','取sp','fee.fee','com.vogins.sps.action.fee.fee.GetAllFee','','0'),(81,'GetFeeInfo.do','取sp详细信息','fee.fee','com.vogins.sps.action.fee.fee.GetFeeInfo','','0'),(82,'GetFeeList.do','取列表','fee.fee','com.vogins.sps.action.fee.fee.GetFeeList','','0'),(83,'UpdateFee.do','更新sp','fee.fee','com.vogins.sps.action.fee.fee.UpdateFee','','0'),(84,'AddChargeCode.do','增加通道','fee.chargecode','com.vogins.sps.action.fee.chargecode.AddChargeCode','','0'),(85,'DeleteChargeCode.do','删除通道','fee.chargecode','com.vogins.sps.action.fee.chargecode.DeleteChargeCode','','0'),(86,'GetChargeCodeInfo.do','通道信息','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetChargeCodeInfo','','0'),(87,'GetChargeCodeList.do','通道列表','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetChargeCodeList','','0'),(88,'UpdateChargeCode.do','更新通道','fee.chargecode','com.vogins.sps.action.fee.chargecode.UpdateChargeCode','','0'),(89,'UpdatePermission.do','修改授权','mobile.permission','com.vogins.sps.action.mobile.permission.UpdatePermission','','2'),(90,'GetPermissionInfo.do','取授权信息','mobile.permission','com.vogins.sps.action.mobile.permission.GetPermissionInfo','','0'),(91,'GetPermissionList.do','取授权列表','mobile.permission','com.vogins.sps.action.mobile.permission.GetPermissionList','','0'),(92,'GeneratePerm.do','生成授权列表','mobile.permission','com.vogins.sps.action.mobile.permission.GeneratePermission','','2'),(93,'DeleteAppStore.do','删除AppStore','app.appstore','com.vogins.sps.action.app.appstore.DeleteAppStore','','2'),(94,'GetAppStoreInfo.do','取AppStore信息','app.appstore','com.vogins.sps.action.app.appstore.GetAppStoreInfo','','0'),(95,'GetAppStoreList.do','取AppStore Test列表','app.appstore','com.vogins.sps.action.app.appstore.GetAppStoreList','','0'),(96,'GetUserRecord.do','用户计费记录','log.fee','com.vogins.sps.action.log.fee.GetUserRecord','','0'),(97,'AddTouse.do','增加投诉','log.touse','com.vogins.sps.action.subscriber.touse.AddTouse','','0'),(98,'DeleteTouse.do','删除投诉','log.touse','com.vogins.sps.action.subscriber.touse.DeleteTouse','','0'),(99,'GetTouseInfo.do','投诉信息','log.touse','com.vogins.sps.action.subscriber.touse.GetTouseInfo','','0'),(100,'UpdateTouse.do','更新投诉','log.touse','com.vogins.sps.action.subscriber.touse.UpdateTouse','','0'),(101,'SearchTouse.do','搜索','log.touse','com.vogins.sps.action.subscriber.touse.SearchTouse','','0'),(102,'GetSubscriber.do','查找注册用户','log.fee','com.vogins.sps.action.subscriber.subscriber.GetSubscriber','','0'),(103,'AddApplication.do','添加产品','app.application','com.vogins.sps.action.app.application.AddApplication','','2'),(104,'UpdateApplication.do','修改产品','app.application','com.vogins.sps.action.app.application.UpdateApplication','','2'),(105,'DeleteApplication.do','删除产品','app.application','com.vogins.sps.action.app.application.DeleteApplication','','2'),(106,'GetAppInfo.do','取产品信息','app.application','com.vogins.sps.action.app.application.GetAppInfo','','0'),(107,'GetAppList.do','取产品列表','app.application','com.vogins.sps.action.app.application.GetAppList','','0'),(108,'DeleteVersion.do','删除产品版本','app.appversion','com.vogins.sps.action.app.appversion.DeleteVersion','','2'),(109,'GetVersionInfo.do','取产品版本信息','app.appversion','com.vogins.sps.action.app.appversion.GetVersionInfo','','0'),(110,'GetVersionList.do','取产品版本列表','app.appversion','com.vogins.sps.action.app.appversion.GetVersionList','','0'),(111,'GetAllCp.do','取所有CP列表','app.cp','com.vogins.sps.action.app.cp.GetAllCp','','0'),(112,'AppDownload.do','下载产品文件','app.appversion','com.vogins.sps.action.app.appversion.AppDownload','','0'),(113,'AddFolder.do','添加目录','app.folderinfo','com.vogins.sps.action.app.folderinfo.AddFolder','','2'),(114,'UpdateFolder.do','修改目录','app.folderinfo','com.vogins.sps.action.app.folderinfo.UpdateFolder','','2'),(115,'DeleteFolder.do','删除目录','app.folderinfo','com.vogins.sps.action.app.folderinfo.DeleteFolder','','2'),(116,'UpFolder.do','上移目录','app.folderinfo','com.vogins.sps.action.app.folderinfo.UpFolder','','2'),(117,'DownFolder.do','下移目录','app.folderinfo','com.vogins.sps.action.app.folderinfo.DownFolder','','2'),(118,'GetFolderInfo.do','取目录信息','app.folderinfo','com.vogins.sps.action.app.folderinfo.GetFolderInfo','','0'),(119,'GetSubFolder.do','取子目录','app.folderinfo','com.vogins.sps.action.app.folderinfo.GetSubFolder','','0'),(120,'AddAppToFolder.do','添加产品到目录','app.appfolder','com.vogins.sps.action.app.appfolder.AddAppToFolder','','2'),(121,'DeleteAppFolder.do','从目录删除产品','app.appfolder','com.vogins.sps.action.app.appfolder.DeleteAppFolder','','2'),(122,'UpAppFolder.do','上移目录中的产品','app.appfolder','com.vogins.sps.action.app.appfolder.UpAppFolder','','2'),(123,'DownAppFolder.do','下移目录中的产品','app.appfolder','com.vogins.sps.action.app.appfolder.DownAppFolder','','2'),(124,'GetAppFolderInfo.do','取目录中的产品信息','app.appfolder','com.vogins.sps.action.app.appfolder.GetAppFolderInfo','','0'),(125,'GetFolderAppList.do','取目录下产品列表','app.appfolder','com.vogins.sps.action.app.appfolder.GetFolderAppList','','0'),(126,'GetAllAppList.do','取所有产品列表','app.application','com.vogins.sps.action.app.application.GetAllAppList','','0'),(127,'DeleteGroupConfig.do','删除配置','mobile.groupconfig','com.vogins.sps.action.mobile.feeGroupConfig.DeleteGroupConfig','','0'),(128,'AddCPBlack.do','添加CP黑名单','app.cpblack','com.vogins.sps.action.app.cpblack.AddCPBlack','','2'),(129,'DeleteCPBlack.do','删除CP黑名单','app.cpblack','com.vogins.sps.action.app.cpblack.DeleteCPBlack','','2'),(130,'GetCPBlack.do','取CP黑名单','app.cpblack','com.vogins.sps.action.app.cpblack.GetCPBlack','','0'),(132,'DeleteAppBlack.do','删除产品黑名单','app.appblack','com.vogins.sps.action.app.appblack.DeleteAppBlack','','2'),(133,'GetAppBlack.do','取产品黑名单','app.appblack','com.vogins.sps.action.app.appblack.GetAppBlack','','0'),(134,'AddMobileAppBlack.do','添加机型产品黑名单','app.mobileblack','com.vogins.sps.action.app.mobileblack.AddMobileAppBlack','','2'),(135,'DelMobileAppBlack.do','删除机型产品黑名单','app.mobileblack','com.vogins.sps.action.app.mobileblack.DeleteMobileAppBlack','','2'),(136,'GetMobileAppBlack.do','取机型产品黑名单','app.mobileblack','com.vogins.sps.action.app.mobileblack.GetMobileAppBlack','','0'),(137,'AddMFArea.do','添加厂商专区','app.mfarea','com.vogins.sps.action.app.mfarea.AddMFArea','','2'),(138,'UpdateMFArea.do','修改厂商专区','app.mfarea','com.vogins.sps.action.app.mfarea.UpdateMFArea','','2'),(139,'DeleteMFArea.do','删除厂商专区','app.mfarea','com.vogins.sps.action.app.mfarea.DeleteMFArea','','2'),(140,'GetMFAreaInfo.do','取厂商专区信息','app.mfarea','com.vogins.sps.action.app.mfarea.GetMFAreaInfo','','0'),(141,'GetMFAreaList.do','取厂商专区列表','app.mfarea','com.vogins.sps.action.app.mfarea.GetMFAreaList','','0'),(142,'AddAreaApp.do','添加产品到专区','app.mfareaapp','com.vogins.sps.action.app.mfareaapp.AddAreaApp','','2'),(143,'DeleteAreaApp.do','删除产品从专区','app.mfareaapp','com.vogins.sps.action.app.mfareaapp.DeleteAreaApp','','2'),(144,'DownAreaApp.do','专区产品下移','app.mfareaapp','com.vogins.sps.action.app.mfareaapp.DownAreaApp','','0'),(145,'UpAreaApp.do','专区产品上移','app.mfareaapp','com.vogins.sps.action.app.mfareaapp.UpAreaApp','','0'),(146,'GetAreaAppInfo.do','取专区产品信息','app.mfareaapp','com.vogins.sps.action.app.mfareaapp.GetAreaAppInfo','','0'),(147,'GetAreaAppList.do','取专区产品列表','app.mfareaapp','com.vogins.sps.action.app.mfareaapp.GetAreaAppList','','0'),(148,'DeleteFee.do','删除','fee.fee','com.vogins.sps.action.fee.fee.DeleteFee','','0'),(149,'GetAllProvince.do','得到省份','publicinfo.province','com.vogins.sps.action.publicinfo.province.GetAllProvince','','0'),(150,'DeleteMF.do','删除','mobile.mf','com.vogins.sps.action.mobile.mf.DeleteMF','','0'),(151,'getNoBillSp.do','取未结算的sp','account.sp','com.vogins.sps.action.bill.sp.GetNoBillSp','','0'),(152,'SpBill.do','SP结算','account.sp','com.vogins.sps.action.bill.sp.SpBill','','0'),(153,'SpBillQuery.do','sp账务查询','account.sp','com.vogins.sps.action.bill.sp.SpBillQuery','','0'),(154,'CpBillQuery.do','产品查询','account.cp','com.vogins.sps.action.bill.cp.CpBillQuery','','0'),(155,'MfBillQuery.do','MF结算查询','account.mf','com.vogins.sps.action.bill.mf.MfBillQuery','','0'),(156,'TotalBillQuery.do','结算总表查询','account.total','com.vogins.sps.action.bill.total.TotalBillQuery','','0'),(157,'AddDefault.do','添加总表','app.defaultinfo','com.vogins.sps.action.app.defaultinfo.AddDefault','','2'),(158,'UpdateDefault.do','修改总表','app.defaultinfo','com.vogins.sps.action.app.defaultinfo.UpdateDefault','','2'),(159,'DeleteDefault.do','删除总表','app.defaultinfo','com.vogins.sps.action.app.defaultinfo.DeleteDefault','','2'),(160,'GetDefaultInfo.do','取总表数据','app.defaultinfo','com.vogins.sps.action.app.defaultinfo.GetDefaultInfo','','0'),(161,'GetDefaultList.do','取总表列表','app.defaultinfo','com.vogins.sps.action.app.defaultinfo.GetDefaultList','','0'),(162,'AddDefaultApp.do','添加总表应用','app.defaultapp','com.vogins.sps.action.app.defaultapp.AddDefaultApp','','2'),(163,'DeleteDefaultApp.do','删除总表应用','app.defaultapp','com.vogins.sps.action.app.defaultapp.DeleteDefaultApp','','2'),(164,'GetDefaultAppList.do','取总表产品列表','app.defaultapp','com.vogins.sps.action.app.defaultapp.GetDefaultAppList','','0'),(165,'DownDefaultApp.do','下移总表产品','app.defaultapp','com.vogins.sps.action.app.defaultapp.DownDefaultApp','','2'),(166,'UpDefaultApp.do','上移总表产品','app.defaultapp','com.vogins.sps.action.app.defaultapp.UpDefaultApp','','2'),(167,'AddDefaultVersion.do','添加总表产品版本','app.defaultversion','com.vogins.sps.action.app.defaultversion.AddDefaultVersion','','2'),(168,'DeleteDefaultVer.do','删除总表产品版本','app.defaultversion','com.vogins.sps.action.app.defaultversion.DeleteDefaultVersion','','2'),(169,'GetDefaultVersion.do','取总表产品版本列表','app.defaultversion','com.vogins.sps.action.app.defaultversion.GetDefaultVersion','','0'),(170,'DefaultDownload.do','下载总表','app.defaultinfo','com.vogins.sps.action.app.defaultinfo.DefaultDownload','','0'),(171,'ASDownload.do','下载AppStore','app.appstore','com.vogins.sps.action.app.appstore.ASDownload','','0'),(173,'Sp_DateReport.do','sp日期计费查询','report','com.vogins.sps.action.report.Report_SPFee','','1'),(174,'Sp_ChannelReport.do','sp按计费通道查询','report','com.vogins.sps.action.report.Report_Channel','','1'),(175,'GetAllChannel.do','取子渠道','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetAllChannel','','1'),(176,'Report_CPFee.do','CP计费总查询','report','com.vogins.sps.action.report.Report_CPFee','','1'),(177,'reprot_ProFee.do','按区域计费查询','report','com.vogins.sps.action.report.report_Provincefee','','1'),(178,'report_AreaFee.do','按区域计费查询','report','com.vogins.sps.action.report.report_Areafee','','0'),(179,'report_DateFee.do','按日期查询计费','report','com.vogins.sps.action.report.report_Datefee','','0'),(180,'report_Hourfee.do','按时间计费','report','com.vogins.sps.action.report.report_Hourfee','','0'),(181,'RegUser_Date.do','按日期查注册用户','report','com.vogins.sps.action.report.RegUser_Date','','0'),(182,'RegUser_Hour.do','按时间用户','report','com.vogins.sps.action.report.RegUser_Hour','','1'),(183,'FeeUser_Date.do','计费用户日期','report','com.vogins.sps.action.report.FeeUser_Date','','0'),(184,'Feeuser_Hour.do','计费用户时间','report','com.vogins.sps.action.report.FeeUser_Hour','','0'),(185,'ActUser_Date.do','活跃用户日期','report','com.vogins.sps.action.report.ActUser_Date','','0'),(186,'ActUser_Hour.do','活跃用户时间','report','com.vogins.sps.action.report.ActUser_Hour','','0'),(187,'Report_CPDownLoad.do','cp下载查询','report','com.vogins.sps.action.report.Report_CpDownLoad','','0'),(188,'Report_AppDownL.do','app下载查询','report','com.vogins.sps.action.report.Report_AppDownLoad','','1'),(189,'Report_MoDownLoad.do','按机型下载查询','report','com.vogins.sps.action.report.Report_MobileDownLoad','','0'),(190,'GetAppByCPId.do','根据CP得到AppName','app.application','com.vogins.sps.action.app.application.GetAppByCPId','','0'),(191,'GetSPChannel.do','取SP计费通道','preport','com.vogins.sps.action.preport.GetSPChannel','','0'),(192,'SPReport_Date.do','SP统计-按日期','preport','com.vogins.sps.action.preport.SPReport_Date','','0'),(193,'SPReport_Channel.do','SP统计-按渠道','preport','com.vogins.sps.action.preport.SPReport_Channel','','0'),(194,'TestDownload.do','产品打包下载','pack','com.vogins.sps.action.pack.TestDownload','','0'),(195,'GetMFMobile.do','取厂商机型','preport','com.vogins.sps.action.preport.GetMFMobile','','0'),(196,'MFReport_Date.do','厂商统计-按日期','preport','com.vogins.sps.action.preport.MFReport_Date','','0'),(197,'MFReport_Mobile.do','厂商统计-按机型','preport','com.vogins.sps.action.preport.MFReport_Mobile','','0'),(198,'GetCPApplication.do','取CP产品','preport','com.vogins.sps.action.preport.GetCPApplication','','0'),(199,'CPReport_Date.do','CP统计-按日期','preport','com.vogins.sps.action.preport.CPReport_Date','','0'),(200,'CPReport_App.do','CP统计-按产品','preport','com.vogins.sps.action.preport.CPReport_App','','0'),(201,'CPReport_Dld.do','CP下载统计','preport','com.vogins.sps.action.preport.CPReport_Dld','','0'),(202,'Report_AppHour.do','下载查询按日期','report','com.vogins.sps.action.report.Report_AppStoreHour','','0'),(203,'Report_AppDate.do','按日期查询','report','com.vogins.sps.action.report.Report_AppStoreDate','','0'),(204,'DeleteMessage.do','删除信息','message','com.oa.actions.message.DeleteMessage','','0'),(205,'GetMessageInfo.do','取信息内容','message','com.oa.actions.message.GetMessageInfo','','0'),(206,'GetDeleteBox.do','取已删除信息','message','com.oa.actions.message.GetDeleteBox','','0'),(207,'GetEditBox.do','取草稿箱内容','message','com.oa.actions.message.GetEditBox','','0'),(208,'GetInputBox.do','取收件箱内容','message','com.oa.actions.message.GetInputBox','','0'),(209,'GetOutputBox.do','取已发信息','message','com.oa.actions.message.GetOutputBox','','0'),(210,'GetWaitingBox.do','取发件箱信息','message','com.oa.actions.message.GetWaitingBox','','0'),(211,'RemoveMessage.do','设置信息为删除','message','com.oa.actions.message.RemoveMessage','','0'),(212,'RestoreMsg.do','恢复信息','message','com.oa.actions.message.RestoreMsg','','0'),(213,'SendWaitMsg.do','发送信息','message','com.oa.actions.message.SendWaitMsg','','0'),(214,'FinishedWF.do','完成工作流','oa.workflow','com.oa.workflow.actions.workflow.FinishedWF','','0'),(215,'GetViewWF.do','进行中工作','oa.workflow','com.oa.workflow.actions.workflow.GetViewWF','','0'),(216,'GetWaitWF.do','待办工作','oa.workflow','com.oa.workflow.actions.workflow.GetWaitWF','','0'),(217,'SearchWF.do','查询工作','oa.workflow','com.oa.workflow.actions.workflow.SearchWF','','0'),(218,'DeleteSubFlow.do','删除步骤','oa.workflow','com.oa.workflow.actions.workflow.DeleteSubFlow','','0'),(219,'GetSubWFList.do','取步骤列表','oa.workflow','com.oa.workflow.actions.workflow.GetSubWFList','','0'),(220,'GetSubWFInfo.do','取步骤信息','oa.workflow','com.oa.workflow.actions.workflow.GetSubWFInfo','','0'),(221,'SetHandleStaff.do','设置执行人','oa.workflow','com.oa.workflow.actions.workflow.SetHandleStaff','','0'),(222,'SubmitWF.do','提交工作流','oa.workflow','com.oa.workflow.actions.workflow.SubmitWF','','0'),(223,'UpdateWorkFlow.do','修改工作流信息','oa.workflow','com.oa.workflow.actions.workflow.UpdateWorkFlow','','0'),(224,'DeleteWorkFlow.do','删除工作流','oa.workflow','com.oa.workflow.actions.workflow.DeleteWorkFlow','','0'),(225,'GetWFView.do','取工作流信息','oa.workflow','com.oa.workflow.actions.workflow.GetWFView','','0'),(226,'DoWFHandle.do','处理工作','oa.workflow','com.oa.workflow.actions.workflow.DoWFHandle','','0'),(227,'GetWFHandle.do','取处理工作流信息','oa.workflow','com.oa.workflow.actions.workflow.GetWFHandle','','0'),(228,'SetJumpSub.do','跳过步骤','oa.workflow','com.oa.workflow.actions.workflow.SetJumpSub','','0'),(229,'GetWFBaseInfo.do','取基本信息','oa.workflow','com.oa.workflow.actions.workflow.GetWFBaseInfo','','0'),(230,'GetHandleSubList.do','取执行人列表','oa.workflow','com.oa.workflow.actions.workflow.GetHandleSubList','','0'),(231,'GetStaffList.do','取员工列表','oa.stafflist','com.oa.workflow.actions.stafflist.GetStaffList','','0'),(232,'Report_UserAgent.do','UA查询','report','com.vogins.sps.action.report.Report_UserAgent','','1'),(233,'GetMFInfo_MF.do','取厂商信息','mfwf','com.vogins.sps.action.mfwf.GetMFInfo_MF','','0'),(234,'AddMFUACode.do','申请UA编码','mfwf','com.vogins.sps.action.mfwf.AddMFUACode','','0'),(235,'GetMFAppList.do','取厂商机型可用产品列表','mfwf','com.vogins.sps.action.mfwf.GetMFAppList','','0'),(236,'MFAppDownload.do','下载机型产品','mfwf','com.vogins.sps.action.mfwf.MFAppDownload','','0'),(237,'GetMFMobileList.do','MF专用','mobile.mf','com.vogins.sps.action.mobile.mobile.GetMFMobileList','','1'),(238,'RepealWorkFlow.do','撤销工作流','oa.workflow','com.oa.workflow.actions.workflow.RepealWorkFlow','','0'),(239,'Report_Detail.do','详细信息','report','com.vogins.sps.action.report.Report_Detail','','0'),(240,'DeleteMFolder.do','删除目录','app30.morefolder','com.vogins.sps.action.app30.morefolder.DeleteMFolder','','0'),(241,'DownMFolder.do','目录下移','app30.morefolder','com.vogins.sps.action.app30.morefolder.DownMFolder','','0'),(242,'GetMFolderInfo.do','取目录信息','app30.morefolder','com.vogins.sps.action.app30.morefolder.GetMFolderInfo','','0'),(243,'GetSubMFolder.do','取子目录','app30.morefolder','com.vogins.sps.action.app30.morefolder.GetSubMFolder','','0'),(244,'UpMFolder.do','目录上移','app30.morefolder','com.vogins.sps.action.app30.morefolder.UpMFolder','','0'),(245,'AddAppToMFolder.do','添加产品到目录','app30.moreapp','com.vogins.sps.action.app30.moreapp.AddAppToMFolder','','0'),(246,'DeleteAppMFolder.do','从目录删除产品','app30.moreapp','com.vogins.sps.action.app30.moreapp.DeleteAppMFolder','','0'),(247,'DownAppMFolder.do','产品下移','app30.moreapp','com.vogins.sps.action.app30.moreapp.DownAppMFolder','','0'),(248,'GetAppMFolderInfo.do','取产品信息','app30.moreapp','com.vogins.sps.action.app30.moreapp.GetAppMFolderInfo','','0'),(249,'GetMFolderAppList.do','取产品列表','app30.moreapp','com.vogins.sps.action.app30.moreapp.GetMFolderAppList','','0'),(250,'UpAppMFolder.do','产品上移','app30.moreapp','com.vogins.sps.action.app30.moreapp.UpAppMFolder','','0'),(251,'DeleteDFolder.do','删除目录','app30.topdldfolder','com.vogins.sps.action.app30.topdldfolder.DeleteDFolder','','0'),(252,'DownDFolder.do','目录下移','app30.topdldfolder','com.vogins.sps.action.app30.topdldfolder.DownDFolder','','0'),(253,'GetDFolderInfo.do','取目录信息','app30.topdldfolder','com.vogins.sps.action.app30.topdldfolder.GetDFolderInfo','','0'),(254,'GetSubDFolder.do','取子目录','app30.topdldfolder','com.vogins.sps.action.app30.topdldfolder.GetSubDFolder','','0'),(255,'UpDFolder.do','目录上移','app30.topdldfolder','com.vogins.sps.action.app30.topdldfolder.UpDFolder','','0'),(256,'DeleteNFolder.do','删除目录','app30.newfolder','com.vogins.sps.action.app30.newfolder.DeleteNFolder','','0'),(257,'DownNFolder.do','目录下移','app30.newfolder','com.vogins.sps.action.app30.newfolder.DownNFolder','','0'),(258,'GetNFolderInfo.do','取目录信息','app30.newfolder','com.vogins.sps.action.app30.newfolder.GetNFolderInfo','','0'),(259,'GetSubNFolder.do','取子目录','app30.newfolder','com.vogins.sps.action.app30.newfolder.GetSubNFolder','','0'),(260,'UpNFolder.do','目录上移','app30.newfolder','com.vogins.sps.action.app30.newfolder.UpNFolder','','0'),(261,'DeleteRFolder.do','删除目录','app30.recommendfolder','com.vogins.sps.action.app30.recommendfolder.DeleteRFolder','','0'),(262,'DownRFolder.do','目录下移','app30.recommendfolder','com.vogins.sps.action.app30.recommendfolder.DownRFolder','','0'),(263,'GetRFolderInfo.do','取目录信息','app30.recommendfolder','com.vogins.sps.action.app30.recommendfolder.GetRFolderInfo','','0'),(264,'GetSubRFolder.do','取子目录','app30.recommendfolder','com.vogins.sps.action.app30.recommendfolder.GetSubRFolder','','0'),(265,'UpRFolder.do','目录上移','app30.recommendfolder','com.vogins.sps.action.app30.recommendfolder.UpRFolder','','0'),(266,'AddAppToRFolder.do','添加产品到目录','app30.recommendapp','com.vogins.sps.action.app30.recommendapp.AddAppToRFolder','','0'),(267,'DeleteAppRFolder.do','从目录删除产品','app30.recommendapp','com.vogins.sps.action.app30.recommendapp.DeleteAppRFolder','','0'),(268,'DownAppRFolder.do','产品下移','app30.recommendapp','com.vogins.sps.action.app30.recommendapp.DownAppRFolder','','0'),(269,'GetAppRFolderInfo.do','取产品信息','app30.recommendapp','com.vogins.sps.action.app30.recommendapp.GetAppRFolderInfo','','0'),(270,'GetRFolderAppList.do','取目录产品列表','app30.recommendapp','com.vogins.sps.action.app30.recommendapp.GetRFolderAppList','','0'),(271,'UpAppRFolder.do','产品上移','app30.recommendapp','com.vogins.sps.action.app30.recommendapp.UpAppRFolder','','0'),(272,'AddAdv.do','添加广告','as30.adv','com.vogins.sps.action.as30.advertising.AddAdv','','0'),(273,'DeleteAdv.do','删除广告','as30.adv','com.vogins.sps.action.as30.advertising.DeleteAdv','','0'),(274,'GetAdvInfo.do','获取信息','as30.adv','com.vogins.sps.action.as30.advertising.GetAdvInfo','','0'),(275,'GetAllAdv.do','取广告列表','as30.adv','com.vogins.sps.action.as30.advertising.GetAllAdv','','0'),(276,'UpdateAdv.do','修改广告','as30.adv','com.vogins.sps.action.as30.advertising.UpdateAdv','','0'),(365,'AddSearch.do','添加','as30.search','com.vogins.sps.action.as30.MobileSearch.AddSearch','','0'),(278,'DeleteSearch.do','删除','as30.search','com.vogins.sps.action.as30.MobileSearch.DeleteSearch','','0'),(279,'GetAllSearch.do','取列表','as30.search','com.vogins.sps.action.as30.MobileSearch.GetAllSearch','','1'),(280,'GetSearchInfo.do','取信息','as30.search','com.vogins.sps.action.as30.MobileSearch.GetSearchInfo','','1'),(281,'UpdateSearch.do','修改','as30.search','com.vogins.sps.action.as30.MobileSearch.UpdateSearch','','1'),(282,'AddWap.do','添加wap','as30.wap','com.vogins.sps.action.as30.wap.AddWap','','0'),(283,'DeleteWap.do','删除wap','as30.wap','com.vogins.sps.action.as30.wap.DeleteWap','','1'),(284,'GetAllWap.do','取wap列表','as30.wap','com.vogins.sps.action.as30.wap.GetAllWap','','0'),(285,'GetWapInfo.do','取信息','as30.wap','com.vogins.sps.action.as30.wap.GetWapInfo','','1'),(286,'UpdateWap.do','更新','as30.wap','com.vogins.sps.action.as30.wap.UpdateWap','','0'),(369,'GetMsgInfo.do','取wap信息','as30.msg','com.vogins.sps.action.as30.WebMessage.GetMsgInfo','','0'),(368,'GetAllMsg.do','取列表','as30.msg','com.vogins.sps.action.as30.WebMessage.GetAllMsg','','0'),(366,'AddWebMsg.do','添加站内消息','as30.msg','com.vogins.sps.action.as30.WebMessage.AddWebMsg','','0'),(367,'DeleteWebMsg.do','删除webMsg','as30.msg','com.vogins.sps.action.as30.WebMessage.DeleteWebMsg','','0'),(364,'MFReport_Detail.do','取详细信息','preport','com.vogins.sps.action.preport.MFReport_Detail','','0'),(297,'Report_SpsDetail.do','详细信息','report','com.vogins.sps.action.report.Report_SpsDetail','','0'),(393,'GetSubMFList.do','取子厂商列表','mobile.submf','com.vogins.sps.action.mobile.submf.GetSubMFList','','0'),(392,'GetSubMFInfo.do','取子厂商信息','mobile.submf','com.vogins.sps.action.mobile.submf.GetSubMFInfo','','0'),(391,'DeleteSubMF.do','删除子厂商','mobile.submf','com.vogins.sps.action.mobile.submf.DeleteSubMF','','0'),(390,'UpdateSubMF.do','修改子厂商','mobile.submf','com.vogins.sps.action.mobile.submf.UpdateSubMF','','0'),(389,'AddSubMF.do','添加子厂商','mobile.submf','com.vogins.sps.action.mobile.submf.AddSubMF','','0'),(298,'DeleteDocument.do','删除文档','cpflow.bucoflow','com.vogins.sps.action.cpworkflow.doc.DeleteDocument','删除文档','2'),(299,'DownloadDocument.do','下载文档','cpflow.bucoflow','com.vogins.sps.action.cpworkflow.doc.DownloadDocument','下载文档','2'),(300,'GetDocumentInfo.do','获取文档信息','cpflow.bucoflow','com.vogins.sps.action.cpworkflow.doc.GetDocumentInfo','获取文档信息','2'),(302,'DownloadQuestion.do','下载文档','cpflow.question','com.vogins.sps.action.cpworkflow.question.DownloadQuestion','','2'),(301,'GetDocumentList.do','获取文档列表','cpflow.bucoflow','com.vogins.sps.action.cpworkflow.doc.GetDocumentList','获取文档列表','2'),(303,'GetQuestionInfo.do','获得问题信息','cpflow.question','com.vogins.sps.action.cpworkflow.question.GetQuestionInfo','','2'),(304,'GetQuestionList.do','获得问题列表','cpflow.question','com.vogins.sps.action.cpworkflow.question.GetQuestionList','','2'),(305,'GetProjectInfo.do','读取工程信息','cpflow.project','com.vogins.sps.action.cpworkflow.project.GetProjectInfo','','0'),(306,'UpdateChargeCodeUpda','获取工程list','cpflow.project','com.vogins.sps.action.cpworkflow.project.GetProjectList','','1'),(307,'GetBugInfo.do','获取bug信息','cpflow.bug','com.vogins.sps.action.cpworkflow.project.GetBugInfo','','1'),(308,'GetBugList.do','获取bug列表','cpflow.bug','com.vogins.sps.action.cpworkflow.project.GetBugList','','1'),(309,'GetAllProject.do','取所有工程','cpflow.project','com.vogins.sps.action.cpworkflow.project.GetAllProject','','1'),(310,'GetQuestionListCP.do','CP获得问题列表','cpflow.question','com.vogins.sps.action.cpworkflow.question.GetQuestionListCP','','2'),(311,'GetQuestionListOt.do','获得问题列表','cpflow.question','com.vogins.sps.action.cpworkflow.question.GetQuestionListOt','','2'),(312,'DownloadApp.do','下载文件','cpflow.bug','com.vogins.sps.action.cpworkflow.project.DownloadApp','','0'),(313,'CloseBug.do','关闭bug','cpflow.bug','com.vogins.sps.action.cpworkflow.project.CloseBug','','1'),(314,'ReBootBug.do','激活bug','cpflow.bug','com.vogins.sps.action.cpworkflow.project.ReBootBug','','1'),(315,'DownloadFile.do','下载项目文件','cpflow.project','com.vogins.sps.action.cpworkflow.project.DownloadFile','','1'),(316,'GetBugListByPro.do','根据pro获取buglist','cpflow.bug','com.vogins.sps.action.cpworkflow.project.GetBugListByPro','','0'),(317,'DeleteProject.do','删除项目','cpflow.project','com.vogins.sps.action.cpworkflow.project.DeleteProject','','1'),(318,'InitSelect.do','初始化CP下拉框(TS调用)','cpflow.question','com.vogins.sps.action.cpworkflow.question.InitSelect','初始化CP下拉框(TS调用)','2'),(319,'GetProAppList.do','取pro的app','cpflow.bug','com.vogins.sps.action.cpworkflow.project.GetProAppList','','1'),(320,'DeleteProApp.do','删除proApp','cpflow.bug','com.vogins.sps.action.cpworkflow.project.DeleteProApp','','0'),(321,'DownloadBugFile.do','下载bug文档','cpflow.bug','com.vogins.sps.action.cpworkflow.project.DownloadBugFile','','1'),(322,'GetEvabbsList.do','获取评论列表','cpflow.evabbs','com.vogins.sps.action.cpworkflow.evabbs.GetEvabbsList','获取评论列表','2'),(323,'GetEvabbsInfo.do','获取评论信息','cpflow.evabbs','com.vogins.sps.action.cpworkflow.evabbs.GetEvabbsInfo','获取评论信息','2'),(324,'DownloadEvabbs.do','下载评论文件','cpflow.evabbs','com.vogins.sps.action.cpworkflow.evabbs.DownloadEvabbs','下载评论文件','2'),(325,'GetDisEbbsListOT.do','获取回复列表','cpflow.evabbs','com.vogins.sps.action.cpworkflow.evabbs.GetDisEbbsListOT','获取回复列表','2'),(326,'GetCPEvaList.do','取产品评估列表','cpflow.eva','com.vogins.sps.action.cpworkflow.eva.GetCPEvaList','','0'),(327,'GetEvaList.do','取产品评估列表','cpflow.eva','com.vogins.sps.action.cpworkflow.eva.GetEvaList','','0'),(328,'GetEvaInfo.do','取产品信息','cpflow.eva','com.vogins.sps.action.cpworkflow.eva.GetEvaInfo','','0'),(329,'GetVContactList.do','获取联系人列表','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.GetVContactList','获取联系人列表','2'),(330,'GetVContactInfo.do','获取联系人信息','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.GetVContactInfo','获取联系人信息','2'),(331,'DeleteVContact.do','删除联系人','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.DeleteVContact','删除联系人','2'),(332,'GetCPProjectList.do','取CP项目列表','cpflow.project','com.vogins.sps.action.cpworkflow.project.GetCPProjectList','','0'),(333,'GetCpProject.do','CP专用','cpflow.project','com.vogins.sps.action.cpworkflow.project.GetCpProject','','0'),(334,'InitVCSelect.do','初始化用户名下拉框','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.InitVCSelect','初始化用户名下拉框','2'),(335,'AddVContact.do','添加联系人','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.AddVContact','添加联系人','2'),(336,'CompleteTest.do','完成测试','cpflow.project','com.vogins.sps.action.cpworkflow.project.CompleteTest','','1'),(337,'UpdateVContact.do','修改联系人信息','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.UpdateVContact','修改联系人信息','2'),(338,'GetEditWF.do','取未完成工作','oa.workflow','com.oa.workflow.actions.workflow.GetEditWF','','0'),(339,'GetProjectEva.do','取等待立项申请','cpflow.eva','com.vogins.sps.action.cpworkflow.eva.GetProjectEva','','0'),(340,'GetProIconList.do','取Iconlist','cpflow.project','com.vogins.sps.action.cpworkflow.project.GetProIconList','','0'),(341,'DownloadIcon.do','下载icon','cpflow.project','com.vogins.sps.action.cpworkflow.project.DownloadIcon','','1'),(342,'GetCPEvabbsList.do','获取回复列表CP界面','cpflow.evabbs','com.vogins.sps.action.cpworkflow.evabbs.GetCPEvabbsList','','2'),(343,'GetProContactList.do','取项目联系人列表','cpflow.voginscontact','com.vogins.sps.action.cpworkflow.contact.GetProContactList','','0'),(344,'GetDisEbbsListCP.do','获取回复列表CP','cpflow.evabbs','com.vogins.sps.action.cpworkflow.evabbs.GetDisEbbsListCP','','2'),(347,'AddUserSc.do','添加快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.AddUserSc','','0'),(346,'GetUabyMFId.do','取UA','mobile.mobile','com.vogins.sps.action.mobile.mobile.GetUabyMFId','','1'),(348,'DeleteUserSc.do','删除快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.DeleteUserSc','','0'),(349,'UpUserSc.do','上移快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.UpUserSc','','0'),(350,'DownUserSc.do','下移快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.DownUserSc','','0'),(351,'GetAllSc.do','取所有快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.GetAllSc','','0'),(352,'GetUserSc.do','取用户快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.GetUserSc','','0'),(353,'ShowShortCut.do','显示快捷方式','oa.shortcut','org.jwdf.framework.actions.shortcut.ShowShortCut','','0'),(354,'UpMenu.do','上移菜单','system.menu','org.jwdf.framework.actions.menu.UpMenu','','0'),(355,'DownMenu.do','下移菜单','system.menu','org.jwdf.framework.actions.menu.DownMenu','','0'),(356,'GetAppListByName.do','获取按产品名称查询列表','app.application','com.vogins.sps.action.app.application.GetAppListByName','获取按产品名称查询列表','2'),(357,'GetCPListByCP.do','按CP名称获取CP列表','app.cp','com.vogins.sps.action.app.cp.GetCPListByCP','按CP名称获取CP列表','2'),(358,'GetFeeCannelBySP.do','根据SPId获取子渠道列表','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetFeeCannelBySP','根据SPId获取子渠道列表','2'),(359,'GetSubInfo.do','根据FeeId获取子渠道具体信息','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetSubInfo','根据FeeId获取子渠道具体信息','2'),(360,'GetSPListBySP.do','按SPName关键字查找具体SP列表','fee.fee','com.vogins.sps.action.fee.fee.GetSPListBySP','按SPName关键字查找具体SP列表','2'),(361,'GetFeeListByFee.do','按FeeName关键字查找列表','fee.fee','com.vogins.sps.action.fee.fee.GetFeeListByFee','按FeeName关键字查找列表','2'),(362,'GetAppListByCPId.do','根据CPId获取产品列表','app.application','com.vogins.sps.action.app.application.GetAppListByCPId','根据CPId获取产品列表','2'),(363,'GetApByApAndCPId.do','按产品名称和CPId获取产品列表','app.application','com.vogins.sps.action.app.application.GetApByApAndCPId','按产品名称和CPId获取产品列表','2'),(370,'UpdateWebMsg.do','更新wabmsg','as30.msg','com.vogins.sps.action.as30.WebMessage.UpdateWebMsg','','0'),(383,'GetGroupByCountry.do','根据国家取通道组','fee.feegroup','com.vogins.sps.action.fee.feegroup.GetGroupByCountry','','0'),(384,'GetFilterApp.do','取预置产品过滤列表','app.preapp','com.vogins.sps.action.app.preapp.GetFilterApp','','0'),(372,'GetSpByCountry.do','按国家取SP','fee.fee','com.vogins.sps.action.fee.fee.GetSpByCountry','','0'),(373,'GetAllCountry.do','取国家','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetAllCountry','','0'),(374,'GetMFListByMFName.do','按手机厂商关键字搜索厂商列表','mobile.mf','com.vogins.sps.action.mobile.mf.GetMFListByMFName','按手机厂商关键字搜索厂商列表','2'),(375,'GetMoByMoAndMFId.do','根据MFId和机型名称查找机型列表','mobile.mobile','com.vogins.sps.action.mobile.mobile.GetMoByMoAndMFId','根据MFId和机型名称查找机型列表','2'),(376,'GetCountryInfo.do','取国家信息','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetCountryInfo','','0'),(377,'getOPByCountry.do','根据国家取OP','publicinfo.country','com.vogins.sps.action.publicinfo.internation.getOPByCountry','','0'),(378,'GetFeeByOp.do','根据OP取通道','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetFeeByOp','','1'),(379,'AddPreApp.do','添加预置产品','app.preapp','com.vogins.sps.action.app.preapp.AddPreApp','','0'),(380,'DeletePreApp.do','删除预置产品','app.preapp','com.vogins.sps.action.app.preapp.DeletePreApp','','0'),(381,'GetPreAppInfo.do','取预置产品信息','app.preapp','com.vogins.sps.action.app.preapp.GetPreAppInfo','','0'),(382,'GetPreAppList.do','取预置产品列表','app.preapp','com.vogins.sps.action.app.preapp.GetPreAppList','','0'),(385,'PreAppDownload.do','预置产品下载','app.preapp','com.vogins.sps.action.app.preapp.PreAppDownload','','0'),(386,'PreAppDldAll.do','下载所有预置产品','app.preapp','com.vogins.sps.action.app.preapp.PreAppDldAll','','0'),(387,'SearchMFMobile.do','搜索厂商机型','mobile.mobile','com.vogins.sps.action.mobile.mobile.SearchMFMobile','','0'),(388,'GetUNCleBillSP.do','根据年份和月份查询为结算的SP','account.sp','com.vogins.sps.action.bill.sp.GetUNCleBillSP','根据年份和月份查询为结算的SP','2'),(394,'GetAllSubMF.do','取所有子厂商','mobile.submf','com.vogins.sps.action.mobile.submf.GetAllSubMF','','0'),(395,'AddSubMFMobile.do','添加子厂商机型','mobile.submfmobile','com.vogins.sps.action.mobile.submfmobile.AddSubMFMobile','','0'),(396,'DeleteSubMFMobile.do','删除子厂商机型','mobile.submfmobile','com.vogins.sps.action.mobile.submfmobile.DeleteSubMFMobile','','0'),(397,'GetSMobileList.do','取子厂商机型列表','mobile.submfmobile','com.vogins.sps.action.mobile.submfmobile.GetSMobileList','','0'),(398,'MFReportUserAgent.do','根据UA查询','preport','com.vogins.sps.action.preport.MFReport_UserAgent','','0'),(399,'GetMFUserAgent.do','根据MF取UA','mobile.mf','com.vogins.sps.action.mobile.mobile.GetMFUserAgent','','0'),(400,'AddAppBlack.do','添加应用黑名单','app.appblack','com.vogins.sps.action.app.appblack.AddAppBlack','添加应用黑名单','0'),(401,'GetCountryList.do','获取国家列表','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetCountryList','获取国家列表','1'),(402,'AddCountry.do','添加国家信息','publicinfo.country','com.vogins.sps.action.publicinfo.internation.AddCountry','添加国家信息','1'),(403,'UpdateCountry.do','修改国家信息','publicinfo.country','com.vogins.sps.action.publicinfo.internation.UpdateCountry','修改国家信息','1'),(404,'DeleteCountry.do','删除国家','publicinfo.country','com.vogins.sps.action.publicinfo.internation.DeleteCountry','删除国家','1'),(425,'GetOPByCountry3.do','根据国家获取运营商','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetOPByCountry3','根据国家获取运营商','0'),(406,'AddOperator.do','添加运营商','publicinfo.country','com.vogins.sps.action.publicinfo.internation.AddOperator','添加运营商','1'),(407,'GetOperatorInfo.do','获取运营商详细信息','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetOperatorInfo','获取运营商详细信息','1'),(408,'GetProListNewPD.do','获取新建项目列表','prodevelop','com.vogins.sps.action.prodevelop.GetProListNewPD','获取新建项目列表','1'),(409,'GetProInfoNewPD.do','获取新建项目详细信息','prodevelop','com.vogins.sps.action.prodevelop.GetProInfoNewPD','获取新建项目详细信息','0'),(410,'UpdateProStaPD.do','新建项目转换到测试状态','prodevelop','com.vogins.sps.action.prodevelop.UpdateProStaPD','新建项目转换到测试状态','0'),(411,'GetProListTestPD.do','获取测试项目列表','prodevelop','com.vogins.sps.action.prodevelop.GetProListTestPD','获取测试项目列表','0'),(412,'GetAppFileList.do','获取相应项目的产品文件列表','prodevelop','com.vogins.sps.action.prodevelop.GetAppFileList','获取相应项目的产品文件列表','1'),(413,'DownloadAppFile.do','下载产品文件','prodevelop','com.vogins.sps.action.prodevelop.DownloadAppFile','下载产品文件','0'),(414,'GetBugFileList.do','获取测试项目BUG文件列表','prodevelop','com.vogins.sps.action.prodevelop.GetBugFileList','获取测试项目BUG文件列表','1'),(418,'DownloadBugPD.do','下载BUG文件','prodevelop','com.vogins.sps.action.prodevelop.DownloadBugPD','下载BUG文件','0'),(419,'GetProListRejPD.do','获取驳回项目列表','prodevelop','com.vogins.sps.action.prodevelop.GetProListRejPD','获取驳回项目列表','0'),(420,'GetProListPassPD.do','获取通过项目列表','prodevelop','com.vogins.sps.action.prodevelop.GetProListPassPD','获取通过项目列表','0'),(421,'GetProListLinePD.do','获取上线项目列表','prodevelop','com.vogins.sps.action.prodevelop.GetProListLinePD','获取上线项目列表','0'),(426,'UpdateOperator.do','修改运营商信息','publicinfo.country','com.vogins.sps.action.publicinfo.internation.UpdateOperator','修改运营商信息','0'),(427,'DeleteOperator.do','删除运营商','publicinfo.country','com.vogins.sps.action.publicinfo.internation.DeleteOperator','','0'),(428,'GetAllOperator.do','获取运营商列表','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetAllOperator','获取运营商列表','0'),(429,'GetCAByOperator.do','根据运营商获取短信中心代码列表','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetCAByOperator','根据运营商获取短信中心代码列表','0'),(430,'AddSmsCA.do','添加短信中心代码','publicinfo.country','com.vogins.sps.action.publicinfo.internation.AddSmsCA','添加短信中心代码','0'),(431,'GetSmsCaInfo.do','获取短信中心代码具体信息','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetSmsCaInfo','获取短信中心代码具体信息','0'),(432,'UpdateSmsCa.do','修改短信中心代码','publicinfo.country','com.vogins.sps.action.publicinfo.internation.UpdateSmsCa','修改短信中心代码','0'),(433,'DeleteSmsCa.do','删除短信中心代码','publicinfo.country','com.vogins.sps.action.publicinfo.internation.DeleteSmsCa','删除短信中心代码','0'),(434,'GetRecDefList.do','获取精品推荐总表列表','app30.recommendinfo','com.vogins.sps.action.app30.recommendinfo.GetRecDefList','获取精品推荐总表列表','0'),(435,'GetRecDefInfo.do','获取精品推荐总表记录详细信息','app30.recommendinfo','com.vogins.sps.action.app30.recommendinfo.GetRecDefInfo','获取精品推荐总表记录详细信息','0'),(436,'AddRecDefault.do','添加精品推荐总表','app30.recommendinfo','com.vogins.sps.action.app30.recommendinfo.AddRecDefault','添加精品推荐总表','0'),(437,'UpdateRecDef.do','修改精品推荐总表','app30.recommendinfo','com.vogins.sps.action.app30.recommendinfo.UpdateRecDef','修改精品推荐总表','0'),(438,'DeleteRecDef.do','删除精品推荐总表','app30.recommendinfo','com.vogins.sps.action.app30.recommendinfo.DeleteRecDef','删除精品推荐总表','0'),(439,'GetChannByCountry.do','根据国家取channel','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetChannelByCountry','','0'),(440,'UpdateTopDef.do','修改热门下载总表','app30.topdldinfo','com.vogins.sps.action.app30.topdldinfo.UpdateTopDef','修改热门下载总表','0'),(441,'GetTopDefList.do','获热门下载总表记录列表','app30.topdldinfo','com.vogins.sps.action.app30.topdldinfo.GetTopDefList','获热门下载总表记录列表','0'),(442,'GetTopDefInfo.do','获取热门下载总表记录详细信息','app30.topdldinfo','com.vogins.sps.action.app30.topdldinfo.GetTopDefInfo','获取热门下载总表记录详细信息','0'),(443,'DeleteTopDef.do','删除热门下载总表','app30.topdldinfo','com.vogins.sps.action.app30.topdldinfo.DeleteTopDef','删除热门下载总表','0'),(444,'AddTopDefault.do','添加热门下载总表','app30.topdldinfo','com.vogins.sps.action.app30.topdldinfo.AddTopDefault','添加热门下载总表','0'),(445,'GetTopDefAppList.do','获取热门产品总表产品列表','app30.topdlddefapp','com.vogins.sps.action.app30.topdlddefapp.GetTopDefAppList','获取热门产品总表产品列表','0'),(446,'GetRecDefAppList.do','获取精品推荐总表产品列表','app30.recommenddefapp','com.vogins.sps.action.app30.recommenddefapp.GetRecDefAppList','获取精品推荐总表产品列表','0'),(447,'AddRecDefApp.do','精品推荐总表添加产品到目录','app30.recommenddefapp','com.vogins.sps.action.app30.recommenddefapp.AddRecDefApp','精品推荐总表添加产品到目录','0'),(448,'AddTopDefApp.do','热门下载总表添加产品到目录','app30.topdlddefapp','com.vogins.sps.action.app30.topdlddefapp.AddTopDefApp','热门下载总表添加产品到目录','0'),(449,'DeleteRecDefApp.do','精品推荐总表文件夹删除产品','app30.recommenddefapp','com.vogins.sps.action.app30.recommenddefapp.DeleteRecDefApp','精品推荐总表文件夹删除产品','0'),(450,'DeleteTopDefApp.do','热门下载总表文件夹删除产品','app30.topdlddefapp','com.vogins.sps.action.app30.topdlddefapp.DeleteTopDefApp','热门下载总表文件夹删除产品','0'),(451,'DownRecDefApp.do','精品推荐总表产品下移','app30.recommenddefapp','com.vogins.sps.action.app30.recommenddefapp.DownRecDefApp','精品推荐总表产品下移','0'),(452,'UpRecDefApp.do','精品推荐总表产品上移','app30.recommenddefapp','com.vogins.sps.action.app30.recommenddefapp.UpRecDefApp','精品推荐总表产品上移','0'),(453,'DownTopDefApp.do','热门下载总表产品下移','app30.topdlddefapp','com.vogins.sps.action.app30.topdlddefapp.DownTopDefApp','热门下载总表产品下移','0'),(454,'UpTopDefApp.do','热门下载总表产品上移','app30.topdlddefapp','com.vogins.sps.action.app30.topdlddefapp.UpTopDefApp','热门下载总表产品上移','0'),(455,'AddRecDefVersion.do','精品推荐总表添加版本','app30.recversion','com.vogins.sps.action.app30.recversion.AddRecDefVersion','精品推荐总表添加版本','0'),(456,'DeleteRecDefVer.do','精品推荐总表删除版本','app30.recversion','com.vogins.sps.action.app30.recversion.DeleteRecDefVer','精品推荐总表删除版本','0'),(457,'GetRecDefVersion.do','精品推荐总表获取版本','app30.recversion','com.vogins.sps.action.app30.recversion.GetRecDefVersion','精品推荐总表获取版本','0'),(458,'AddTopDefVersion.do','热门下载总表添加版本','app30.topversion','com.vogins.sps.action.app30.topversion.AddTopDefVersion','热门下载总表添加版本','0'),(459,'DeleteTopDefVer.do','热门下载总表删除版本','app30.topversion','com.vogins.sps.action.app30.topversion.DeleteTopDefVer','热门下载总表删除版本','0'),(460,'GetTopDefVersion.do','热门下载总表获取版本','app30.topversion','com.vogins.sps.action.app30.topversion.GetTopDefVersion','热门下载总表获取版本','0'),(461,'TopDefDownload.do','下载热门推荐总表','app30.topdldinfo','com.vogins.sps.action.app30.topdldinfo.TopDefDownload','下载热门推荐总表','0'),(462,'RecDefDownload.do','下载精品推荐总表','app30.recommendinfo','com.vogins.sps.action.app30.recommendinfo.RecDefDownload','下载精品推荐总表','0'),(463,'GetSubRDFolder.do','获取精品推荐目录结构','app30.recommenddeffolder','com.vogins.sps.action.app30.recommenddeffolder.GetSubRDFolder','获取精品推荐目录结构','0'),(464,'DeleteRDFolder.do','删除精品推荐总表目录','app30.recommenddeffolder','com.vogins.sps.action.app30.recommenddeffolder.DeleteRDFolder','删除精品推荐总表目录','0'),(465,'UpRDFolder.do','上移精品推荐总表目录','app30.recommenddeffolder','com.vogins.sps.action.app30.recommenddeffolder.UpRDFolder','上移精品推荐总表目录','0'),(466,'DownRDFolder.do','下移精品推荐总表目录','app30.recommenddeffolder','com.vogins.sps.action.app30.recommenddeffolder.DownRDFolder','下移精品推荐总表目录','0'),(467,'GetRDFolderInfo.do','获取精品推荐总表目录详细信息','app30.recommenddeffolder','com.vogins.sps.action.app30.recommenddeffolder.GetRDFolderInfo','获取精品推荐总表目录详细信息','0'),(468,'UpRTFolder.do','上移热门下载总表目录','app30.topdlddeffolder','com.vogins.sps.action.app30.topdlddeffolder.UpRTFolder','上移热门下载总表目录','0'),(469,'GetSubRTFolder.do','获得热门下载总表目录','app30.topdlddeffolder','com.vogins.sps.action.app30.topdlddeffolder.GetSubRTFolder','获得热门下载总表目录','0'),(470,'GetRTFolderInfo.do','获取热门下载总表目录详细信息','app30.topdlddeffolder','com.vogins.sps.action.app30.topdlddeffolder.GetRTFolderInfo','获取热门下载总表目录详细信息','0'),(471,'DownRTFolder.do','下移热门下载总表目录','app30.topdlddeffolder','com.vogins.sps.action.app30.topdlddeffolder.DownRTFolder','下移热门下载总表目录','0'),(472,'DeleteRTFolder.do','删除热门下载总表目录','app30.topdlddeffolder','com.vogins.sps.action.app30.topdlddeffolder.DeleteRTFolder','删除热门下载总表目录','0'),(473,'GetCityByProId.do','根据省份获取城市列表','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetCityByProId','根据省份获取城市列表','0'),(474,'GetProList.do','获取产品列表','fs.product','com.vogins.sps.action.fs.product.GetProList','获取产品列表','0'),(475,'GetProInfo.do','获取产品详细信息','fs.product','com.vogins.sps.action.fs.product.GetProInfo','获取产品详细信息','0'),(476,'GetProListByName.do','按名称关键字查询产品列表','fs.product','com.vogins.sps.action.fs.product.GetProListByName','按名称关键字查询产品列表','0'),(477,'DeleteProduct.do','删除产品','fs.product','com.vogins.sps.action.fs.product.DeleteProduct','删除产品','0'),(478,'AddFSProToMFolder.do','添加资源到目录','app30.moreapp','com.vogins.sps.action.app30.moreapp.AddFSProToMFolder','添加资源到目录','0'),(479,'GetMFolderProList.do','获取对应目录的资源列表','app30.moreapp','com.vogins.sps.action.app30.moreapp.GetMFolderProList','获取对应目录的资源列表','0'),(480,'GetProMFolderInfo.do','获取应用或资源详细信息','app30.moreapp','com.vogins.sps.action.app30.moreapp.GetProMFolderInfo','获取应用或资源详细信息','0'),(481,'GetAllProList.do','获取所有资源列表(更多下载模块使用)','fs.product','com.vogins.sps.action.fs.product.GetAllProList','获取所有资源列表(更多下载模块使用)','0'),(482,'addDepartment.do','增加部门','account.cp','test.neat.action.AddDepartmentAction','','0'),(513,'GetCSpByCountry.do','按国家取SP','cfee.fee','com.vogins.sps.action.cfee.fee.GetCSpByCountry','','0'),(512,'GetCFeeListByFee.do','按FeeName关键字查找列表','cfee.fee','com.vogins.sps.actionc.cfee.fee.GetCFeeListByFee','','0'),(493,'AddCChargeCode.do','增加通道','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.AddCChargeCode','','0'),(494,'DeleteCChargeCode.do','删除通道','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.DeleteCChargeCode','','0'),(487,'AddTip.do','添加计费提示语','publicinfo.feetips','com.vogins.sps.action.publicinfo.feetips.AddTip','','0'),(488,'DeleteTip.do','删除计费提示语','publicinfo.feetips','com.vogins.sps.action.publicinfo.feetips.DeleteTip','','0'),(489,'GetTipInfo.do','获取计费提示语信息','publicinfo.feetips','com.vogins.sps.action.publicinfo.feetips.GetTipInfo','','0'),(490,'GetTipList.do','获取计费提示语列表','publicinfo.feetips','com.vogins.sps.action.publicinfo.feetips.GetTipList','','0'),(491,'UpdateTip.do','修改计费提示语','publicinfo.feetips','com.vogins.sps.action.publicinfo.feetips.UpdateTip','','0'),(492,'GetCountryCode.do','获取所有国家代码列表','publicinfo.country','com.vogins.sps.action.publicinfo.internation.GetCountryCode','','0'),(497,'GetCCodeInfo.do','通道信息','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetCChargeCodeInfo','','0'),(498,'GetCCodeList.do','通道列表','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetCChargeCodeList','','0'),(499,'UpdateCChargeCode.do','更新通道','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.UpdateCChargeCode','','0'),(500,'GetAllCChannel.do','取子渠道','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetAllCChannel','','0'),(501,'GetCFeeCannelBySP.do','根据SPId获取子渠道列表','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetCFeeCannelBySP','','0'),(502,'GetCSubInfo.do','根据FeeId获取子渠道具体信息','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetCSubInfo','根据FeeId获取子渠道具体信息','0'),(503,'GetCFeeByOp.do','根据OP取通道','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetCFeeByOp','','0'),(504,'GetCCountry.do','根据国家取channel','cfee.chargecode','com.vogins.sps.action.cfee.chargecode.GetCChannelByCountry','','0'),(505,'AddCFee.do','增加sp','cfee.fee','com.vogins.sps.action.cfee.fee.AddCFee','','0'),(506,'GetAllCFee.do','取sp','cfee.fee','com.vogins.sps.action.cfee.fee.GetAllCFee','','0'),(507,'GetCFeeInfo.do','取sp详细信息','cfee.fee','com.vogins.sps.action.cfee.fee.GetCFeeInfo','','1'),(508,'GetCFeeList.do','取列表','cfee.fee','com.vogins.sps.action.cfee.fee.GetCFeeList','','1'),(509,'UpdateCFee.do','更新sp','cfee.fee','com.vogins.sps.action.cfee.fee.UpdateCFee','','1'),(510,'DeleteCFee.do','删除','cfee.fee','com.vogins.sps.action.cfee.fee.DeleteCFee','','0'),(511,'GetCSPListBySP.do','按SPName关键字查找具体SP列表','cfee.fee','com.vogins.sps.action.cfee.fee.GetCSPListBySP','','0'),(514,'GetAppStore2List.do','取AppStore2列表','app.appstore','com.vogins.sps.action.app.appstore.GetAppStoreList','','0'),(515,'GetCFeeGroupInfo.do','通道组信息','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.GetCFeeGroupInfo','','0'),(516,'GetCFeeGroupList.do','通道组列表','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.GetCFeeGroupList','','0'),(517,'GetAppStore3List.do','取AppStore3列表','app.appstore','com.vogins.sps.action.app.appstore.GetAppStoreList','','0'),(518,'UpdateCFeeGroup.do','更新通道组','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.UpdateCFeeGroupc','','0'),(519,'GetCGroupCountry.do','根据国家取通道组','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.GetCGroupByCountry','','0'),(520,'AddCGroupConfig.do','配置通道组','mobile.cgroupconfig','com.vogins.sps.action.mobile.cfeeGroupConfig.AddCGroupConfig','','0'),(521,'cchanneldown.do','下移','mobile.cgroupconfig','com.vogins.sps.action.mobile.cfeeGroupConfig.CChannelDown','','0'),(522,'cchannelUp.do','上移','mobile.cgroupconfig','com.vogins.sps.action.mobile.cfeeGroupConfig.CChannelUp','','0'),(523,'GetCChannelList.do','得到通道列表','mobile.cgroupconfig','com.vogins.sps.action.mobile.cfeeGroupConfig.GetCChannelList','','0'),(524,'DelCGroupConfig.do','删除配置','mobile.cgroupconfig','com.vogins.sps.action.mobile.cfeeGroupConfig.DeleteCGroupConfig','','0'),(525,'FormalPublish.do','将AppStore发布为对应的正式版','app.appstore','com.vogins.sps.action.app.appstore.FormalPublish','','0'),(526,'CustomChannelList.do','厂商通道组信息','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.CustomChannelList','','0'),(527,'CustomChannelInfo.do','厂商通道组列表','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.CustomChannelInfo','','0'),(528,'AddCustomChannel.do','添加厂商通道','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.AddCustomChannel','','0'),(529,'UpdateCustom.do','删除厂商通道','cfee.feegroup','com.vogins.sps.action.cfee.feegroup.UpdateCustomChannel','','0'),(530,'GetCMCCChannel2x.do','取移动通道','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetCMCCChannel2x','','0'),(531,'GetUNChannel2x.do','取联通通道','fee.chargecode','com.vogins.sps.action.fee.chargecode.GetUNICOMChannel2x','','0'),(532,'66','66','00','66','','0');
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_b_user`;
CREATE TABLE `bs_b_user` (
  `UserId` int(11) NOT NULL AUTO_INCREMENT,
  `UserName` varchar(50) NOT NULL DEFAULT '',
  `NickName` varchar(50) NOT NULL DEFAULT '',
  `LoginPassword` varchar(50) NOT NULL DEFAULT '',
  `GroupName` varchar(50) DEFAULT '00',
  `UserStatus` char(1) NOT NULL DEFAULT '0',
  `AddUser` varchar(50) NOT NULL DEFAULT '',
  `RegTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ActionTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`UserId`,`UserName`(1))
) ENGINE=MyISAM AUTO_INCREMENT=55 DEFAULT CHARSET=utf8;

LOCK TABLES `bs_b_user` WRITE;
INSERT INTO `bs_b_user` VALUES (1,'admin','测试','202CB962AC59075B964B07152D234B70','Admin','0','null','2005-11-16 13:35:11','2010-06-10 15:55:31'),(33,'sp','sp','202CB962AC59075B964B07152D234B70','SP','0','admin','2009-08-12 07:32:22','2010-03-30 11:22:55'),(34,'mf','mf','202CB962AC59075B964B07152D234B70','MF','0','admin','2009-08-17 08:19:30','2010-06-08 15:26:38'),(35,'cp','cp','202CB962AC59075B964B07152D234B70','CP','0','admin','2009-08-17 09:14:53','2010-06-04 13:38:17'),(36,'test111','111','202CB962AC59075B964B07152D234B70','Admin','1','admin','2009-10-14 07:16:42','2009-10-14 07:16:42'),(37,'bd','bd','202CB962AC59075B964B07152D234B70','BD','0','admin','2009-10-26 06:45:16','2010-06-01 15:38:03'),(38,'ops','ops','202CB962AC59075B964B07152D234B70','OPS','0','admin','2009-10-28 01:36:21','2010-06-03 15:33:53'),(39,'wangdaiming','wangdaiming','202CB962AC59075B964B07152D234B70','QA','0','admin','2009-10-28 01:37:45','2010-04-02 18:02:54'),(40,'lx','联想','202CB962AC59075B964B07152D234B70','MF','0','bd','2009-11-06 06:02:02','2009-11-06 06:10:47'),(41,'lx1','ddd','202CB962AC59075B964B07152D234B70','MF.上海','0','admin','2009-11-06 06:07:02','2009-11-06 06:07:02'),(46,'yuan','yuan','E10ADC3949BA59ABBE56E057F20F883E','OPS','0','admin','2009-12-10 14:26:51','2009-12-10 14:31:16'),(43,'test','testtest','202CB962AC59075B964B07152D234B70','sp','0','admin','2009-11-23 17:26:35','2010-06-03 17:41:28'),(45,'yuanye','heihei','202CB962AC59075B964B07152D234B70','customer','0','admin','2009-11-30 11:36:19','2010-03-03 17:45:59'),(47,'test11','1','202CB962AC59075B964B07152D234B70','Admin','0','admin','2009-12-25 13:19:04','2009-12-25 13:19:04'),(49,'submf1','submf1','202CB962AC59075B964B07152D234B70','SUBMF','0','mf','2010-01-22 03:32:45','2010-03-03 17:44:35'),(50,'fdsafdsaf','fdsafdsaf','202CB962AC59075B964B07152D234B70','SUBMF','0','mf','2010-01-22 03:36:46','2010-01-22 03:36:46'),(52,'test123','test111','202CB962AC59075B964B07152D234B70','Admin','0','admin','2010-05-20 09:35:48','2010-06-03 17:46:48'),(53,'QQA','QQ','202CB962AC59075B964B07152D234B70','QA','0','admin','2010-05-20 13:24:10','2010-05-20 16:00:42');
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_c_filter`;
CREATE TABLE `bs_c_filter` (
  `FilterId` int(11) NOT NULL AUTO_INCREMENT,
  `FilterType` varchar(20) DEFAULT NULL,
  `FilterContent` varchar(100) DEFAULT NULL,
  `Reserve` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`FilterId`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

LOCK TABLES `bs_c_filter` WRITE;
INSERT INTO `bs_c_filter` VALUES (1,'login','login.htm',''),(2,'login','login.do',''),(3,'login','timeout.htm',''),(4,'access','login.htm',''),(5,'access','login.do',''),(6,'access','getusersubmenu.do',''),(7,'access','updatepassword.do',''),(8,'access','getlogininfo.do',''),(9,'access','logout.do',''),(10,'access','showshortcut.do',''),(11,'login','login.jsp',''),(12,'access','login.jsp',''),(13,'login','timeout.jsp','');
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_c_shortcut`;
CREATE TABLE `bs_c_shortcut` (
  `ScId` int(11) NOT NULL AUTO_INCREMENT,
  `ScName` varchar(50) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `LinkPage` varchar(100) DEFAULT NULL,
  `MenuId` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ScId`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `bs_c_shortcut` WRITE;
INSERT INTO `bs_c_shortcut` VALUES (1,'收件箱','sc_inputbox.gif','message/inputbox.htm',201010),(2,'代办工作','sc_waitwork.gif','workflow/wait.htm',2020);
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_l_action`;
CREATE TABLE `bs_l_action` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `ServletId` int(11) NOT NULL DEFAULT '0',
  `ServletName` varchar(20) DEFAULT NULL,
  `OperateName` varchar(20) DEFAULT NULL,
  `ExecuteTime` datetime DEFAULT NULL,
  `ExecuteUser` varchar(50) DEFAULT NULL,
  `Params` text,
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`LogId`)
) ENGINE=MyISAM AUTO_INCREMENT=24842 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `bs_r_menuaccess`;
CREATE TABLE `bs_r_menuaccess` (
  `MenuAccId` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `Operator` varchar(50) NOT NULL DEFAULT '',
  `OperatorType` char(1) NOT NULL DEFAULT '0',
  `MenuId` int(10) DEFAULT NULL,
  PRIMARY KEY (`MenuAccId`)
) ENGINE=MyISAM AUTO_INCREMENT=406 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `bs_r_menuaccess` WRITE;
INSERT INTO `bs_r_menuaccess` VALUES (11,'admin','1',104),(12,'admin','1',1),(22,'admin','1',103),(24,'admin','1',102),(26,'admin','1',106),(31,'admin','1',105),(35,'admin','1',107),(41,'admin','1',101),(42,'admin','1',108),(44,'admin','1',2),(45,'admin','1',202),(46,'admin','1',401),(47,'admin','1',4),(48,'admin','1',402),(49,'admin','1',403),(50,'admin','1',203),(361,'admin','1',109),(52,'admin','1',301),(53,'admin','1',3),(54,'admin','1',302),(55,'admin','1',303),(56,'admin','1',304),(57,'admin','1',305),(58,'admin','1',306),(59,'admin','1',307),(60,'admin','1',30701),(61,'admin','1',30702),(62,'admin','1',30703),(70,'admin','1',601),(74,'admin','1',702),(69,'admin','1',6),(71,'admin','1',602),(72,'admin','1',701),(68,'admin','1',5),(73,'admin','1',7),(75,'admin','1',703),(76,'admin','1',704),(77,'admin','1',501),(78,'admin','1',502),(79,'admin','1',503),(80,'admin','1',504),(81,'admin','1',505),(82,'sp','1',8),(83,'sp','1',801),(84,'sp','1',802),(85,'admin','1',308),(86,'mf','1',901),(87,'mf','1',9),(88,'mf','1',902),(89,'cp','1',1001),(90,'cp','1',10),(91,'cp','1',1002),(92,'cp','1',1003),(93,'admin','1',506),(94,'admin','1',201010),(95,'admin','1',2010),(96,'admin','1',20),(97,'admin','1',201020),(98,'admin','1',201030),(99,'admin','1',201040),(100,'admin','1',201050),(101,'mf','1',903),(102,'mf','1',904),(103,'mf','1',905),(104,'admin','1',2020),(105,'admin','1',2030),(106,'admin','1',2040),(107,'admin','1',201),(108,'admin','1',9),(109,'admin','1',902),(110,'admin','1',903),(111,'admin','1',904),(116,'mf','1',90101),(113,'admin','1',901),(114,'admin','1',90102),(115,'admin','1',90101),(117,'bd','1',201010),(118,'bd','1',2010),(119,'bd','1',20),(120,'bd','1',201020),(121,'bd','1',201030),(122,'bd','1',201040),(123,'bd','1',201050),(124,'bd','1',2020),(125,'bd','1',2030),(126,'bd','1',2040),(128,'mf','1',90102),(129,'mf','1',90103),(130,'mf','1',90104),(131,'mf','1',906),(132,'bd','1',201),(133,'bd','1',2),(134,'bd','1',202),(135,'ops','1',201),(136,'ops','1',2),(137,'ops','1',202),(138,'ops','1',203),(139,'ops','1',301),(140,'ops','1',3),(141,'ops','1',302),(142,'ops','1',303),(143,'ops','1',304),(144,'ops','1',305),(145,'ops','1',306),(146,'ops','1',30701),(147,'ops','1',307),(148,'ops','1',30702),(149,'ops','1',30703),(150,'ops','1',308),(151,'ops','1',401),(152,'ops','1',4),(153,'ops','1',402),(154,'ops','1',403),(155,'ops','1',201010),(156,'ops','1',2010),(157,'ops','1',20),(158,'ops','1',201020),(159,'ops','1',201030),(160,'ops','1',201040),(161,'ops','1',201050),(162,'ops','1',2020),(163,'ops','1',2030),(164,'ops','1',2040),(165,'qa','1',201),(166,'qa','1',2),(167,'qa','1',202),(168,'qa','1',203),(169,'qa','1',301),(170,'qa','1',3),(171,'qa','1',302),(172,'qa','1',303),(173,'qa','1',304),(174,'qa','1',305),(175,'qa','1',306),(176,'qa','1',30701),(177,'qa','1',307),(178,'qa','1',30702),(179,'qa','1',30703),(180,'qa','1',308),(181,'qa','1',401),(182,'qa','1',4),(183,'qa','1',402),(184,'qa','1',403),(185,'qa','1',201010),(186,'qa','1',2010),(187,'qa','1',20),(188,'qa','1',201020),(189,'qa','1',201030),(190,'qa','1',201040),(191,'qa','1',201050),(192,'qa','1',2020),(193,'qa','1',2030),(194,'qa','1',2040),(195,'bd','0',101),(196,'bd','0',1),(197,'admin','1',3010),(198,'admin','1',30),(199,'admin','1',3020),(200,'admin','1',3030),(201,'admin','1',3040),(202,'admin','1',3041),(203,'admin','1',3042),(204,'admin','1',3043),(205,'admin','1',4044),(212,'admin','1',110),(209,'customer','1',110),(210,'customer','1',1),(211,'admin','1',507),(225,'admin','1',802),(224,'admin','1',801),(226,'admin','1',10),(227,'admin','1',1001),(228,'admin','1',1002),(229,'admin','1',1003),(230,'admin','1',905),(405,'admin','1',31),(222,'admin','1',3101),(223,'admin','1',8),(231,'admin','1',906),(232,'customer','1',2),(233,'customer','1',3),(234,'customer','1',4),(235,'customer','1',5),(236,'customer','1',6),(237,'customer','1',7),(238,'customer','1',31),(239,'customer','1',3101),(241,'admin','1',3107),(242,'ops','1',31),(244,'ops','1',3107),(245,'ops','1',30),(246,'ops','1',1),(247,'ops','1',101),(248,'ops','1',102),(249,'ops','1',103),(250,'ops','1',104),(251,'ops','1',105),(252,'ops','1',106),(253,'ops','1',107),(254,'ops','1',108),(255,'ops','1',109),(256,'admin','1',3108),(257,'admin','1',3109),(266,'cp','1',4010),(265,'admin','1',3112),(260,'admin','1',3166),(267,'cp','1',40),(264,'admin','1',3110),(268,'cp','1',4020),(269,'admin','0',3116),(272,'admin','1',3190),(273,'cp','1',4030),(274,'cp','0',3131),(381,'cp','0',31),(293,'admin','0',40),(292,'admin','0',4020),(291,'admin','1',40),(290,'admin','1',4040),(289,'admin','1',3104),(283,'admin','1',2015),(284,'ops','1',2015),(285,'cp','1',4040),(286,'cp','1',4050),(287,'cp','1',4060),(288,'admin','1',3103),(294,'admin','1',201053),(295,'admin','1',201052),(296,'admin','1',3),(297,'admin','1',0),(298,'admin','1',201054),(299,'mf','1',201056),(300,'mf','1',201055),(301,'mf','1',201057),(302,'admin','0',4030),(303,'admin','0',4010),(304,'admin','0',201060),(305,'admin','0',201062),(306,'admin','0',4),(307,'admin','0',0),(308,'admin','0',201067),(328,'admin','1',201075),(310,'admin','0',201068),(311,'admin','0',201069),(312,'admin','0',201070),(313,'admin','0',201071),(314,'admin','0',201072),(315,'admin','0',201073),(341,'admin','1',201086),(329,'admin','1',201080),(350,'admin','1',201077),(351,'mf','1',201092),(321,'admin','0',201078),(367,'test123','0',0),(330,'admin','1',201082),(325,'admin','1',201081),(326,'admin','1',201074),(331,'admin','1',201083),(332,'admin','1',201084),(344,'admin','0',201088),(343,'admin','1',201087),(340,'admin','1',201085),(347,'admin','1',201089),(348,'admin','1',201065),(349,'admin','1',201076),(352,'mf','1',201091),(353,'mf','1',201093),(354,'mf','1',201094),(355,'mf','1',201095),(356,'qateam','1',1),(357,'qateam','1',0),(360,'admin','1',201079),(366,'test123','0',1),(365,'test123','0',201051),(378,'qa','1',3040),(372,'QQA','0',3010),(373,'QQA','0',3020),(379,'bd','0',20),(376,'qa','1',30),(377,'qa','1',0),(380,'bd','0',0),(399,'cp','1',9),(383,'cp','0',3101),(384,'cp','0',3103),(385,'cp','0',3104),(386,'cp','0',3107),(387,'cp','0',3108),(388,'cp','0',3109),(389,'cp','0',3112),(390,'cp','0',3190),(400,'cp','1',2015),(392,'cp','0',8),(393,'cp','0',7),(394,'cp','0',6),(395,'cp','0',5),(396,'cp','0',4),(397,'cp','1',20),(398,'cp','1',0),(401,'cp','1',2020),(402,'cp','1',2030),(403,'cp','1',2040),(404,'cp','1',2010);
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_r_menuservlet`;
CREATE TABLE `bs_r_menuservlet` (
  `MenuId` int(10) NOT NULL DEFAULT '0',
  `ServletId` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MenuId`,`ServletId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `bs_r_menuservlet` WRITE;
INSERT INTO `bs_r_menuservlet` VALUES (101,2),(101,3),(101,4),(101,5),(101,6),(101,28),(102,21),(102,22),(102,23),(102,24),(102,25),(102,29),(103,13),(103,14),(103,15),(103,16),(103,17),(103,354),(103,355),(104,7),(104,8),(104,9),(104,10),(104,11),(105,4),(105,29),(105,30),(105,31),(105,32),(105,33),(106,34),(106,35),(106,36),(107,19),(107,37),(107,38),(107,39),(107,40),(107,41),(107,42),(108,48),(108,49),(110,292),(110,293),(110,294),(110,295),(110,296),(201,55),(201,56),(201,57),(201,58),(201,59),(201,67),(201,68),(201,69),(201,70),(201,71),(201,150),(201,483),(201,484),(201,485),(201,486),(202,60),(202,61),(202,62),(202,63),(202,64),(202,65),(202,66),(202,68),(202,69),(203,68),(203,89),(203,90),(203,91),(203,92),(301,50),(301,51),(301,52),(301,53),(301,54),(301,55),(301,56),(301,57),(301,58),(301,59),(302,93),(302,94),(302,95),(302,171),(303,53),(303,54),(303,103),(303,104),(303,108),(303,109),(303,111),(303,219),(303,356),(303,357),(304,113),(304,114),(304,115),(304,116),(304,117),(304,118),(304,119),(304,120),(304,121),(304,122),(304,123),(304,124),(304,125),(304,126),(305,137),(305,138),(305,139),(305,140),(305,141),(305,142),(305,143),(305,144),(305,145),(305,146),(305,147),(306,157),(306,158),(306,159),(306,160),(306,161),(306,162),(306,163),(306,164),(306,165),(306,166),(306,167),(306,168),(306,169),(306,170),(308,175),(308,194),(308,530),(308,531),(401,55),(401,56),(401,57),(401,58),(401,59),(401,82),(401,372),(401,373),(401,376),(402,84),(402,85),(402,86),(402,87),(402,88),(402,149),(402,373),(402,376),(402,377),(402,378),(403,72),(403,73),(403,74),(403,75),(403,76),(403,77),(403,78),(403,87),(403,127),(403,383),(403,439),(501,68),(501,80),(501,81),(501,82),(501,175),(501,239),(501,358),(501,359),(501,360),(501,361),(502,53),(502,106),(502,107),(502,111),(502,190),(502,239),(502,357),(502,362),(502,363),(503,149),(503,177),(503,178),(503,179),(503,180),(503,190),(503,239),(504,62),(504,65),(504,68),(504,75),(504,111),(504,175),(504,187),(504,188),(504,189),(504,190),(505,181),(505,182),(505,183),(505,184),(505,185),(505,186),(506,62),(506,63),(506,65),(506,68),(506,202),(506,203),(506,371),(506,374),(506,375),(507,63),(507,65),(507,70),(507,176),(507,346),(601,96),(601,97),(601,98),(601,99),(601,100),(601,101),(601,102),(602,96),(602,97),(602,98),(602,99),(602,100),(602,101),(602,102),(701,151),(701,152),(701,388),(702,154),(703,155),(704,156),(801,191),(801,192),(801,193),(902,62),(902,63),(902,64),(902,237),(903,62),(903,65),(903,68),(903,70),(903,232),(904,364),(904,398),(904,399),(906,119),(906,235),(906,236),(906,237),(906,384),(906,385),(906,386),(906,387),(1001,198),(1001,199),(1001,200),(1002,201),(2015,238),(2015,338),(2020,216),(2020,219),(2020,220),(2020,221),(2020,222),(2020,224),(2020,225),(2020,226),(2020,227),(2020,228),(2020,229),(2020,230),(2020,231),(2030,215),(2030,238),(2040,214),(2040,217),(3010,240),(3010,241),(3010,242),(3010,243),(3010,244),(3010,245),(3010,246),(3010,247),(3010,248),(3010,249),(3010,250),(3010,478),(3010,479),(3010,480),(3010,481),(3020,251),(3020,252),(3020,253),(3020,254),(3020,255),(3030,256),(3030,257),(3030,258),(3030,259),(3030,260),(3040,261),(3040,262),(3040,263),(3040,264),(3040,265),(3040,266),(3040,267),(3040,268),(3040,269),(3040,270),(3040,271),(3041,287),(3041,288),(3041,289),(3041,290),(3041,291),(3041,366),(3041,367),(3041,368),(3041,369),(3041,370),(3042,277),(3042,278),(3042,279),(3042,280),(3042,281),(3042,365),(3043,282),(3043,283),(3043,284),(3043,285),(3043,286),(3101,298),(3101,299),(3101,300),(3101,301),(3103,327),(3103,328),(3103,342),(3104,339),(3106,298),(3106,299),(3106,300),(3106,301),(3107,305),(3107,306),(3107,309),(3107,315),(3107,317),(3107,332),(3107,343),(3108,302),(3108,303),(3108,304),(3108,318),(3109,305),(3109,307),(3109,308),(3109,309),(3109,312),(3109,313),(3109,314),(3109,316),(3109,319),(3109,320),(3109,321),(3109,333),(3109,336),(3110,311),(3110,318),(3112,298),(3112,299),(3112,300),(3112,301),(3116,322),(3116,323),(3116,324),(3116,325),(3131,302),(3131,303),(3131,310),(3166,310),(3166,318),(3170,327),(3170,328),(3190,329),(3190,330),(3190,331),(3190,334),(3190,335),(3190,337),(4010,299),(4010,300),(4010,301),(4020,322),(4020,323),(4020,324),(4020,325),(4020,326),(4020,328),(4020,342),(4020,344),(4030,302),(4030,303),(4030,305),(4030,310),(4030,315),(4030,318),(4030,333),(4030,343),(4040,305),(4040,307),(4040,312),(4040,316),(4040,319),(4040,320),(4040,321),(4040,333),(4040,340),(4040,341),(4044,272),(4044,273),(4044,274),(4044,275),(4044,276),(30701,111),(30701,128),(30701,129),(30701,130),(30702,126),(30702,131),(30702,132),(30702,133),(30702,400),(30703,62),(30703,68),(30703,134),(30703,135),(30703,136),(90102,215),(90102,238),(90103,214),(90103,217),(90104,216),(90104,218),(90104,224),(90104,225),(90104,229),(201010,205),(201010,208),(201010,211),(201020,204),(201020,205),(201020,210),(201020,213),(201030,204),(201030,205),(201030,209),(201040,204),(201040,205),(201040,206),(201040,212),(201050,204),(201050,205),(201050,207),(201053,379),(201053,380),(201053,381),(201053,382),(201054,384),(201054,385),(201054,386),(201056,389),(201056,390),(201056,391),(201056,392),(201056,393),(201057,237),(201057,394),(201057,395),(201057,396),(201057,397),(201060,376),(201060,401),(201060,402),(201060,403),(201060,404),(201062,373),(201062,405),(201062,406),(201062,407),(201062,423),(201062,424),(201062,425),(201062,426),(201062,427),(201067,408),(201067,409),(201067,410),(201068,409),(201068,411),(201069,409),(201069,411),(201069,412),(201069,413),(201069,414),(201069,415),(201069,416),(201069,417),(201069,418),(201070,409),(201070,419),(201071,409),(201071,420),(201072,409),(201072,421),(201073,428),(201073,429),(201073,430),(201073,431),(201073,432),(201073,433),(201073,473),(201076,440),(201076,441),(201076,442),(201076,443),(201076,444),(201076,445),(201076,448),(201076,450),(201076,453),(201076,454),(201076,458),(201076,459),(201076,460),(201076,461),(201076,468),(201076,469),(201076,470),(201076,471),(201076,472),(201077,434),(201077,435),(201077,436),(201077,437),(201077,438),(201077,446),(201077,447),(201077,449),(201077,451),(201077,452),(201077,455),(201077,456),(201077,457),(201077,462),(201077,463),(201077,464),(201077,465),(201077,466),(201077,467),(201078,463),(201078,464),(201078,465),(201078,466),(201078,467),(201079,53),(201079,54),(201079,357),(201079,474),(201079,475),(201079,476),(201079,477),(201080,487),(201080,488),(201080,489),(201080,490),(201080,491),(201080,492),(201082,55),(201082,56),(201082,57),(201082,58),(201082,59),(201082,373),(201082,376),(201082,505),(201082,506),(201082,507),(201082,508),(201082,509),(201082,510),(201082,513),(201083,373),(201083,376),(201083,377),(201083,493),(201083,494),(201083,497),(201083,498),(201083,499),(201083,501),(201083,503),(201083,507),(201083,508),(201083,511),(201084,373),(201084,498),(201084,504),(201084,515),(201084,516),(201084,518),(201084,519),(201084,520),(201084,521),(201084,522),(201084,523),(201084,524),(201085,94),(201085,495),(201085,517),(201086,496),(201086,514),(201087,95),(201087,525),(201088,373),(201088,406),(201088,407),(201088,425),(201088,426),(201088,427),(201089,526),(201089,527),(201089,528),(201089,529),(201090,149),(201092,505),(201092,506),(201092,507),(201092,508),(201092,509),(201092,510),(201092,511),(201092,512),(201092,513),(201093,149),(201093,373),(201093,377),(201093,425),(201093,493),(201093,494),(201093,497),(201093,498),(201093,499),(201093,500),(201093,501),(201093,502),(201093,503),(201093,504),(201094,515),(201094,516),(201094,518),(201094,519),(201094,520),(201094,521),(201094,522),(201094,523),(201094,524),(201094,526),(201094,527),(201094,528),(201094,529),(201095,515),(201095,526),(201095,527),(201095,528),(201095,529);
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_r_servletaccess`;
CREATE TABLE `bs_r_servletaccess` (
  `ServletAccId` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `Operator` varchar(50) NOT NULL DEFAULT '',
  `OperatorType` char(1) NOT NULL DEFAULT '0',
  `ServletId` int(11) NOT NULL DEFAULT '0',
  `MenuId` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ServletAccId`)
) ENGINE=MyISAM AUTO_INCREMENT=1597 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `bs_r_servletaccess` WRITE;
INSERT INTO `bs_r_servletaccess` VALUES (9,'admin','1',13,106),(10,'admin','1',14,106),(11,'admin','1',15,106),(12,'admin','1',16,106),(13,'admin','1',17,106),(35,'admin','1',7,104),(36,'admin','1',8,104),(37,'admin','1',9,104),(38,'admin','1',10,104),(39,'admin','1',11,104),(46,'admin','1',21,105),(47,'admin','1',22,105),(48,'admin','1',23,105),(49,'admin','1',24,105),(50,'admin','1',25,105),(52,'admin','1',13,103),(54,'admin','1',15,103),(55,'admin','1',16,103),(56,'admin','1',17,103),(64,'admin','1',22,102),(65,'admin','1',23,102),(66,'admin','1',24,102),(68,'admin','1',29,102),(69,'admin','1',25,102),(76,'admin','1',34,106),(77,'admin','1',35,106),(78,'admin','1',36,106),(86,'admin','1',4,105),(87,'admin','1',29,105),(88,'admin','1',30,105),(89,'admin','1',31,105),(90,'admin','1',32,105),(91,'admin','1',33,105),(94,'admin','1',19,107),(95,'admin','1',37,107),(96,'admin','1',38,107),(97,'admin','1',39,107),(98,'admin','1',40,107),(99,'admin','1',41,107),(100,'admin','1',42,107),(116,'admin','1',3,101),(117,'admin','1',4,101),(869,'admin','1',6,101),(868,'admin','1',5,101),(120,'admin','1',28,101),(121,'admin','1',14,103),(122,'admin','1',21,102),(124,'admin','1',2,101),(125,'admin','1',48,108),(126,'admin','1',49,108),(127,'admin','1',50,301),(128,'admin','1',51,301),(129,'admin','1',52,301),(130,'admin','1',53,301),(131,'admin','1',54,301),(132,'admin','1',55,301),(133,'admin','1',56,301),(134,'admin','1',57,301),(135,'admin','1',58,301),(136,'admin','1',59,301),(137,'admin','1',89,203),(138,'admin','1',90,203),(139,'admin','1',91,203),(140,'admin','1',92,203),(141,'admin','1',68,203),(142,'admin','1',93,302),(143,'admin','1',94,302),(144,'admin','1',95,302),(155,'admin','1',60,202),(156,'admin','1',61,202),(157,'admin','1',62,202),(158,'admin','1',63,202),(159,'admin','1',64,202),(160,'admin','1',65,202),(161,'admin','1',66,202),(162,'admin','1',55,401),(163,'admin','1',56,401),(164,'admin','1',57,401),(165,'admin','1',58,401),(166,'admin','1',59,401),(167,'admin','1',79,401),(168,'admin','1',80,401),(169,'admin','1',81,401),(170,'admin','1',82,401),(171,'admin','1',83,401),(172,'admin','1',84,402),(173,'admin','1',85,402),(174,'admin','1',86,402),(175,'admin','1',87,402),(176,'admin','1',88,402),(177,'admin','1',76,403),(178,'admin','1',77,403),(179,'admin','1',78,403),(257,'admin','1',101,601),(256,'admin','1',100,601),(255,'admin','1',99,601),(254,'admin','1',98,601),(253,'admin','1',97,601),(252,'admin','1',96,601),(265,'admin','1',102,602),(264,'admin','1',101,602),(263,'admin','1',100,602),(867,'admin','1',99,602),(866,'admin','1',98,602),(865,'admin','1',97,602),(259,'admin','1',96,602),(195,'admin','1',103,303),(196,'admin','1',104,303),(197,'admin','1',105,303),(198,'admin','1',106,303),(199,'admin','1',107,303),(200,'admin','1',108,303),(201,'admin','1',109,303),(202,'admin','1',110,303),(203,'admin','1',111,303),(204,'admin','1',112,303),(205,'admin','1',72,403),(206,'admin','1',73,403),(207,'admin','1',74,403),(208,'admin','1',75,403),(209,'admin','1',113,304),(210,'admin','1',114,304),(211,'admin','1',115,304),(212,'admin','1',116,304),(213,'admin','1',117,304),(214,'admin','1',118,304),(215,'admin','1',119,304),(216,'admin','1',120,304),(217,'admin','1',121,304),(218,'admin','1',122,304),(219,'admin','1',123,304),(220,'admin','1',124,304),(221,'admin','1',125,304),(222,'admin','1',126,304),(223,'admin','1',87,403),(224,'admin','1',127,403),(225,'admin','1',128,30701),(226,'admin','1',129,30701),(227,'admin','1',130,30701),(228,'admin','1',131,30702),(229,'admin','1',132,30702),(230,'admin','1',133,30702),(231,'admin','1',134,30703),(232,'admin','1',135,30703),(233,'admin','1',136,30703),(234,'admin','1',111,30701),(235,'admin','1',126,30702),(236,'admin','1',62,30703),(237,'admin','1',68,30703),(238,'admin','1',137,305),(239,'admin','1',138,305),(240,'admin','1',139,305),(241,'admin','1',140,305),(242,'admin','1',141,305),(243,'admin','1',142,305),(244,'admin','1',143,305),(245,'admin','1',144,305),(246,'admin','1',145,305),(247,'admin','1',146,305),(248,'admin','1',147,305),(249,'admin','1',148,401),(250,'admin','1',149,402),(258,'admin','1',102,601),(864,'admin','1',151,701),(863,'admin','1',152,701),(862,'admin','1',153,701),(269,'admin','1',154,702),(270,'admin','1',155,703),(271,'admin','1',156,704),(272,'admin','1',158,306),(273,'admin','1',157,306),(274,'admin','1',159,306),(275,'admin','1',160,306),(276,'admin','1',161,306),(277,'admin','1',162,306),(278,'admin','1',163,306),(279,'admin','1',164,306),(280,'admin','1',165,306),(281,'admin','1',166,306),(282,'admin','1',167,306),(283,'admin','1',168,306),(284,'admin','1',169,306),(285,'admin','1',170,306),(286,'admin','1',171,302),(287,'admin','1',68,501),(288,'admin','1',80,501),(289,'admin','1',173,501),(290,'admin','1',174,501),(291,'admin','1',175,501),(292,'admin','1',54,502),(293,'admin','1',107,502),(294,'admin','1',111,502),(295,'admin','1',126,502),(296,'admin','1',176,502),(297,'admin','1',149,503),(298,'admin','1',177,503),(299,'admin','1',178,503),(300,'admin','1',179,503),(301,'admin','1',180,503),(302,'admin','1',62,504),(303,'admin','1',68,504),(304,'admin','1',75,504),(305,'admin','1',111,504),(306,'admin','1',175,504),(307,'admin','1',187,504),(308,'admin','1',188,504),(309,'admin','1',189,504),(310,'admin','1',181,505),(311,'admin','1',182,505),(312,'admin','1',183,505),(313,'admin','1',184,505),(314,'admin','1',185,505),(315,'admin','1',186,505),(316,'admin','1',190,502),(317,'admin','1',190,504),(318,'sp','1',191,801),(319,'sp','1',192,801),(320,'sp','1',193,801),(321,'admin','1',194,308),(322,'mf','1',195,901),(323,'mf','1',196,901),(324,'mf','1',197,901),(325,'cp','1',198,1001),(326,'cp','1',199,1001),(327,'cp','1',200,1001),(328,'cp','1',201,1002),(329,'admin','1',62,506),(330,'admin','1',63,506),(331,'admin','1',68,506),(332,'admin','1',202,506),(333,'admin','1',203,506),(334,'admin','1',208,201010),(335,'admin','1',211,201010),(336,'admin','1',205,201010),(337,'admin','1',204,201020),(338,'admin','1',205,201020),(339,'admin','1',210,201020),(340,'admin','1',213,201020),(341,'admin','1',204,201030),(342,'admin','1',205,201030),(343,'admin','1',209,201030),(344,'admin','1',204,201040),(345,'admin','1',205,201040),(346,'admin','1',206,201040),(347,'admin','1',212,201040),(348,'admin','1',204,201050),(349,'admin','1',205,201050),(350,'admin','1',207,201050),(351,'mf','1',195,904),(352,'mf','1',196,904),(353,'mf','1',197,904),(354,'admin','1',216,2020),(355,'admin','1',225,2020),(356,'admin','1',226,2020),(357,'admin','1',227,2020),(358,'admin','1',228,2020),(359,'admin','1',229,2020),(360,'admin','1',230,2020),(361,'admin','1',215,2030),(362,'admin','1',214,2040),(363,'admin','1',217,2040),(364,'admin','1',219,2020),(365,'admin','1',220,2020),(366,'admin','1',231,2020),(367,'admin','1',55,201),(368,'admin','1',56,201),(369,'admin','1',57,201),(370,'admin','1',58,201),(371,'admin','1',59,201),(372,'admin','1',67,201),(373,'admin','1',68,201),(374,'admin','1',69,201),(375,'admin','1',70,201),(376,'admin','1',71,201),(377,'admin','1',150,201),(378,'admin','1',195,904),(379,'admin','1',196,904),(380,'admin','1',197,904),(382,'admin','1',221,2020),(383,'admin','1',222,2020),(384,'admin','1',224,2020),(385,'admin','1',62,902),(386,'admin','1',63,902),(387,'admin','1',64,902),(388,'admin','1',65,902),(389,'admin','1',68,902),(390,'admin','1',70,902),(391,'admin','1',62,903),(392,'admin','1',65,903),(393,'admin','1',68,903),(394,'admin','1',70,903),(395,'admin','1',232,903),(396,'mf','1',233,90101),(397,'mf','1',234,90101),(398,'bd','1',205,201010),(399,'bd','1',208,201010),(400,'bd','1',211,201010),(401,'bd','1',204,201020),(402,'bd','1',205,201020),(403,'bd','1',210,201020),(404,'bd','1',213,201020),(405,'bd','1',204,201030),(406,'bd','1',205,201030),(407,'bd','1',209,201030),(408,'bd','1',204,201040),(409,'bd','1',205,201040),(410,'bd','1',206,201040),(411,'bd','1',212,201040),(412,'bd','1',204,201050),(413,'bd','1',205,201050),(414,'bd','1',207,201050),(415,'bd','1',216,2020),(416,'bd','1',219,2020),(417,'bd','1',220,2020),(418,'bd','1',221,2020),(419,'bd','1',222,2020),(420,'bd','1',224,2020),(421,'bd','1',225,2020),(422,'bd','1',226,2020),(423,'bd','1',227,2020),(424,'bd','1',228,2020),(425,'bd','1',229,2020),(426,'bd','1',230,2020),(427,'bd','1',231,2020),(428,'bd','1',215,2030),(429,'bd','1',214,2040),(430,'bd','1',217,2040),(431,'mf','1',215,90102),(432,'mf','1',214,90103),(433,'mf','1',217,90103),(434,'mf','1',216,90104),(435,'mf','1',218,90104),(436,'mf','1',225,90104),(437,'mf','1',229,90104),(438,'mf','1',224,90104),(439,'mf','1',119,906),(440,'mf','1',235,906),(441,'mf','1',236,906),(442,'mf','1',62,902),(443,'mf','1',64,902),(444,'mf','1',63,902),(445,'mf','1',65,902),(446,'mf','1',68,902),(447,'mf','1',70,902),(448,'mf','1',62,903),(449,'mf','1',65,903),(450,'mf','1',68,903),(451,'mf','1',70,903),(452,'mf','1',232,903),(453,'bd','1',55,201),(454,'bd','1',56,201),(455,'bd','1',57,201),(456,'bd','1',58,201),(457,'bd','1',59,201),(458,'bd','1',67,201),(459,'bd','1',68,201),(460,'bd','1',69,201),(461,'bd','1',70,201),(462,'bd','1',71,201),(463,'bd','1',150,201),(464,'bd','1',60,202),(465,'bd','1',61,202),(466,'bd','1',62,202),(467,'bd','1',63,202),(468,'bd','1',64,202),(469,'bd','1',65,202),(470,'bd','1',66,202),(471,'bd','1',68,202),(472,'bd','1',69,202),(473,'ops','1',55,201),(474,'ops','1',56,201),(475,'ops','1',57,201),(476,'ops','1',58,201),(477,'ops','1',59,201),(478,'ops','1',67,201),(479,'ops','1',68,201),(480,'ops','1',69,201),(481,'ops','1',70,201),(482,'ops','1',71,201),(483,'ops','1',150,201),(484,'ops','1',60,202),(485,'ops','1',61,202),(486,'ops','1',62,202),(487,'ops','1',63,202),(488,'ops','1',64,202),(489,'ops','1',65,202),(490,'ops','1',66,202),(491,'ops','1',68,202),(492,'ops','1',69,202),(493,'ops','1',68,203),(494,'ops','1',89,203),(495,'ops','1',90,203),(496,'ops','1',91,203),(497,'ops','1',92,203),(498,'ops','1',50,301),(499,'ops','1',51,301),(500,'ops','1',52,301),(501,'ops','1',53,301),(502,'ops','1',54,301),(503,'ops','1',55,301),(504,'ops','1',56,301),(505,'ops','1',57,301),(506,'ops','1',58,301),(507,'ops','1',59,301),(508,'ops','1',93,302),(509,'ops','1',94,302),(510,'ops','1',95,302),(511,'ops','1',171,302),(512,'ops','1',103,303),(513,'ops','1',104,303),(514,'ops','1',105,303),(515,'ops','1',106,303),(516,'ops','1',107,303),(517,'ops','1',108,303),(518,'ops','1',109,303),(519,'ops','1',110,303),(520,'ops','1',111,303),(521,'ops','1',112,303),(522,'ops','1',113,304),(523,'ops','1',114,304),(524,'ops','1',115,304),(525,'ops','1',116,304),(526,'ops','1',117,304),(527,'ops','1',118,304),(528,'ops','1',119,304),(529,'ops','1',120,304),(530,'ops','1',121,304),(531,'ops','1',122,304),(532,'ops','1',123,304),(533,'ops','1',124,304),(534,'ops','1',125,304),(535,'ops','1',126,304),(536,'ops','1',137,305),(537,'ops','1',138,305),(538,'ops','1',139,305),(539,'ops','1',140,305),(540,'ops','1',141,305),(541,'ops','1',142,305),(542,'ops','1',143,305),(543,'ops','1',144,305),(544,'ops','1',145,305),(545,'ops','1',146,305),(546,'ops','1',147,305),(547,'ops','1',157,306),(548,'ops','1',158,306),(549,'ops','1',159,306),(550,'ops','1',160,306),(551,'ops','1',161,306),(552,'ops','1',162,306),(553,'ops','1',163,306),(554,'ops','1',164,306),(555,'ops','1',165,306),(556,'ops','1',166,306),(557,'ops','1',167,306),(558,'ops','1',168,306),(559,'ops','1',169,306),(560,'ops','1',170,306),(561,'ops','1',111,30701),(562,'ops','1',128,30701),(563,'ops','1',129,30701),(564,'ops','1',130,30701),(565,'ops','1',126,30702),(566,'ops','1',131,30702),(567,'ops','1',132,30702),(568,'ops','1',133,30702),(569,'ops','1',62,30703),(570,'ops','1',68,30703),(571,'ops','1',134,30703),(572,'ops','1',135,30703),(573,'ops','1',136,30703),(574,'ops','1',194,308),(575,'ops','1',55,401),(576,'ops','1',56,401),(577,'ops','1',57,401),(578,'ops','1',58,401),(579,'ops','1',59,401),(580,'ops','1',79,401),(581,'ops','1',80,401),(582,'ops','1',81,401),(583,'ops','1',82,401),(584,'ops','1',83,401),(585,'ops','1',148,401),(586,'ops','1',84,402),(587,'ops','1',85,402),(588,'ops','1',86,402),(589,'ops','1',87,402),(590,'ops','1',88,402),(591,'ops','1',149,402),(592,'ops','1',72,403),(593,'ops','1',73,403),(594,'ops','1',74,403),(595,'ops','1',75,403),(596,'ops','1',76,403),(597,'ops','1',77,403),(598,'ops','1',78,403),(599,'ops','1',87,403),(600,'ops','1',127,403),(601,'ops','1',205,201010),(602,'ops','1',208,201010),(603,'ops','1',211,201010),(604,'ops','1',204,201020),(605,'ops','1',205,201020),(606,'ops','1',210,201020),(607,'ops','1',213,201020),(608,'ops','1',204,201030),(609,'ops','1',205,201030),(610,'ops','1',209,201030),(611,'ops','1',204,201040),(612,'ops','1',205,201040),(613,'ops','1',206,201040),(614,'ops','1',212,201040),(615,'ops','1',204,201050),(616,'ops','1',205,201050),(617,'ops','1',207,201050),(618,'ops','1',216,2020),(619,'ops','1',219,2020),(620,'ops','1',220,2020),(621,'ops','1',221,2020),(622,'ops','1',222,2020),(623,'ops','1',224,2020),(624,'ops','1',225,2020),(625,'ops','1',226,2020),(626,'ops','1',227,2020),(627,'ops','1',228,2020),(628,'ops','1',229,2020),(629,'ops','1',230,2020),(630,'ops','1',231,2020),(631,'ops','1',215,2030),(632,'ops','1',214,2040),(633,'ops','1',217,2040),(634,'qa','1',55,201),(635,'qa','1',56,201),(636,'qa','1',57,201),(637,'qa','1',58,201),(638,'qa','1',59,201),(639,'qa','1',67,201),(640,'qa','1',68,201),(641,'qa','1',69,201),(642,'qa','1',70,201),(643,'qa','1',71,201),(644,'qa','1',150,201),(645,'qa','1',60,202),(646,'qa','1',61,202),(647,'qa','1',62,202),(648,'qa','1',63,202),(649,'qa','1',64,202),(650,'qa','1',65,202),(651,'qa','1',66,202),(652,'qa','1',68,202),(653,'qa','1',69,202),(654,'qa','1',68,203),(655,'qa','1',89,203),(656,'qa','1',90,203),(657,'qa','1',91,203),(658,'qa','1',92,203),(659,'qa','1',50,301),(660,'qa','1',51,301),(661,'qa','1',52,301),(662,'qa','1',53,301),(663,'qa','1',54,301),(664,'qa','1',55,301),(665,'qa','1',56,301),(666,'qa','1',57,301),(667,'qa','1',58,301),(668,'qa','1',59,301),(669,'qa','1',93,302),(670,'qa','1',94,302),(671,'qa','1',95,302),(672,'qa','1',171,302),(673,'qa','1',103,303),(674,'qa','1',104,303),(675,'qa','1',105,303),(676,'qa','1',106,303),(677,'qa','1',107,303),(678,'qa','1',108,303),(679,'qa','1',109,303),(680,'qa','1',110,303),(681,'qa','1',111,303),(682,'qa','1',112,303),(683,'qa','1',113,304),(684,'qa','1',114,304),(685,'qa','1',115,304),(686,'qa','1',116,304),(687,'qa','1',117,304),(688,'qa','1',118,304),(689,'qa','1',119,304),(690,'qa','1',120,304),(691,'qa','1',121,304),(692,'qa','1',122,304),(693,'qa','1',123,304),(694,'qa','1',124,304),(695,'qa','1',125,304),(696,'qa','1',126,304),(697,'qa','1',137,305),(698,'qa','1',138,305),(699,'qa','1',139,305),(700,'qa','1',140,305),(701,'qa','1',141,305),(702,'qa','1',142,305),(703,'qa','1',143,305),(704,'qa','1',144,305),(705,'qa','1',145,305),(706,'qa','1',146,305),(707,'qa','1',147,305),(708,'qa','1',157,306),(709,'qa','1',158,306),(710,'qa','1',159,306),(711,'qa','1',160,306),(712,'qa','1',161,306),(713,'qa','1',162,306),(714,'qa','1',163,306),(715,'qa','1',164,306),(716,'qa','1',165,306),(717,'qa','1',166,306),(718,'qa','1',167,306),(719,'qa','1',168,306),(720,'qa','1',169,306),(721,'qa','1',170,306),(722,'qa','1',111,30701),(723,'qa','1',128,30701),(724,'qa','1',129,30701),(725,'qa','1',130,30701),(726,'qa','1',126,30702),(727,'qa','1',131,30702),(728,'qa','1',132,30702),(729,'qa','1',133,30702),(730,'qa','1',62,30703),(731,'qa','1',68,30703),(732,'qa','1',134,30703),(733,'qa','1',135,30703),(734,'qa','1',136,30703),(735,'qa','1',194,308),(736,'qa','1',55,401),(737,'qa','1',56,401),(738,'qa','1',57,401),(739,'qa','1',58,401),(740,'qa','1',59,401),(741,'qa','1',79,401),(742,'qa','1',80,401),(743,'qa','1',81,401),(744,'qa','1',82,401),(745,'qa','1',83,401),(746,'qa','1',148,401),(747,'qa','1',84,402),(748,'qa','1',85,402),(749,'qa','1',86,402),(750,'qa','1',87,402),(751,'qa','1',88,402),(752,'qa','1',149,402),(753,'qa','1',72,403),(754,'qa','1',73,403),(755,'qa','1',74,403),(756,'qa','1',75,403),(757,'qa','1',76,403),(758,'qa','1',77,403),(759,'qa','1',78,403),(760,'qa','1',87,403),(761,'qa','1',127,403),(762,'qa','1',205,201010),(763,'qa','1',208,201010),(764,'qa','1',211,201010),(765,'qa','1',204,201020),(766,'qa','1',205,201020),(767,'qa','1',210,201020),(768,'qa','1',213,201020),(769,'qa','1',204,201030),(770,'qa','1',205,201030),(771,'qa','1',209,201030),(772,'qa','1',204,201040),(773,'qa','1',205,201040),(774,'qa','1',206,201040),(775,'qa','1',212,201040),(776,'qa','1',204,201050),(777,'qa','1',205,201050),(778,'qa','1',207,201050),(779,'qa','1',216,2020),(780,'qa','1',219,2020),(781,'qa','1',220,2020),(782,'qa','1',221,2020),(783,'qa','1',222,2020),(784,'qa','1',224,2020),(785,'qa','1',225,2020),(786,'qa','1',226,2020),(787,'qa','1',227,2020),(788,'qa','1',228,2020),(789,'qa','1',229,2020),(790,'qa','1',230,2020),(791,'qa','1',231,2020),(792,'qa','1',215,2030),(793,'qa','1',214,2040),(794,'qa','1',217,2040),(795,'mf','1',237,902),(796,'admin','1',237,902),(797,'admin','1',238,2030),(798,'bd','1',238,2030),(799,'ops','1',238,2030),(800,'qa','1',238,2030),(801,'mf','1',238,90102),(802,'bd','0',2,101),(803,'bd','0',3,101),(804,'bd','0',4,101),(805,'bd','0',5,101),(806,'bd','0',6,101),(807,'bd','0',28,101),(808,'mf','1',239,904),(809,'admin','1',239,904),(810,'admin','1',240,3010),(811,'admin','1',241,3010),(812,'admin','1',242,3010),(813,'admin','1',243,3010),(814,'admin','1',244,3010),(815,'admin','1',245,3010),(816,'admin','1',246,3010),(817,'admin','1',247,3010),(818,'admin','1',248,3010),(819,'admin','1',249,3010),(820,'admin','1',250,3010),(821,'admin','1',251,3020),(822,'admin','1',252,3020),(823,'admin','1',253,3020),(824,'admin','1',254,3020),(825,'admin','1',255,3020),(826,'admin','1',256,3030),(827,'admin','1',257,3030),(828,'admin','1',258,3030),(829,'admin','1',259,3030),(830,'admin','1',260,3030),(831,'admin','1',261,3040),(832,'admin','1',262,3040),(833,'admin','1',263,3040),(834,'admin','1',264,3040),(835,'admin','1',265,3040),(836,'admin','1',266,3040),(837,'admin','1',267,3040),(838,'admin','1',268,3040),(839,'admin','1',269,3040),(840,'admin','1',270,3040),(841,'admin','1',271,3040),(842,'admin','1',287,3041),(843,'admin','1',288,3041),(844,'admin','1',289,3041),(845,'admin','1',290,3041),(846,'admin','1',291,3041),(847,'admin','1',277,3042),(848,'admin','1',278,3042),(849,'admin','1',279,3042),(850,'admin','1',280,3042),(851,'admin','1',281,3042),(852,'admin','1',282,3043),(853,'admin','1',283,3043),(854,'admin','1',284,3043),(855,'admin','1',285,3043),(856,'admin','1',286,3043),(857,'admin','1',272,4044),(858,'admin','1',273,4044),(859,'admin','1',274,4044),(860,'admin','1',275,4044),(861,'admin','1',276,4044),(894,'admin','1',292,110),(895,'admin','1',293,110),(896,'admin','1',294,110),(885,'customer','1',292,110),(886,'customer','1',293,110),(887,'customer','1',294,110),(888,'customer','1',295,110),(889,'customer','1',296,110),(890,'admin','1',62,507),(891,'admin','1',63,507),(892,'admin','1',68,507),(893,'admin','1',70,507),(897,'admin','1',295,110),(898,'admin','1',296,110),(899,'admin','1',297,501),(902,'admin','1',297,502),(903,'admin','1',239,503),(904,'admin','1',297,507),(920,'admin','1',193,801),(919,'admin','1',192,801),(918,'admin','1',191,801),(923,'admin','1',200,1001),(922,'admin','1',199,1001),(924,'admin','1',201,1002),(921,'admin','1',198,1001),(1403,'admin','1',301,3101),(1402,'admin','1',300,3101),(1401,'admin','1',299,3101),(1400,'admin','1',298,3101),(925,'admin','1',119,906),(926,'admin','1',235,906),(927,'admin','1',236,906),(928,'customer','1',298,3101),(929,'customer','1',299,3101),(930,'customer','1',300,3101),(931,'customer','1',301,3101),(1090,'admin','0',325,4020),(1089,'admin','0',324,4020),(1088,'admin','0',323,4020),(1087,'admin','0',322,4020),(1084,'cp','1',323,4020),(1083,'cp','1',322,4020),(1082,'cp','1',312,4040),(1081,'cp','1',341,4040),(940,'ops','1',2,101),(941,'ops','1',3,101),(942,'ops','1',4,101),(943,'ops','1',5,101),(944,'ops','1',6,101),(945,'ops','1',28,101),(946,'ops','1',21,102),(947,'ops','1',22,102),(948,'ops','1',23,102),(949,'ops','1',24,102),(950,'ops','1',25,102),(951,'ops','1',29,102),(952,'ops','1',13,103),(953,'ops','1',14,103),(954,'ops','1',15,103),(955,'ops','1',16,103),(956,'ops','1',17,103),(957,'ops','1',7,104),(958,'ops','1',8,104),(959,'ops','1',9,104),(960,'ops','1',10,104),(961,'ops','1',11,104),(962,'ops','1',4,105),(963,'ops','1',29,105),(964,'ops','1',30,105),(965,'ops','1',31,105),(966,'ops','1',32,105),(967,'ops','1',33,105),(968,'ops','1',34,106),(969,'ops','1',35,106),(970,'ops','1',36,106),(971,'ops','1',19,107),(972,'ops','1',37,107),(973,'ops','1',38,107),(974,'ops','1',39,107),(975,'ops','1',40,107),(976,'ops','1',41,107),(977,'ops','1',42,107),(978,'ops','1',48,108),(979,'ops','1',49,108),(980,'admin','1',302,3108),(981,'admin','1',303,3108),(982,'admin','1',304,3108),(983,'admin','1',305,3107),(984,'admin','1',306,3107),(985,'admin','1',307,3109),(986,'admin','1',308,3109),(987,'admin','1',309,3109),(988,'admin','0',310,3166),(1001,'admin','1',311,3110),(1005,'admin','1',301,3112),(1004,'admin','1',300,3112),(1003,'admin','1',299,3112),(1002,'admin','1',298,3112),(994,'admin','1',309,3107),(995,'admin','1',315,3107),(996,'admin','1',313,3109),(997,'admin','1',314,3109),(998,'admin','1',316,3109),(999,'admin','1',312,3109),(1000,'admin','1',317,3107),(1006,'admin','0',318,3166),(1007,'admin','0',318,3110),(1008,'admin','0',318,3108),(1009,'admin','1',305,3109),(1010,'admin','1',320,3109),(1011,'admin','1',319,3109),(1012,'admin','1',321,3109),(1013,'admin','0',322,3116),(1014,'admin','0',323,3116),(1015,'admin','0',324,3116),(1016,'admin','0',325,3116),(1017,'cp','1',326,4020),(1018,'cp','1',299,4010),(1019,'cp','1',300,4010),(1020,'cp','1',301,4010),(1086,'cp','1',325,4020),(1022,'cp','1',328,4020),(1085,'cp','1',324,4020),(1024,'admin','0',329,3190),(1025,'admin','0',330,3190),(1026,'admin','0',331,3190),(1027,'cp','1',305,4030),(1028,'cp','1',332,4030),(1029,'cp','1',315,4030),(1030,'cp','1',310,4030),(1031,'cp','1',302,4030),(1032,'cp','1',303,4030),(1033,'cp','1',318,4030),(1034,'cp','0',302,3131),(1035,'cp','0',303,3131),(1036,'cp','0',310,3131),(1080,'cp','1',340,4040),(1079,'admin','1',341,4040),(1078,'admin','1',340,4040),(1077,'admin','1',333,4040),(1076,'admin','1',321,4040),(1075,'admin','1',320,4040),(1074,'admin','1',319,4040),(1073,'admin','1',316,4040),(1072,'admin','1',307,4040),(1071,'admin','1',305,4040),(1070,'admin','1',339,3104),(1069,'cp','1',333,4030),(1049,'admin','0',334,3190),(1050,'admin','0',335,3190),(1051,'admin','1',333,3109),(1052,'admin','1',336,3109),(1068,'admin','1',332,3107),(1054,'admin','0',337,3190),(1055,'admin','1',338,2015),(1056,'admin','1',238,2015),(1057,'ops','1',238,2015),(1058,'ops','1',338,2015),(1059,'cp','1',333,4040),(1060,'cp','1',305,4040),(1061,'cp','1',307,4040),(1062,'cp','1',316,4040),(1063,'cp','1',319,4040),(1064,'cp','1',320,4040),(1065,'cp','1',321,4040),(1066,'admin','1',327,3103),(1067,'admin','1',328,3103),(1091,'admin','0',326,4020),(1092,'admin','0',328,4020),(1093,'admin','0',342,4020),(1094,'cp','1',342,4020),(1095,'cp','1',343,4030),(1096,'admin','1',343,3107),(1097,'cp','1',344,4020),(1100,'admin','1',233,90101),(1101,'admin','1',234,90101),(1102,'admin','1',195,904),(1103,'admin','1',196,904),(1104,'admin','1',197,904),(1105,'admin','1',239,904),(1106,'admin','1',364,904),(1107,'admin','0',53,303),(1108,'admin','0',54,303),(1109,'admin','0',106,303),(1110,'admin','0',105,303),(1111,'admin','0',107,303),(1112,'admin','0',110,303),(1113,'admin','0',112,303),(1114,'admin','0',219,303),(1115,'admin','0',356,303),(1116,'admin','0',357,303),(1117,'admin','1',366,3041),(1118,'admin','1',367,3041),(1120,'admin','1',369,3041),(1121,'admin','1',370,3041),(1122,'admin','1',368,3041),(1123,'admin','1',365,3042),(1124,'admin','0',81,501),(1125,'admin','0',82,501),(1126,'admin','0',173,501),(1127,'admin','0',174,501),(1128,'admin','0',297,501),(1129,'admin','0',358,501),(1130,'admin','0',359,501),(1131,'admin','0',360,501),(1132,'admin','0',361,501),(1133,'admin','0',53,502),(1134,'admin','0',106,502),(1135,'admin','0',54,502),(1136,'admin','0',176,502),(1137,'admin','0',297,502),(1138,'admin','0',362,502),(1139,'admin','0',363,502),(1140,'admin','0',357,502),(1141,'admin','0',371,506),(1142,'admin','1',79,401),(1143,'admin','1',80,401),(1144,'admin','1',81,401),(1145,'admin','1',83,401),(1146,'admin','1',148,401),(1147,'admin','1',372,401),(1148,'admin','1',373,401),(1149,'admin','0',374,506),(1150,'admin','0',375,506),(1151,'admin','1',376,401),(1152,'admin','0',62,507),(1153,'admin','0',68,507),(1154,'admin','0',176,507),(1155,'admin','0',297,507),(1156,'admin','0',346,507),(1157,'admin','1',373,402),(1158,'admin','1',376,402),(1159,'admin','1',377,402),(1160,'admin','1',378,402),(1161,'admin','1',379,201053),(1162,'admin','1',380,201053),(1163,'admin','1',381,201053),(1164,'admin','1',382,201053),(1165,'admin','1',383,403),(1166,'admin','1',384,201054),(1167,'admin','1',385,201054),(1168,'admin','1',386,201054),(1169,'mf','1',237,906),(1170,'mf','1',384,906),(1171,'mf','1',385,906),(1172,'mf','1',386,906),(1173,'mf','1',387,906),(1174,'admin','0',153,701),(1175,'admin','0',388,701),(1176,'admin','1',354,103),(1177,'admin','1',355,103),(1178,'mf','1',389,201056),(1179,'mf','1',390,201056),(1180,'mf','1',391,201056),(1181,'mf','1',392,201056),(1182,'mf','1',393,201056),(1183,'mf','1',237,201057),(1184,'mf','1',394,201057),(1185,'mf','1',395,201057),(1186,'mf','1',396,201057),(1187,'mf','1',397,201057),(1188,'admin','1',398,904),(1189,'admin','1',399,904),(1191,'admin','0',400,30702),(1192,'admin','0',344,4020),(1193,'admin','0',312,4040),(1194,'admin','0',302,4030),(1195,'admin','0',303,4030),(1196,'admin','0',305,4030),(1197,'admin','0',310,4030),(1198,'admin','0',315,4030),(1199,'admin','0',318,4030),(1200,'admin','0',333,4030),(1201,'admin','0',343,4030),(1202,'admin','0',299,4010),(1203,'admin','0',300,4010),(1204,'admin','0',301,4010),(1205,'admin','0',342,3103),(1206,'admin','0',215,90102),(1207,'admin','0',238,90102),(1208,'admin','0',237,906),(1209,'admin','0',384,906),(1210,'admin','0',385,906),(1211,'admin','0',386,906),(1212,'admin','0',387,906),(1213,'admin','0',239,501),(1214,'admin','0',239,502),(1215,'admin','0',190,503),(1216,'admin','0',65,504),(1217,'admin','0',65,506),(1218,'admin','0',65,507),(1219,'admin','0',175,308),(1220,'admin','0',376,201060),(1221,'admin','0',401,201060),(1222,'admin','0',402,201060),(1223,'admin','0',403,201060),(1224,'admin','0',404,201060),(1225,'admin','0',373,201062),(1226,'admin','0',377,201062),(1227,'admin','0',405,201062),(1228,'admin','0',406,201062),(1229,'admin','0',407,201062),(1230,'admin','0',408,201067),(1231,'admin','0',409,201067),(1232,'admin','0',410,201067),(1233,'admin','0',411,201068),(1234,'admin','0',409,201068),(1235,'admin','0',409,201069),(1236,'admin','0',411,201069),(1237,'admin','0',412,201069),(1238,'admin','0',413,201069),(1239,'admin','0',414,201069),(1240,'admin','0',415,201069),(1241,'admin','0',416,201069),(1242,'admin','0',417,201069),(1243,'admin','0',418,201069),(1244,'admin','0',409,201070),(1245,'admin','0',419,201070),(1246,'admin','0',409,201071),(1247,'admin','0',420,201071),(1248,'admin','0',409,201072),(1249,'admin','0',421,201072),(1250,'admin','0',423,201062),(1251,'admin','0',424,201062),(1252,'admin','0',425,201062),(1253,'admin','0',426,201062),(1254,'admin','0',427,201062),(1255,'admin','0',428,201073),(1256,'admin','0',429,201073),(1257,'admin','0',430,201073),(1258,'admin','0',431,201073),(1259,'admin','0',432,201073),(1260,'admin','0',433,201073),(1442,'admin','1',457,201077),(1441,'admin','1',456,201077),(1440,'admin','1',455,201077),(1439,'admin','1',452,201077),(1266,'admin','1',439,403),(1424,'admin','1',461,201076),(1425,'admin','1',468,201076),(1426,'admin','1',469,201076),(1423,'admin','1',460,201076),(1438,'admin','1',451,201077),(1422,'admin','1',459,201076),(1437,'admin','1',449,201077),(1421,'admin','1',458,201076),(1436,'admin','1',447,201077),(1420,'admin','1',454,201076),(1419,'admin','1',453,201076),(1435,'admin','1',446,201077),(1434,'admin','1',438,201077),(1417,'admin','1',448,201076),(1418,'admin','1',450,201076),(1433,'admin','1',437,201077),(1432,'admin','1',436,201077),(1431,'admin','1',435,201077),(1416,'admin','1',445,201076),(1430,'admin','1',434,201077),(1292,'admin','0',463,201078),(1293,'admin','0',464,201078),(1294,'admin','0',465,201078),(1295,'admin','0',466,201078),(1296,'admin','0',467,201078),(1415,'admin','1',444,201076),(1414,'admin','1',443,201076),(1413,'admin','1',442,201076),(1412,'admin','1',441,201076),(1411,'admin','1',440,201076),(1302,'admin','0',473,201073),(1303,'wangdaiming','0',373,402),(1304,'wangdaiming','0',376,402),(1305,'wangdaiming','0',377,402),(1306,'wangdaiming','0',378,402),(1493,'admin','1',53,201079),(1494,'admin','1',54,201079),(1495,'admin','1',357,201079),(1496,'admin','1',474,201079),(1497,'admin','1',475,201079),(1314,'admin','0',478,3010),(1315,'admin','0',479,3010),(1316,'admin','0',480,3010),(1317,'admin','0',481,3010),(1318,'admin','1',483,201),(1319,'admin','1',484,201),(1320,'admin','1',485,201),(1321,'admin','1',486,201),(1333,'admin','1',492,201080),(1332,'admin','1',491,201080),(1331,'admin','1',490,201080),(1330,'admin','1',489,201080),(1329,'admin','1',488,201080),(1328,'admin','1',487,201080),(1334,'admin','0',95,201085),(1383,'admin','1',95,201087),(1336,'admin','1',495,201085),(1337,'admin','1',496,201086),(1339,'admin','1',517,201085),(1340,'admin','1',514,201086),(1342,'admin','1',55,201082),(1346,'admin','1',56,201082),(1344,'admin','1',57,201082),(1345,'admin','1',58,201082),(1347,'admin','1',59,201082),(1348,'admin','1',373,201082),(1349,'admin','1',376,201082),(1350,'admin','1',513,201082),(1351,'admin','1',373,201083),(1352,'admin','1',376,201083),(1353,'admin','1',377,201083),(1354,'admin','1',493,201083),(1355,'admin','1',494,201083),(1356,'admin','1',497,201083),(1357,'admin','1',498,201083),(1358,'admin','1',499,201083),(1359,'admin','1',503,201083),(1360,'admin','1',498,201084),(1361,'admin','1',504,201084),(1362,'admin','1',515,201084),(1363,'admin','1',516,201084),(1364,'admin','1',518,201084),(1365,'admin','1',519,201084),(1366,'admin','1',520,201084),(1367,'admin','1',522,201084),(1368,'admin','1',523,201084),(1369,'admin','1',524,201084),(1370,'admin','1',521,201084),(1378,'admin','1',506,201082),(1379,'admin','1',507,201082),(1380,'admin','1',508,201082),(1381,'admin','1',509,201082),(1382,'admin','1',510,201082),(1384,'admin','1',525,201087),(1377,'admin','1',505,201082),(1385,'admin','0',373,201088),(1386,'admin','0',406,201088),(1389,'admin','0',426,201088),(1388,'admin','0',427,201088),(1390,'admin','0',425,201088),(1391,'admin','0',407,201088),(1392,'admin','1',373,201084),(1397,'admin','1',507,201083),(1398,'admin','1',508,201083),(1399,'admin','1',511,201083),(1396,'admin','1',501,201083),(1405,'admin','1',526,201089),(1406,'admin','1',527,201089),(1407,'admin','1',528,201089),(1408,'admin','1',529,201089),(1409,'admin','1',531,308),(1410,'admin','1',530,308),(1427,'admin','1',470,201076),(1428,'admin','1',471,201076),(1429,'admin','1',472,201076),(1443,'admin','1',462,201077),(1444,'admin','1',463,201077),(1445,'admin','1',464,201077),(1446,'admin','1',465,201077),(1447,'admin','1',466,201077),(1448,'admin','1',467,201077),(1449,'admin','0',94,201085),(1450,'mf','1',505,201092),(1451,'mf','1',506,201092),(1452,'mf','1',507,201092),(1453,'mf','1',508,201092),(1454,'mf','1',509,201092),(1455,'mf','1',510,201092),(1456,'mf','1',511,201092),(1457,'mf','1',512,201092),(1458,'mf','1',513,201092),(1459,'mf','1',149,201093),(1460,'mf','1',373,201093),(1461,'mf','1',377,201093),(1462,'mf','1',425,201093),(1463,'mf','1',493,201093),(1464,'mf','1',494,201093),(1465,'mf','1',497,201093),(1466,'mf','1',498,201093),(1467,'mf','1',499,201093),(1468,'mf','1',500,201093),(1469,'mf','1',501,201093),(1470,'mf','1',502,201093),(1471,'mf','1',503,201093),(1472,'mf','1',504,201093),(1473,'mf','1',515,201094),(1474,'mf','1',516,201094),(1475,'mf','1',518,201094),(1476,'mf','1',519,201094),(1477,'mf','1',526,201094),(1478,'mf','1',527,201094),(1479,'mf','1',528,201094),(1480,'mf','1',529,201094),(1481,'mf','1',515,201095),(1482,'mf','1',526,201095),(1483,'mf','1',527,201095),(1484,'mf','1',528,201095),(1485,'mf','1',529,201095),(1498,'admin','1',476,201079),(1499,'admin','1',477,201079),(1500,'QQA','0',240,3010),(1501,'QQA','0',241,3010),(1502,'QQA','0',242,3010),(1503,'QQA','0',243,3010),(1504,'QQA','0',244,3010),(1505,'QQA','0',245,3010),(1506,'QQA','0',246,3010),(1507,'QQA','0',247,3010),(1508,'QQA','0',248,3010),(1509,'QQA','0',249,3010),(1510,'QQA','0',250,3010),(1511,'QQA','0',478,3010),(1512,'QQA','0',479,3010),(1513,'QQA','0',480,3010),(1514,'QQA','0',481,3010),(1515,'QQA','0',251,3020),(1516,'QQA','0',252,3020),(1517,'QQA','0',253,3020),(1518,'QQA','0',254,3020),(1519,'QQA','0',255,3020),(1520,'qa','1',261,3040),(1521,'qa','1',262,3040),(1522,'qa','1',263,3040),(1523,'qa','1',264,3040),(1524,'qa','1',265,3040),(1525,'qa','1',266,3040),(1526,'qa','1',267,3040),(1527,'qa','1',268,3040),(1528,'qa','1',269,3040),(1529,'qa','1',270,3040),(1530,'qa','1',271,3040),(1531,'mf','1',520,201094),(1532,'mf','1',521,201094),(1533,'mf','1',522,201094),(1534,'mf','1',523,201094),(1535,'mf','1',524,201094),(1536,'cp','0',298,3101),(1537,'cp','0',299,3101),(1538,'cp','0',300,3101),(1539,'cp','0',301,3101),(1540,'cp','0',327,3103),(1541,'cp','0',328,3103),(1542,'cp','0',342,3103),(1543,'cp','0',339,3104),(1544,'cp','0',305,3107),(1545,'cp','0',306,3107),(1546,'cp','0',309,3107),(1547,'cp','0',315,3107),(1548,'cp','0',317,3107),(1549,'cp','0',332,3107),(1550,'cp','0',343,3107),(1551,'cp','0',302,3108),(1552,'cp','0',303,3108),(1553,'cp','0',304,3108),(1554,'cp','0',318,3108),(1555,'cp','0',305,3109),(1556,'cp','0',307,3109),(1557,'cp','0',308,3109),(1558,'cp','0',309,3109),(1559,'cp','0',312,3109),(1560,'cp','0',313,3109),(1561,'cp','0',314,3109),(1562,'cp','0',316,3109),(1563,'cp','0',319,3109),(1564,'cp','0',320,3109),(1565,'cp','0',321,3109),(1566,'cp','0',333,3109),(1567,'cp','0',336,3109),(1568,'cp','0',298,3112),(1569,'cp','0',299,3112),(1570,'cp','0',300,3112),(1571,'cp','0',301,3112),(1572,'cp','0',329,3190),(1573,'cp','0',330,3190),(1574,'cp','0',331,3190),(1575,'cp','0',334,3190),(1576,'cp','0',335,3190),(1577,'cp','0',337,3190),(1578,'cp','1',238,2015),(1579,'cp','1',338,2015),(1580,'cp','1',216,2020),(1581,'cp','1',219,2020),(1582,'cp','1',220,2020),(1583,'cp','1',221,2020),(1584,'cp','1',222,2020),(1585,'cp','1',224,2020),(1586,'cp','1',225,2020),(1587,'cp','1',226,2020),(1588,'cp','1',227,2020),(1589,'cp','1',228,2020),(1590,'cp','1',229,2020),(1591,'cp','1',230,2020),(1592,'cp','1',231,2020),(1593,'cp','1',215,2030),(1594,'cp','1',238,2030),(1595,'cp','1',214,2040),(1596,'cp','1',217,2040);
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_r_shortcut`;
CREATE TABLE `bs_r_shortcut` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `StaffId` varchar(20) DEFAULT NULL,
  `ScId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `bs_r_shortcut` WRITE;
INSERT INTO `bs_r_shortcut` VALUES (1,'admin',1,2),(2,'admin',2,3);
UNLOCK TABLES;

DROP TABLE IF EXISTS `bs_r_userrole`;
CREATE TABLE `bs_r_userrole` (
  `UserName` varchar(50) NOT NULL DEFAULT '',
  `RoleName` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`UserName`,`RoleName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

LOCK TABLES `bs_r_userrole` WRITE;
INSERT INTO `bs_r_userrole` VALUES ('admin','admin'),('bd','bd'),('cp','cp'),('fdsafdsaf','submf'),('lx','mf'),('mf','mf'),('ops','ops'),('QQA','qa'),('sp','sp'),('submf1','submf'),('test123','admin'),('test123','qateam'),('wangdaiming','qa'),('yuanye','admin'),('yuanye','customer');
UNLOCK TABLES;

DROP TABLE IF EXISTS `cjf_b_feegroup`;
CREATE TABLE `cjf_b_feegroup` (
  `GroupId` int(11) NOT NULL AUTO_INCREMENT,
  `CountryCode` varchar(20) DEFAULT NULL,
  `MFId` int(11) DEFAULT '0',
  `FeeGroupId` int(11) NOT NULL DEFAULT '0',
  `FeeGroupName` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`GroupId`)
) ENGINE=MyISAM AUTO_INCREMENT=225 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_b_app`;
CREATE TABLE `cp_b_app` (
  `AppId` int(11) NOT NULL DEFAULT '0',
  `AppCode` varchar(100) DEFAULT '',
  `CPId` int(11) NOT NULL DEFAULT '0',
  `AppType` int(11) DEFAULT '0',
  `AppName` varchar(50) DEFAULT NULL,
  `AppNameBig5` varchar(50) DEFAULT NULL,
  `AppNameEn` varchar(50) DEFAULT NULL,
  `Price` int(6) DEFAULT NULL,
  `TopPrice` int(6) DEFAULT NULL,
  `Manual` mediumtext,
  `AppDesc` mediumtext,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `SearchWord` varchar(200) DEFAULT '',
  `DownloadCount` int(11) DEFAULT '0',
  `AddTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(50) DEFAULT '',
  `RemoveFlag` char(1) DEFAULT '0',
  `LevelFlag` char(1) DEFAULT '0',
  PRIMARY KEY (`AppId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_appfolder`;
CREATE TABLE `cp_b_appfolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqType` char(1) DEFAULT '0',
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=35 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_appstore`;
CREATE TABLE `cp_b_appstore` (
  `AppStoreId` int(11) NOT NULL AUTO_INCREMENT,
  `PackVersion` varchar(10) DEFAULT '',
  `ASVersion` varchar(20) DEFAULT '',
  `VersionType` char(1) DEFAULT '1',
  `CertId` int(11) DEFAULT '2',
  `VREVersion` varchar(20) DEFAULT '',
  `MemorySize` int(11) DEFAULT '0',
  `ScreenType` int(11) DEFAULT '0',
  `ScreenWidth` int(11) DEFAULT '0',
  `ScreenHeight` int(11) DEFAULT '0',
  `InputDC` int(11) DEFAULT '0',
  `MobileList` text,
  `FileName` varchar(100) DEFAULT '',
  `FileSize` int(11) DEFAULT '0',
  `SavePath` varchar(255) DEFAULT '',
  `AddTime` datetime DEFAULT NULL,
  `UpdateTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  `Remark` varchar(200) DEFAULT '',
  `PublishType` int(1) DEFAULT '110000',
  PRIMARY KEY (`AppStoreId`)
) ENGINE=MyISAM AUTO_INCREMENT=142 DEFAULT CHARSET=utf8 CHECKSUM=1 DELAY_KEY_WRITE=1 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_appversion`;
CREATE TABLE `cp_b_appversion` (
  `VerId` varchar(25) NOT NULL DEFAULT '',
  `AppId` varchar(20) DEFAULT NULL,
  `PackVersion` varchar(10) DEFAULT '',
  `VerType` char(1) DEFAULT '1',
  `Rank` int(11) DEFAULT NULL,
  `CertId` int(11) DEFAULT NULL,
  `AppVersion` varchar(20) DEFAULT NULL,
  `MemorySize` int(11) DEFAULT '0',
  `ScreenType` int(11) DEFAULT '0',
  `ScreenList` varchar(200) DEFAULT '',
  `ScreenWidth` int(11) DEFAULT '0',
  `ScreenHeight` int(11) DEFAULT '0',
  `InputDC` int(11) DEFAULT '0',
  `FeeGroupId` int(11) DEFAULT NULL,
  `FeeChannel` int(11) DEFAULT '0',
  `FeeChannel1` int(11) DEFAULT '0',
  `FeePrice` int(11) DEFAULT NULL,
  `FeeType` int(11) DEFAULT NULL,
  `FeeValue` int(11) DEFAULT NULL,
  `VREVersion` varchar(20) DEFAULT NULL,
  `MTKVersion` varchar(20) DEFAULT NULL,
  `ChipVersion` varchar(100) DEFAULT NULL,
  `CompilerVersion` int(11) DEFAULT NULL,
  `TrialFlag` int(11) DEFAULT NULL,
  `TrialPrice` int(11) DEFAULT NULL,
  `TrialType` int(11) DEFAULT NULL,
  `TrialValue` int(11) DEFAULT NULL,
  `Permission` text,
  `CertDate` varchar(20) DEFAULT '00000000000000',
  `FileName` varchar(50) DEFAULT NULL,
  `FileSize` int(11) DEFAULT NULL,
  `SavePath` varchar(200) DEFAULT NULL,
  `PackageFlag` varchar(10) DEFAULT '0',
  `MobileList` text,
  `BackgroundRun` varchar(1) DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`VerId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_cp`;
CREATE TABLE `cp_b_cp` (
  `CPId` int(11) NOT NULL AUTO_INCREMENT,
  `CPCode` varchar(40) DEFAULT '',
  `CPType` char(1) DEFAULT '1',
  `CPName` varchar(200) DEFAULT '',
  `ShortName` varchar(40) NOT NULL,
  `Address` varchar(400) NOT NULL,
  `Phone` varchar(200) DEFAULT '',
  `Fax` varchar(200) DEFAULT '',
  `HomePage` varchar(200) DEFAULT '',
  `BillType` int(2) DEFAULT '1',
  `SystemUser` varchar(200) DEFAULT '',
  `AddTime` datetime NOT NULL,
  `AddUser` varchar(50) NOT NULL,
  `RemoveFlag` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`CPId`)
) ENGINE=MyISAM AUTO_INCREMENT=115 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_b_default`;
CREATE TABLE `cp_b_default` (
  `DefId` int(11) NOT NULL AUTO_INCREMENT,
  `DefName` varchar(50) DEFAULT '',
  `DefDesc` text,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`DefId`)
) ENGINE=MyISAM AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_b_mfarea`;
CREATE TABLE `cp_b_mfarea` (
  `AreaId` int(11) NOT NULL AUTO_INCREMENT,
  `MFId` int(11) DEFAULT '0',
  `AreaName` varchar(50) NOT NULL DEFAULT '',
  `DataSource` char(1) NOT NULL DEFAULT '0',
  `DataURL` varchar(200) DEFAULT '',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`AreaId`)
) ENGINE=MyISAM AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_b_morefolder`;
CREATE TABLE `cp_b_morefolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=58 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_newfolder`;
CREATE TABLE `cp_b_newfolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `SeqRule` varchar(255) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_recommenddeffolder`;
CREATE TABLE `cp_b_recommenddeffolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=37 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_recommendfolder`;
CREATE TABLE `cp_b_recommendfolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=41 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_topdlddeffolder`;
CREATE TABLE `cp_b_topdlddeffolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `SeqRule` varchar(255) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=20 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_b_topdldfolder`;
CREATE TABLE `cp_b_topdldfolder` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `SeqRule` varchar(255) DEFAULT NULL,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=17 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_d_preapp`;
CREATE TABLE `cp_d_preapp` (
  `PreId` int(11) NOT NULL AUTO_INCREMENT,
  `AppId` int(11) DEFAULT '0',
  `AddUser` varchar(50) DEFAULT '',
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`PreId`)
) ENGINE=MyISAM AUTO_INCREMENT=83 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_d_preversion`;
CREATE TABLE `cp_d_preversion` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `PreId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `VerId` varchar(25) DEFAULT '',
  `FileName` varchar(50) DEFAULT '',
  `FilePath` varchar(200) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=65 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_d_recommand`;
CREATE TABLE `cp_d_recommand` (
  `RecommendId` int(11) NOT NULL AUTO_INCREMENT,
  `RecommendName` varchar(100) DEFAULT NULL,
  `RecommendDesc` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`RecommendId`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_d_topdld`;
CREATE TABLE `cp_d_topdld` (
  `TopDldId` int(11) NOT NULL AUTO_INCREMENT,
  `TopDldName` varchar(100) DEFAULT NULL,
  `TopDldDesc` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`TopDldId`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_l_apprank`;
CREATE TABLE `cp_l_apprank` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `LogTime` datetime DEFAULT NULL,
  `SubscriberId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `VerId` varchar(25) DEFAULT '',
  `Version` varchar(20) DEFAULT '',
  `Rank` int(11) DEFAULT '1',
  `Remark` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`LogId`)
) ENGINE=MyISAM AUTO_INCREMENT=71 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_l_asdldrequest`;
CREATE TABLE `cp_l_asdldrequest` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `RequestTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SubscriberId` int(11) DEFAULT '0',
  `GatewayIP` varchar(20) DEFAULT '',
  `AppStoreId` int(11) DEFAULT '0',
  `MFId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `Remark` varchar(200) DEFAULT '',
  PRIMARY KEY (`LogId`,`RequestTime`),
  KEY `1` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=262 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_l_asdownload`;
CREATE TABLE `cp_l_asdownload` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `DownloadTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SubscriberId` int(11) DEFAULT '0',
  `GatewayIP` varchar(20) DEFAULT '',
  `AppStoreId` int(11) DEFAULT '0',
  `MFId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `Remark` varchar(200) DEFAULT '',
  PRIMARY KEY (`LogId`,`DownloadTime`),
  KEY `1` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=204 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_l_dldrequest`;
CREATE TABLE `cp_l_dldrequest` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `RequestTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SubscriberId` int(11) DEFAULT '0',
  `GatewayIP` varchar(20) DEFAULT '',
  `CPId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `AppName` varchar(50) DEFAULT '',
  `VerId` varchar(20) DEFAULT '',
  `MFId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `Remark` varchar(200) DEFAULT '',
  PRIMARY KEY (`LogId`,`RequestTime`),
  KEY `1` (`AppId`),
  KEY `2` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=1156 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_l_download`;
CREATE TABLE `cp_l_download` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `DownloadTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SubscriberId` int(11) DEFAULT '0',
  `GatewayIP` varchar(20) DEFAULT '',
  `CPId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `AppName` varchar(50) DEFAULT '',
  `VerId` varchar(20) DEFAULT '',
  `MFId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `Remark` varchar(200) DEFAULT '',
  PRIMARY KEY (`LogId`,`DownloadTime`),
  KEY `1` (`AppId`),
  KEY `2` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=1029 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_appblack`;
CREATE TABLE `cp_r_appblack` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `AppId` int(11) NOT NULL DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=28 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_appfolder`;
CREATE TABLE `cp_r_appfolder` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` varchar(20) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=133 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_r_cpblack`;
CREATE TABLE `cp_r_cpblack` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `CPId` int(11) NOT NULL DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=26 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_defapp`;
CREATE TABLE `cp_r_defapp` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `DefId` int(11) DEFAULT '0',
  `FolderId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `SeqNo` int(11) DEFAULT '0',
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`),
  KEY `1` (`DefId`)
) ENGINE=MyISAM AUTO_INCREMENT=92 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_defversion`;
CREATE TABLE `cp_r_defversion` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `DefId` int(11) DEFAULT '0',
  `FolderId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `VerId` varchar(20) DEFAULT '',
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`),
  KEY `1` (`DefId`)
) ENGINE=MyISAM AUTO_INCREMENT=41 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_mfapp`;
CREATE TABLE `cp_r_mfapp` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `AreaId` int(11) NOT NULL DEFAULT '0',
  `AppId` int(11) NOT NULL DEFAULT '0',
  `SeqNo` int(11) NOT NULL DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=94 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_mobileappblack`;
CREATE TABLE `cp_r_mobileappblack` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `MobileId` int(11) NOT NULL DEFAULT '0',
  `AppId` int(11) NOT NULL DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_morefolder`;
CREATE TABLE `cp_r_morefolder` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` varchar(20) DEFAULT NULL,
  `ContentType` char(1) DEFAULT '1',
  `SeqNo` int(11) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=565 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_r_recapp`;
CREATE TABLE `cp_r_recapp` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `RecommendId` int(11) DEFAULT NULL,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=58 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_recommendfolder`;
CREATE TABLE `cp_r_recommendfolder` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` varchar(20) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=399 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_r_recversion`;
CREATE TABLE `cp_r_recversion` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `RecommendId` int(11) DEFAULT NULL,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` int(11) DEFAULT NULL,
  `VerId` varchar(20) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=83 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_topdldapp`;
CREATE TABLE `cp_r_topdldapp` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `TopDldId` int(11) DEFAULT NULL,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_r_topdldversion`;
CREATE TABLE `cp_r_topdldversion` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `TopDldId` int(11) DEFAULT NULL,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` int(11) DEFAULT NULL,
  `VerId` varchar(20) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_t_app`;
CREATE TABLE `cp_t_app` (
  `AppId` int(11) NOT NULL,
  `AppCode` varchar(100) DEFAULT '',
  `CPId` int(11) NOT NULL DEFAULT '0',
  `AppType` int(11) DEFAULT '0',
  `AppName` varchar(50) DEFAULT NULL,
  `AppNameBig5` varchar(50) DEFAULT NULL,
  `AppNameEn` varchar(50) DEFAULT NULL,
  `Price` int(6) DEFAULT NULL,
  `TopPrice` int(6) DEFAULT NULL,
  `Manual` mediumtext,
  `AppDesc` mediumtext,
  `IconName` varchar(50) DEFAULT NULL,
  `IconPath` varchar(200) DEFAULT NULL,
  `SearchWord` varchar(200) DEFAULT NULL,
  `DownloadCount` int(11) DEFAULT '0',
  `LevelFlag` char(1) DEFAULT '0',
  `AddTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(50) DEFAULT '',
  `RemoveFlag` char(1) DEFAULT '0',
  PRIMARY KEY (`AppId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_t_appfolder`;
CREATE TABLE `cp_t_appfolder` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FolderId` int(11) DEFAULT NULL,
  `AppId` varchar(20) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_t_appfolderinfo`;
CREATE TABLE `cp_t_appfolderinfo` (
  `FolderId` int(11) NOT NULL AUTO_INCREMENT,
  `ParentId` int(11) DEFAULT NULL,
  `SeqType` char(1) DEFAULT '0',
  `SeqNo` int(11) DEFAULT NULL,
  `FolderName` varchar(50) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`FolderId`)
) ENGINE=MyISAM AUTO_INCREMENT=35 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_t_appstore`;
CREATE TABLE `cp_t_appstore` (
  `AppStoreId` int(11) NOT NULL AUTO_INCREMENT,
  `PackVersion` varchar(11) DEFAULT NULL,
  `IsPackage` char(1) DEFAULT '1',
  `ASVersion` varchar(20) DEFAULT '',
  `VersionType` char(1) DEFAULT '1',
  `CertId` int(11) DEFAULT '2',
  `VREVersion` varchar(20) DEFAULT '',
  `MemorySize` int(11) DEFAULT '0',
  `ScreenType` int(11) DEFAULT '0',
  `ScreenWidth` int(11) DEFAULT '0',
  `ScreenHeight` int(11) DEFAULT '0',
  `InputDC` int(11) DEFAULT '0',
  `MobileList` text,
  `FileName` varchar(100) DEFAULT '',
  `FileSize` int(11) DEFAULT '0',
  `SavePath` varchar(255) DEFAULT '',
  `AddTime` datetime DEFAULT NULL,
  `UpdateTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  `Remark` varchar(200) DEFAULT '',
  `PublishType` int(11) DEFAULT '0',
  PRIMARY KEY (`AppStoreId`)
) ENGINE=MyISAM AUTO_INCREMENT=142 DEFAULT CHARSET=utf8 CHECKSUM=1 DELAY_KEY_WRITE=1 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_t_appversion`;
CREATE TABLE `cp_t_appversion` (
  `VerId` varchar(25) NOT NULL DEFAULT '',
  `AppId` varchar(20) DEFAULT NULL,
  `PackVersion` varchar(10) DEFAULT '',
  `VerType` char(1) DEFAULT '1',
  `Rank` int(11) DEFAULT NULL,
  `CertId` int(11) DEFAULT NULL,
  `AppVersion` varchar(20) DEFAULT NULL,
  `MemorySize` int(11) DEFAULT '0',
  `ScreenType` int(11) DEFAULT '0',
  `ScreenList` varchar(200) DEFAULT '',
  `ScreenWidth` int(11) DEFAULT '0',
  `ScreenHeight` int(11) DEFAULT '0',
  `InputDC` int(11) DEFAULT '0',
  `FeeGroupId` int(11) DEFAULT NULL,
  `FeeChannel` int(11) DEFAULT '0',
  `FeeChannel1` int(11) DEFAULT '0',
  `FeePrice` int(11) DEFAULT NULL,
  `FeeType` int(11) DEFAULT NULL,
  `FeeValue` int(11) DEFAULT NULL,
  `VREVersion` varchar(20) DEFAULT NULL,
  `MTKVersion` varchar(20) DEFAULT NULL,
  `ChipVersion` varchar(100) DEFAULT NULL,
  `CompilerVersion` int(11) DEFAULT NULL,
  `TrialFlag` int(11) DEFAULT NULL,
  `TrialPrice` int(11) DEFAULT NULL,
  `TrialType` int(11) DEFAULT NULL,
  `TrialValue` int(11) DEFAULT NULL,
  `Permission` text,
  `CertDate` varchar(20) DEFAULT '00000000000000',
  `FileName` varchar(50) DEFAULT NULL,
  `FileSize` int(11) DEFAULT NULL,
  `SavePath` varchar(200) DEFAULT NULL,
  `PackageFlag` varchar(10) DEFAULT '0',
  `MobileList` text,
  `BackgroundRun` varchar(1) DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`VerId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `cp_t_cp`;
CREATE TABLE `cp_t_cp` (
  `CPId` int(11) NOT NULL AUTO_INCREMENT,
  `CPCode` varchar(40) DEFAULT '',
  `CPType` char(1) DEFAULT '1',
  `CPName` varchar(200) DEFAULT '',
  `ShortName` varchar(40) NOT NULL,
  `Address` varchar(400) NOT NULL,
  `Phone` varchar(200) DEFAULT '',
  `Fax` varchar(200) DEFAULT '',
  `HomePage` varchar(200) DEFAULT '',
  `BillType` int(2) DEFAULT '1',
  `SystemUser` varchar(200) DEFAULT '',
  `AddTime` datetime NOT NULL,
  `AddUser` varchar(50) NOT NULL,
  `RemoveFlag` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`CPId`)
) ENGINE=MyISAM AUTO_INCREMENT=115 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `cp_t_preapp`;
CREATE TABLE `cp_t_preapp` (
  `PreId` int(11) NOT NULL AUTO_INCREMENT,
  `AppId` int(11) DEFAULT '0',
  `AddUser` varchar(50) DEFAULT '',
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`PreId`)
) ENGINE=MyISAM AUTO_INCREMENT=218 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `gg_b_advertising`;
CREATE TABLE `gg_b_advertising` (
  `AdvId` int(11) NOT NULL AUTO_INCREMENT,
  `AdvName` varchar(64) DEFAULT NULL,
  `Url` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`AdvId`)
) ENGINE=MyISAM AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_b_area`;
CREATE TABLE `gg_b_area` (
  `AreaId` int(11) NOT NULL AUTO_INCREMENT,
  `ProvinceId` int(11) NOT NULL DEFAULT '0',
  `AreaName` varchar(50) DEFAULT NULL,
  `EnName` varchar(50) DEFAULT NULL,
  `AreaCode` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`AreaId`)
) ENGINE=MyISAM AUTO_INCREMENT=341 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `gg_b_area` WRITE;
INSERT INTO `gg_b_area` VALUES (1,2,'北京',NULL,'10'),(2,3,'广州',NULL,'20'),(3,4,'上海',NULL,'21'),(4,5,'天津',NULL,'22'),(5,6,'重庆',NULL,'23'),(6,7,'沈阳',NULL,'24'),(7,15,'南京',NULL,'25'),(8,21,'武汉',NULL,'27'),(9,25,'成都',NULL,'28'),(10,8,'西安',NULL,'29'),(11,9,'邯郸',NULL,'310'),(12,9,'石家庄',NULL,'311'),(13,9,'保定',NULL,'312'),(14,9,'张家口',NULL,'313'),(15,9,'承德',NULL,'314'),(16,9,'唐山',NULL,'315'),(17,9,'廊坊',NULL,'316'),(18,9,'沧州',NULL,'317'),(19,9,'衡水',NULL,'318'),(20,9,'邢台',NULL,'319'),(21,9,'秦皇岛',NULL,'335'),(22,10,'朔州',NULL,'349'),(23,10,'忻州',NULL,'350'),(24,10,'太原',NULL,'351'),(25,10,'大同',NULL,'352'),(26,10,'阳泉',NULL,'353'),(27,10,'晋中',NULL,'354'),(28,10,'长治',NULL,'355'),(29,10,'晋城',NULL,'356'),(30,10,'临汾',NULL,'357'),(31,10,'吕梁',NULL,'358'),(32,10,'运城',NULL,'359'),(33,11,'商丘',NULL,'370'),(34,11,'郑州',NULL,'371'),(35,11,'安阳',NULL,'372'),(36,11,'新乡',NULL,'373'),(37,11,'许昌',NULL,'374'),(38,11,'平顶山',NULL,'375'),(39,11,'信阳',NULL,'376'),(40,11,'南阳',NULL,'377'),(41,11,'开封',NULL,'378'),(42,11,'洛阳',NULL,'379'),(43,11,'焦作',NULL,'391'),(44,11,'鹤壁',NULL,'392'),(45,11,'濮阳',NULL,'393'),(46,11,'周口',NULL,'394'),(47,11,'漯河',NULL,'395'),(48,11,'驻马店',NULL,'396'),(49,11,'潢川',NULL,'397'),(50,11,'三门峡',NULL,'398'),(51,7,'铁岭',NULL,'410'),(52,7,'大连',NULL,'411'),(53,7,'鞍山',NULL,'412'),(54,7,'抚顺',NULL,'413'),(55,7,'本溪',NULL,'414'),(56,7,'丹东',NULL,'415'),(57,7,'锦州',NULL,'416'),(58,7,'营口',NULL,'417'),(59,7,'阜新',NULL,'418'),(60,7,'辽阳',NULL,'419'),(61,7,'朝阳',NULL,'421'),(62,7,'盘锦',NULL,'427'),(63,7,'葫芦岛',NULL,'429'),(64,12,'长春',NULL,'431'),(65,12,'吉林',NULL,'432'),(66,12,'延吉',NULL,'433'),(67,12,'四平',NULL,'434'),(68,12,'通化',NULL,'435'),(69,12,'白城',NULL,'436'),(70,12,'辽源',NULL,'437'),(71,12,'松原',NULL,'438'),(72,12,'白山',NULL,'439'),(73,12,'珲春',NULL,'440'),(74,12,'梅河口',NULL,'448'),(75,13,'哈尔滨',NULL,'451'),(76,13,'齐齐哈尔',NULL,'452'),(77,13,'牡丹江',NULL,'453'),(78,13,'佳木斯',NULL,'454'),(79,13,'绥化',NULL,'455'),(80,13,'黑河',NULL,'456'),(81,13,'大兴安岭',NULL,'457'),(82,13,'伊春',NULL,'458'),(83,13,'大庆',NULL,'459'),(84,13,'七台河',NULL,'464'),(85,13,'鸡西',NULL,'467'),(86,13,'鹤岗',NULL,'468'),(87,13,'双鸭山',NULL,'469'),(88,14,'海拉尔',NULL,'470'),(89,14,'呼和浩特',NULL,'471'),(90,14,'包头',NULL,'472'),(91,14,'乌海',NULL,'473'),(92,14,'乌兰察布盟',NULL,'474'),(93,14,'通辽',NULL,'475'),(94,14,'赤峰',NULL,'476'),(95,14,'鄂尔多斯',NULL,'477'),(96,14,'巴彦卓尔盟',NULL,'478'),(97,14,'锡林浩特',NULL,'479'),(98,14,'乌兰浩特',NULL,'482'),(99,14,'巴彦浩特',NULL,'483'),(100,15,'无锡',NULL,'510'),(101,15,'镇江',NULL,'511'),(102,15,'苏州',NULL,'512'),(103,15,'南通',NULL,'513'),(104,15,'扬州',NULL,'514'),(105,15,'盐城',NULL,'515'),(106,15,'徐州',NULL,'516'),(107,15,'淮安',NULL,'517'),(108,15,'连云港',NULL,'518'),(109,15,'常州',NULL,'519'),(110,15,'洪泽',NULL,'520'),(111,15,'泰州',NULL,'523'),(112,15,'宿迁',NULL,'527'),(113,16,'荷泽',NULL,'530'),(114,16,'济南',NULL,'531'),(115,16,'青岛',NULL,'532'),(116,16,'淄博',NULL,'533'),(117,16,'德州',NULL,'534'),(118,16,'烟台',NULL,'535'),(119,16,'潍坊',NULL,'536'),(120,16,'济宁',NULL,'537'),(121,16,'泰安',NULL,'538'),(122,16,'临沂',NULL,'539'),(123,16,'滨州',NULL,'543'),(124,16,'东营',NULL,'546'),(125,17,'滁州',NULL,'550'),(126,17,'合肥',NULL,'551'),(127,17,'蚌埠',NULL,'552'),(128,17,'芜湖',NULL,'553'),(129,17,'淮南',NULL,'554'),(130,17,'马鞍山',NULL,'555'),(131,17,'安庆',NULL,'556'),(132,17,'宿州',NULL,'557'),(133,17,'阜阳',NULL,'558'),(134,17,'黄山',NULL,'559'),(135,17,'淮北',NULL,'561'),(136,17,'铜陵',NULL,'562'),(137,17,'宣城',NULL,'563'),(138,17,'六安',NULL,'564'),(139,17,'巢湖',NULL,'565'),(140,17,'池州',NULL,'566'),(141,18,'衢州',NULL,'570'),(142,18,'杭州',NULL,'571'),(143,18,'湖州',NULL,'572'),(144,18,'嘉兴',NULL,'573'),(145,18,'宁波',NULL,'574'),(146,18,'绍兴',NULL,'575'),(147,18,'台州',NULL,'576'),(148,18,'温州',NULL,'577'),(149,18,'丽水',NULL,'578'),(150,18,'金华',NULL,'579'),(151,18,'舟山',NULL,'580'),(152,19,'福州',NULL,'591'),(153,19,'厦门',NULL,'592'),(154,19,'宁德',NULL,'593'),(155,19,'莆田',NULL,'594'),(156,19,'泉州',NULL,'595'),(157,19,'漳州',NULL,'596'),(158,19,'龙岩',NULL,'597'),(159,19,'三明',NULL,'598'),(160,19,'南平',NULL,'599'),(161,16,'威海',NULL,'631'),(162,16,'枣庄',NULL,'632'),(163,16,'日照',NULL,'633'),(164,16,'莱芜',NULL,'634'),(165,16,'聊城',NULL,'635'),(166,3,'汕尾',NULL,'660'),(167,3,'潮阳',NULL,'661'),(168,3,'阳江',NULL,'662'),(169,3,'揭阳',NULL,'663'),(170,3,'茂名',NULL,'668'),(171,20,'西双版纳',NULL,'691'),(172,20,'德宏',NULL,'692'),(173,24,'鹰潭',NULL,'701'),(174,21,'襄樊',NULL,'710'),(175,21,'鄂州',NULL,'711'),(176,21,'孝感',NULL,'712'),(177,21,'黄冈',NULL,'713'),(178,21,'黄石',NULL,'714'),(179,21,'咸宁',NULL,'715'),(180,21,'荆州',NULL,'716'),(181,21,'宜昌',NULL,'717'),(182,21,'恩施',NULL,'718'),(183,21,'十堰',NULL,'719'),(184,21,'随州',NULL,'722'),(185,21,'荆门',NULL,'724'),(186,21,'江汉',NULL,'728'),(187,22,'岳阳',NULL,'730'),(188,22,'长沙',NULL,'731'),(189,22,'湘潭',NULL,'732'),(190,22,'株洲',NULL,'733'),(191,22,'衡阳',NULL,'734'),(192,22,'郴州',NULL,'735'),(193,22,'常德',NULL,'736'),(194,22,'益阳',NULL,'737'),(195,22,'娄底',NULL,'738'),(196,22,'邵阳',NULL,'739'),(197,22,'吉首',NULL,'743'),(198,22,'张家界',NULL,'744'),(199,22,'怀化',NULL,'745'),(200,22,'永州',NULL,'746'),(201,3,'江门',NULL,'750'),(202,3,'韶关',NULL,'751'),(203,3,'惠州',NULL,'752'),(204,3,'梅州',NULL,'753'),(205,3,'汕头',NULL,'754'),(206,3,'深圳',NULL,'755'),(207,3,'珠海',NULL,'756'),(208,3,'佛山',NULL,'757'),(209,3,'肇庆',NULL,'758'),(210,3,'湛江',NULL,'759'),(211,3,'中山',NULL,'760'),(212,3,'河源',NULL,'762'),(213,3,'清远',NULL,'763'),(214,3,'顺德',NULL,'765'),(215,3,'云浮',NULL,'766'),(216,3,'潮州',NULL,'768'),(217,3,'东莞',NULL,'769'),(218,23,'防城港',NULL,'770'),(219,23,'南宁',NULL,'771'),(220,23,'柳州',NULL,'772'),(221,23,'桂林',NULL,'773'),(222,23,'梧州',NULL,'774'),(223,23,'玉林',NULL,'775'),(224,23,'百色',NULL,'776'),(225,23,'钦州',NULL,'777'),(226,23,'河池',NULL,'778'),(227,23,'北海',NULL,'779'),(228,24,'新余',NULL,'790'),(229,24,'南昌',NULL,'791'),(230,24,'九江',NULL,'792'),(231,24,'上饶',NULL,'793'),(232,24,'抚州',NULL,'794'),(233,24,'宜春',NULL,'795'),(234,24,'吉安',NULL,'796'),(235,24,'赣州',NULL,'797'),(236,24,'景德镇',NULL,'798'),(237,24,'萍乡',NULL,'799'),(238,25,'攀枝花',NULL,'812'),(239,25,'自贡',NULL,'813'),(240,25,'绵阳',NULL,'816'),(241,25,'南充',NULL,'817'),(242,25,'达州',NULL,'818'),(243,25,'遂宁',NULL,'825'),(244,25,'广安',NULL,'826'),(245,25,'巴中',NULL,'827'),(246,25,'泸州',NULL,'830'),(247,25,'宜宾',NULL,'831'),(248,25,'内江',NULL,'832'),(249,25,'乐山',NULL,'833'),(250,25,'凉山',NULL,'834'),(251,25,'雅安',NULL,'835'),(252,25,'甘孜',NULL,'836'),(253,25,'阿坝',NULL,'837'),(254,25,'德阳',NULL,'838'),(255,25,'广元',NULL,'839'),(256,26,'贵阳',NULL,'851'),(257,26,'遵义',NULL,'852'),(258,26,'安顺',NULL,'853'),(259,26,'黔南',NULL,'854'),(260,26,'黔东南',NULL,'855'),(261,26,'铜仁',NULL,'856'),(262,26,'毕节',NULL,'857'),(263,26,'六盘水',NULL,'858'),(264,26,'黔西南',NULL,'859'),(265,20,'昭通',NULL,'870'),(266,20,'昆明',NULL,'871'),(267,20,'大理',NULL,'872'),(268,20,'红河',NULL,'873'),(269,20,'曲靖',NULL,'874'),(270,20,'保山',NULL,'875'),(271,20,'文山',NULL,'876'),(272,20,'玉溪',NULL,'877'),(273,20,'楚雄',NULL,'878'),(274,20,'思茅',NULL,'879'),(275,20,'临沧',NULL,'883'),(276,20,'怒江',NULL,'886'),(277,20,'迪庆',NULL,'887'),(278,20,'丽江',NULL,'888'),(279,27,'儋州',NULL,'890'),(280,28,'拉萨',NULL,'891'),(281,28,'日喀则',NULL,'892'),(282,28,'山南',NULL,'893'),(283,28,'林芝',NULL,'894'),(284,28,'昌都',NULL,'895'),(285,28,'那曲',NULL,'896'),(286,28,'阿里',NULL,'897'),(287,27,'海口',NULL,'898'),(288,27,'三亚',NULL,'899'),(289,32,'塔城',NULL,'901'),(290,32,'哈密',NULL,'902'),(291,32,'和田',NULL,'903'),(292,32,'阿勒泰',NULL,'906'),(293,32,'阿图什（克州）',NULL,'908'),(294,32,'博州',NULL,'909'),(295,8,'咸阳',NULL,'910'),(296,8,'延安',NULL,'911'),(297,8,'榆林',NULL,'912'),(298,8,'渭南',NULL,'913'),(299,8,'商洛',NULL,'914'),(300,8,'安康',NULL,'915'),(301,8,'汉中',NULL,'916'),(302,8,'宝鸡',NULL,'917'),(303,8,'铜川',NULL,'919'),(304,29,'临夏',NULL,'930'),(305,29,'兰州',NULL,'931'),(306,29,'定西',NULL,'932'),(307,29,'平凉',NULL,'933'),(308,29,'庆阳',NULL,'934'),(309,29,'金昌武威',NULL,'935'),(310,29,'张掖',NULL,'936'),(311,29,'酒泉嘉峪关',NULL,'937'),(312,29,'天水',NULL,'938'),(313,29,'陇南',NULL,'939'),(314,29,'甘南',NULL,'941'),(315,29,'白银',NULL,'943'),(316,30,'银川',NULL,'951'),(317,30,'石嘴山',NULL,'952'),(318,30,'吴忠',NULL,'953'),(319,30,'固原',NULL,'954'),(320,31,'海晏',NULL,'970'),(321,31,'西宁',NULL,'971'),(322,31,'海东州',NULL,'972'),(323,31,'黄南藏族',NULL,'973'),(324,31,'共和',NULL,'974'),(325,31,'玛沁（果洛）',NULL,'975'),(326,31,'玉树',NULL,'976'),(327,31,'德令哈',NULL,'977'),(328,31,'格尔木',NULL,'979'),(329,32,'克拉玛依',NULL,'990'),(330,32,'乌鲁木齐',NULL,'991'),(331,32,'奎屯',NULL,'992'),(332,32,'石河子',NULL,'993'),(333,32,'昌吉',NULL,'994'),(334,32,'吐鲁番',NULL,'995'),(335,32,'库尔勒',NULL,'996'),(336,32,'阿克苏',NULL,'997'),(337,32,'喀什',NULL,'998'),(338,32,'伊犁',NULL,'999'),(339,12,'梅河口',NULL,'445'),(340,30,'中卫',NULL,'955');
UNLOCK TABLES;

DROP TABLE IF EXISTS `gg_b_contact`;
CREATE TABLE `gg_b_contact` (
  `ContactId` int(11) NOT NULL AUTO_INCREMENT,
  `PartnerType` char(1) NOT NULL DEFAULT '0',
  `PartnerId` int(11) NOT NULL DEFAULT '0',
  `Name` varchar(50) DEFAULT NULL,
  `Sex` char(10) DEFAULT '',
  `Mobile` varchar(100) DEFAULT NULL,
  `Phone` varchar(100) DEFAULT NULL,
  `Email` varchar(200) DEFAULT NULL,
  `Title` varchar(40) DEFAULT '',
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`ContactId`)
) ENGINE=MyISAM AUTO_INCREMENT=117 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `gg_b_feetips`;
CREATE TABLE `gg_b_feetips` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `CountryCode` varchar(20) NOT NULL DEFAULT '',
  `Notice1` varchar(320) DEFAULT NULL,
  `Notice2` varchar(256) DEFAULT NULL,
  `Notice3` varchar(256) DEFAULT NULL,
  `Notice4` varchar(320) DEFAULT NULL,
  `Notice5` varchar(128) DEFAULT NULL,
  `Notice6` varchar(32) DEFAULT NULL,
  `Notice7` varchar(32) DEFAULT NULL,
  `Magnification` int(11) DEFAULT NULL,
  `Remark` varchar(500) DEFAULT NULL,
  `CurrencyUnit` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=29 DEFAULT CHARSET=utf8;

LOCK TABLES `gg_b_feetips` WRITE;
INSERT INTO `gg_b_feetips` VALUES (24,'IND','तुम एक _gn_ करेगा, कीमत _gp_ डॉलर है, तो आप खरीदना होगा?\r\n','चार्ज, कृपया प्रतीक्षा करें ...\r\n',' प्रतीक्षा करें','विफलता चार्ज, कृपया पुनः प्रयास',' प्रतीक्षा करें','अच्छा','वापस',0,'','Rs'),(23,'CHN','Вы будзеце _gn_, цана  даляраў, вы _gp_ набыць?','Зарадка, калі ласка, пачакайце ...','Зарадка паспяховай','Зарадка правал','Зарадка правал','OK','Назад',0,'','rub'),(27,'RUS','Вы будете _gn_, цена долларов, вы_gp_ купить?цена ','Зарядка, пожалуйста, подождите ...','ожалуйста','ожалуйста','ожалуйста','ожалуйста','ожалуйста',0,'','rb'),(26,'VNM','Jūs pirkti, _gn_ yra  JAV dolerių, _gp_prašau pirkti?','Baterijos, prašome palaukti ...','Įkrovimo sėkmei','Baterijos gedimas, bandykite dar kartą','Įkrovimo sėkmei','Gerai','Atgal',0,'','YAB'),(28,'MYS','Anda akan membeli __goodname__, harganya _goodprice_ร์จโปรด, anda akan anda akananda akananda akananda akananda akananda akananda akananda akananda ','Pengisian, berharap tunggu ...','Pengisian sucessful','Mengisi kegagalan, sila cuba lagi','kegagalan','Oke','Kembali',0,'','RM');
UNLOCK TABLES;

DROP TABLE IF EXISTS `gg_b_feeuser`;
CREATE TABLE `gg_b_feeuser` (
  `Mobile` varchar(30) NOT NULL DEFAULT '0',
  `SubscriberId` int(1) DEFAULT '0',
  `RegTime` datetime DEFAULT '0000-00-00 00:00:00',
  `ActionTime` datetime DEFAULT '0000-00-00 00:00:00',
  `Remark` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`Mobile`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_b_mobilesegment`;
CREATE TABLE `gg_b_mobilesegment` (
  `PhoneNumber` varchar(20) NOT NULL DEFAULT '',
  `AreaCode` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`PhoneNumber`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `gg_b_province`;
CREATE TABLE `gg_b_province` (
  `ProvinceId` int(11) NOT NULL AUTO_INCREMENT,
  `ProvinceName` varchar(50) NOT NULL DEFAULT '',
  `EnName` varchar(50) DEFAULT NULL,
  `WAPGatewayIP` text,
  PRIMARY KEY (`ProvinceId`)
) ENGINE=MyISAM AUTO_INCREMENT=33 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `gg_b_province` WRITE;
INSERT INTO `gg_b_province` VALUES (2,'北京',NULL,';211.136.28.167;211.136.28.135;221.130.33.39;221.130.33.135;'),(3,'广东',NULL,';211.139.151.10;211.139.151.1;211.139.151.42;211.139.151.33;211.139.151.74;211.139.151.65;211.139.144.74;211.139.145.106;211.139.190.202;211.139.146.107;211.139.146.180;211.139.190.234;211.139.163.138;211.139.163.153;211.139.163.168;211.139.163.183;211.139.146.138;211.136.222.66;211.136.222.74;211.136.222.82;211.136.222.90;211.136.222.98;211.136.222.106;211.136.221.42;218.204.243.1;218.204.243.10;218.204.243.42;218.204.243.33;211.136.16.41;'),(4,'上海',NULL,';211.136.115.9;211.136.115.68;211.136.115.39;211.136.115.45;211.136.115.24;'),(5,'天津',NULL,';211.103.89.81;211.103.89.84;211.137.170.18;'),(6,'重庆',NULL,';211.139.60.19;211.139.60.22;221.179.8.18;221.179.21.50;221.179.8.74;221.179.21.10;'),(7,'辽宁',NULL,';211.136.23.50;211.136.23.7;211.136.23.6;211.136.23.43;211.137.33.167;'),(8,'陕西',NULL,';211.137.119.231;'),(9,'河北',NULL,';211.138.5.36;211.138.5.51;211.138.5.46;211.143.58.36;211.143.58.46;'),(10,'山西',NULL,';211.138.100.173;211.138.100.175;211.138.104.18;'),(11,'河南',NULL,';211.142.189.77;211.142.189.202;211.142.189.231;218.206.252.65;218.206.252.66;'),(12,'吉林',NULL,';211.137.211.137;211.137.211.139;'),(13,'黑龙江',NULL,';218.203.63.189;218.203.63.66;'),(14,'内蒙古',NULL,';218.202.106.201;'),(15,'江苏',NULL,';221.131.143.50;221.131.128.199;'),(16,'山东',NULL,';211.137.199.5;211.137.199.53;211.137.199.55;211.137.180.233;211.137.180.235;211.137.181.40;211.137.199.3;'),(17,'安徽',NULL,';211.138.184.201;211.138.184.207;'),(18,'浙江',NULL,';211.140.12.200;211.140.16.2;211.140.16.4;211.140.16.14;211.140.18.130;211.140.3.110;211.140.18.145;'),(19,'福建',NULL,';211.138.147.33;211.138.147.158;211.143.171.143;211.143.145.241;211.143.145.209;'),(20,'云南',NULL,';218.202.4.135;'),(21,'湖北',NULL,';211.137.59.23;211.137.69.234;'),(22,'湖南',NULL,';211.138.237.135;211.138.237.173;211.138.236.200;'),(23,'广西',NULL,';211.138.250.103;211.138.250.107;211.138.243.111;211.136.20.44;211.136.20.37;'),(24,'江西',NULL,';221.176.1.64;221.176.1.77;221.176.1.75;211.141.86.10;211.141.86.13;'),(25,'四川',NULL,';218.205.237.10;218.205.237.42;'),(26,'贵州',NULL,';218.201.200.134;'),(27,'海南',NULL,';211.138.172.201;211.138.170.18;'),(28,'西藏',NULL,';211.136.20.37;'),(29,'甘肃',NULL,';211.139.92.11;'),(30,'宁夏',NULL,';218.203.123.41;'),(31,'青海',NULL,NULL),(32,'新疆',NULL,';211.138.45.11;');
UNLOCK TABLES;

DROP TABLE IF EXISTS `gg_b_search`;
CREATE TABLE `gg_b_search` (
  `SearchId` int(11) NOT NULL AUTO_INCREMENT,
  `SearchName` varchar(50) DEFAULT NULL,
  `Url` varchar(200) DEFAULT NULL,
  `CodeType` varchar(20) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  PRIMARY KEY (`SearchId`)
) ENGINE=MyISAM AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_b_session`;
CREATE TABLE `gg_b_session` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `SessionId` varchar(50) DEFAULT NULL,
  `ActionTime` datetime DEFAULT NULL,
  `SubscriberId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `MFId` int(11) DEFAULT '0',
  `NeedSecure` char(1) DEFAULT '0',
  `CertId` int(11) DEFAULT '0',
  `DesKey` varchar(200) DEFAULT NULL,
  `UserAgent` varchar(200) DEFAULT NULL,
  `VREVersion` varchar(50) DEFAULT NULL,
  `MTKVersion` varchar(50) DEFAULT NULL,
  `ScreenWidth` varchar(20) DEFAULT NULL,
  `ScreenHeight` varchar(20) DEFAULT NULL,
  `MemorySize` varchar(20) DEFAULT NULL,
  `SupKeypad` char(1) DEFAULT '1',
  `SupTouch` char(1) DEFAULT '1',
  `SupFTE` char(1) DEFAULT '0',
  `SupGS` char(1) DEFAULT '0',
  `SupCS` char(1) DEFAULT '0',
  `SmsCenter` varchar(50) DEFAULT '',
  `OpCode` varchar(20) DEFAULT '',
  `IMSI` varchar(50) DEFAULT '',
  `CountryCode` varchar(10) DEFAULT '',
  `ProvinceId` int(11) DEFAULT '0',
  `AddTime` datetime DEFAULT NULL,
  PRIMARY KEY (`RecId`),
  KEY `SessionId` (`SessionId`)
) ENGINE=MyISAM AUTO_INCREMENT=86061 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_b_subscriber`;
CREATE TABLE `gg_b_subscriber` (
  `SubscriberId` int(11) NOT NULL AUTO_INCREMENT,
  `Mobile` varchar(255) DEFAULT NULL,
  `IMSI` varchar(255) DEFAULT NULL,
  `GatewayIP` varchar(200) DEFAULT NULL,
  `MobileId` int(11) DEFAULT NULL,
  `ProvinceId` int(11) DEFAULT '0',
  `RegTime` datetime DEFAULT '0000-00-00 00:00:00',
  `ActionTime` datetime DEFAULT '0000-00-00 00:00:00',
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`SubscriberId`)
) ENGINE=MyISAM AUTO_INCREMENT=1148 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_b_waplist`;
CREATE TABLE `gg_b_waplist` (
  `WapId` int(11) NOT NULL AUTO_INCREMENT,
  `WapName` varchar(20) DEFAULT NULL,
  `Url` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`WapId`)
) ENGINE=MyISAM AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_b_webmessage`;
CREATE TABLE `gg_b_webmessage` (
  `MsgId` int(11) NOT NULL AUTO_INCREMENT,
  `MsgSubject` varchar(100) DEFAULT NULL,
  `MsgContent` text,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `LevelFlag` char(1) DEFAULT '0',
  PRIMARY KEY (`MsgId`)
) ENGINE=MyISAM AUTO_INCREMENT=44 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gg_g_country`;
CREATE TABLE `gg_g_country` (
  `CountryCode` varchar(20) NOT NULL DEFAULT '',
  `CountryName` varchar(100) DEFAULT NULL,
  `EnName` varchar(100) DEFAULT '',
  PRIMARY KEY (`CountryCode`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

LOCK TABLES `gg_g_country` WRITE;
INSERT INTO `gg_g_country` VALUES ('CHN','中国','China'),('RUS','俄罗斯','Russia'),('IND','印度','India'),('VNM','越南','Viet Nam'),('IDN','印度尼西亚','Indonesia'),('MYS','马来西亚','Malaysia'),('GBR','英国','United Kingdom'),('JP','日本','Japan');
UNLOCK TABLES;

DROP TABLE IF EXISTS `gg_p_mobile`;
CREATE TABLE `gg_p_mobile` (
  `MobileId` int(11) NOT NULL DEFAULT '0',
  `ItemName` varchar(100) NOT NULL DEFAULT '',
  `ItemValue` varchar(200) NOT NULL DEFAULT '',
  `ItemDesc` varchar(200) DEFAULT '',
  PRIMARY KEY (`MobileId`,`ItemName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

LOCK TABLES `gg_p_mobile` WRITE;
INSERT INTO `gg_p_mobile` VALUES (887,'permission_list','20090717084219',''),(881,'permission_list','20090922105502',''),(892,'permission_list','20091228104107',''),(891,'permission_list','20090922105455',''),(897,'permission_list','20090922105519',''),(894,'permission_list','20100114105702',''),(886,'permission_list','20100120094413',''),(895,'permission_list','20100429132307',''),(2,'permission_list','20100609125600',''),(898,'permission_list','20100422091534',''),(906,'permission_list','20100310143251',''),(903,'permission_list','20100514174239',''),(900,'permission_list','20100421173851',''),(902,'permission_list','20100421173830',''),(919,'permission_list','20100421173857',''),(920,'permission_list','20100421173921',''),(918,'permission_list','20100421174132','');
UNLOCK TABLES;

DROP TABLE IF EXISTS `gg_p_system`;
CREATE TABLE `gg_p_system` (
  `ItemName` varchar(100) NOT NULL DEFAULT '',
  `ItemValue` varchar(200) NOT NULL DEFAULT '',
  `ItemDesc` varchar(200) DEFAULT '',
  PRIMARY KEY (`ItemName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

LOCK TABLES `gg_p_system` WRITE;
INSERT INTO `gg_p_system` VALUES ('app_id','287',''),('app_version_id','290',''),('app_black_list','20100607170405',''),('permission_list','20100422091804',''),('fee_channel','20100610155513','');
UNLOCK TABLES;

DROP TABLE IF EXISTS `gg_t_advertising`;
CREATE TABLE `gg_t_advertising` (
  `AdvId` int(11) NOT NULL AUTO_INCREMENT,
  `AdvName` varchar(64) DEFAULT NULL,
  `Url` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`AdvId`)
) ENGINE=MyISAM AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `gg_t_search`;
CREATE TABLE `gg_t_search` (
  `SearchId` int(11) NOT NULL AUTO_INCREMENT,
  `SearchName` varchar(50) DEFAULT NULL,
  `Url` varchar(200) DEFAULT NULL,
  `CodeType` varchar(20) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  PRIMARY KEY (`SearchId`)
) ENGINE=MyISAM AUTO_INCREMENT=37 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `gg_t_waplist`;
CREATE TABLE `gg_t_waplist` (
  `WapId` int(11) NOT NULL AUTO_INCREMENT,
  `WapName` varchar(20) DEFAULT NULL,
  `Url` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`WapId`)
) ENGINE=MyISAM AUTO_INCREMENT=43 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `gg_t_webmessage`;
CREATE TABLE `gg_t_webmessage` (
  `MsgId` int(11) NOT NULL AUTO_INCREMENT,
  `MsgSubject` varchar(100) DEFAULT NULL,
  `MsgContent` text,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `LevelFlag` char(1) DEFAULT '0',
  PRIMARY KEY (`MsgId`)
) ENGINE=MyISAM AUTO_INCREMENT=67 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `jf_b_feechannel`;
CREATE TABLE `jf_b_feechannel` (
  `FeeId` int(11) NOT NULL AUTO_INCREMENT,
  `SPId` int(11) DEFAULT NULL,
  `CountryCode` varchar(100) DEFAULT NULL,
  `FeeName` varchar(200) DEFAULT NULL,
  `OpCode` varchar(200) DEFAULT NULL,
  `FeeStyle` varchar(11) DEFAULT NULL,
  `URI` varchar(200) DEFAULT NULL,
  `Param` varchar(50) DEFAULT NULL,
  `CommandType` char(1) DEFAULT '1',
  `Price` int(11) DEFAULT NULL,
  `ValidPrice` int(11) DEFAULT '0',
  `Province` varchar(255) DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `LevelFlag` char(1) DEFAULT '',
  `Open2x` char(1) DEFAULT '0',
  `SpName` varchar(50) DEFAULT NULL,
  `BusinessName` varchar(50) DEFAULT NULL,
  `SpTel` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`FeeId`)
) ENGINE=MyISAM AUTO_INCREMENT=147 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `jf_b_feegroup`;
CREATE TABLE `jf_b_feegroup` (
  `GroupId` int(11) NOT NULL AUTO_INCREMENT,
  `CountryCode` varchar(20) DEFAULT NULL,
  `FeeGroupId` int(11) NOT NULL DEFAULT '0',
  `FeeGroupName` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`GroupId`)
) ENGINE=MyISAM AUTO_INCREMENT=241 DEFAULT CHARSET=utf8;

LOCK TABLES `jf_b_feegroup` WRITE;
INSERT INTO `jf_b_feegroup` VALUES (1,'CHN',0,'默认组'),(2,'CHN',1,'一组'),(3,'CHN',2,'二组'),(4,'CHN',3,'三组'),(5,'CHN',4,'四组'),(6,'CHN',5,'五组'),(7,'CHN',6,'六组'),(8,'CHN',7,'七组'),(9,'CHN',8,'八组'),(10,'CHN',9,'九组'),(11,'CHN',10,'十组'),(12,'CHN',11,'十一组'),(13,'CHN',12,'十二组'),(14,'CHN',13,'十三组'),(15,'CHN',14,'十四组'),(16,'CHN',15,'十五组'),(81,'GBR',0,'默认通道组'),(82,'GBR',1,'通道组1'),(83,'GBR',2,'通道组2'),(84,'GBR',3,'通道组3'),(85,'GBR',4,'通道组4'),(86,'GBR',5,'通道组5'),(87,'GBR',6,'通道组6'),(88,'GBR',7,'通道组7'),(89,'GBR',8,'通道组8'),(90,'GBR',9,'通道组9'),(94,'GBR',13,'通道组13'),(93,'GBR',12,'通道组12'),(92,'GBR',11,'通道组11'),(91,'GBR',10,'通道组10'),(95,'GBR',14,'通道组14'),(96,'GBR',15,'通道组15'),(97,'RUS',0,'Group0'),(98,'RUS',1,'Group1'),(99,'RUS',2,'Group2'),(100,'RUS',3,'Group3'),(101,'RUS',4,'Group4'),(102,'RUS',5,'Group5'),(103,'RUS',6,'Group6'),(104,'RUS',7,'Group7'),(105,'RUS',8,'Group8'),(106,'RUS',9,'Group9'),(107,'RUS',10,'Group10'),(108,'RUS',11,'Group11'),(109,'RUS',12,'Group12'),(110,'RUS',13,'Group13'),(111,'RUS',14,'Group14'),(112,'RUS',15,'Group15'),(113,'IND',0,'Group0'),(114,'IND',1,'Group1'),(115,'IND',2,'Group2'),(116,'IND',3,'Group3'),(117,'IND',4,'Group4'),(118,'IND',5,'Group5'),(119,'IND',6,'Group6'),(120,'IND',7,'Group7'),(121,'IND',8,'Group8'),(122,'IND',9,'Group9'),(123,'IND',10,'Group10'),(124,'IND',11,'Group11'),(125,'IND',12,'Group12'),(126,'IND',13,'Group13'),(127,'IND',14,'Group14'),(128,'IND',15,'Group15'),(129,'VNM',0,'Group0'),(130,'VNM',1,'Group1'),(131,'VNM',2,'Group2'),(132,'VNM',3,'Group3'),(133,'VNM',4,'Group4'),(134,'VNM',5,'Group5'),(135,'VNM',6,'Group6'),(136,'VNM',7,'Group7'),(137,'VNM',8,'Group8'),(138,'VNM',9,'Group9'),(139,'VNM',10,'Group10'),(140,'VNM',11,'Group11'),(141,'VNM',12,'Group12'),(142,'VNM',13,'Group13'),(143,'VNM',14,'Group14'),(144,'VNM',15,'Group15'),(145,'IDN',0,'Group0'),(146,'IDN',1,'Group1'),(147,'IDN',2,'Group2'),(148,'IDN',3,'Group3'),(149,'IDN',4,'Group4'),(150,'IDN',5,'Group5'),(151,'IDN',6,'Group6'),(152,'IDN',7,'Group7'),(153,'IDN',8,'Group8'),(154,'IDN',9,'Group9'),(155,'IDN',10,'Group10'),(156,'IDN',11,'Group11'),(157,'IDN',12,'Group12'),(158,'IDN',13,'Group13'),(159,'IDN',14,'Group14'),(160,'IDN',15,'Group15'),(161,'MYS',0,'Group0'),(162,'MYS',1,'Group1'),(163,'MYS',2,'Group2'),(164,'MYS',3,'Group3'),(165,'MYS',4,'Group4'),(166,'MYS',5,'Group5'),(167,'MYS',6,'Group6'),(168,'MYS',7,'Group7'),(169,'MYS',8,'Group8'),(170,'MYS',9,'Group9'),(171,'MYS',10,'Group10'),(172,'MYS',11,'Group11'),(173,'MYS',12,'Group12'),(174,'MYS',13,'Group13'),(175,'MYS',14,'Group14'),(176,'MYS',15,'Group15'),(177,'美国',0,'默认通道组'),(178,'美国',1,'通道组1'),(179,'美国',2,'通道组2'),(180,'美国',3,'通道组3'),(181,'美国',4,'通道组4'),(182,'美国',5,'通道组5'),(183,'美国',6,'通道组6'),(184,'美国',7,'通道组7'),(185,'美国',8,'通道组8'),(186,'美国',9,'通道组9'),(187,'美国',10,'通道组10'),(188,'美国',11,'通道组11'),(189,'美国',12,'通道组12'),(190,'美国',13,'通道组13'),(191,'美国',14,'通道组14'),(192,'美国',15,'通道组15'),(240,'JP',15,'通道组15'),(239,'JP',14,'通道组14'),(238,'JP',13,'通道组13'),(237,'JP',12,'通道组12'),(236,'JP',11,'通道组11'),(235,'JP',10,'通道组10'),(234,'JP',9,'通道组9'),(233,'JP',8,'通道组8'),(232,'JP',7,'通道组7'),(231,'JP',6,'通道组6'),(230,'JP',5,'通道组5'),(229,'JP',4,'通道组4'),(228,'JP',3,'通道组3'),(227,'JP',2,'通道组2'),(226,'JP',1,'通道组1'),(225,'JP',0,'默认通道组');
UNLOCK TABLES;

DROP TABLE IF EXISTS `jf_b_sp`;
CREATE TABLE `jf_b_sp` (
  `SPId` int(11) NOT NULL AUTO_INCREMENT,
  `CountryCode` varchar(20) DEFAULT NULL,
  `SPName` varchar(255) DEFAULT NULL,
  `ShortName` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Phone` varchar(200) DEFAULT NULL,
  `Fax` varchar(200) DEFAULT NULL,
  `HomePage` varchar(200) DEFAULT NULL,
  `BillType` int(11) DEFAULT NULL,
  `SystemUser` varchar(200) DEFAULT NULL,
  `VoginsUser` varchar(200) DEFAULT NULL,
  `VoginsPass` varchar(200) DEFAULT NULL,
  `FeeURL` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  PRIMARY KEY (`SPId`)
) ENGINE=MyISAM AUTO_INCREMENT=56 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `jf_g_operator`;
CREATE TABLE `jf_g_operator` (
  `OpId` int(11) NOT NULL AUTO_INCREMENT,
  `CountryCode` varchar(20) DEFAULT NULL,
  `OpCode` varchar(50) NOT NULL DEFAULT '',
  `Operator` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`OpId`)
) ENGINE=MyISAM AUTO_INCREMENT=304 DEFAULT CHARSET=utf8 CHECKSUM=1 DELAY_KEY_WRITE=1 ROW_FORMAT=DYNAMIC;

LOCK TABLES `jf_g_operator` WRITE;
INSERT INTO `jf_g_operator` VALUES (1,'CHN','46000','中国移动'),(2,'CHN','46001','中国联通'),(3,'CHN','46002','中国移动'),(4,'CHN','46003','中国移动'),(5,'CHN','46004','中国移动'),(6,'CHN','46005','中国移动'),(7,'IND','40410','AIRTELL'),(8,'IND','40431','AIRTELL'),(9,'IND','40496','AIRTELL'),(10,'IND','40495','AIRTELL'),(11,'IND','40494','AIRTELL'),(12,'IND','40497','AIRTELL'),(13,'IND','40492','AIRTELL'),(14,'IND','40498','AIRTELL'),(15,'IND','40490','AIRTELL'),(16,'IND','40493','AIRTELL'),(17,'IND','40445','AIRTELL'),(18,'IND','40449','AIRTELL'),(19,'IND','40402','AIRTELL'),(20,'IND','40440','AIRTELL'),(21,'IND','40403','AIRTELL'),(22,'IND','40407','TATA'),(23,'IND','40422','IDEA CELLULAR'),(24,'IND','40424','IDEA CELLULAR'),(25,'IND','40404','IDEA CELLULAR'),(26,'IND','40478','IDEA CELLULAR'),(27,'IND','40414','SPICE'),(28,'IND','40409','RELIANCE'),(29,'IND','40418','RELIANCE'),(30,'IND','40450','RELIANCE'),(31,'IND','40436','RELIANCE'),(32,'IND','40452','RELIANCE'),(33,'IND','40467','RELIANCE'),(34,'IND','40485','RELIANCE'),(35,'IND','40413','VODAFONE'),(36,'IND','40411','VODAFONE'),(37,'IND','40405','VODAFONE'),(38,'IND','40486','VODAFONE'),(39,'VNM','50601','tas'),(40,'VNM','50602','tasa'),(41,'VNM','50603','tas'),(42,'VNM','50604','rax'),(43,'RUS','25002','SDFSDF'),(44,'CHN','46006','CMCC'),(45,'CHN','46007','CMCC'),(46,'CHN','46008','CMCC'),(47,'CHN','46009','CMCC'),(48,'CHN','46010','CMCC'),(49,'CHN','46011','CMCC'),(50,'CHN','46012','CMCC'),(51,'CHN','46013','CMCC'),(52,'CHN','46014','CMCC'),(53,'CHN','46015','CMCC'),(54,'CHN','46016','CMCC'),(55,'CHN','46017','CMCC'),(56,'CHN','46018','CMCC'),(57,'CHN','46019','CMCC'),(58,'CHN','46020','CMCC'),(59,'CHN','46021','CMCC'),(60,'CHN','46022','CMCC'),(61,'CHN','46023','CMCC'),(62,'CHN','46024','CMCC'),(63,'CHN','46025','CMCC'),(64,'CHN','46026','CMCC'),(65,'CHN','46027','CMCC'),(66,'CHN','46028','CMCC'),(67,'CHN','46029','CMCC'),(68,'CHN','46030','CMCC'),(69,'CHN','46031','CMCC'),(70,'CHN','46032','CMCC'),(71,'CHN','46033','CMCC'),(72,'CHN','46034','CMCC'),(73,'CHN','46035','CMCC'),(74,'CHN','46036','CMCC'),(75,'CHN','46037','CMCC'),(76,'CHN','46038','CMCC'),(77,'CHN','46039','CMCC'),(78,'CHN','46040','CMCC'),(79,'CHN','46041','CMCC'),(80,'CHN','46042','CMCC'),(81,'CHN','46043','CMCC'),(82,'CHN','46044','CMCC'),(83,'CHN','46045','CMCC'),(84,'CHN','46046','CMCC'),(85,'CHN','46047','CMCC'),(86,'CHN','46048','CMCC'),(87,'CHN','46049','CMCC'),(88,'CHN','46050','CMCC'),(89,'CHN','46051','CMCC'),(90,'CHN','46052','CMCC'),(91,'CHN','46053','CMCC'),(92,'CHN','46054','CMCC'),(93,'CHN','46055','CMCC'),(94,'CHN','46056','CMCC'),(95,'CHN','46057','CMCC'),(96,'CHN','46058','CMCC'),(97,'CHN','46059','CMCC'),(98,'CHN','46060','CMCC'),(99,'CHN','46061','CMCC'),(100,'CHN','46062','CMCC'),(101,'CHN','46063','CMCC'),(102,'CHN','46064','CMCC'),(103,'CHN','46065','CMCC'),(104,'CHN','46066','CMCC'),(105,'CHN','46067','CMCC'),(106,'CHN','46068','CMCC'),(107,'CHN','46069','CMCC'),(108,'CHN','46070','CMCC'),(109,'CHN','46071','CMCC'),(110,'CHN','46072','CMCC'),(111,'CHN','46073','CMCC'),(112,'CHN','46074','CMCC'),(113,'CHN','46075','CMCC'),(114,'CHN','46076','CMCC'),(115,'CHN','46077','CMCC'),(116,'CHN','46078','CMCC'),(117,'CHN','46079','CMCC'),(118,'CHN','46080','CMCC'),(119,'CHN','46081','CMCC'),(120,'CHN','46082','CMCC'),(121,'CHN','46083','CMCC'),(122,'CHN','46084','CMCC'),(123,'CHN','46085','CMCC'),(124,'CHN','46086','CMCC'),(125,'CHN','46087','CMCC'),(126,'CHN','46088','CMCC'),(127,'CHN','46089','CMCC'),(128,'CHN','46090','CMCC'),(129,'CHN','46091','CMCC'),(130,'CHN','46092','CMCC'),(131,'CHN','46093','CMCC'),(132,'CHN','46094','CMCC'),(133,'CHN','46095','CMCC'),(134,'CHN','46096','CMCC'),(135,'CHN','46097','CMCC'),(136,'CHN','46098','CMCC'),(137,'CHN','46099','CMCC'),(138,'CHN','46100','CMCC'),(139,'CHN','46101','CMCC'),(140,'CHN','46102','CMCC'),(141,'CHN','46103','CMCC'),(142,'CHN','46104','CMCC'),(143,'CHN','46105','CMCC'),(144,'CHN','46106','CMCC'),(145,'CHN','46107','CMCC'),(146,'CHN','46108','CMCC'),(147,'CHN','46109','CMCC'),(148,'CHN','46110','CMCC'),(149,'CHN','46111','CMCC'),(150,'CHN','46112','CMCC'),(151,'CHN','46113','CMCC'),(152,'CHN','46114','CMCC'),(153,'CHN','46115','CMCC'),(154,'CHN','46116','CMCC'),(155,'CHN','46117','CMCC'),(156,'CHN','46118','CMCC'),(157,'CHN','46119','CMCC'),(158,'CHN','46120','CMCC'),(159,'CHN','46121','CMCC'),(160,'CHN','46122','CMCC'),(161,'CHN','46123','CMCC'),(162,'CHN','46124','CMCC'),(163,'CHN','46125','CMCC'),(164,'CHN','46126','CMCC'),(165,'CHN','46127','CMCC'),(166,'CHN','46128','CMCC'),(167,'CHN','46129','CMCC'),(168,'CHN','46130','CMCC'),(303,'CHN','46131','CMCC China Mobile'),(171,'RUS','25003','SDFSDF'),(172,'RUS','25004','SDFSDF'),(173,'RUS','25005','SDFSDF'),(174,'RUS','25006','SDFSDF'),(175,'RUS','25007','SDFSDF'),(176,'RUS','25008','SDFSDF'),(177,'RUS','25009','SDFSDF'),(178,'RUS','25010','SDFSDF'),(179,'RUS','25011','SDFSDF'),(180,'RUS','25012','SDFSDF'),(181,'RUS','25013','SDFSDF'),(182,'RUS','25014','SDFSDF'),(183,'RUS','25015','SDFSDF'),(184,'RUS','25016','SDFSDF'),(185,'RUS','25017','SDFSDF'),(186,'RUS','25018','SDFSDF'),(187,'RUS','25019','SDFSDF'),(188,'RUS','25020','SDFSDF'),(189,'RUS','25021','SDFSDF'),(190,'RUS','25022','SDFSDF'),(191,'RUS','25023','SDFSDF'),(192,'RUS','25024','SDFSDF'),(193,'RUS','25025','SDFSDF'),(194,'RUS','25026','SDFSDF'),(195,'RUS','25027','SDFSDF'),(196,'RUS','25028','SDFSDF'),(197,'RUS','25029','SDFSDF'),(198,'RUS','25030','SDFSDF'),(199,'RUS','25031','SDFSDF'),(200,'RUS','25032','SDFSDF'),(201,'RUS','25033','SDFSDF'),(202,'RUS','25034','SDFSDF'),(203,'RUS','25035','SDFSDF'),(204,'RUS','25036','SDFSDF'),(205,'RUS','25037','SDFSDF'),(206,'RUS','25038','SDFSDF'),(207,'RUS','25039','SDFSDF'),(208,'RUS','25040','SDFSDF'),(209,'RUS','25041','SDFSDF'),(210,'RUS','25042','SDFSDF'),(211,'RUS','25043','SDFSDF'),(212,'RUS','25044','SDFSDF'),(213,'RUS','25045','SDFSDF'),(214,'RUS','25046','SDFSDF'),(215,'RUS','25047','SDFSDF'),(216,'RUS','25048','SDFSDF'),(217,'RUS','25049','SDFSDF'),(218,'RUS','25050','SDFSDF'),(219,'RUS','25051','SDFSDF'),(220,'RUS','25052','SDFSDF'),(221,'RUS','25053','SDFSDF'),(222,'RUS','25054','SDFSDF'),(223,'RUS','25055','SDFSDF'),(224,'RUS','25056','SDFSDF'),(225,'RUS','25057','SDFSDF'),(226,'RUS','25058','SDFSDF'),(227,'RUS','25059','SDFSDF'),(228,'RUS','25060','SDFSDF'),(229,'RUS','25061','SDFSDF'),(230,'RUS','25062','SDFSDF'),(231,'RUS','25063','SDFSDF'),(232,'RUS','25064','SDFSDF'),(233,'RUS','25065','SDFSDF'),(234,'RUS','25066','SDFSDF'),(235,'RUS','25067','SDFSDF'),(236,'RUS','25068','SDFSDF'),(237,'RUS','25069','SDFSDF'),(238,'RUS','25070','SDFSDF'),(239,'RUS','25071','SDFSDF'),(240,'RUS','25072','SDFSDF'),(241,'RUS','25073','SDFSDF'),(242,'RUS','25074','SDFSDF'),(243,'RUS','25075','SDFSDF'),(244,'RUS','25076','SDFSDF'),(245,'RUS','25077','SDFSDF'),(246,'RUS','25078','SDFSDF'),(247,'RUS','25079','SDFSDF'),(248,'RUS','25080','SDFSDF'),(249,'RUS','25081','SDFSDF'),(250,'RUS','25082','SDFSDF'),(251,'RUS','25083','SDFSDF'),(252,'RUS','25084','SDFSDF'),(253,'RUS','25085','SDFSDF'),(254,'RUS','25086','SDFSDF'),(255,'RUS','25087','SDFSDF'),(256,'RUS','25088','SDFSDF'),(257,'RUS','25089','SDFSDF'),(258,'RUS','25090','SDFSDF'),(259,'RUS','25091','SDFSDF'),(260,'RUS','25092','SDFSDF'),(261,'RUS','25093','SDFSDF'),(262,'RUS','25094','SDFSDF'),(263,'RUS','25095','SDFSDF'),(264,'RUS','25096','SDFSDF'),(265,'RUS','25097','SDFSDF'),(266,'RUS','25098','SDFSDF'),(267,'RUS','25099','SDFSDF'),(268,'RUS','25100','SDFSDF'),(269,'RUS','25101','SDFSDF'),(270,'RUS','25102','SDFSDF'),(271,'RUS','25103','SDFSDF'),(272,'RUS','25104','SDFSDF'),(273,'RUS','25105','SDFSDF'),(274,'RUS','25106','SDFSDF'),(275,'RUS','25107','SDFSDF'),(276,'RUS','25108','SDFSDF'),(277,'RUS','25109','SDFSDF'),(278,'RUS','25110','SDFSDF'),(279,'RUS','25111','SDFSDF'),(280,'RUS','25112','SDFSDF'),(281,'RUS','25113','SDFSDF'),(282,'RUS','25114','SDFSDF'),(283,'RUS','25115','SDFSDF'),(284,'RUS','25116','SDFSDF'),(285,'RUS','25117','SDFSDF'),(286,'RUS','25118','SDFSDF'),(287,'RUS','25119','SDFSDF'),(288,'RUS','25120','SDFSDF'),(289,'RUS','25121','SDFSDF'),(290,'RUS','25122','SDFSDF'),(291,'RUS','25123','SDFSDF'),(292,'RUS','25124','SDFSDF'),(293,'RUS','25125','SDFSDF'),(294,'RUS','25126','SDFSDF'),(295,'RUS','25127','SDFSDF'),(296,'RUS','25128','SDFSDF'),(297,'RUS','25129','SDFSDF'),(298,'RUS','25130','SDFSDF'),(301,'MYS','50212','MAXIS'),(300,'MYS','50219','Celcom');
UNLOCK TABLES;

DROP TABLE IF EXISTS `jf_g_smsca`;
CREATE TABLE `jf_g_smsca` (
  `CAId` int(11) NOT NULL AUTO_INCREMENT,
  `OpId` int(11) DEFAULT NULL,
  `ProId` int(11) DEFAULT NULL,
  `AreaId` varchar(255) DEFAULT NULL,
  `SmsCA` varchar(100) NOT NULL DEFAULT '',
  PRIMARY KEY (`CAId`)
) ENGINE=MyISAM AUTO_INCREMENT=46 DEFAULT CHARSET=utf8;

LOCK TABLES `jf_g_smsca` WRITE;
INSERT INTO `jf_g_smsca` VALUES (42,1,2,'0','+8613800100500'),(43,2,2,'0','+8613010112500'),(44,1,4,'0','+8613800210500'),(45,2,4,'0','+8613010314500');
UNLOCK TABLES;

DROP TABLE IF EXISTS `jf_l_fee`;
CREATE TABLE `jf_l_fee` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `FeeTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `CPId` int(11) DEFAULT NULL,
  `AppId` int(11) DEFAULT NULL,
  `AppName` varchar(50) DEFAULT NULL,
  `AppPrice` int(11) DEFAULT NULL,
  `AppSrc` int(11) DEFAULT NULL,
  `InsideId` int(11) DEFAULT NULL,
  `InsideInfo` varchar(50) DEFAULT NULL,
  `SubscriberId` int(11) DEFAULT NULL,
  `Mobile` varchar(30) DEFAULT NULL,
  `ProvinceId` int(11) DEFAULT NULL,
  `AreaId` int(11) DEFAULT NULL,
  `MFId` int(11) DEFAULT NULL,
  `MobileId` int(11) DEFAULT NULL,
  `UserAgent` varchar(100) DEFAULT NULL,
  `SPId` int(11) DEFAULT NULL,
  `FeeId` int(11) DEFAULT NULL,
  `FeeType` char(1) DEFAULT NULL,
  `FeePrice` int(11) DEFAULT NULL,
  `AddTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Remark` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`LogId`,`FeeTime`),
  KEY `1` (`AppId`),
  KEY `2` (`Mobile`),
  KEY `3` (`MobileId`),
  KEY `4` (`FeeId`)
) ENGINE=MyISAM AUTO_INCREMENT=820 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `jf_l_smsinfo`;
CREATE TABLE `jf_l_smsinfo` (
  `SeqId` int(11) NOT NULL AUTO_INCREMENT,
  `RecTime` datetime DEFAULT NULL,
  `SPId` int(11) DEFAULT NULL,
  `FeeId` int(11) DEFAULT NULL,
  `SmsAccess` varchar(10) DEFAULT NULL,
  `SmsCommand` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`SeqId`)
) ENGINE=MyISAM AUTO_INCREMENT=115 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `jf_l_smsmo`;
CREATE TABLE `jf_l_smsmo` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `MoId` varchar(50) DEFAULT NULL,
  `MsgId` varchar(50) DEFAULT NULL,
  `Sender` varchar(30) DEFAULT NULL,
  `Receiver` varchar(30) DEFAULT NULL,
  `MsgContent` varchar(200) DEFAULT NULL,
  `SendTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SaveTime` datetime DEFAULT NULL,
  `Reserve` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`LogId`,`SendTime`),
  KEY `1` (`MoId`),
  KEY `2` (`Sender`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `jf_l_smsmt`;
CREATE TABLE `jf_l_smsmt` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `MtId` varchar(50) DEFAULT NULL,
  `MoId` varchar(50) DEFAULT NULL,
  `MsgId` varchar(50) DEFAULT NULL,
  `Sender` varchar(30) DEFAULT NULL,
  `Receiver` varchar(30) DEFAULT NULL,
  `MsgContent` varchar(200) DEFAULT NULL,
  `SendTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SaveTime` datetime DEFAULT NULL,
  `Reserve` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`LogId`,`SendTime`),
  KEY `1` (`MtId`),
  KEY `2` (`MoId`),
  KEY `3` (`Receiver`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `jf_l_smsreport`;
CREATE TABLE `jf_l_smsreport` (
  `LogId` int(11) NOT NULL AUTO_INCREMENT,
  `MtId` varchar(50) DEFAULT NULL,
  `MoId` varchar(50) DEFAULT NULL,
  `MsgId` varchar(50) DEFAULT NULL,
  `Sender` varchar(30) DEFAULT NULL,
  `Receiver` varchar(30) DEFAULT NULL,
  `StatusReport` varchar(50) DEFAULT NULL,
  `SendTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `SaveTime` datetime DEFAULT NULL,
  `Reserve` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`LogId`,`SendTime`),
  KEY `1` (`MtId`),
  KEY `2` (`MoId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `jf_r_feegroup`;
CREATE TABLE `jf_r_feegroup` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `GroupId` int(11) DEFAULT NULL,
  `FeeGroupId` int(11) DEFAULT NULL,
  `FeeId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `CountryCode` varchar(20) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=62 DEFAULT CHARSET=utf8 CHECKSUM=1 DELAY_KEY_WRITE=1 ROW_FORMAT=DYNAMIC;

LOCK TABLES `jf_r_feegroup` WRITE;
INSERT INTO `jf_r_feegroup` VALUES (6,1,0,71,5,'CHN','2010-05-13 16:11:13','admin'),(7,1,0,63,6,'CHN','2010-05-15 16:54:42','admin'),(35,2,1,72,3,'CHN','2010-05-20 17:17:20','admin'),(4,2,1,63,1,'CHN','2010-05-11 17:11:41','admin'),(10,97,0,115,1,'RUS','2010-05-15 18:17:36','admin'),(11,113,0,107,1,'IND','2010-05-18 09:06:45','admin'),(12,113,0,109,2,'IND','2010-05-18 09:07:52','admin'),(13,114,1,110,1,'IND','2010-05-18 09:16:32','admin'),(14,115,2,111,1,'IND','2010-05-18 09:17:18','admin'),(15,98,1,116,1,'RUS','2010-05-18 09:47:49','admin'),(41,162,1,122,1,'MYS','2010-05-21 10:59:05','admin'),(17,161,0,118,1,'MYS','2010-05-18 14:59:53','admin'),(34,2,1,71,2,'CHN','2010-05-20 17:16:57','admin'),(57,1,0,74,10,'CHN','2010-06-10 13:24:19','admin'),(59,1,0,94,11,'CHN','2010-06-10 13:28:11','admin'),(37,2,1,86,5,'CHN','2010-05-20 17:18:50','admin'),(36,2,1,83,4,'CHN','2010-05-20 17:18:23','admin'),(58,2,1,74,6,'CHN','2010-06-10 13:25:56','admin'),(60,1,0,81,12,'CHN','2010-06-10 13:30:21','admin'),(61,2,1,78,7,'CHN','2010-06-10 13:32:40','admin');
UNLOCK TABLES;

DROP TABLE IF EXISTS `jf_t_feechannel`;
CREATE TABLE `jf_t_feechannel` (
  `FeeId` int(11) NOT NULL AUTO_INCREMENT,
  `SPId` int(11) DEFAULT NULL,
  `CountryCode` varchar(255) DEFAULT NULL,
  `FeeName` varchar(200) DEFAULT NULL,
  `OpCode` varchar(200) DEFAULT NULL,
  `FeeStyle` int(11) DEFAULT NULL,
  `URI` varchar(200) DEFAULT NULL,
  `Param` varchar(50) DEFAULT NULL,
  `CommandType` char(1) DEFAULT '1',
  `Price` int(11) DEFAULT NULL,
  `Province` varchar(255) DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `LevelFlag` char(1) DEFAULT NULL,
  `SpName` varchar(50) DEFAULT NULL,
  `BusinessName` varchar(20) DEFAULT NULL,
  `SpTel` varchar(15) DEFAULT NULL,
  `ValidPrice` varchar(50) DEFAULT NULL,
  `Open2x` char(50) DEFAULT '0',
  PRIMARY KEY (`FeeId`)
) ENGINE=MyISAM AUTO_INCREMENT=147 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `jf_t_feegroup`;
CREATE TABLE `jf_t_feegroup` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `GroupId` int(11) DEFAULT NULL,
  `FeeGroupId` int(11) DEFAULT NULL,
  `FeeId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `CountryCode` varchar(20) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM AUTO_INCREMENT=62 DEFAULT CHARSET=utf8 CHECKSUM=1 DELAY_KEY_WRITE=1 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `jf_t_sp`;
CREATE TABLE `jf_t_sp` (
  `SPId` int(11) NOT NULL AUTO_INCREMENT,
  `SPName` varchar(255) DEFAULT NULL,
  `ShortName` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Phone` varchar(200) DEFAULT NULL,
  `Fax` varchar(200) DEFAULT NULL,
  `HomePage` varchar(200) DEFAULT NULL,
  `BillType` int(11) DEFAULT NULL,
  `SystemUser` varchar(200) DEFAULT NULL,
  `VoginsUser` varchar(200) DEFAULT NULL,
  `VoginsPass` varchar(200) DEFAULT NULL,
  `FeeURL` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `CountryCode` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`SPId`)
) ENGINE=MyISAM AUTO_INCREMENT=56 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

LOCK TABLES `jf_t_sp` WRITE;
INSERT INTO `jf_t_sp` VALUES (40,'公司222333','简称222333','23','23','23','23',23,'23','23','23','23','2010-03-26 15:15:56','admin','1','CHN'),(41,'21','3213','11','1','213','121',11,'11','1','21','1','2010-03-26 15:17:39','admin','1','CHN'),(42,'222kkk','222','2','2','2','2',22,'2','2','22','2','2010-03-26 19:50:51','admin','1','CHN'),(43,'中文测试123','中文测试213','中文测试213','123123123','123123123','123123',123123,'123123','123123','123123','123123','2010-03-29 12:51:43','admin','1','CHN'),(44,'名称123','简称123','地址123','123','123','123',123,'123','123','123','123','2010-03-29 15:56:25','admin','1','CHN'),(45,'公司名称','公司简称','23','23','23','23',23,'23','23','23','23','2010-03-29 15:58:45','admin','0','CHN'),(46,'测试111','11','11','11','11','11',11,'11','11','11','11','2010-03-30 14:36:17','admin','0','CHN'),(47,'SP00001','SP01','BEIJING','2853489','23898','348989',3,'admin','','','','2010-04-21 14:00:02','admin','0','CHN'),(48,'SP00002','SP02','beijing','234234','2342','df',23,'e','','','','2010-04-21 14:00:59','admin','0','CHN'),(49,'wqe','sad','wqe','sad','2q3','213',0,'213','213','213','213','2010-05-11 17:14:26','admin','0','CHN'),(50,'印度测试运营商','IND','奥斯丁','35454','6545','32132',0,'32132','123','123','23132','2010-05-15 14:33:08','admin','0','CHN'),(51,'rus','A','A','A','A','A',0,'123','123','123','123','2010-05-15 15:19:55','admin','0','CHN'),(52,'MYS','MYS','MYS','MYS','MYS','MYS',0,'MYS','MYS','MYS','MYS','2010-05-18 14:38:53','admin','0','CHN'),(53,'test','test','shanghai','123456','123456','www.test.com',0,';admin;','test','test','admin_test','2010-05-18 16:38:16','admin','1','CHN'),(54,'QQ','','','','','',0,'','','','','2010-05-20 10:20:13','admin','0','CHN'),(55,'易讯','yixun','sh','021','123456','www.xx.com',0,'admin','user1','user1','','2010-06-09 13:35:30','admin','0','CHN'),(39,'公司111','简称110','1','1','1','1',1,'1','1','1','1','2010-03-26 15:15:13','admin','0','CHN');
UNLOCK TABLES;

DROP TABLE IF EXISTS `js_d_bill`;
CREATE TABLE `js_d_bill` (
  `BillId` int(11) NOT NULL AUTO_INCREMENT,
  `SPId` int(11) DEFAULT NULL,
  `BillYear` int(11) DEFAULT NULL,
  `BillMonth` int(11) DEFAULT NULL,
  `RegCount` int(11) DEFAULT NULL,
  `FeeCount` int(11) DEFAULT NULL,
  `FeeTotal` float DEFAULT NULL,
  `FeeRate` float DEFAULT NULL,
  `ARPU` float DEFAULT NULL,
  `Profit` float DEFAULT NULL,
  `BillRate` float DEFAULT NULL,
  `RealProfit` float DEFAULT NULL,
  `SPProfit` float DEFAULT NULL,
  `MFProfit` float DEFAULT NULL,
  `CPProfit` float DEFAULT NULL,
  `VoginsProfit` float DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`BillId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `js_d_cpbill`;
CREATE TABLE `js_d_cpbill` (
  `CPId` int(11) DEFAULT NULL,
  `BillId` int(11) NOT NULL AUTO_INCREMENT,
  `BillYear` int(11) DEFAULT NULL,
  `BillMonth` int(11) DEFAULT NULL,
  `FeeTotal` float DEFAULT NULL,
  `BillRate` float DEFAULT NULL,
  `OpRate` float DEFAULT NULL,
  `Tax` float DEFAULT NULL,
  `Profit` float DEFAULT NULL,
  `SPRate` float DEFAULT NULL,
  `MFRate` float DEFAULT NULL,
  `RealProfit` float DEFAULT NULL,
  `CPRate` float DEFAULT NULL,
  `BillProfit` float DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`BillId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `js_d_mfbill`;
CREATE TABLE `js_d_mfbill` (
  `BillId` int(11) NOT NULL AUTO_INCREMENT,
  `MFId` int(11) DEFAULT NULL,
  `BillYear` int(11) DEFAULT NULL,
  `BillMonth` int(11) DEFAULT NULL,
  `RegCount` int(11) DEFAULT NULL,
  `FeeCount` int(11) DEFAULT NULL,
  `FeeTotal` float DEFAULT NULL,
  `OpRate` float DEFAULT NULL,
  `BillRate` float DEFAULT NULL,
  `Tax` float DEFAULT NULL,
  `Profit` float DEFAULT NULL,
  `SPRate` float DEFAULT NULL,
  `RealProfit` float DEFAULT NULL,
  `SPProfit` float DEFAULT NULL,
  `MFRate` float DEFAULT NULL,
  `BillProfit` float DEFAULT NULL,
  `VoginsProfit` float DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`BillId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `js_d_spbill`;
CREATE TABLE `js_d_spbill` (
  `BillId` int(11) NOT NULL AUTO_INCREMENT,
  `SPId` int(11) DEFAULT NULL,
  `BillYear` int(11) DEFAULT NULL,
  `BillMonth` int(11) DEFAULT NULL,
  `FeeTotal` float DEFAULT NULL,
  `RealProfit` float DEFAULT NULL,
  `FeeRate` float DEFAULT NULL,
  `OpRate` float DEFAULT NULL,
  `Tax` float DEFAULT NULL,
  `AllProfit` float DEFAULT NULL,
  `VoginsRate` float DEFAULT NULL,
  `BillProfit` float DEFAULT NULL,
  `SPProfit` float DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`BillId`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `jx_b_mf`;
CREATE TABLE `jx_b_mf` (
  `MFId` int(11) NOT NULL AUTO_INCREMENT,
  `MFName` varchar(100) DEFAULT NULL,
  `ShortName` varchar(20) NOT NULL,
  `UAId` varchar(255) DEFAULT '',
  `Address` varchar(100) NOT NULL,
  `Phone` varchar(50) DEFAULT NULL,
  `Fax` varchar(50) DEFAULT NULL,
  `HomePage` varchar(100) DEFAULT NULL,
  `BillType` int(2) DEFAULT NULL,
  `SystemUser` text,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT '',
  `RemoveFlag` char(1) DEFAULT NULL,
  `TestFlag` char(1) DEFAULT '0',
  `FeeChannelTag` char(1) NOT NULL DEFAULT '0',
  `ProductDirectoryTag` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MFId`)
) ENGINE=MyISAM AUTO_INCREMENT=327 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `jx_b_mobile`;
CREATE TABLE `jx_b_mobile` (
  `MobileId` int(11) NOT NULL AUTO_INCREMENT,
  `MFId` int(11) NOT NULL,
  `AppListType` char(1) DEFAULT '1',
  `MobileName` varchar(50) DEFAULT NULL,
  `UserAgent` varchar(50) NOT NULL,
  `ScreenWidth` int(6) NOT NULL,
  `ScreenHeight` int(6) NOT NULL,
  `VREVersion` varchar(20) DEFAULT NULL,
  `MTKVersion` varchar(20) DEFAULT NULL,
  `MemorySize` varchar(20) DEFAULT NULL,
  `InputType` int(4) DEFAULT '0',
  `InputKeypad` char(1) DEFAULT '0',
  `InputTouch` char(1) DEFAULT '0',
  `InputFTE` char(1) DEFAULT '0',
  `InputGS` char(1) DEFAULT '0',
  `InputCS` char(1) DEFAULT '0',
  `FileExtName` varchar(10) DEFAULT 'VXP',
  `Remark` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `LevelFlag` char(1) DEFAULT NULL,
  PRIMARY KEY (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=978 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `jx_b_submf`;
CREATE TABLE `jx_b_submf` (
  `SubMFId` int(11) NOT NULL AUTO_INCREMENT,
  `MFId` int(11) DEFAULT '0',
  `MFName` varchar(100) DEFAULT NULL,
  `ShortName` varchar(20) NOT NULL,
  `Address` varchar(100) NOT NULL,
  `Phone` varchar(50) DEFAULT NULL,
  `Fax` varchar(50) DEFAULT NULL,
  `HomePage` varchar(100) DEFAULT NULL,
  `BillType` int(2) DEFAULT NULL,
  `SystemUser` text,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT '',
  `RemoveFlag` char(1) DEFAULT NULL,
  PRIMARY KEY (`SubMFId`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `jx_p_permission`;
CREATE TABLE `jx_p_permission` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `MobileId` int(11) NOT NULL DEFAULT '0',
  `OpIndex` varchar(10) NOT NULL DEFAULT '',
  `TypeName` varchar(50) DEFAULT NULL,
  `EnName` varchar(50) DEFAULT NULL,
  `FuncList` text,
  `OpPermission` varchar(10) DEFAULT NULL,
  `Remark` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`),
  KEY `MobileId` (`MobileId`,`OpIndex`)
) ENGINE=MyISAM AUTO_INCREMENT=269 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

LOCK TABLES `jx_p_permission` WRITE;
INSERT INTO `jx_p_permission` VALUES (1,0,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-06-10 13:56:00','SYSTEM'),(2,0,'5001','PER_CALL_OUT','PER_CALL_OUT','','1','','2009-06-10 13:56:00','SYSTEM'),(3,0,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-06-10 13:56:00','SYSTEM'),(4,0,'5003','PER_FILE','PER_FILE','','1','','2009-06-10 13:56:00','SYSTEM'),(5,0,'5004','PER_HTTP','PER_HTTP','','1','','2009-06-10 13:56:00','SYSTEM'),(6,0,'5005','PER_RECORD','PER_RECORD','','1','','2009-06-10 13:56:00','SYSTEM'),(7,0,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-06-10 13:56:00','SYSTEM'),(8,0,'5007','PER_SIM','PER_SIM','','1','','2009-06-10 13:56:00','SYSTEM'),(9,0,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-06-10 13:56:00','SYSTEM'),(10,0,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-06-10 13:56:00','SYSTEM'),(11,0,'5010','PER_TCP','PER_TCP','','1','','2009-06-10 13:56:00','SYSTEM'),(12,0,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-06-10 13:56:00','SYSTEM'),(25,1024,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-12-11 10:23:23','wangdaiming'),(26,1024,'5001','PER_CALL_OUT','PER_CALL_OUT','','1','','2009-12-11 10:23:23','wangdaiming'),(27,1024,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-12-11 10:23:23','wangdaiming'),(28,1024,'5003','PER_FILE','PER_FILE','','1','','2009-12-11 10:23:23','wangdaiming'),(29,1024,'5004','PER_HTTP','PER_HTTP','','1','','2009-12-11 10:23:23','wangdaiming'),(30,1024,'5005','PER_RECORD','PER_RECORD','','1','','2009-12-11 10:23:23','wangdaiming'),(31,1024,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-12-11 10:23:23','wangdaiming'),(32,1024,'5007','PER_SIM','PER_SIM','','1','','2009-12-11 10:23:23','wangdaiming'),(33,1024,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-12-11 10:23:23','wangdaiming'),(34,1024,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-12-11 10:23:23','wangdaiming'),(35,1024,'5010','PER_TCP','PER_TCP','','1','','2009-12-11 10:23:23','wangdaiming'),(36,1024,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-12-11 10:23:23','wangdaiming'),(14,0,'5013','PER_BITSTREAM','PER_BITSTREAM','','1','','2010-03-18 11:00:00','SYSTEM'),(15,0,'5014','PER_CONTACT','PER_CONTACT','','1','','2010-03-18 11:00:00','SYSTEM'),(16,0,'5015','PER_LBS','PER_LBS','','1','','2010-03-18 11:00:00','SYSTEM'),(17,0,'5016','PER_MMS','PER_MMS','','1','','2010-03-18 11:00:00','SYSTEM'),(18,0,'5017','PER_PRO','PER_PRO','','1','','2010-03-18 11:00:00','SYSTEM'),(19,0,'5018','PER_SMSMNG','PER_SMSMNG','','1','','2010-03-18 11:00:00','SYSTEM'),(13,0,'5012','PER_BILLING','PER_BILLING','','1','','2010-03-18 11:00:00','SYSTEM'),(20,0,'5019','PER_VIDEO','PER_VIDEO','','1','','2010-03-18 11:00:00','SYSTEM'),(21,0,'5020','PER_XML','PER_XML','','1','','2010-03-18 11:00:00','SYSTEM'),(206,895,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2010-04-29 13:23:01','admin'),(207,895,'5001','PER_CALL_OUT','PER_CALL_OUT','','1','','2010-04-29 13:23:01','admin'),(208,895,'5002','PER_CAMERA','PER_CAMERA','','1','','2010-04-29 13:23:01','admin'),(209,895,'5003','PER_FILE','PER_FILE','','1','','2010-04-29 13:23:01','admin'),(210,895,'5004','PER_HTTP','PER_HTTP','','1','','2010-04-29 13:23:01','admin'),(211,895,'5005','PER_RECORD','PER_RECORD','','1','','2010-04-29 13:23:01','admin'),(212,895,'5006','PER_SENSOR','PER_SENSOR','','1','','2010-04-29 13:23:01','admin'),(213,895,'5007','PER_SIM','PER_SIM','','1','','2010-04-29 13:23:01','admin'),(214,895,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2010-04-29 13:23:01','admin'),(215,895,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2010-04-29 13:23:01','admin'),(216,895,'5010','PER_TCP','PER_TCP','','1','','2010-04-29 13:23:01','admin'),(217,895,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2010-04-29 13:23:01','admin'),(218,895,'5012','PER_BILLING','PER_BILLING','','1','','2010-04-29 13:23:01','admin'),(219,895,'5013','PER_BITSTREAM','PER_BITSTREAM','','1','','2010-04-29 13:23:01','admin'),(220,895,'5014','PER_CONTACT','PER_CONTACT','','1','','2010-04-29 13:23:01','admin'),(221,895,'5015','PER_LBS','PER_LBS','','1','','2010-04-29 13:23:01','admin'),(222,895,'5016','PER_MMS','PER_MMS','','1','','2010-04-29 13:23:01','admin'),(223,895,'5017','PER_PRO','PER_PRO','','1','','2010-04-29 13:23:01','admin'),(224,895,'5018','PER_SMSMNG','PER_SMSMNG','','1','','2010-04-29 13:23:01','admin'),(225,895,'5019','PER_VIDEO','PER_VIDEO','','1','','2010-04-29 13:23:01','admin'),(226,895,'5020','PER_XML','PER_XML','','1','','2010-04-29 13:23:01','admin'),(227,903,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2010-05-14 17:42:39','admin'),(228,903,'5001','PER_CALL_OUT','PER_CALL_OUT','','1','','2010-05-14 17:42:39','admin'),(229,903,'5002','PER_CAMERA','PER_CAMERA','','1','','2010-05-14 17:42:39','admin'),(230,903,'5003','PER_FILE','PER_FILE','','1','','2010-05-14 17:42:39','admin'),(231,903,'5004','PER_HTTP','PER_HTTP','','1','','2010-05-14 17:42:39','admin'),(232,903,'5005','PER_RECORD','PER_RECORD','','1','','2010-05-14 17:42:39','admin'),(233,903,'5006','PER_SENSOR','PER_SENSOR','','1','','2010-05-14 17:42:39','admin'),(234,903,'5007','PER_SIM','PER_SIM','','1','','2010-05-14 17:42:39','admin'),(235,903,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2010-05-14 17:42:39','admin'),(236,903,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2010-05-14 17:42:39','admin'),(237,903,'5010','PER_TCP','PER_TCP','','1','','2010-05-14 17:42:39','admin'),(238,903,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2010-05-14 17:42:39','admin'),(239,903,'5012','PER_BILLING','PER_BILLING','','1','','2010-05-14 17:42:39','admin'),(240,903,'5013','PER_BITSTREAM','PER_BITSTREAM','','1','','2010-05-14 17:42:39','admin'),(241,903,'5014','PER_CONTACT','PER_CONTACT','','1','','2010-05-14 17:42:39','admin'),(242,903,'5015','PER_LBS','PER_LBS','','1','','2010-05-14 17:42:39','admin'),(243,903,'5016','PER_MMS','PER_MMS','','1','','2010-05-14 17:42:39','admin'),(244,903,'5017','PER_PRO','PER_PRO','','1','','2010-05-14 17:42:39','admin'),(245,903,'5018','PER_SMSMNG','PER_SMSMNG','','1','','2010-05-14 17:42:39','admin'),(246,903,'5019','PER_VIDEO','PER_VIDEO','','1','','2010-05-14 17:42:39','admin'),(247,903,'5020','PER_XML','PER_XML','','1','','2010-05-14 17:42:39','admin'),(248,2,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2010-06-09 12:55:51','admin'),(249,2,'5001','PER_CALL_OUT','PER_CALL_OUT','','1','','2010-06-09 12:55:51','admin'),(250,2,'5002','PER_CAMERA','PER_CAMERA','','1','','2010-06-09 12:55:51','admin'),(251,2,'5003','PER_FILE','PER_FILE','','1','','2010-06-09 12:55:51','admin'),(252,2,'5004','PER_HTTP','PER_HTTP','','1','','2010-06-09 12:55:51','admin'),(253,2,'5005','PER_RECORD','PER_RECORD','','1','','2010-06-09 12:55:51','admin'),(254,2,'5006','PER_SENSOR','PER_SENSOR','','1','','2010-06-09 12:55:51','admin'),(255,2,'5007','PER_SIM','PER_SIM','','1','','2010-06-09 12:55:51','admin'),(256,2,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2010-06-09 12:55:51','admin'),(257,2,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2010-06-09 12:55:51','admin'),(258,2,'5010','PER_TCP','PER_TCP','','1','','2010-06-09 12:55:51','admin'),(259,2,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2010-06-09 12:55:51','admin'),(260,2,'5012','PER_BILLING','PER_BILLING','','1','','2010-06-09 12:55:51','admin'),(261,2,'5013','PER_BITSTREAM','PER_BITSTREAM','','1','','2010-06-09 12:55:51','admin'),(262,2,'5014','PER_CONTACT','PER_CONTACT','','1','','2010-06-09 12:55:51','admin'),(263,2,'5015','PER_LBS','PER_LBS','','1','','2010-06-09 12:55:51','admin'),(264,2,'5016','PER_MMS','PER_MMS','','1','','2010-06-09 12:55:51','admin'),(265,2,'5017','PER_PRO','PER_PRO','','1','','2010-06-09 12:55:51','admin'),(266,2,'5018','PER_SMSMNG','PER_SMSMNG','','1','','2010-06-09 12:55:51','admin'),(267,2,'5019','PER_VIDEO','PER_VIDEO','','1','','2010-06-09 12:55:51','admin'),(268,2,'5020','PER_XML','PER_XML','','1','','2010-06-09 12:55:51','admin');
UNLOCK TABLES;

DROP TABLE IF EXISTS `jx_r_submfmobile`;
CREATE TABLE `jx_r_submfmobile` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `MFId` int(11) DEFAULT '0',
  `SubMFId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `UserAgent` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `jx_t_mf`;
CREATE TABLE `jx_t_mf` (
  `MFId` int(11) NOT NULL AUTO_INCREMENT,
  `MFName` varchar(100) DEFAULT NULL,
  `ShortName` varchar(20) NOT NULL,
  `UAId` varchar(255) DEFAULT NULL,
  `Address` varchar(100) NOT NULL,
  `Phone` varchar(50) DEFAULT NULL,
  `Fax` varchar(50) DEFAULT NULL,
  `HomePage` varchar(100) DEFAULT NULL,
  `BillType` int(2) DEFAULT NULL,
  `SystemUser` text,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT '',
  `RemoveFlag` char(1) DEFAULT NULL,
  `TestFlag` char(1) DEFAULT NULL,
  `FeeChannelTag` char(1) NOT NULL DEFAULT '0',
  `ProductDirectoryTag` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MFId`)
) ENGINE=MyISAM AUTO_INCREMENT=327 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `jx_t_mobile`;
CREATE TABLE `jx_t_mobile` (
  `MobileId` int(11) NOT NULL AUTO_INCREMENT,
  `MFId` int(11) NOT NULL,
  `AppListType` char(1) DEFAULT '1',
  `MobileName` varchar(50) DEFAULT NULL,
  `UserAgent` varchar(50) NOT NULL,
  `ScreenWidth` int(6) NOT NULL,
  `ScreenHeight` int(6) NOT NULL,
  `VREVersion` varchar(20) DEFAULT NULL,
  `MTKVersion` varchar(20) DEFAULT NULL,
  `MemorySize` varchar(20) DEFAULT NULL,
  `InputType` int(4) DEFAULT '0',
  `FileExtName` varchar(10) DEFAULT 'VXP',
  `Remark` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(200) DEFAULT NULL,
  `RemoveFlag` char(1) DEFAULT NULL,
  `LevelFlag` char(1) DEFAULT NULL COMMENT '机型评级',
  PRIMARY KEY (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=943 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `jx_t_permission`;
CREATE TABLE `jx_t_permission` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `MobileId` int(11) NOT NULL DEFAULT '0',
  `OpIndex` varchar(10) NOT NULL DEFAULT '',
  `TypeName` varchar(50) DEFAULT NULL,
  `EnName` varchar(50) DEFAULT NULL,
  `FuncList` text,
  `OpPermission` varchar(10) DEFAULT NULL,
  `Remark` varchar(200) DEFAULT NULL,
  `AddTime` datetime DEFAULT NULL,
  `AddUser` varchar(50) DEFAULT '',
  PRIMARY KEY (`RecId`),
  KEY `MobileId` (`MobileId`,`OpIndex`)
) ENGINE=MyISAM AUTO_INCREMENT=73 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

LOCK TABLES `jx_t_permission` WRITE;
INSERT INTO `jx_t_permission` VALUES (6,0,'5005','PER_RECORD','PER_RECORD','','1','','2009-06-10 13:56:00','SYSTEM'),(7,0,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-06-10 13:56:00','SYSTEM'),(8,0,'5007','PER_SIM','PER_SIM','','1','','2009-06-10 13:56:00','SYSTEM'),(9,0,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-06-10 13:56:00','SYSTEM'),(10,0,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-06-10 13:56:00','SYSTEM'),(1,0,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-06-10 13:56:00','SYSTEM'),(2,0,'5001','PER_CALL_OUT','PER_CALL_OUT','','0','','2009-06-10 13:56:00','SYSTEM'),(3,0,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-06-10 13:56:00','SYSTEM'),(4,0,'5003','PER_FILE','PER_FILE','','1','','2009-06-10 13:56:00','SYSTEM'),(5,0,'5004','PER_HTTP','PER_HTTP','','1','','2009-06-10 13:56:00','SYSTEM'),(11,0,'5010','PER_TCP','PER_TCP','','1','','2009-06-10 13:56:00','SYSTEM'),(12,0,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-06-10 13:56:00','SYSTEM'),(13,887,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-07-17 08:42:09','admin'),(14,887,'5001','PER_CALL_OUT','PER_CALL_OUT','','0','','2009-07-17 08:42:09','admin'),(15,887,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-07-17 08:42:09','admin'),(16,887,'5003','PER_FILE','PER_FILE','','1','','2009-07-17 08:42:09','admin'),(17,887,'5004','PER_HTTP','PER_HTTP','','1','','2009-07-17 08:42:09','admin'),(18,887,'5005','PER_RECORD','PER_RECORD','','1','','2009-07-17 08:42:10','admin'),(19,887,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-07-17 08:42:10','admin'),(20,887,'5007','PER_SIM','PER_SIM','','1','','2009-07-17 08:42:10','admin'),(21,887,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-07-17 08:42:11','admin'),(22,887,'5009','PER_SMS_SP','PER_SMS_SP','','0','','2009-07-17 08:42:11','admin'),(23,887,'5010','PER_TCP','PER_TCP','','1','','2009-07-17 08:42:11','admin'),(24,887,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-07-17 08:42:11','admin'),(25,881,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-09-22 10:54:47','admin'),(26,881,'5001','PER_CALL_OUT','PER_CALL_OUT','','0','','2009-09-22 10:54:47','admin'),(27,881,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-09-22 10:54:47','admin'),(28,881,'5003','PER_FILE','PER_FILE','','1','','2009-09-22 10:54:47','admin'),(29,881,'5004','PER_HTTP','PER_HTTP','','1','','2009-09-22 10:54:47','admin'),(30,881,'5005','PER_RECORD','PER_RECORD','','1','','2009-09-22 10:54:47','admin'),(31,881,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-09-22 10:54:47','admin'),(32,881,'5007','PER_SIM','PER_SIM','','1','','2009-09-22 10:54:47','admin'),(33,881,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-09-22 10:54:47','admin'),(34,881,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-09-22 10:54:47','admin'),(35,881,'5010','PER_TCP','PER_TCP','','1','','2009-09-22 10:54:47','admin'),(36,881,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-09-22 10:54:47','admin'),(37,892,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-09-22 10:54:53','admin'),(38,892,'5001','PER_CALL_OUT','PER_CALL_OUT','','0','','2009-09-22 10:54:53','admin'),(39,892,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-09-22 10:54:53','admin'),(40,892,'5003','PER_FILE','PER_FILE','','1','','2009-09-22 10:54:53','admin'),(41,892,'5004','PER_HTTP','PER_HTTP','','1','','2009-09-22 10:54:53','admin'),(42,892,'5005','PER_RECORD','PER_RECORD','','1','','2009-09-22 10:54:53','admin'),(43,892,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-09-22 10:54:53','admin'),(44,892,'5007','PER_SIM','PER_SIM','','1','','2009-09-22 10:54:53','admin'),(45,892,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-09-22 10:54:53','admin'),(46,892,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-09-22 10:54:53','admin'),(47,892,'5010','PER_TCP','PER_TCP','','1','','2009-09-22 10:54:53','admin'),(48,892,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-09-22 10:54:53','admin'),(49,891,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-09-22 10:54:55','admin'),(50,891,'5001','PER_CALL_OUT','PER_CALL_OUT','','0','','2009-09-22 10:54:55','admin'),(51,891,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-09-22 10:54:55','admin'),(52,891,'5003','PER_FILE','PER_FILE','','1','','2009-09-22 10:54:55','admin'),(53,891,'5004','PER_HTTP','PER_HTTP','','1','','2009-09-22 10:54:55','admin'),(54,891,'5005','PER_RECORD','PER_RECORD','','1','','2009-09-22 10:54:55','admin'),(55,891,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-09-22 10:54:55','admin'),(56,891,'5007','PER_SIM','PER_SIM','','1','','2009-09-22 10:54:55','admin'),(57,891,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-09-22 10:54:55','admin'),(58,891,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-09-22 10:54:55','admin'),(59,891,'5010','PER_TCP','PER_TCP','','1','','2009-09-22 10:54:55','admin'),(60,891,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-09-22 10:54:55','admin'),(61,897,'5000','PER_AUDIO_PLAY','PER_AUDIO_PLAY','','1','','2009-09-22 10:55:07','admin'),(62,897,'5001','PER_CALL_OUT','PER_CALL_OUT','','1','adf','2009-09-22 10:55:07','admin'),(63,897,'5002','PER_CAMERA','PER_CAMERA','','1','','2009-09-22 10:55:07','admin'),(64,897,'5003','PER_FILE','PER_FILE','','1','','2009-09-22 10:55:07','admin'),(65,897,'5004','PER_HTTP','PER_HTTP','','1','','2009-09-22 10:55:07','admin'),(66,897,'5005','PER_RECORD','PER_RECORD','','1','','2009-09-22 10:55:07','admin'),(67,897,'5006','PER_SENSOR','PER_SENSOR','','1','','2009-09-22 10:55:07','admin'),(68,897,'5007','PER_SIM','PER_SIM','','1','','2009-09-22 10:55:07','admin'),(69,897,'5008','PER_SMS_PER','PER_SMS_PER','','1','','2009-09-22 10:55:07','admin'),(70,897,'5009','PER_SMS_SP','PER_SMS_SP','','1','','2009-09-22 10:55:07','admin'),(71,897,'5010','PER_TCP','PER_TCP','','1','','2009-09-22 10:55:07','admin'),(72,897,'5011','PER_APPSTORE','PER_APPSTORE','','1','','2009-09-22 10:55:07','admin');
UNLOCK TABLES;

DROP TABLE IF EXISTS `kf_b_touse`;
CREATE TABLE `kf_b_touse` (
  `TouseId` int(11) NOT NULL AUTO_INCREMENT,
  `SubscriberId` int(11) DEFAULT NULL,
  `Mobile` varchar(200) DEFAULT NULL,
  `MobileId` int(11) DEFAULT NULL,
  `AppID` int(11) DEFAULT NULL,
  `AppName` varchar(200) DEFAULT NULL,
  `AppPrice` varchar(200) DEFAULT NULL,
  `FeeType` char(1) DEFAULT NULL,
  `FeeValue` int(11) DEFAULT NULL,
  `TouseContent` varchar(255) DEFAULT NULL,
  `Solution` varchar(255) DEFAULT NULL,
  `Compensation` int(11) DEFAULT NULL,
  `TouseStatus` char(1) DEFAULT NULL,
  `TouseTime` datetime DEFAULT '0000-00-00 00:00:00',
  `ModifyTime` datetime DEFAULT '0000-00-00 00:00:00',
  `AddUser` varchar(255) DEFAULT NULL,
  `ModifyUser` varchar(255) DEFAULT NULL,
  `Remark` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`TouseId`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `oa_d_message`;
CREATE TABLE `oa_d_message` (
  `MsgId` int(11) NOT NULL AUTO_INCREMENT,
  `MsgType` char(1) DEFAULT NULL,
  `Sender` varchar(20) DEFAULT NULL,
  `Receiver` varchar(20) DEFAULT NULL,
  `Receivers` text,
  `Level` varchar(10) DEFAULT NULL,
  `Subject` varchar(100) DEFAULT NULL,
  `Content` text,
  `MsgStatus` char(1) DEFAULT NULL,
  `ReqReply` char(1) DEFAULT NULL,
  `Reply` char(1) DEFAULT NULL,
  `ReadFlag` char(1) DEFAULT NULL,
  `AttachFlag` char(1) DEFAULT NULL,
  `SendTime` datetime DEFAULT NULL,
  PRIMARY KEY (`MsgId`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `oa_d_msgattach`;
CREATE TABLE `oa_d_msgattach` (
  `AttachId` int(11) NOT NULL AUTO_INCREMENT,
  `MsgId` int(11) DEFAULT NULL,
  `AttachPath` varchar(200) DEFAULT NULL,
  `AttachName` varchar(50) DEFAULT NULL,
  `AttachSize` int(11) DEFAULT NULL,
  `UploadTime` datetime DEFAULT NULL,
  PRIMARY KEY (`AttachId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

DROP TABLE IF EXISTS `oa_f_attachment`;
CREATE TABLE `oa_f_attachment` (
  `AttachmentId` int(11) NOT NULL AUTO_INCREMENT,
  `FlowId` int(11) DEFAULT NULL,
  `AttachmentPath` varchar(200) DEFAULT NULL,
  `AttachmentName` varchar(50) DEFAULT NULL,
  `AttachmentSize` int(11) DEFAULT NULL,
  `UploadTime` datetime DEFAULT NULL,
  `UploadStaff` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`AttachmentId`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `oa_f_field`;
CREATE TABLE `oa_f_field` (
  `FieldId` int(11) NOT NULL AUTO_INCREMENT,
  `TypeId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `DataType` varchar(50) DEFAULT NULL,
  `SelectId` int(11) DEFAULT NULL,
  `FieldName` varchar(50) DEFAULT NULL,
  `ShowName` varchar(50) DEFAULT NULL,
  `FlowField` varchar(50) DEFAULT NULL,
  `Remark` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`FieldId`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

LOCK TABLES `oa_f_field` WRITE;
INSERT INTO `oa_f_field` VALUES (1,1,1,'ShortString',NULL,'CPId','CP编号','ShortString1',NULL),(2,2,1,'ShortString',NULL,'CPId','CP编号','ShortString1',NULL),(3,3,1,'ShortString',NULL,'CPId','CP编号','ShortString1',NULL),(4,4,1,'ShortString',NULL,'MFId','厂商编号','ShortString1',NULL),(5,5,1,'ShortString',NULL,'MFId','厂商编号','ShortString1',NULL),(6,6,1,'ShortString',NULL,'MFId','厂商编号','ShortString1',NULL),(7,7,1,'ShortString',NULL,'MFId','厂商编号','ShortString1',NULL);
UNLOCK TABLES;

DROP TABLE IF EXISTS `oa_f_node`;
CREATE TABLE `oa_f_node` (
  `NodeId` int(11) NOT NULL AUTO_INCREMENT,
  `TypeId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `NodeName` varchar(50) DEFAULT NULL,
  `NodeType` varchar(50) DEFAULT NULL,
  `AppointType` varchar(50) DEFAULT NULL,
  `AppSeqNo` int(11) DEFAULT NULL,
  `CanJump` char(1) DEFAULT NULL,
  `ReAppoint` char(1) DEFAULT NULL,
  `DoExecute` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`NodeId`)
) ENGINE=MyISAM AUTO_INCREMENT=218 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

LOCK TABLES `oa_f_node` WRITE;
INSERT INTO `oa_f_node` VALUES (1,1,1,'新建CP','0','0',0,'0','0','com.vogins.workflow.execute.cp.DelAddCP'),(2,1,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cp.ExeAddCP'),(3,2,1,'修改CP','0','0',0,'0','0','com.vogins.workflow.execute.cp.DelUpdateCP'),(4,2,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cp.ExeUpdateCP'),(5,3,1,'删除CP','0','0',0,'0','0',NULL),(6,3,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cp.ExeDeleteCP'),(18,4,1,'厂商申请','0','0',0,'0','0','com.vogins.workflow.execute.mfwf.DelUACode'),(19,4,2,'BD检查','1','1',0,'0','0',NULL),(20,4,3,'运营确认','1','1',2,'0','0','com.vogins.workflow.execute.mfwf.ExeAddUACode'),(21,5,1,'新建厂商','0','0',0,'0','0','com.vogins.workflow.execute.mf.DelAddMF'),(22,5,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.mf.ExeAddMF'),(23,6,1,'修改厂商','0','0',0,'0','0','com.vogins.workflow.execute.mf.DelUpdateMF'),(24,6,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.mf.ExeUpdateMF'),(25,7,1,'删除厂商','0','0',0,'0','0',NULL),(26,7,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.mf.ExeDeleteMF'),(27,8,1,'修改机型','0','0',0,'0','0','com.vogins.workflow.execute.Mobile.DelUpdateMobile'),(28,8,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.Mobile.ExeUpdateMobile'),(29,9,1,'新建Fee','0','0',0,'0','0','com.vogins.workflow.execute.Fee.DelAddFee'),(30,9,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.Fee.ExeAddFee'),(31,10,1,'修改fee','0','0',0,'0','0','com.vogins.workflow.execute.Fee.DelUpdateFee'),(32,10,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.Fee.ExeUpdateFee'),(33,11,1,'删除Fee','0','0',0,'0','0',NULL),(34,11,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.Fee.ExeDeleteFee'),(35,12,1,'新建SP','0','0',0,'0','0','com.vogins.workflow.execute.sp.DelAddSp'),(36,12,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.sp.ExeAddSp'),(37,13,1,'修改Sp','0','0',0,'0','0','com.vogins.workflow.execute.sp.DelUpdateSp'),(38,13,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.sp.ExeUpdateSp'),(39,14,1,'删除Sp','0','0',0,'0','0',NULL),(40,14,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.sp.ExeDeleteSp'),(41,15,1,'添加产品','0','0',0,'0','0','com.vogins.workflow.execute.app.DelAddApp'),(42,15,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.app.ExeAddApp'),(43,16,1,'修改产品','0','0',0,'0','0','com.vogins.workflow.execute.app.DelUpdateApp'),(44,16,2,'运营检查','1','1',1,'0','0',NULL),(45,16,3,'指定测试员','1','1',1,'0','0',NULL),(46,16,4,'测试','1','1',3,'0','0',NULL),(47,16,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.app.ExeUpdateApp'),(48,17,1,'删除产品','0','0',0,'0','0',NULL),(49,17,2,'运营检查','1','1',1,'0','0',NULL),(50,17,3,'指定测试员','1','1',1,'0','0',NULL),(51,17,4,'测试','1','1',3,'0','0',NULL),(52,17,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.app.ExeDeleteApp'),(53,18,1,'修改产品','0','0',0,'0','0','com.vogins.workflow.execute.app.DelUpdateApp'),(54,18,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.app.ExeUpdateApp'),(55,19,1,'删除产品','0','0',0,'0','0',NULL),(56,19,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.app.ExeDeleteApp'),(57,20,1,'添加通道','0','0',0,'0','0','com.vogins.workflow.execute.feegroup.ExeCansleFeeGroup'),(58,20,2,'运营检查','1','1',1,'0','0',NULL),(59,20,3,'指定测试员','1','1',1,'0','0',NULL),(60,20,4,'测试','1','1',3,'0','0',NULL),(61,20,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.feegroup.ExeAddFeeGroup'),(62,21,1,'删除通道','0','0',0,'0','0',NULL),(63,21,2,'运营检查','1','1',1,'0','0',NULL),(64,21,3,'指定测试员','1','1',1,'0','0',NULL),(65,21,4,'测试','1','1',3,'0','0',NULL),(66,21,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.feegroup.ExeDelFeeGroup'),(67,22,1,'添加版本','0','0',0,'0','0','com.vogins.workflow.execute.appversion.DelAddVersion'),(68,22,2,'运营检查','1','1',1,'0','0',NULL),(69,22,3,'指定测试员','1','1',1,'0','0',NULL),(70,22,4,'测试','1','1',3,'0','0',NULL),(71,22,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appversion.ExeAddVersion'),(72,23,1,'修改版本','0','0',0,'0','0','com.vogins.workflow.execute.appversion.DelUpdateVersion'),(73,23,2,'运营检查','1','1',1,'0','0',NULL),(74,23,3,'指定测试员','1','1',1,'0','0',NULL),(75,23,4,'测试','1','1',3,'0','0',NULL),(76,23,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appversion.ExeUpdateVersion'),(77,24,1,'删除版本','0','0',0,'0','0',NULL),(78,24,2,'运营检查','1','1',1,'0','0',NULL),(79,24,3,'指定测试员','1','1',1,'0','0',NULL),(80,24,4,'测试','1','1',3,'0','0',NULL),(81,24,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appversion.ExeDeleteVersion'),(82,25,1,'添加版本','0','0',0,'0','0','com.vogins.workflow.execute.appversion.DelAddVersion'),(83,25,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appversion.ExeAddVersion'),(84,26,1,'修改版本','0','0',0,'0','0','com.vogins.workflow.execute.appversion.DelUpdateVersion'),(85,26,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appversion.ExeUpdateVersion'),(86,27,1,'删除版本','0','0',0,'0','0',NULL),(87,27,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appversion.ExeDeleteVersion'),(88,28,1,'添加AS','0','0',0,'0','0','com.vogins.workflow.execute.appstore.DelAddAS'),(89,28,2,'运营检查','1','1',1,'0','0',NULL),(90,28,3,'指定测试员','1','1',1,'0','0',NULL),(91,28,4,'测试','1','1',3,'0','0',NULL),(92,28,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appstore.ExeAddAS'),(93,29,1,'修改AS','0','0',0,'0','0','com.vogins.workflow.execute.appstore.DelUpdateAS'),(94,29,2,'运营检查','1','1',1,'0','0',NULL),(95,29,3,'指定测试员','1','1',1,'0','0',NULL),(96,29,4,'测试','1','1',3,'0','0',NULL),(97,29,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appstore.ExeUpdateAS'),(98,30,1,'删除AS','0','0',0,'0','0',NULL),(99,30,2,'运营检查','1','1',1,'0','0',NULL),(100,30,3,'指定测试员','1','1',1,'0','0',NULL),(101,30,4,'测试','1','1',3,'0','0',NULL),(102,30,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.appstore.ExeDeleteAS'),(103,31,1,'添加CP黑名单','0','0',0,'0','0','com.vogins.workflow.execute.blacklist.DelAddCP'),(104,31,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.blacklist.ExeAddCP'),(105,32,1,'删除CP黑名单','0','0',0,'0','0',NULL),(106,32,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.blacklist.ExeDeleteCP'),(107,33,1,'添加产品黑名单','0','0',0,'0','0','com.vogins.workflow.execute.blacklist.DelAddApp'),(108,33,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.blacklist.ExeAddApp'),(109,34,1,'删除产品黑名单','0','0',0,'0','0',NULL),(110,34,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.blacklist.ExeDeleteApp'),(111,35,1,'添加机型产品黑名单','0','0',0,'0','0','com.vogins.workflow.execute.blacklist.DelAddMobileApp'),(112,35,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.blacklist.ExeAddMobileApp'),(113,36,1,'删除机型产品黑名单','0','0',0,'0','0',NULL),(114,36,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.blacklist.ExeDeleteMobileApp'),(115,37,1,'添加商务流程','0','0',0,'0','0','com.vogins.workflow.execute.cpwf.document.DelAddDoc'),(116,37,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cpwf.document.ExeAddDoc'),(117,38,1,'修改商务流程','0','0',0,'0','0','com.vogins.workflow.execute.cpwf.document.DelUpdateDoc'),(118,38,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cpwf.document.ExeUpdateDoc'),(119,39,1,'删除商务流程','0','0',0,'0','0',NULL),(120,39,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cpwf.document.ExeDeleteDoc'),(121,40,1,'CP提交','0','0',0,'0','0','com.vogins.workflow.execute.cpwf.evaluation.RejectEva'),(122,40,2,'商务确认','1','0',1,'0','0',NULL),(123,40,3,'技术确认','1','1',2,'0','0',NULL),(124,40,4,'运营确认','1','1',2,'0','0','com.vogins.workflow.execute.cpwf.evaluation.PassEva'),(125,41,1,'添加目录','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelAddFolder'),(126,41,2,'运营检查','1','1',1,'0','0',NULL),(127,41,3,'指定测试员','1','1',1,'0','0',NULL),(128,41,4,'测试','1','1',3,'0','0',NULL),(129,41,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeAddFolder'),(130,42,1,'修改目录','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelUpdateFolder'),(131,42,2,'运营检查','1','1',1,'0','0',NULL),(132,42,3,'指定测试员','1','1',1,'0','0',NULL),(133,42,4,'测试','1','1',3,'0','0',NULL),(134,42,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeUpdateFolder'),(135,43,1,'删除目录','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelDeleteFolder'),(136,43,2,'运营检查','1','1',1,'0','0',NULL),(137,43,3,'指定测试员','1','1',1,'0','0',NULL),(138,43,4,'测试','1','1',3,'0','0',NULL),(139,43,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeDeleteFolder'),(140,44,1,'目录上移','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelUpFolder'),(141,44,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeUpFolder'),(142,45,1,'目录下移','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelDownFolder'),(143,45,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeDownFolder'),(144,46,1,'添加产品到目录','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelAddFolderApp'),(145,46,2,'运营检查','1','1',1,'0','0',NULL),(146,46,3,'指定测试员','1','1',1,'0','0',NULL),(147,46,4,'测试','1','1',3,'0','0',NULL),(148,46,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeAddFolderApp'),(149,47,1,'从目录删除产品','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelDeleteFolderApp'),(150,47,2,'运营检查','1','1',1,'0','0',NULL),(151,47,3,'指定测试员','1','1',1,'0','0',NULL),(152,47,4,'测试','1','1',3,'0','0',NULL),(153,47,5,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeDeleteFolderApp'),(154,48,1,'目录产品上移','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelUpFolderApp'),(155,48,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeUpFolderApp'),(156,49,1,'目录产品下移','0','0',0,'0','0','com.vogins.workflow.execute.folder.DelDownFolderApp'),(157,49,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.folder.ExeDownFolderApp'),(158,50,1,'立项申请','0','0',0,'0','0','com.vogins.workflow.execute.cpwf.project.RejectProject'),(159,50,2,'技术确认','1','1',1,'0','0',NULL),(160,50,3,'QA确认','1','1',1,'0','0',NULL),(161,50,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cpwf.project.PassProject'),(162,51,1,'完成测试','0','0',0,'0','0',''),(163,51,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cpwf.project.ProjectTest'),(164,52,1,'上线申请','0','0',0,'0','0','com.vogins.workflow.execute.cpwf.online.RejectOnline'),(165,52,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.cpwf.online.PassOnline'),(166,53,1,'添加预置产品','0','0',0,'0','0','com.vogins.workflow.execute.preapp.DelAddPreApp'),(167,53,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.preapp.ExeAddPreApp'),(168,54,1,'删除预置产品','0','0',0,'0','0',''),(169,54,2,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.preapp.ExeDeletePreApp'),(170,55,1,'添加站内信息','0','0',0,'0','0','com.vogins.workflow.execute.as3.msg.DelAddMsg'),(171,55,2,'指定测试员','1','1',1,'0','0',NULL),(172,55,3,'测试','1','1',2,'0','0',NULL),(173,55,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.msg.ExeAddMsg'),(174,56,1,'修改站内信息','0','0',0,'0','0','com.vogins.workflow.execute.as3.msg.DelUpdateMsg'),(175,56,2,'指定测试员','1','1',1,'0','0',NULL),(176,56,3,'测试','1','1',2,'0','0',NULL),(177,56,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.msg.ExeUpdateMsg'),(178,57,1,'删除站内信息','0','0',0,'0','0',NULL),(179,57,2,'指定测试员','1','1',1,'0','0',NULL),(180,57,3,'测试','1','1',2,'0','0',NULL),(181,57,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.msg.ExeDeleteMsg'),(182,58,1,'添加搜索引擎','0','0',0,'0','0','com.vogins.workflow.execute.as3.search.DelAddSearch'),(183,58,2,'指定测试员','1','1',1,'0','0',NULL),(184,58,3,'测试','1','1',2,'0','0',NULL),(185,58,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.search.ExeAddSearch'),(186,59,1,'修改搜索引擎','0','0',0,'0','0','com.vogins.workflow.execute.as3.search.DelUpdateSearch'),(187,59,2,'指定测试员','1','1',1,'0','0',NULL),(188,59,3,'测试','1','1',2,'0','0',NULL),(189,59,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.search.ExeUpdateSearch'),(190,60,1,'删除搜索引擎','0','0',0,'0','0',NULL),(191,60,2,'指定测试员','1','1',1,'0','0',NULL),(192,60,3,'测试','1','1',2,'0','0',NULL),(193,60,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.search.ExeDeleteSearch'),(194,61,1,'添加手机酷站','0','0',0,'0','0','com.vogins.workflow.execute.as3.wap.DelAddWap'),(195,61,2,'指定测试员','1','1',1,'0','0',NULL),(196,61,3,'测试','1','1',2,'0','0',NULL),(197,61,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.wap.ExeAddWap'),(198,62,1,'修改手机酷站','0','0',0,'0','0','com.vogins.workflow.execute.as3.wap.DelUpdateWap'),(199,62,2,'指定测试员','1','1',1,'0','0',NULL),(200,62,3,'测试','1','1',2,'0','0',NULL),(201,62,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.wap.ExeUpdateWap'),(202,63,1,'删除手机酷站','0','0',0,'0','0',''),(203,63,2,'指定测试员','1','1',1,'0','0',NULL),(204,63,3,'测试','1','1',2,'0','0',NULL),(205,63,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.wap.ExeDeleteWap'),(206,64,1,'添加广告','0','0',0,'0','0','com.vogins.workflow.execute.as3.adv.DelAddAdv'),(207,64,2,'指定测试员','1','1',1,'0','0',NULL),(208,64,3,'测试','1','1',2,'0','0',NULL),(209,64,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.adv.ExeAddAdv'),(210,65,1,'修改广告','0','0',0,'0','0','com.vogins.workflow.execute.as3.adv.DelUpdateAdv'),(211,65,2,'指定测试员','1','1',1,'0','0',NULL),(212,65,3,'测试','1','1',2,'0','0',NULL),(213,65,4,'运营确认','1','1',1,'0','0','com.vogins.workflow.execute.as3.adv.ExeUpdateAdv'),(214,66,1,'删除广告','0','0',0,'0','0',NULL),(215,66,2,'指定测试员','1','1',1,'0','0',NULL),(216,66,3,'测试','1','1',2,'0','0',NULL),(217,66,4,'运营','1','1',1,'0','0','com.vogins.workflow.execute.as3.adv.ExeDeleteAdv');
UNLOCK TABLES;

DROP TABLE IF EXISTS `oa_f_option`;
CREATE TABLE `oa_f_option` (
  `OptionId` int(11) NOT NULL AUTO_INCREMENT,
  `SelectId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `OptionName` varchar(50) DEFAULT NULL,
  `OptionValue` varchar(50) DEFAULT NULL,
  `OptionDesc` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`OptionId`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

LOCK TABLES `oa_f_option` WRITE;
INSERT INTO `oa_f_option` VALUES (1,NULL,NULL,NULL,NULL,NULL);
UNLOCK TABLES;

DROP TABLE IF EXISTS `oa_f_select`;
CREATE TABLE `oa_f_select` (
  `SelectId` int(11) NOT NULL AUTO_INCREMENT,
  `SelectName` varchar(50) DEFAULT NULL,
  `SelectDesc` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`SelectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `oa_f_subflow`;
CREATE TABLE `oa_f_subflow` (
  `SubId` int(11) NOT NULL AUTO_INCREMENT,
  `FlowId` int(11) DEFAULT NULL,
  `SeqNo` int(11) DEFAULT NULL,
  `SubName` varchar(50) DEFAULT NULL,
  `HandleStaff` varchar(20) DEFAULT NULL,
  `HandleResult` varchar(50) DEFAULT NULL,
  `HandleOpinion` text,
  `HandleTime` datetime DEFAULT NULL,
  `Remark` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`SubId`)
) ENGINE=MyISAM AUTO_INCREMENT=12380 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `oa_f_type`;
CREATE TABLE `oa_f_type` (
  `TypeId` int(11) NOT NULL AUTO_INCREMENT,
  `TypeName` varchar(50) DEFAULT NULL,
  `TypeDesc` varchar(500) DEFAULT NULL,
  `CreateStaff` varchar(20) DEFAULT NULL,
  `CreateTime` datetime DEFAULT NULL,
  `UpdateStaff` varchar(20) DEFAULT NULL,
  `UpdateTime` datetime DEFAULT NULL,
  `Remark` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`TypeId`)
) ENGINE=MyISAM AUTO_INCREMENT=67 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

LOCK TABLES `oa_f_type` WRITE;
INSERT INTO `oa_f_type` VALUES (1,'新建CP','新建CP','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',''),(2,'修改CP','修改CP','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',''),(3,'删除CP','删除CP','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',NULL),(4,'UA编码申请','UA编码申请','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',NULL),(5,'新建厂商','新建厂商','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',NULL),(6,'修改厂商','修改厂商','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',NULL),(7,'删除厂商','删除厂商','admin','2009-10-20 11:14:24','admin','2009-10-20 11:14:24',NULL),(8,'修改机型厂商','修改机型厂商','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(9,'新建计费通道','新建计费通道','admin','2009-11-18 13:31:24','admin','2009-11-18 13:31:24',NULL),(10,'修改计费通道','修改计费通道','admin','2009-11-18 13:31:24','admin','2009-11-18 13:31:24',NULL),(11,'删除计费通道','删除计费通道','admin','2009-11-18 13:31:24','admin','2009-11-18 13:31:24',NULL),(12,'新建SP','新建SP','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(13,'修改SP','修改SP','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(14,'删除SP','删除SP','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(15,'添加产品','添加产品','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(16,'修改产品','修改产品','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(17,'删除产品','删除产品','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(18,'修改产品(S)','修改产品(S)','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(19,'删除产品(S)','删除产品(S)','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(20,'添加通道到通道组','添加通道到通道组','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(21,'从通道组删除通道','从通道组删除通道','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(22,'添加产品版本','添加产品版本','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(23,'修改产品版本','修改产品版本','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(24,'删除产品版本','删除产品版本','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(25,'添加产品版本(S)','添加产品版本(S)','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(26,'修改产品版本(S)','修改产品版本(S)','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(27,'删除产品版本(S)','删除产品版本(S)','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(28,'添加AS','添加AS','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(29,'修改AS','修改AS','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(30,'删除AS','删除AS','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(31,'添加CP黑名单','添加CP黑名单','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(32,'删除CP黑名单','删除CP黑名单','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(33,'添加产品黑名单','添加产品黑名单','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(34,'删除产品黑名单','删除产品黑名单','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(35,'添加机型产品黑名单','添加机型产品黑名单','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(36,'删除机型产品黑名单','删除机型产品黑名单','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(37,'添加商务流程','添加商务流程','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(38,'修改商务流程','修改商务流程','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(39,'删除商务流程','删除商务流程','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(40,'提交产品评估','提交产品评估','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(41,'添加目录','添加目录','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(42,'修改目录','修改目录','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(43,'删除目录','删除目录','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(44,'上移目录','上移目录','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(45,'下移目录','下移目录','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(46,'添加产品到目录','添加产品到目录','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(47,'从目录删除产品','从目录删除产品','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(48,'目录产品上移','目录产品上移','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(49,'目录产品下移','目录产品下移','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(50,'CP工作流-立项申请','CP工作流-立项申请','admin','2009-11-09 11:34:24','admin','2009-11-09 11:34:24',NULL),(51,'CP完成测试','CP完成测试','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(52,'CP工作流-项目上线申请','CP工作流-项目上线申请','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(53,'添加预置产品','添加预置产品','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(54,'删除预置产品','删除预置产品','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(55,'添加站内信息','添加站内信息','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(56,'修改站内信息','修改站内信息','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(57,'删除站内信息','删除站内信息','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(58,'添加搜索引擎','添加搜索引擎','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(59,'修改搜索引擎','修改搜索引擎','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(60,'删除搜索引擎','删除搜索引擎','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(61,'添加手机酷站','添加手机酷站','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(62,'修改手机酷站','修改手机酷站','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(63,'删除手机酷站','删除手机酷站','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(64,'添加广告','添加广告','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(65,'修改广告','修改广告','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL),(66,'删除广告','删除广告','admin','2009-12-24 11:34:24','admin','2009-12-24 11:34:24',NULL);
UNLOCK TABLES;

DROP TABLE IF EXISTS `oa_f_workflow`;
CREATE TABLE `oa_f_workflow` (
  `FlowId` int(11) NOT NULL AUTO_INCREMENT,
  `FlowType` int(11) DEFAULT NULL,
  `ImportanceLevel` varchar(20) DEFAULT NULL,
  `SecretLevel` varchar(20) DEFAULT NULL,
  `Subject` varchar(100) DEFAULT NULL,
  `Content` text,
  `CreateStaff` varchar(20) DEFAULT NULL,
  `CreateTime` datetime DEFAULT NULL,
  `FlowStatus` char(1) DEFAULT NULL,
  `StorePosition` varchar(100) DEFAULT NULL,
  `Pigeonhole` char(1) DEFAULT NULL,
  `DocType` varchar(50) DEFAULT NULL,
  `ShortString1` varchar(50) DEFAULT NULL,
  `ShortString2` varchar(50) DEFAULT NULL,
  `ShortString3` varchar(50) DEFAULT NULL,
  `ShortString4` varchar(50) DEFAULT NULL,
  `ShortString5` varchar(50) DEFAULT NULL,
  `String1` varchar(200) DEFAULT NULL,
  `String2` varchar(200) DEFAULT NULL,
  `String3` varchar(200) DEFAULT NULL,
  `String4` varchar(200) DEFAULT NULL,
  `String5` varchar(200) DEFAULT NULL,
  `DateTime1` datetime DEFAULT NULL,
  `DateTime2` datetime DEFAULT NULL,
  `DateTime3` datetime DEFAULT NULL,
  `DateTime4` datetime DEFAULT NULL,
  `DateTime5` datetime DEFAULT NULL,
  `Content1` text,
  `Content2` text,
  `Content3` text,
  PRIMARY KEY (`FlowId`)
) ENGINE=MyISAM AUTO_INCREMENT=3695 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

DROP TABLE IF EXISTS `tj_d_appdownload`;
CREATE TABLE `tj_d_appdownload` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `DldDate` date DEFAULT '0000-00-00',
  `DldHour` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `ReqCount` int(11) DEFAULT '0',
  `DldCount` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`DldDate`),
  KEY `2` (`DldHour`),
  KEY `3` (`AppId`),
  KEY `4` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=672 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `tj_d_areafee`;
CREATE TABLE `tj_d_areafee` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FeeDate` date DEFAULT '0000-00-00',
  `ProvinceId` int(11) DEFAULT '0',
  `AreaId` int(11) DEFAULT '0',
  `FeeCount` int(11) DEFAULT '0',
  `FeeTotal` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`FeeDate`),
  KEY `2` (`ProvinceId`),
  KEY `3` (`AreaId`)
) ENGINE=MyISAM AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `tj_d_asdownload`;
CREATE TABLE `tj_d_asdownload` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `DldDate` date DEFAULT '0000-00-00',
  `DldHour` int(11) DEFAULT '0',
  `AppStoreId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `ReqCount` int(11) DEFAULT '0',
  `DldCount` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`DldDate`),
  KEY `2` (`DldHour`),
  KEY `3` (`AppStoreId`),
  KEY `4` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=134 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `tj_d_cpfee`;
CREATE TABLE `tj_d_cpfee` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FeeDate` date DEFAULT '0000-00-00',
  `CPId` int(11) DEFAULT '0',
  `AppId` int(11) DEFAULT '0',
  `FeeCount` int(11) DEFAULT '0',
  `FeeTotal` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`FeeDate`),
  KEY `2` (`CPId`),
  KEY `3` (`AppId`)
) ENGINE=MyISAM AUTO_INCREMENT=33 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `tj_d_mffee`;
CREATE TABLE `tj_d_mffee` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FeeDate` date DEFAULT '0000-00-00',
  `MFId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `UserAgent` varchar(50) DEFAULT '',
  `FeeCount` int(11) DEFAULT '0',
  `FeeTotal` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`FeeDate`),
  KEY `2` (`MFId`),
  KEY `3` (`MobileId`),
  KEY `4` (`UserAgent`)
) ENGINE=MyISAM AUTO_INCREMENT=36 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `tj_d_reguser`;
CREATE TABLE `tj_d_reguser` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `RegDate` date DEFAULT '0000-00-00',
  `RegHour` int(11) DEFAULT '0',
  `ProvinceId` int(11) DEFAULT '0',
  `MobileId` int(11) DEFAULT '0',
  `RegCount` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`RegDate`),
  KEY `2` (`RegHour`),
  KEY `3` (`ProvinceId`),
  KEY `4` (`MobileId`)
) ENGINE=MyISAM AUTO_INCREMENT=355 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `tj_d_spfee`;
CREATE TABLE `tj_d_spfee` (
  `RecId` int(11) NOT NULL AUTO_INCREMENT,
  `FeeDate` date DEFAULT '0000-00-00',
  `FeeHour` int(11) DEFAULT '0',
  `SPId` int(11) DEFAULT '0',
  `FeeId` int(11) DEFAULT '0',
  `FeeCount` int(11) DEFAULT '0',
  `FeeTotal` int(11) DEFAULT '0',
  PRIMARY KEY (`RecId`),
  KEY `1` (`FeeDate`),
  KEY `2` (`FeeHour`),
  KEY `3` (`SPId`),
  KEY `4` (`FeeId`)
) ENGINE=MyISAM AUTO_INCREMENT=118 DEFAULT CHARSET=utf8;
