#ifndef _GLOBALS_H_
#define _GLOBALS_H_

// Warning disabled ---
#pragma warning( disable : 4577 ) // Warning that exceptions are disabled
#pragma warning( disable : 4530 )

#include <windows.h> // NOOOOOOOOOOOO LUL JSJAJAJAJSADJ
#include <stdio.h>

#define INTERNAL_LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define CAP(n) ((n <= 0.0f) ? n=0.0f : (n >= 1.0f) ? n=1.0f : n=n)

#define DEGTORAD   0.0174532925199432957f
#define RADTODEG   57.295779513082320876f
#define PI		   3.14159265358979323846f
#define TWO_PI	   6.28318530717958647692f
#define HALF_PI	   1.57079632679489661923f
#define QUARTER_PI 0.78539816339744830961f
#define INV_PI	   0.31830988618379067154f
#define INV_TWO_PI 0.15915494309189533576f

typedef unsigned int uint;
typedef unsigned char uchar;

// Deletes a buffer
#define RELEASE( x ) \
    {                        \
    if( x != NULL && x != nullptr )        \
	    {                      \
      delete x;            \
	  x = nullptr;              \
	    }                      \
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
    {                              \
    if( x != nullptr )              \
	    {                            \
      delete[] x;                \
	  x = nullptr;                    \
	    }                            \
                              \
    }

// Performance macros
#define PERF_START(timer) timer.Start()
#define PERF_PEEK(timer) EDITOR_LOG("%s took %f ms", __FUNCTION__, timer.ReadMs())


#endif // !_GLOBALS_H_