Game Engine Frame
===============
A cross-platform multi-process game server framework, with the network layer implemented using SocketApi, Boost Asio, and Libuv respectively. 
The framework uses shared memory, lock-free queues, object pools, and memory pools to improve server performance.

There is also a continuously improving Demo client, the game includes a large number of complete resources, mounts, pets, companions, equipment, all of which can be equipped and worn, and can enter dungeon battles, multiplayer gameplay is also implemented,
Demo client address:https://github.com/ylmbtm/DemoClient

#### Server Deployment and Startup Instructions
 ##### 1. Compilation
	Windows: Use Visual Studio 2017 or above to open the solution and compile directly.
	Linux: Execute the buildall.sh script to compile.  
##### 2. Install MySQL
	Install MySQL database on the machine, recommended version MySQL 5.7. After installation, if you don't want to change the configuration file, create a user root with password 123456 (the configuration file defaults to this).
	Then find the db_create.sql file in the project and execute it in the database to create the database tables.
##### 3. Start the server
	After completing the above two steps, in the \Server directory there is a StartServer.bat file, execute the bat file, then follow the prompts.

#### Server Role Description
	Login Server (LoginServer) Description: Accepts player login connections, processes login request messages.
	Account Server (AccountServer) Description: Handles account login verification, creation of new accounts, database saving of accounts.
	Center Server (CenterServer) Description: Used for cross-server activities, cross-server battle requirements.
	Logic Server (LogicServer) Description: Handles player character's logical data, processes general logical functions of player characters.
	Game Server (GameServer) Description: Handles player movement synchronization, skills, buffs and other combat functions.
	Data Server (DBServer) Description: Acts as a proxy server between the logic server and MySQL database, responsible for periodically writing player data to the database.
	Gateway Server (ProxyServer) Description: Acts as a transit server between the client and logic server, battle server, mainly responsible for message forwarding.
	Log Server (LogServer) Description: Log server mainly responsible for writing logic server operation logs to MySQL database.
	Watch Server (WatchServer) Description: Mainly responsible for accepting control commands from the WEB backend, controlling the server.

#### Documentation and Tutorials
1. Video setup tutorial provided by group friend Binaryhobart (450282550) [Tutorial Address](https://www.bilibili.com/video/BV1k5411s7Vf?from=search&seid=3304544258866101487)

Gitee address: https://gitee.com/ylmbtm/GameProject3

QQ Group: 962315897
Public Account: ![public1](https://github.com/ylmbtm/resource/blob/master/20210818175029.png)
![public1](https://wx1.sinaimg.cn/mw2000/002dp2Ulgy1gvofyue87sj6065065wf602.jpg)


#### Experience Client Effects (All client code and resources are in group files)
![login1](https://github.com/ylmbtm/resource/blob/master/01.png)
![login2](https://github.com/ylmbtm/resource/blob/master/02.png)
![login3](https://github.com/ylmbtm/resource/blob/master/03.png)
![login4](https://github.com/ylmbtm/resource/blob/master/04.png)


