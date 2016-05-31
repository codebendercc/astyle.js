// js_format_string.cpp

/* This program calls the Artistic Style formatter (AStyleMain)
 * to format the astyle source files in a test-data directory.
 */

#include "astyle.h"
#include "astyle_main.h"

#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#if defined(__GNUC__)
#include <string.h>         // need both string and string.h for GCC
#endif

using namespace std;

// allow for different calling conventions in Linux and Windows
#ifdef _WIN32
#define STDCALL __stdcall
#else
#define STDCALL
#endif

// functions to call AStyleMain
extern "C" char* STDCALL AStyleMain(const char* sourceIn,
                                    const char* optionsIn,
                                    void (STDCALL* fpError)(int, const char*),
                                    char* (STDCALL* fpAlloc)(unsigned long));
void  STDCALL ASErrorHandler(int errorNumber, const char* errorMessage);
char* STDCALL ASMemoryAlloc(unsigned long memoryNeeded);

// Error handler for the Artistic Style formatter.
void  STDCALL ASErrorHandler(int errorNumber, const char* errorMessage)
{   cout << "astyle error " << errorNumber << "\n"
         << errorMessage << endl;
}

// Allocate memory for the Artistic Style formatter.
char* STDCALL ASMemoryAlloc(unsigned long memoryNeeded)
{   // error condition is checked after return from AStyleMain
    char* buffer = new(nothrow) char [memoryNeeded];
    return buffer;
}

// Exposed formatting function
extern "C" char* js_format_string(char *textIn)
{
    char *formattedText = AStyleMain(textIn,
                               "-A1tpS",
                               ASErrorHandler,
                               ASMemoryAlloc);

    return formattedText;
}
