DROP DATABASE IF EXISTS `db_gm`;
CREATE DATABASE IF NOT EXISTS `db_gm`;


DROP DATABASE IF EXISTS `db_log`;
CREATE DATABASE IF NOT EXISTS `db_log` ;


DROP DATABASE IF EXISTS `db_game`;
CREATE DATABASE IF NOT EXISTS `db_game` ;


DROP DATABASE IF EXISTS `db_account`;
CREATE DATABASE IF NOT EXISTS `db_account` ;

use db_account;
-- ----------------------------
-- Table structure for account
-- ----------------------------
DROP TABLE IF EXISTS `account`;
CREATE TABLE `account` (
  `id` bigint(20) NOT NULL,
  `name` char(255) NOT NULL DEFAULT '0' ,
  `password` char(20) NOT NULL DEFAULT '0' ,
  `lastsvrid1` int(11) NOT NULL DEFAULT 0,
  `lastsvrid2` int(11) NULL DEFAULT NULL,
  `channel` int(11) NOT NULL DEFAULT 0,
  `logincount` int(11) unsigned NOT NULL DEFAULT '0' ,
  `create_time` datetime(0) NOT NULL,
  `seal_end_time` datetime(0) NOT NULL,
  `seal_describle` varchar(255) DEFAULT '' ,
  PRIMARY KEY (`id`),
  KEY `id` (`id`) USING BTREE,
  KEY `name` (`name`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ;

use db_game;
-- ----------------------------
-- Table structure for activity
-- ----------------------------
DROP TABLE IF EXISTS `activity`;
CREATE TABLE `activity`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL,
  `roleid` bigint(255) NOT NULL,
  `join_time` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `data_len` int(11) NOT NULL,
  `data` blob NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bag
-- ----------------------------
DROP TABLE IF EXISTS `bag`;
CREATE TABLE `bag`  (
  `guid` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `itemguid` bigint(20) NULL DEFAULT NULL,
  `itemid` int(11) NULL DEFAULT NULL,
  `count` bigint(11) NULL DEFAULT NULL,
  `status` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`guid`, `roleid`) USING BTREE,
  UNIQUE INDEX `index_guid`(`guid`) USING BTREE,
  INDEX `index_roleid`(`roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for chapter
-- ----------------------------
DROP TABLE IF EXISTS `chapter`;
CREATE TABLE `chapter`  (
  `chapterid` int(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `staraward` int(11) NULL DEFAULT NULL,
  `sceneaward` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`chapterid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for copy
-- ----------------------------
DROP TABLE IF EXISTS `copy`;
CREATE TABLE `copy`  (
  `copyid` int(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `star` int(11) NULL DEFAULT NULL,
  `battlecnt` int(11) NULL DEFAULT NULL,
  `resetcnt` int(11) NULL DEFAULT NULL,
  `battletime` bigint(20) NULL DEFAULT NULL,
  `resettime` bigint(20) NULL DEFAULT NULL,
  PRIMARY KEY (`copyid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for counter
-- ----------------------------
DROP TABLE IF EXISTS `counter`;
CREATE TABLE `counter`  (
  `id` int(11) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `cindex` int(11) NOT NULL,
  `time` bigint(20) NULL DEFAULT NULL,
  `value` bigint(20) NULL DEFAULT NULL,
  PRIMARY KEY (`id`, `roleid`, `cindex`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for equip
-- ----------------------------
DROP TABLE IF EXISTS `equip`;
CREATE TABLE `equip`  (
  `guid` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `equipid` int(11) NULL DEFAULT NULL,
  `isuse` int(11) NULL DEFAULT NULL,
  `strengthlvl` int(11) NULL DEFAULT NULL,
  `refinelvl` int(11) NULL DEFAULT NULL,
  `starlvl` int(11) NULL DEFAULT NULL,
  `status` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`guid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for gem
-- ----------------------------
DROP TABLE IF EXISTS `gem`;
CREATE TABLE `gem`  (
  `guid` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `gemid` int(11) NULL DEFAULT NULL,
  `pos` int(11) NULL DEFAULT NULL,
  `strengthlvl` int(11) NULL DEFAULT NULL,
  `refinelvl` int(11) NULL DEFAULT NULL,
  `starlvl` int(11) NULL DEFAULT NULL,
  `status` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`guid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for globaldata
-- ----------------------------
DROP TABLE IF EXISTS `globaldata`;
CREATE TABLE `globaldata`  (
  `serverid` int(11) NOT NULL,
  `maxguid` bigint(20) NULL DEFAULT NULL,
  `maxonline` int(11) NULL DEFAULT NULL,
  `extradata` tinyblob NULL,
  PRIMARY KEY (`serverid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for guild
-- ----------------------------
DROP TABLE IF EXISTS `guild`;
CREATE TABLE `guild`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` char(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `level` int(11) NOT NULL,
  `notice` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `exp` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for guild_member
-- ----------------------------
DROP TABLE IF EXISTS `guild_member`;
CREATE TABLE `guild_member`  (
  `guildid` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Auto-increment ID',
  `roleid` bigint(20) NOT NULL,
  `join_time` bigint(20) NOT NULL,
  `pose` int(11) NOT NULL,
  PRIMARY KEY (`guildid`) USING BTREE,
  INDEX `role_id_gang_role_idx`(`roleid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mail
-- ----------------------------
DROP TABLE IF EXISTS `mail`;
CREATE TABLE `mail`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `groupid` bigint(20) NULL DEFAULT NULL COMMENT 'Group mail GUID',
  `roleid` bigint(20) NOT NULL,
  `mailtype` int(11) NULL DEFAULT NULL COMMENT 'Mail type',
  `mailstatus` int(255) NULL DEFAULT NULL COMMENT 'Mail status',
  `senderid` bigint(20) NOT NULL,
  `sendername` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `mail_time` bigint(20) NOT NULL,
  `title` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `content` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `itemdata` tinyblob NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mail_group
-- ----------------------------
DROP TABLE IF EXISTS `mail_group`;
CREATE TABLE `mail_group`  (
  `id` bigint(20) NOT NULL,
  `mail_time` bigint(20) NOT NULL,
  `mailtype` int(11) NULL DEFAULT NULL,
  `channel` int(11) NULL DEFAULT NULL,
  `title` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `content` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sender` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `itemdata` tinyblob NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mount
-- ----------------------------
DROP TABLE IF EXISTS `mount`;
CREATE TABLE `mount`  (
  `guid` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `mountid` int(11) NULL DEFAULT NULL,
  `isuse` int(11) NULL DEFAULT NULL,
  `strengthlvl` int(11) NULL DEFAULT NULL,
  `refinelvl` int(11) NULL DEFAULT NULL,
  `starlvl` int(11) NULL DEFAULT NULL,
  `status` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`guid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for partner
-- ----------------------------
DROP TABLE IF EXISTS `partner`;
CREATE TABLE `partner`  (
  `guid` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `partnerid` int(11) NULL DEFAULT NULL,
  `setpos` int(11) NULL DEFAULT NULL,
  `strengthlvl` int(11) NULL DEFAULT NULL,
  `refinelvl` int(11) NULL DEFAULT NULL,
  `starlvl` int(11) NULL DEFAULT NULL,
  `status` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`guid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pet
-- ----------------------------
DROP TABLE IF EXISTS `pet`;
CREATE TABLE `pet`  (
  `guid` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `petid` int(11) NULL DEFAULT NULL,
  `isuse` int(11) NULL DEFAULT NULL,
  `strengthlvl` int(11) NULL DEFAULT NULL,
  `refinelvl` int(11) NULL DEFAULT NULL,
  `starlvl` int(11) NULL DEFAULT NULL,
  `status` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`guid`, `roleid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for player
-- ----------------------------
DROP TABLE IF EXISTS `player`;
CREATE TABLE `player`  (
  `id` bigint(20) NOT NULL,
  `accountid` bigint(20) NULL DEFAULT NULL,
  `name` varchar(256) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `carrerid` int(11) NULL DEFAULT NULL,
  `level` int(11) NULL DEFAULT NULL,
  `exp` bigint(20) NULL DEFAULT NULL,
  `langid` int(11) NULL DEFAULT NULL,
  `viplevel` int(11) NULL DEFAULT NULL,
  `vipexp` int(11) NULL DEFAULT NULL,
  `citycopyid` int(11) NULL DEFAULT NULL,
  `action1` bigint(20) NULL DEFAULT NULL,
  `action2` bigint(20) NULL DEFAULT NULL,
  `action3` bigint(20) NULL DEFAULT NULL,
  `action4` bigint(20) NULL DEFAULT NULL,
  `actime1` bigint(20) NULL DEFAULT NULL,
  `actime2` bigint(20) NULL DEFAULT NULL,
  `actime3` bigint(20) NULL DEFAULT NULL,
  `actime4` bigint(20) NULL DEFAULT NULL,
  `fightvalue` bigint(20) NULL DEFAULT NULL,
  `isdelete` int(11) NOT NULL DEFAULT 0 COMMENT 'Delete flag',
  `createtime` bigint(20) NULL DEFAULT NULL,
  `logontime` bigint(20) NULL DEFAULT NULL,
  `logofftime` bigint(20) NULL DEFAULT NULL,
  `grouptime` bigint(20) NULL DEFAULT NULL,
  `guildid` bigint(20) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for relationship
-- ----------------------------
DROP TABLE IF EXISTS `relationship`;
CREATE TABLE `relationship`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `other_id` char(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `ship_type` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for skill
-- ----------------------------
DROP TABLE IF EXISTS `skill`;
CREATE TABLE `skill`  (
  `id` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `level` int(20) NOT NULL,
  `key_pos` int(255) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for task
-- ----------------------------
DROP TABLE IF EXISTS `task`;
CREATE TABLE `task`  (
  `id` bigint(20) NOT NULL,
  `roleid` bigint(20) NOT NULL,
  `task_status` int(11) NOT NULL,
  `progress` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

use db_log;

-- ----------------------------
-- Table structure for accountcreate
-- ----------------------------
DROP TABLE IF EXISTS `account_create`;
CREATE TABLE `account_create`  (
  `accountid` bigint(22) NOT NULL COMMENT 'Account',
  `version` int(11) NULL DEFAULT NULL,
  `channel` int(11) NULL DEFAULT NULL COMMENT 'Platform ID',
  `optime` datetime(0) NOT NULL COMMENT 'Account creation time',
  `imodel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Device model',
  `imei` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `ip` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `openid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `idfa` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `uuid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  INDEX `operation_time_index`(`optime`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for account_login
-- ----------------------------
DROP TABLE IF EXISTS `account_login`;
CREATE TABLE `account_login`  (
  `accountid` bigint(20) NOT NULL COMMENT 'Account ID',
  `channel` int(11) NULL DEFAULT NULL COMMENT 'Platform ID',
  `version` int(11) NULL DEFAULT NULL COMMENT 'Version ID',
  `optime` datetime(0) NOT NULL COMMENT 'Logout time',
  `ip` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Login IP',
  `openid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `uuid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Login device UUID',
  `idfa` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imei` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imodel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for role_chat
-- ----------------------------
DROP TABLE IF EXISTS `role_chat`;
CREATE TABLE `role_chat`  (
  `roleid` bigint(20) NULL DEFAULT NULL,
  `level` int(11) NULL DEFAULT NULL,
  `rolename` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `viplevel` int(11) NULL DEFAULT NULL,
  `areaid` int(11) NULL DEFAULT NULL,
  `channel` int(11) NULL DEFAULT NULL,
  `text` varchar(256) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `optime` datetime(0) NULL DEFAULT NULL,
  `targetid` bigint(20) NULL DEFAULT NULL,
  `targetvip` int(11) NULL DEFAULT NULL,
  `targetname` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `chatchl` int(11) NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for role_create
-- ----------------------------
DROP TABLE IF EXISTS `role_create`;
CREATE TABLE `role_create`  (
  `roleid` bigint(22) NOT NULL,
  `accountid` bigint(22) NOT NULL COMMENT 'Account',
  `areaid` int(11) NULL DEFAULT NULL,
  `channel` int(11) NULL DEFAULT NULL COMMENT 'Platform ID',
  `optime` datetime(0) NOT NULL COMMENT 'Account creation time',
  `rolename` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imodel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Device model',
  `imei` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `idfa` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `uuid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  INDEX `operation_time_index`(`optime`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for role_login
-- ----------------------------
DROP TABLE IF EXISTS `role_login`;
CREATE TABLE `role_login`  (
  `roleid` bigint(20) NOT NULL,
  `accountid` bigint(20) NOT NULL COMMENT 'Account ID',
  `channel` int(11) NULL DEFAULT NULL COMMENT 'Platform ID',
  `level` int(11) NULL DEFAULT NULL COMMENT 'Level',
  `viplevel` int(11) NULL DEFAULT NULL COMMENT 'VIP level',
  `optime` datetime(0) NOT NULL COMMENT 'Logout time',
  `areaid` int(11) NULL DEFAULT NULL COMMENT 'Server ID',
  `rolename` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `uuid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Login device UUID',
  `idfa` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imei` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imodel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for role_logout
-- ----------------------------
DROP TABLE IF EXISTS `role_logout`;
CREATE TABLE `role_logout`  (
  `roleid` bigint(20) NOT NULL,
  `accountid` bigint(20) NOT NULL COMMENT 'Account ID',
  `channel` int(11) NULL DEFAULT NULL COMMENT 'Platform ID',
  `level` int(11) NULL DEFAULT NULL COMMENT 'Level',
  `viplevel` int(11) NULL DEFAULT NULL COMMENT 'VIP level',
  `optime` datetime(0) NOT NULL COMMENT 'Logout time',
  `areaid` int(11) NULL DEFAULT NULL COMMENT 'Server ID',
  `rolename` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `createtime` datetime(0) NULL DEFAULT NULL,
  `idfa` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imei` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `imodel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

use db_gm;
-- ----------------------------
-- Table structure for admin_config
-- ----------------------------
DROP TABLE IF EXISTS `admin_config`;
CREATE TABLE `admin_config`  (
  `name` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT 'Configuration name',
  `content` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Configuration content',
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'Configuration information table' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for admin_log
-- ----------------------------
DROP TABLE IF EXISTS `admin_log`;
CREATE TABLE `admin_log`  (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT 'Administrator name',
  `url` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `modulename` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT 'Module name',
  `extramsg` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Additional information',
  `content` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Content',
  `createtime` datetime(0) NOT NULL COMMENT 'Operation time',
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `name`(`username`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'Administrator operation log table' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for admin_role
-- ----------------------------
DROP TABLE IF EXISTS `admin_role`;
CREATE TABLE `admin_role`  (
  `id` varchar(36) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Primary key',
  `father_id` varchar(36) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' COMMENT 'Permission parent ID',
  `name` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Role name',
  `rank` int(10) NOT NULL DEFAULT 0 COMMENT 'Role permission level',
  `permission` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Role permissions',
  `createtime` int(10) NOT NULL COMMENT 'Role creation time',
  `modifytime` int(10) NOT NULL COMMENT 'Role modification time',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'Role table' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admin_role
-- ----------------------------
INSERT INTO `admin_role` VALUES ('43163187-f63f-409a-807c-7723d5919b62', 'Please select', 'Super administrator', 100, 'a:3:{s:9:\"allow_uri\";a:1:{i:0;s:0:\"\";}s:8:\"deny_uri\";a:1:{i:0;s:0:\"\";}s:5:\"admin\";a:16:{i:0;s:7:\"general\";s:7:\"general\";a:3:{i:0;s:4:\"main\";i:1;s:6:\"config\";s:6:\"config\";a:3:{i:0;s:5:\"index\";i:1;s:4:\"edit\";i:2;s:7:\"restore\";}}i:1;s:4:\"role\";s:4:\"role\";a:6:{i:0;s:4:\"role\";s:4:\"role\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:1;s:5:\"admin\";s:5:\"admin\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:2;s:3:\"log\";s:3:\"log\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}}i:2;s:14:\"datastatistics\";i:3;s:4:\"area\";s:4:\"area\";a:4:{i:0;s:4:\"area\";s:4:\"area\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:1;s:8:\"realtime\";s:8:\"realtime\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}}i:4;s:4:\"seal\";s:4:\"seal\";a:13:{i:0;s:15:\"sealaccountlist\";s:15:\"sealaccountlist\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:1;s:10:\"sealplayer\";s:10:\"sealplayer\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:2;s:8:\"sealchat\";s:8:\"sealchat\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:3;s:13:\"passwordreset\";i:4;s:9:\"flashmove\";s:9:\"flashmove\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:5;s:9:\"gmcommand\";s:9:\"gmcommand\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:6;s:13:\"pullrolelevel\";s:13:\"pullrolelevel\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}}i:5;s:8:\"activity\";s:8:\"activity\";a:4:{i:0;s:12:\"activitytime\";s:12:\"activitytime\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:1;s:7:\"giftbag\";s:7:\"giftbag\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}}i:6;s:4:\"mail\";s:4:\"mail\";a:4:{i:0;s:10:\"singlemail\";s:10:\"singlemail\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}i:1;s:9:\"groupmail\";s:9:\"groupmail\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}}i:7;s:9:\"broadcast\";s:9:\"broadcast\";a:2:{i:0;s:15:\"broadcastmamage\";s:15:\"broadcastmamage\";a:4:{i:0;s:5:\"index\";i:1;s:3:\"add\";i:2;s:4:\"edit\";i:3;s:3:\"del\";}}i:8;s:6:\"notice\";}}', 1389364254, 1522668025);

-- ----------------------------
-- Table structure for admin_user
-- ----------------------------
DROP TABLE IF EXISTS `admin_user`;
CREATE TABLE `admin_user`  (
  `id` varchar(36) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `role_id` varchar(36) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0',
  `username` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Username',
  `password` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Password',
  `sex` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 COMMENT 'Gender',
  `createtime` int(10) NOT NULL DEFAULT 0 COMMENT 'Creation time',
  `logintime` int(10) NOT NULL DEFAULT 0 COMMENT 'Join time',
  `loginfailure` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 COMMENT 'Login failure count',
  `sessionid` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `pagesize` int(10) UNSIGNED NOT NULL DEFAULT 20 COMMENT 'Page size',
  `searchbar` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 COMMENT 'Whether to display search bar',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'Administrator table' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admin_user
-- ----------------------------
INSERT INTO `admin_user` VALUES ('b21e146e-37f0-4d97-89f9-4686ea46b70f', '43163187-f63f-409a-807c-7723d5919b62', 'admin', '21232f297a57a5a743894a0e4a801fc3', 0, 1419316797, 1572058131, 0, 'nbboa27pncmg3upna0egjjcme2', 20, 0);
-- ----------------------------
-- Table structure for gm_command
-- ----------------------------
DROP TABLE IF EXISTS `gm_command`;
CREATE TABLE `gm_command`  (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `area_host` char(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `area_name` char(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `role_name` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `gm_command` char(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `insert_time` datetime(0) NULL DEFAULT NULL,
  `managername` char(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mail_data
-- ----------------------------
DROP TABLE IF EXISTS `mail_data`;
CREATE TABLE `mail_data`  (
  `autoid` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Identification ID',
  `area_host` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT 'Area number',
  `type` int(1) NULL DEFAULT NULL COMMENT '0 for single send, 1 for group send',
  `reciver_name` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Player name',
  `mail_title` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Mail title',
  `keep_time` int(3) NULL DEFAULT NULL COMMENT 'Client save time',
  `mail_content` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT 'Mail content',
  `itemid1` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 1',
  `itemid2` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 2',
  `itemid3` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 3',
  `itemid4` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 4',
  `reciver_group` int(1) NULL DEFAULT NULL COMMENT '0 for all players in the area, 1 for guild',
  `group_name` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Team name',
  `insert_time` datetime(0) NULL DEFAULT NULL COMMENT 'Add time',
  `receiver_id` bigint(20) NULL DEFAULT 0,
  `reason` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sendmanager` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `language` int(11) NOT NULL DEFAULT 0,
  `sendtime` datetime(0) NULL DEFAULT NULL,
  `sendstatus` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`autoid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mail_data_backup
-- ----------------------------
DROP TABLE IF EXISTS `mail_data_backup`;
CREATE TABLE `mail_data_backup`  (
  `autoid` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Identification ID',
  `area_host` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT 'Area number',
  `type` int(1) NULL DEFAULT NULL COMMENT '0 for single send, 1 for group send',
  `reciver_name` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Player name',
  `mail_title` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Mail title',
  `keep_time` int(3) NULL DEFAULT NULL COMMENT 'Client save time',
  `mail_content` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT 'Mail content',
  `itemid1` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 1',
  `itemid2` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 2',
  `itemid3` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 3',
  `itemid4` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Attachment 4',
  `reciver_group` int(1) NULL DEFAULT NULL COMMENT '0 for all players in the area, 1 for guild',
  `group_name` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Team name',
  `insert_time` datetime(0) NULL DEFAULT NULL COMMENT 'Add time',
  `receiver_id` bigint(20) NULL DEFAULT NULL,
  `reason` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sendmanager` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `language` int(11) NOT NULL DEFAULT 0,
  `sendtime` datetime(0) NULL DEFAULT NULL,
  `sendstatus` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`autoid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for review_client
-- ----------------------------
DROP TABLE IF EXISTS `review_client`;
CREATE TABLE `review_client`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `client_version` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `client_ip` varchar(4096) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for seal_account
-- ----------------------------
DROP TABLE IF EXISTS `seal_account`;
CREATE TABLE `seal_account`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `accountid` bigint(11) NULL DEFAULT NULL,
  `accountname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `accounttime` bigint(20) NULL DEFAULT NULL,
  `areaid` int(11) NULL DEFAULT NULL COMMENT 'Area number',
  `rolename` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Role name',
  `sealendtime` bigint(20) NULL DEFAULT NULL COMMENT 'Ban end time',
  `description` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Description',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for sealplayer
-- ----------------------------
DROP TABLE IF EXISTS `seal_player`;
CREATE TABLE `seal_player`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `areaid` int(11) NULL DEFAULT NULL COMMENT 'Area number',
  `accountid` bigint(50) NULL DEFAULT NULL,
  `roleid` bigint(11) NULL DEFAULT NULL COMMENT 'Role ID',
  `rolename` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `rolelevel` int(11) NULL DEFAULT NULL,
  `sealtype` int(11) NULL DEFAULT NULL COMMENT 'Ban type 1: Login ban 2: Chat ban 3: Trade ban 4: PVP ban',
  `description` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Description',
  `optime` datetime(0) NULL DEFAULT NULL,
  `operator` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sealtime` bigint(20) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for server_db
-- ----------------------------
DROP TABLE IF EXISTS `server_db`;
CREATE TABLE `server_db`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `areanum` int(11) NULL DEFAULT NULL COMMENT 'Area number',
  `areaname` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Area name',
  `dbip` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Database IP',
  `dbtype` int(11) NULL DEFAULT NULL COMMENT 'Database type (0:database 1:dyn 2:type 3:log 4:gm 5:account )',
  `dbname` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '' COMMENT 'Database name',
  `username` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Username',
  `userpwd` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'User password',
  `starttime` bigint(20) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for server_list
-- ----------------------------
DROP TABLE IF EXISTS `server_list`;
CREATE TABLE `server_list`  (
  `id` int(11) NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `outer_ip` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `inner_ip` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `port` int(11) NULL DEFAULT 0,
  `http_port` int(11) NULL DEFAULT NULL,
  `watch_port` int(11) NULL DEFAULT NULL,
  `opentime` bigint(20) NULL DEFAULT 0,
  `corner_mark` int(11) NULL DEFAULT 0,
  `svr_flag` int(11) NULL DEFAULT 0,
  `min_version` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '',
  `max_version` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '',
  `check_chan` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `check_ip` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for server_status
-- ----------------------------
DROP TABLE IF EXISTS `server_status`;
CREATE TABLE `server_status`  (
  `id` int(11) NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `curr_online` int(11) NULL DEFAULT NULL,
  `max_online` int(11) NULL DEFAULT 0,
  `total_cnt` int(11) NULL DEFAULT 0,
  `cache_cnt` int(11) NULL DEFAULT NULL COMMENT 'Cached number of people',
  `dberr_cnt` int(11) NULL DEFAULT NULL COMMENT 'Database write failure count',
  `update_time` bigint(11) NULL DEFAULT 0,
  `status` int(11) NULL DEFAULT 0,
  `file_version` int(11) NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;



