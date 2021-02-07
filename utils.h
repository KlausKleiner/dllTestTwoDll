#pragma once

#ifdef COMPILING_DLL 
asfd
#endif

#ifdef BUILD_LIB
// header for building the dll, exporting
#define IMPORT_EXPORT __declspec(dllexport)
#pragma message "exporting functions "
#else
// header for building the app, importing
#define IMPORT_EXPORT __declspec(dllimport)
#pragma message "importing functions"
#endif

IMPORT_EXPORT int addInt(int a, int b);