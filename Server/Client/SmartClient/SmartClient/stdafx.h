// stdafx.h : Include file for standard system include files,
// or frequently used but infrequently changed
// Project specific include files
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
#include <assert.h>
#include <direct.h>
#include <time.h>
#include "..\Src\ServerEngine\Platform.h"
//#define ASSERT_FAIELD (ASSERT(false))

#define ASSERT_FAIELD (assert(false))
#ifndef ASSERT
#define ASSERT assert
#endif

#pragma  comment(lib,"ws2_32")
#pragma  comment(lib, "Mswsock")

// TODO: reference additional headers required by the program here
