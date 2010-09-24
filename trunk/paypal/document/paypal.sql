/*
MySQL Data Transfer
Source Host: localhost
Source Database: paypal
Target Host: localhost
Target Database: paypal
Date: 2010-10-25 13:41:02
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for business
-- ----------------------------
CREATE TABLE `business` (
  `id` int(12) NOT NULL auto_increment,
  `goodId` int(12) default NULL,
  `buyName` varchar(100) default NULL,
  `buyTime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for gameresource
-- ----------------------------
CREATE TABLE `gameresource` (
  `id` int(11) NOT NULL auto_increment,
  `name` varchar(255) default NULL,
  `images` varchar(255) default '',
  `info` text,
  `file1` varchar(255) default NULL,
  `file2` varchar(255) default NULL,
  `ua` varchar(255) default NULL,
  `spid` int(11) default '0',
  `sdate` timestamp NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `lg` varchar(2) default 'en',
  `kindid` int(4) default '0',
  `typeid` int(2) default '0',
  `rel` tinyint(3) default '1',
  `orderid` int(11) default '100',
  `sizeid` smallint(6) default '1',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for goods
-- ----------------------------
CREATE TABLE `goods` (
  `id` int(12) NOT NULL auto_increment,
  `name` varchar(64) default NULL,
  `price` varchar(16) default NULL,
  `jarName` varchar(64) default NULL,
  `jadName` varchar(64) default NULL,
  `addTime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `business` VALUES ('7', '1', 'tcltcl_1278899860_per@gmail.com', '2010-09-23 11:29:59');
INSERT INTO `business` VALUES ('8', '2', 'tcltcl_1278899860_per@gmail.com', '2010-09-23 11:30:36');
INSERT INTO `business` VALUES ('9', '2', 'tcltcl_1278899860_per@gmail.com', '2010-09-23 14:52:17');
INSERT INTO `business` VALUES ('10', '2', 'tcltcl_1278899860_per@gmail.com', '2010-09-23 15:00:31');
INSERT INTO `business` VALUES ('11', '1', 'tcltcl_1278899860_per@gmail.com', '2010-09-23 18:18:01');
INSERT INTO `gameresource` VALUES ('1', '俄罗斯方块', '', null, '', null, null, '0', '2010-09-23 15:38:29', 'en', '0', '0', '1', '100', '1');
INSERT INTO `goods` VALUES ('1', '打地鼠', '0.01', 'RussGame.jar', 'RussGame.jad', '2010-09-23 14:04:31');
INSERT INTO `goods` VALUES ('2', '俄罗斯方块', '0.01', 'RussGame.jar', 'RussGame.jad', '2010-09-23 14:05:09');
