drop table if exists approval;

drop table if exists changeLog;

drop table if exists city;

drop table if exists comment;



drop table if exists customer;

drop table if exists downloadInfo;
drop table if exists gameResouce;
drop table if exists gameInfo;



drop table if exists ipInfo;

drop table if exists javaParameter;

drop table if exists language;

drop table if exists locationPage;

drop table if exists logs;

drop table if exists mobileInfo;

drop table if exists pageInfo;

drop table if exists province;

drop table if exists resource;

drop table if exists role;

drop table if exists spInfo;

drop table if exists telecomOperators;

drop table if exists user;

drop table if exists visiteInfo;

drop table if exists country;

/*
MySQL Data Transfer
Source Host: localhost
Source Database: tcl
Target Host: localhost
Target Database: tcl
Date: 2010-8-18 15:40:22
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
  `type` int(2) default NULL,
  `addTime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `spid` int(6) default NULL,
  `imageName` varchar(32) default NULL,
  `language` varchar(10) default NULL,
  `style` varchar(10) default NULL,
  `disable` int(11) NOT NULL,
  `brief` varchar(100) default NULL,
  `icon` varchar(32) default NULL,
  `level` int(11) default NULL,
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
  `resource` varchar(20) default NULL,
  `resource2` varchar(20) default NULL,
  `path` varchar(20) default NULL,
  `priority` int(11) default NULL,
  `type` int(11) default NULL,
  `disable` int(11) default NULL,
  `fileName` varchar(20) default NULL,
  `price` decimal(10,0) default NULL,
  PRIMARY KEY  (`id`),
  KEY `FK_Reference_game` (`gameId`),
  CONSTRAINT `FK_Reference_game` FOREIGN KEY (`gameId`) REFERENCES `gameinfo` (`id`)
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
  `ua` varchar(10) NOT NULL,
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
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

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
-- Table structure for user
-- ----------------------------
CREATE TABLE `user` (
  `id` int(8) NOT NULL auto_increment,
  `name` varchar(32) default NULL COMMENT '用户名',
  `password` varchar(32) default NULL COMMENT '密码',
  `disabled` int(1) default NULL COMMENT '是否有效',
  `role_id` int(4) default NULL COMMENT '角色id',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

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
INSERT INTO `changelog` VALUES ('1', '1', '1', null, '2010-08-10 14:47:19');
INSERT INTO `changelog` VALUES ('2', '1', null, '0', '2010-08-10 14:47:35');
INSERT INTO `changelog` VALUES ('3', '1', '2', null, '2010-08-10 14:48:03');
INSERT INTO `changelog` VALUES ('4', '1', null, '1', '2010-08-10 14:48:03');
INSERT INTO `city` VALUES ('1', '深圳', '0', '', '0755');
INSERT INTO `city` VALUES ('2', '广州', '0', '', '020');
INSERT INTO `city` VALUES ('3', '珠海', '0', '', '0756');
INSERT INTO `country` VALUES ('1', 'CN', '中国');
INSERT INTO `country` VALUES ('2', 'US', '美国');
INSERT INTO `gameinfo` VALUES ('1', '测试游戏', '1', '1', '2010-08-04 00:00:00', '1', '1', '1', '1', '1', '1', '1', '2');
INSERT INTO `gameinfo` VALUES ('2', '打地鼠', '1', '1', '2010-08-09 00:00:00', '1', '1', '1', '1', '1', '1', '1', '1');
INSERT INTO `gameinfo` VALUES ('3', '俄罗斯方块', '1', '1', '2010-08-09 00:00:00', '1', '1', '1', '1', '0', '1', '1', '1');
INSERT INTO `gameresouce` VALUES ('1', '3', '0', '1', '2010-08-10 00:00:00', null, null, '1', '1', '1', '1', null, '2');
INSERT INTO `gameresouce` VALUES ('2', '3', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('3', '3', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('4', '3', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('5', '3', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('6', '3', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('7', '3', '0', '1', '2010-08-16 00:00:00', null, null, '2', '2', '2', '1', null, '2');
INSERT INTO `gameresouce` VALUES ('8', '3', '0', '1', '2010-08-16 00:00:00', null, null, '3', '3', '3', '1', null, '3');
INSERT INTO `gameresouce` VALUES ('9', '3', '0', '1', '2010-08-16 00:00:00', null, null, '6', '6', '6', '1', null, '6');
INSERT INTO `gameresouce` VALUES ('10', '2', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('11', '2', '0', '1', '2010-08-16 00:00:00', null, null, '2', '2', '2', '1', null, '2');
INSERT INTO `gameresouce` VALUES ('12', '1', '0', '1', '2010-08-16 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('13', '2', '0', '1', '2010-08-16 00:00:00', null, null, '2', '2', '2', '1', null, '2');
INSERT INTO `gameresouce` VALUES ('14', '3', '0', '1', '2010-08-16 00:00:00', null, null, 'd:\\pathTest', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('15', '1', '0', '001', '2010-08-18 00:00:00', null, null, '1', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('16', '2', '0', '001', '2010-08-18 00:00:00', null, null, 'd:\\pathTest', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('17', '2', '0', '001', '2010-08-18 00:00:00', null, null, 'd:\\pathTest', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('18', '2', '0', '001', '2010-08-18 00:00:00', null, null, 'd:\\pathTest', '1', '1', '1', null, '1');
INSERT INTO `gameresouce` VALUES ('19', '3', '0', '001', '2010-08-18 00:00:00', null, null, 'd:\\pathTest', '1', '1', '1', 'main_01.gif', '1');
INSERT INTO `ipinfo` VALUES ('1', '100.122.52.56', '0', '1', '1', '1');
INSERT INTO `ipinfo` VALUES ('2', '100.100.20.30', '0', '1', '1', '1');
INSERT INTO `ipinfo` VALUES ('3', '233.122.11.13', '0', '1', '1', '3');
INSERT INTO `ipinfo` VALUES ('4', '192.168.1.3', '0', '1', '1', '1');
INSERT INTO `javaparameter` VALUES ('1', 'JDK', '1.5', '');
INSERT INTO `language` VALUES ('1', '英语', '1');
INSERT INTO `locationpage` VALUES ('1', '1', '12');
INSERT INTO `mobileinfo` VALUES ('001', '1', '1', '1', '1', '1', '0', '1', null, null, '2010-08-17 00:00:00', '1');
INSERT INTO `pageinfo` VALUES ('1', '1', '1', '1', '2', '1');
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
INSERT INTO `role` VALUES ('4', '运营', '运营角色', '11:12:13:14:15:16:17:18:19:20:21:22:');
INSERT INTO `role` VALUES ('3', 'admin', '管理员角色', '6:7:8:25:26:27:28:29:30:31:32:33:34:35:36:37:38:39:40:41:42:43:');
INSERT INTO `role` VALUES ('5', '测试', '测试', '5:9:10:11:12:13:16:19:20:21:23:24:');
INSERT INTO `role` VALUES ('6', '基本', '基本角色', '5:9:10:');
INSERT INTO `spinfo` VALUES ('1', 'SP测试', '1', '1', '1', '', '2010-08-04 00:00:00', '2010-08-05 00:00:00');
INSERT INTO `telecomoperators` VALUES ('1', '移动', '1');
INSERT INTO `user` VALUES ('11', 'shenkun', 'c4ca4238a0b923820dcc509a6f75849b', '1', '3');
