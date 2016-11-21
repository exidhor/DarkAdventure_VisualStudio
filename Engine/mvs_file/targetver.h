#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>



/*
targetver.h and SDKDDKVer.h are used to control what functions, constants, etc. are included 
into your code from the Windows headers, based on the OS that you want your program to support. 
I believe that targetver.h sets defaults to using the latest version of Windows unless 
the defines are specified elsewhere.
SDKDDKVer.h is the header file that actually defines the #defines that represent each version 
of Windows, IE, etc.
*/

// source : http://stackoverflow.com/questions/10539391/what-is-sdkddkver-h-for