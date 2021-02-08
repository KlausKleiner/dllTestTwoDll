# 1. Compile your own dll

## 1.1 g++ options
-E      stop after preprocessing, the output will to to stdout
-c      stop after compiling, do not run linker
-o      output files
-l      search library when linking
-L      directory
-shared Produce a shared object which can then be linked form an executable

## 1.2 Create dll
create a source, e.g. utils.cpp that provieds the function implementations

create a header that can be used for building the lib (exporting the functions) and building the application (importing the functions) 

```C
#ifdef BUILD_LIB
// header for building the dll, exporting the functions
#define IMPORT_EXPORT __declspec(dllexport)
#pragma message "exporting functions "
#else
// header for building the app, importing the functions
#define IMPORT_EXPORT __declspec(dllimport)
#pragma message "importing functions"
#endif

IMPORT_EXPORT int addInt(int a, int b);
```
compile and link the dll
by defining BUILD_LIB the header will export the functions

`g++ -DBUILD_LIB -shared -o utils.dll utils.cpp`

you may check dll with dependencies.exe (Dependency Walker)

## 1.3 Create your application
create a source, e.g. main.cpp

include the header of the lib, since BUILD_LIB is not defined, the header will import the functions this time.

compile and link against the dll
`g++ -o main.exe main.cpp utils.dll`
