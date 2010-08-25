/*
MySQL Data Transfer
Source Host: localhost
Source Database: tcl
Target Host: localhost
Target Database: tcl
Date: 2010-8-25 17:58:23
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
  `id` int(12) NOT NULL,
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
INSERT INTO `country` VALUES ('1', 'CN', '中国');
INSERT INTO `country` VALUES ('2', 'US', '美国');
INSERT INTO `customer` VALUES ('1', '1', '1', '1', '1', '2010-08-20 15:12:04', '5');
INSERT INTO `gameresouce` VALUES ('1', '1', '0', '231', '2010-08-25 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `ipinfo` VALUES ('1', '100.122.52.56', '0', '1', '1', '1');
INSERT INTO `ipinfo` VALUES ('2', '100.100.20.30', '0', '1', '1', '1');
INSERT INTO `ipinfo` VALUES ('3', '233.122.11.13', '0', '1', '1', '3');
INSERT INTO `ipinfo` VALUES ('4', '192.168.1.3', '0', '1', '1', '1');
INSERT INTO `javaparameter` VALUES ('1', 'JDK', '1.5', '');
INSERT INTO `language` VALUES ('1', '英语', '1');
INSERT INTO `locationpage` VALUES ('1', '1', '12');
INSERT INTO `mobileinfo` VALUES ('001', '1', '1', '1', '1', '1', '0', '1', null, null, '2010-08-17 00:00:00', '1');
INSERT INTO `mobileinfo` VALUES ('231', 'OT-800', '240*320', 'Alcatel-OT-800', '0', '2', '0', '', null, null, '2010-08-24 00:00:00', '');
INSERT INTO `pageinfo` VALUES ('1', '测试', 'd:/pathTest\\11.txt', '1', '', '1', '0');
INSERT INTO `pageinfo` VALUES ('2', 'ceshi ', 'Android.doc', '0', '', '1', '2');
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
INSERT INTO `user` VALUES ('15', 'tcl12', 'c4ca4238a0b923820dcc509a6f75849b', '1', '1');
INSERT INTO `user` VALUES ('14', 'tcl3', 'c4ca4238a0b923820dcc509a6f75849b', '1', '3');
INSERT INTO `user` VALUES ('13', 'tcl2', 'c4ca4238a0b923820dcc509a6f75849b', '1', '2');
INSERT INTO `user` VALUES ('12', 'tcl1', 'c4ca4238a0b923820dcc509a6f75849b', '1', '1');
INSERT INTO `user` VALUES ('11', 'shenkun', 'c4ca4238a0b923820dcc509a6f75849b', '1', '4');
