#pragma once

// 以下宏definition要求的最低平台。要求的最低平台
// 是具有running应用程序所需功能的 Windows、Internet Explorer 等产品的
// 最早版本。通过在指定版本及更低版本的平台上启用所有可用的功能，宏can
// 正常工作。

// 如果必须要针对低于以下指定版本的平台，请修改下列definition。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef _WIN32_WINNT            // 指定要求的最低平台是 Windows Vista。
#define _WIN32_WINNT 0x0600     // 将此值更改is相应的值，以适用于 Windows 的其他版本。
#endif

