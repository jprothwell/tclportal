/*
MySQL Data Transfer
Source Host: localhost
Source Database: tcl
Target Host: localhost
Target Database: tcl
Date: 2010-9-10 14:42:58
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for approval
-- ----------------------------
CREATE TABLE `approval` (
  `id` int(8) NOT NULL auto_increment,
  `game` varchar(32) default NULL,
  `content` varchar(100) default NULL,
  `proposer` int(6) default NULL,
  `proTime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `checker` int(6) default NULL,
  `checkInfo` varchar(64) default NULL,
  `checkTime` timestamp NOT NULL default '0000-00-00 00:00:00',
  `finalChecker` int(6) default NULL,
  `finalCheckInfo` varchar(64) default NULL,
  `finalCheckTime` timestamp NOT NULL default '0000-00-00 00:00:00',
  `status` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for changelog
-- ----------------------------
CREATE TABLE `changelog` (
  `id` int(10) NOT NULL auto_increment,
  `gameResourceId` int(8) default NULL,
  `price` decimal(10,0) default NULL,
  `disable` int(2) default NULL,
  `ctime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for city
-- ----------------------------
CREATE TABLE `city` (
  `id` int(8) NOT NULL auto_increment,
  `cityName` varchar(16) default NULL,
  `provinceId` int(6) default NULL,
  `remarker` varchar(32) default NULL,
  `cityCode` varchar(6) default NULL,
  PRIMARY KEY  (`id`),
  KEY `FK_provinceCity` (`provinceId`),
  CONSTRAINT `FK_provinceCity` FOREIGN KEY (`provinceId`) REFERENCES `province` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for comment
-- ----------------------------
CREATE TABLE `comment` (
  `id` int(12) NOT NULL auto_increment,
  `mobileUserId` int(10) default NULL,
  `gameId` int(8) default NULL,
  `content` varchar(100) default NULL,
  `ctime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `disable` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for country
-- ----------------------------
CREATE TABLE `country` (
  `id` int(3) NOT NULL auto_increment,
  `shorterForm` varchar(10) default NULL,
  `name` varchar(32) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for customer
-- ----------------------------
CREATE TABLE `customer` (
  `id` int(10) NOT NULL auto_increment,
  `userName` varchar(32) default NULL,
  `password` varchar(32) default NULL,
  `email` varbinary(32) default NULL,
  `mobile` varchar(11) default NULL,
  `ctime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `point` int(10) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for downloadinfo
-- ----------------------------
CREATE TABLE `downloadinfo` (
  `id` int(8) NOT NULL auto_increment,
  `gameId` int(8) default NULL,
  `customerId` int(10) default NULL,
  `ipId` int(6) default NULL,
  `did` varchar(8) default NULL,
  `titleId` int(2) default NULL,
  `location` int(2) default NULL,
  `dtime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `telephone` varchar(16) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for gameinfo
-- ----------------------------
CREATE TABLE `gameinfo` (
  `id` int(8) NOT NULL auto_increment,
  `gameName` varchar(12) NOT NULL,
  `detailInfo` varchar(200) default NULL,
  `kindId` int(2) default NULL,
  `addTime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `spid` int(6) default NULL,
  `imageName` varchar(32) default NULL,
  `language` int(6) default NULL,
  `style` varchar(10) default NULL,
  `disable` int(11) NOT NULL,
  `brief` varchar(100) default NULL,
  `icon` varchar(32) default NULL,
  `lev` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for gameresouce
-- ----------------------------
CREATE TABLE `gameresouce` (
  `id` int(8) NOT NULL auto_increment,
  `gameId` int(8) NOT NULL,
  `provinceId` int(2) NOT NULL,
  `did` varchar(8) NOT NULL,
  `startTime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `jarFile` varchar(100) default NULL,
  `jadFile` varchar(100) default NULL,
  `path` varchar(20) default NULL,
  `priority` int(11) default NULL,
  `typeId` int(11) default NULL,
  `disable` int(11) default NULL,
  `fileName` varchar(100) default NULL,
  `price` decimal(10,0) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for ipinfo
-- ----------------------------
CREATE TABLE `ipinfo` (
  `id` int(6) NOT NULL auto_increment,
  `ip` varchar(20) NOT NULL,
  `proviceId` int(6) default NULL,
  `country` int(6) default NULL,
  `telecomOperators` int(11) default NULL,
  `city` int(6) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for javaparameter
-- ----------------------------
CREATE TABLE `javaparameter` (
  `id` int(3) NOT NULL auto_increment,
  `name` varchar(16) default NULL,
  `value` varchar(16) default NULL,
  `remarker` varchar(64) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for language
-- ----------------------------
CREATE TABLE `language` (
  `id` int(3) NOT NULL auto_increment,
  `language` varchar(8) default NULL,
  `remarker` varchar(32) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for locationpage
-- ----------------------------
CREATE TABLE `locationpage` (
  `id` int(3) NOT NULL auto_increment,
  `localName` varchar(16) default NULL,
  `local` varchar(3) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for logs
-- ----------------------------
CREATE TABLE `logs` (
  `id` int(12) NOT NULL auto_increment,
  `userId` int(6) default NULL,
  `doSomthing` varchar(32) default NULL,
  `ltime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for mobileinfo
-- ----------------------------
CREATE TABLE `mobileinfo` (
  `did` varchar(8) NOT NULL,
  `phoneType` varchar(20) NOT NULL,
  `screen` varchar(10) default NULL,
  `ua` varchar(100) NOT NULL,
  `wap` int(11) default NULL,
  `pageid` int(11) default NULL,
  `type` int(11) default NULL,
  `javaParameter` varchar(64) default NULL,
  `reserve1` varchar(64) default NULL,
  `reserve2` varchar(64) default NULL,
  `mtime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `remark` varchar(64) default NULL,
  PRIMARY KEY  (`did`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for pageinfo
-- ----------------------------
CREATE TABLE `pageinfo` (
  `id` int(6) NOT NULL auto_increment,
  `pagename` varchar(16) default NULL,
  `filename` varchar(32) default NULL,
  `isdefault` int(2) default NULL,
  `remark` varchar(64) default NULL,
  `languageId` int(3) default NULL,
  `pageType` int(2) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for province
-- ----------------------------
CREATE TABLE `province` (
  `id` int(6) NOT NULL,
  `provinceName` varchar(6) NOT NULL,
  `countryId` int(3) NOT NULL,
  PRIMARY KEY  (`id`),
  KEY `FK_countryProvince` (`countryId`),
  CONSTRAINT `FK_countryProvince` FOREIGN KEY (`countryId`) REFERENCES `country` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for resource
-- ----------------------------
CREATE TABLE `resource` (
  `id` int(6) NOT NULL auto_increment,
  `name` varchar(32) default NULL,
  `value` varchar(32) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for role
-- ----------------------------
CREATE TABLE `role` (
  `id` int(4) NOT NULL auto_increment,
  `name` varchar(32) default NULL COMMENT '角色名',
  `description` varchar(255) default NULL COMMENT '角色描述',
  `resources` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for spinfo
-- ----------------------------
CREATE TABLE `spinfo` (
  `id` int(6) NOT NULL auto_increment,
  `name` varchar(32) NOT NULL,
  `address` varchar(60) default NULL,
  `contactPerson` varchar(12) default NULL,
  `phone` varchar(20) default NULL,
  `remark` varchar(100) default NULL,
  `begainTime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `endTime` timestamp NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for telecomoperators
-- ----------------------------
CREATE TABLE `telecomoperators` (
  `id` int(3) NOT NULL auto_increment,
  `name` varchar(16) default NULL,
  `countryId` int(3) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for types
-- ----------------------------
CREATE TABLE `types` (
  `id` int(6) NOT NULL auto_increment,
  `fid` int(6) default NULL,
  `typeValue` varchar(64) default NULL,
  `allowance` varchar(64) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for user
-- ----------------------------
CREATE TABLE `user` (
  `id` int(8) NOT NULL auto_increment,
  `name` varchar(32) default NULL COMMENT '用户名',
  `password` varchar(32) default NULL COMMENT '密码',
  `disabled` int(1) default NULL COMMENT '是否有效',
  `role_id` int(4) default NULL COMMENT '角色id',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for visiteinfo
-- ----------------------------
CREATE TABLE `visiteinfo` (
  `id` int(12) NOT NULL auto_increment,
  `ip` varchar(20) default NULL,
  `telephone` varchar(11) default NULL,
  `did` varchar(8) default NULL,
  `titleId` int(11) default NULL,
  `gameId` int(11) default NULL,
  `location` int(11) default NULL,
  `vtime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `approval` VALUES ('4', '测试', '测试区2', '12', '2010-08-23 17:18:28', '13', '审核', '2010-08-23 17:44:40', '14', '通过', '2010-08-23 17:48:49', '3');
INSERT INTO `approval` VALUES ('5', 'c2', 'ss', '12', '2010-08-24 09:43:29', '13', '不合格', '2010-08-24 10:08:35', '0', null, '2010-08-24 09:43:29', '2');
INSERT INTO `approval` VALUES ('6', 'tcl12提交', '测', '15', '2010-08-24 09:55:57', '0', null, '2010-08-24 09:55:57', '0', null, '2010-08-24 09:55:57', '1');
INSERT INTO `changelog` VALUES ('1', '1', '1', null, '2010-08-10 14:47:19');
INSERT INTO `changelog` VALUES ('2', '1', null, '0', '2010-08-10 14:47:35');
INSERT INTO `changelog` VALUES ('3', '1', '2', null, '2010-08-10 14:48:03');
INSERT INTO `changelog` VALUES ('4', '1', null, '1', '2010-08-10 14:48:03');
INSERT INTO `city` VALUES ('1', '深圳', '0', '', '0755');
INSERT INTO `city` VALUES ('2', '广州', '0', '', '020');
INSERT INTO `city` VALUES ('3', '珠海', '0', '', '0756');
INSERT INTO `comment` VALUES ('11', null, '2', 'ä¸­æä¹±ç ', '2010-09-10 09:32:53', '1');
INSERT INTO `comment` VALUES ('12', null, '2', '中文乱码', '2010-09-10 09:51:59', '1');
INSERT INTO `country` VALUES ('1', 'CN', '中国');
INSERT INTO `country` VALUES ('2', 'US', '美国');
INSERT INTO `customer` VALUES ('1', '1', '1', '1', '1', '2010-08-20 15:12:04', '5');
INSERT INTO `customer` VALUES ('2', 'ceshi', 'c4ca4238a0b923820dcc509a6f75849b', '11@11', '111', '2010-09-07 10:56:43', '0');
INSERT INTO `downloadinfo` VALUES ('1', '1', null, '0', '231', '0', '0', '2010-09-06 19:18:27', null);
INSERT INTO `downloadinfo` VALUES ('2', '1', null, '0', '231', '0', '0', '2010-09-06 19:23:22', null);
INSERT INTO `downloadinfo` VALUES ('3', '1', null, '0', '231', '0', '0', '2010-09-06 19:25:23', null);
INSERT INTO `downloadinfo` VALUES ('4', '1', null, '0', '231', '0', '0', '2010-09-06 19:25:55', null);
INSERT INTO `downloadinfo` VALUES ('5', '1', null, '0', '231', '0', '0', '2010-09-06 19:26:54', null);
INSERT INTO `downloadinfo` VALUES ('6', '1', null, '0', '231', '0', '0', '2010-09-06 19:29:07', null);
INSERT INTO `downloadinfo` VALUES ('7', '1', null, '0', '231', '0', '0', '2010-09-06 19:29:19', null);
INSERT INTO `downloadinfo` VALUES ('8', '1', null, '0', '231', '0', '0', '2010-09-06 19:30:46', null);
INSERT INTO `downloadinfo` VALUES ('9', '1', null, '0', '231', '0', '0', '2010-09-06 19:31:14', null);
INSERT INTO `downloadinfo` VALUES ('10', '1', null, '0', '231', '0', '0', '2010-09-06 19:33:02', null);
INSERT INTO `downloadinfo` VALUES ('11', '1', null, '0', '231', '0', '0', '2010-09-06 19:33:31', null);
INSERT INTO `downloadinfo` VALUES ('12', '1', null, '0', '231', '0', '0', '2010-09-06 19:34:28', null);
INSERT INTO `downloadinfo` VALUES ('13', '1', null, '0', '231', '0', '0', '2010-09-06 19:36:53', null);
INSERT INTO `downloadinfo` VALUES ('14', '2', null, '0', '231', '0', '0', '2010-09-10 10:05:25', null);
INSERT INTO `downloadinfo` VALUES ('15', '1', null, '0', '231', '0', '0', '2010-09-10 13:56:11', null);
INSERT INTO `downloadinfo` VALUES ('16', '1', null, '0', '231', '0', '0', '2010-09-10 13:56:14', null);
INSERT INTO `downloadinfo` VALUES ('17', '1', null, '0', '231', '0', '0', '2010-09-10 13:56:16', null);
INSERT INTO `downloadinfo` VALUES ('18', '1', null, '0', '231', '0', '0', '2010-09-10 13:56:16', null);
INSERT INTO `downloadinfo` VALUES ('19', '2', null, '0', '231', '0', '0', '2010-09-10 13:56:23', null);
INSERT INTO `downloadinfo` VALUES ('20', '2', null, '0', '231', '0', '0', '2010-09-10 13:58:18', null);
INSERT INTO `downloadinfo` VALUES ('21', '2', null, '0', '231', '0', '0', '2010-09-10 13:58:26', null);
INSERT INTO `downloadinfo` VALUES ('22', '1', null, '0', '231', '0', '0', '2010-09-10 14:07:14', null);
INSERT INTO `downloadinfo` VALUES ('23', '1', null, '0', '231', '0', '0', '2010-09-10 14:07:40', null);
INSERT INTO `downloadinfo` VALUES ('24', '1', null, '0', '231', '0', '0', '2010-09-10 14:09:08', null);
INSERT INTO `downloadinfo` VALUES ('25', '1', null, '0', '231', '0', '0', '2010-09-10 14:11:59', null);
INSERT INTO `downloadinfo` VALUES ('26', '1', null, '0', '231', '0', '0', '2010-09-10 14:12:54', null);
INSERT INTO `gameinfo` VALUES ('1', 'QQ2009', 'teset', '1', '2010-08-31 14:16:32', '1', 'd5b8ee7f.jpg', '1', '1', '1', '游戏简介，欢迎使用最新游戏', '171.jpg', '1');
INSERT INTO `gameinfo` VALUES ('2', 'QQ斗地主', 'asdf', '1', '2010-09-06 15:43:53', '1', null, '1', '1', '1', '非常精彩的游戏，请随时关注我们的游戏栏目！', null, '1');
INSERT INTO `gameinfo` VALUES ('3', 'QQ游戏', 'asdfasdf', '2', '2010-08-31 14:17:59', '1', '173.jpg', '1', null, '1', '玩家控制游戏里的主角-斯派罗过关斩将,铲除邪恶,拯救同伴。', '173.jpg', '2');
INSERT INTO `gameinfo` VALUES ('4', '布克阅读', 'asdfasdf', '3', '2010-09-06 15:43:41', '1', null, '1', '', '1', '布克阅读提供时下最新热门影视作品匹配的电子书。', null, '3');
INSERT INTO `gameresouce` VALUES ('1', '1', '0', '231', '2010-08-31 14:25:44', 'lsddz_OT-708_240x320.jar', 'lsddz_OT-708_240x320.jad', '1', '0', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('2', '2', '0', '231', '2010-08-31 14:25:30', 'msnllk_OT-708_240x320.jar', 'msnllk_OT-708_240x320.jad', '1', null, '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('3', '3', '0', '231', '2010-08-31 14:25:31', 'wjsmj_OT-708_240x320.jar', 'wjsmj_OT-708_240x320.jad', '1', null, '2', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('4', '4', '0', '231', '2010-08-31 14:25:31', 'wjsmj_OT-708_240x320.jar', 'wjsmj_OT-708_240x320.jad', '1', null, '3', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('5', '1', '0', '236', '2010-08-31 14:25:32', 'lsddz_OT-708_240x320.jar', 'lsddz_OT-708_240x320.jad', '1', null, '2', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('6', '2', '0', '236', '2010-08-31 14:28:16', 'msnllk_OT-708_240x320.jar', 'msnllk_OT-708_240x320.jad', '1', null, '3', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('7', '3', '0', '236', '2010-09-06 10:39:47', 'wjsmj_OT-708_240x320.jar', 'wjsmj_OT-708_240x320.jad', '1', null, '3', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('8', '4', '0', '236', '2010-08-31 14:28:19', 'wjsmj_OT-708_240x320.jar', 'wjsmj_OT-708_240x320.jad', '1', null, '1', '1', null, '1');
INSERT INTO `ipinfo` VALUES ('1', '100.122.52.56', '0', '1', '1', '1');
INSERT INTO `ipinfo` VALUES ('2', '100.100.20.30', '0', '1', '1', '1');
INSERT INTO `ipinfo` VALUES ('3', '233.122.11.13', '0', '1', '1', '3');
INSERT INTO `ipinfo` VALUES ('4', '192.168.1.3', '0', '1', '1', '1');
INSERT INTO `javaparameter` VALUES ('1', 'JDK', '1.5', '');
INSERT INTO `language` VALUES ('1', '英语', '1');
INSERT INTO `locationpage` VALUES ('1', '1', '12');
INSERT INTO `mobileinfo` VALUES ('231', 'OT-800', '240*320', 'Alcatel-OT-800', '0', '1', '0', '', null, null, '2010-08-27 09:17:57', '');
INSERT INTO `mobileinfo` VALUES ('236', 'OT-708', '240*320', 'Alcatel-OT-708', '1', '2', '0', '1', null, null, '2010-08-31 14:26:45', '1');
INSERT INTO `pageinfo` VALUES ('1', 'wap1.2首页', 'page/wml1/index.jsp', '1', 'user to wap1.2 index', '1', '0');
INSERT INTO `pageinfo` VALUES ('2', 'wap2.0首页', 'page/wml2/index.jsp', '0', 'user to wap2.0 index', '1', '2');
INSERT INTO `pageinfo` VALUES ('3', 'http首页', 'page/wml3/index.jsp', '0', 'user to http index', '1', '0');
INSERT INTO `province` VALUES ('0', '广东', '1');
INSERT INTO `resource` VALUES ('6', '用户信息', '/user.do');
INSERT INTO `resource` VALUES ('7', '角色信息', '/role.do');
INSERT INTO `resource` VALUES ('8', '资源信息', '/resource.do');
INSERT INTO `resource` VALUES ('25', '国家信息', '/country.do');
INSERT INTO `resource` VALUES ('26', '省份信息', '/province.do');
INSERT INTO `resource` VALUES ('27', '城市信息', '/city.do');
INSERT INTO `resource` VALUES ('28', '运营商', '/telecomoperators.do');
INSERT INTO `resource` VALUES ('29', '语言信息', '/language.do');
INSERT INTO `resource` VALUES ('30', 'SP信息', '/spinfo.do');
INSERT INTO `resource` VALUES ('31', 'IP信息', '/ipinfo.do');
INSERT INTO `resource` VALUES ('32', 'java参数', '/javapara.do');
INSERT INTO `resource` VALUES ('33', '手机信息', '/mobileinfo.do');
INSERT INTO `resource` VALUES ('34', '游戏基本信息', '/gameinfo.do');
INSERT INTO `resource` VALUES ('35', '游戏资源信息', '/gameresouce.do');
INSERT INTO `resource` VALUES ('36', '页面信息', '/pageinfo.do');
INSERT INTO `resource` VALUES ('37', '页面位置信息', '/locationpage.do');
INSERT INTO `resource` VALUES ('38', '访问信息', '/visiteinfo.do');
INSERT INTO `resource` VALUES ('39', '下载统计', '/downloadinfo.do');
INSERT INTO `resource` VALUES ('40', '业务变更', '/changelog.do');
INSERT INTO `resource` VALUES ('41', '后台日志', '/logs.do');
INSERT INTO `resource` VALUES ('42', '手机用户', '/customer.do');
INSERT INTO `resource` VALUES ('43', '评论', '/comment.do');
INSERT INTO `resource` VALUES ('44', '审批', '/approval.do');
INSERT INTO `resource` VALUES ('45', '类型信息', '/types.do');
INSERT INTO `role` VALUES ('3', '主管', '审核最高权限', '44:');
INSERT INTO `role` VALUES ('4', 'admin', '管理员角色', '6:7:8:25:26:27:28:29:30:31:32:33:34:35:36:37:38:39:40:41:42:43:44:45:');
INSERT INTO `role` VALUES ('2', '运营', '运营人员', '44:');
INSERT INTO `role` VALUES ('1', '基本', '基本角色', '44:');
INSERT INTO `spinfo` VALUES ('1', 'SP测试', '1', '1', '1', '', '2010-08-04 00:00:00', '2010-08-05 00:00:00');
INSERT INTO `telecomoperators` VALUES ('1', '移动', '1');
INSERT INTO `types` VALUES ('1', '0', '格斗', null);
INSERT INTO `types` VALUES ('2', '0', '棋牌', null);
INSERT INTO `types` VALUES ('3', '0', '手机应用', null);
INSERT INTO `user` VALUES ('15', 'tcl12', 'c4ca4238a0b923820dcc509a6f75849b', '1', '1');
INSERT INTO `user` VALUES ('14', 'tcl3', 'c4ca4238a0b923820dcc509a6f75849b', '1', '3');
INSERT INTO `user` VALUES ('13', 'tcl2', 'c4ca4238a0b923820dcc509a6f75849b', '1', '2');
INSERT INTO `user` VALUES ('12', 'tcl1', 'c4ca4238a0b923820dcc509a6f75849b', '1', '1');
INSERT INTO `user` VALUES ('11', 'shenkun', 'c4ca4238a0b923820dcc509a6f75849b', '1', '4');
INSERT INTO `visiteinfo` VALUES ('1', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 11:18:57');
INSERT INTO `visiteinfo` VALUES ('2', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 11:22:46');
INSERT INTO `visiteinfo` VALUES ('3', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 11:23:14');
INSERT INTO `visiteinfo` VALUES ('4', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 11:27:41');
INSERT INTO `visiteinfo` VALUES ('5', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 13:22:46');
INSERT INTO `visiteinfo` VALUES ('6', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 13:23:28');
INSERT INTO `visiteinfo` VALUES ('7', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 13:36:41');
INSERT INTO `visiteinfo` VALUES ('8', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 13:53:56');
INSERT INTO `visiteinfo` VALUES ('9', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 13:55:08');
INSERT INTO `visiteinfo` VALUES ('10', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 14:43:54');
INSERT INTO `visiteinfo` VALUES ('11', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 15:24:42');
INSERT INTO `visiteinfo` VALUES ('12', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 15:59:46');
INSERT INTO `visiteinfo` VALUES ('13', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 19:15:18');
INSERT INTO `visiteinfo` VALUES ('14', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-06 19:23:19');
INSERT INTO `visiteinfo` VALUES ('15', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-07 10:43:38');
INSERT INTO `visiteinfo` VALUES ('16', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-07 10:56:43');
INSERT INTO `visiteinfo` VALUES ('17', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-07 10:57:35');
INSERT INTO `visiteinfo` VALUES ('18', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-07 18:47:28');
INSERT INTO `visiteinfo` VALUES ('19', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-07 18:47:43');
INSERT INTO `visiteinfo` VALUES ('20', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-10 09:28:26');
INSERT INTO `visiteinfo` VALUES ('21', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:28:28');
INSERT INTO `visiteinfo` VALUES ('22', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:28:34');
INSERT INTO `visiteinfo` VALUES ('23', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:28:55');
INSERT INTO `visiteinfo` VALUES ('24', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:37');
INSERT INTO `visiteinfo` VALUES ('25', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:38');
INSERT INTO `visiteinfo` VALUES ('26', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:38');
INSERT INTO `visiteinfo` VALUES ('27', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:39');
INSERT INTO `visiteinfo` VALUES ('28', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:39');
INSERT INTO `visiteinfo` VALUES ('29', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:40');
INSERT INTO `visiteinfo` VALUES ('30', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:40');
INSERT INTO `visiteinfo` VALUES ('31', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:30:41');
INSERT INTO `visiteinfo` VALUES ('32', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-10 09:32:10');
INSERT INTO `visiteinfo` VALUES ('33', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 09:32:12');
INSERT INTO `visiteinfo` VALUES ('34', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-10 09:32:49');
INSERT INTO `visiteinfo` VALUES ('35', '127.0.0.1', '1380000000', '231', '1', '2', '1', '2010-09-10 09:32:50');
INSERT INTO `visiteinfo` VALUES ('36', '127.0.0.1', '1380000000', '231', '1', '2', '1', '2010-09-10 09:32:53');
INSERT INTO `visiteinfo` VALUES ('37', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-10 09:51:52');
INSERT INTO `visiteinfo` VALUES ('38', '127.0.0.1', '1380000000', '231', '1', '2', '1', '2010-09-10 09:51:53');
INSERT INTO `visiteinfo` VALUES ('39', '127.0.0.1', '1380000000', '231', '1', '2', '1', '2010-09-10 09:51:59');
INSERT INTO `visiteinfo` VALUES ('40', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-10 13:56:06');
INSERT INTO `visiteinfo` VALUES ('41', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 13:56:07');
INSERT INTO `visiteinfo` VALUES ('42', '127.0.0.1', '1380000000', '231', '1', '2', '1', '2010-09-10 13:56:22');
INSERT INTO `visiteinfo` VALUES ('43', '127.0.0.1', '1380000000', '231', '1', '2', '1', '2010-09-10 13:58:16');
INSERT INTO `visiteinfo` VALUES ('44', '127.0.0.1', '1380000000', '231', '0', '0', '0', '2010-09-10 14:07:11');
INSERT INTO `visiteinfo` VALUES ('45', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 14:07:12');
INSERT INTO `visiteinfo` VALUES ('46', '127.0.0.1', '1380000000', '231', '1', '1', '1', '2010-09-10 14:11:58');
