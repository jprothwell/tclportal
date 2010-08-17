/*
MySQL Data Transfer
Source Host: localhost
Source Database: tcl
Target Host: localhost
Target Database: tcl
Date: 2010-7-28 14:03:10
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
  `price` varchar(6) default NULL,
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
  PRIMARY KEY  (`id`)
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
  `ctime` timestamp NOT NULL default CURRENT_TIMESTAMP,
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
  `ua` varchar(10) default NULL,
  `titleId` int(2) default NULL,
  `location` int(2) default NULL,
  `dtime` timestamp NOT NULL default CURRENT_TIMESTAMP,
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
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for ipinfo
-- ----------------------------
CREATE TABLE `ipinfo` (
  `id` int(6) NOT NULL auto_increment,
  `ip` varchar(20) NOT NULL,
  `proviceId` int(6) default NULL,
  `country` varchar(6) default NULL,
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
  `id` int(8) NOT NULL auto_increment,
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
  `mtime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `remark` varchar(64) default NULL,
  PRIMARY KEY  (`id`)
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
  `id` int(6) NOT NULL auto_increment,
  `provinceName` varchar(6) NOT NULL,
  `countryId` int(3) NOT NULL,
  PRIMARY KEY  (`id`)
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
  `id` int(6) NOT NULL auto_increment,
  `roleName` varchar(32) default NULL,
  `description` varchar(100) default NULL,
  `resource` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
  `id` int(6) NOT NULL auto_increment,
  `userName` varchar(20) default NULL,
  `password` varchar(32) default NULL,
  `roleId` int(2) default NULL,
  `addTime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for visiteinfo
-- ----------------------------
CREATE TABLE `visiteinfo` (
  `id` int(12) NOT NULL,
  `ip` varchar(20) default NULL,
  `telephone` varchar(11) default NULL,
  `ua` varchar(10) default NULL,
  `titleId` int(11) default NULL,
  `gameId` int(11) default NULL,
  `location` int(11) default NULL,
  `vtime` timestamp NOT NULL default CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
