#pragma once

// The following macros specify the minimum required platform. The minimum
// required platform is the earliest version of Windows, Internet Explorer, etc.,
// that has the necessary functionality to run the application. By enabling all
// available features on the specified and earlier platforms, the macros will
// work correctly.

// If you must target a platform earlier than the following, change the values
// accordingly. For the latest information on corresponding values for
// different platforms, please refer to MSDN.
#ifndef _WIN32_WINNT            // Specifies the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this value to target other versions of Windows.
#endif

