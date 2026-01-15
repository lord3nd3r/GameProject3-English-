// stdafx.h : include file for standard system include files,
// or often used but not often changed
// project specific include files
//

#pragma once

#include "targetver.h"
#include <io.h>
#include <stdio.h>
#include <tchar.h>

#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <mstcpip.h>
#include <assert.h>
#include <direct.h>
#include <time.h>
#include <Mstcpip.h>
#define ASSERT_FAIELD (assert(false))
#ifndef ASSERT
#define ASSERT assert
#endif
#pragma  comment(lib,"ws2_32")
#pragma  comment(lib, "Mswsock")

// TODO: 在此处引用程序需要的其他头文件
