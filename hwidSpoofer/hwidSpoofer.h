#pragma once

#include <api/api.h>
#include <api/plugin_header.h>
#include <teamspeak/ts3_functions.h>

#include <cstddef>
#include <string>
#include <tuple>

#ifdef WIN32
#define PLUGINS_EXPORTDLL __declspec(dllexport)
#else
#define PLUGINS_EXPORTDLL __attribute__ ((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

PLUGINS_EXPORTDLL const char *ts3plugin_name();
PLUGINS_EXPORTDLL const char *ts3plugin_version();
PLUGINS_EXPORTDLL int ts3plugin_apiVersion();
PLUGINS_EXPORTDLL const char *ts3plugin_author();
PLUGINS_EXPORTDLL const char *ts3plugin_description();
PLUGINS_EXPORTDLL void ts3plugin_setFunctionPointers(const struct TS3Functions funcs);
PLUGINS_EXPORTDLL int ts3plugin_init();
PLUGINS_EXPORTDLL void ts3plugin_shutdown();
PLUGINS_EXPORTDLL int ts3plugin_offersConfigure();
PLUGINS_EXPORTDLL void ts3plugin_configure(void* handle, void* qParentWidget);
#ifdef __cplusplus
}
#endif
