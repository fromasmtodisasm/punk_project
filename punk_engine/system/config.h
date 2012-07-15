#ifndef _H_PUNK_SYSTEM_CONFIG
#define _H_PUNK_SYSTEM_CONFIG

#define STRING2(X) #X
#define TO_STRING(X) STRING2(X)

#ifdef _WIN32
#ifdef PUNK_SYSTEM_EXPORTS
#define MODULE_SYSTEM __declspec(dllexport)
#else
#define MODULE_SYSTEM __declspec(dllimport)
#endif

#pragma warning(disable : 4251)

#endif

#ifdef __linux__
#define MODULE_SYSTEM
#endif

#endif