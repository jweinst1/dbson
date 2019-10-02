#ifndef DBSON_COMPILER_INFO_H
#define DBSON_COMPILER_INFO_H

/**
 * Header that gives info about availabilities in the C
 * distribution.
 */

#if defined(__STDC__)
#  if defined(__STDC_VERSION__)
#    if (__STDC_VERSION__ >= 199409L)
#        if (__STDC_VERSION__ >= 199901L)
#           if (__STDC_VERSION__ >= 201112L)
               // Define both here for c99 and later features.
#              define DBSON_CVERS_11
#              define DBSON_CVERS_99
#           else // !(__STDC_VERSION__ >= 201112L)
#              define DBSON_CVERS_99
#           endif // (__STDC_VERSION__ >= 201112L)
#        else // !(__STDC_VERSION__ >= 199901L)
#           define DBSON_CVERS_94
#        endif // (__STDC_VERSION__ >= 199901L)
#    else // (__STDC_VERSION__ >= 199409L)
#       define DBSON_CVERS_90
#    endif // !(__STDC_VERSION__ >= 199409L)
#  else // defined(__STDC_VERSION__)
#    define DBSON_CVERS_89
#  endif // !defined(__STDC_VERSION__)
#else // defined(__STDC__)
#  ifdef _WIN32
#     pragma message("__STDC__ is not defined, this is a non-standard C version.")
#  else
#     warn "__STDC__ is not defined, this is a non-standard C version."
#  endif
#endif

#include <limits.h>
// Disabled for now until better size testing mechanism
/*
#ifdef _MSC_VER
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#else // _MSC_VER
*/
#if defined(HAVE_STDINT) || __STDC_VERSION__ >= 199901L
#      include <stdint.h>
#endif
/*#endif // !_MSC_VER*/

#ifdef UINT_MAX
#  if UINT_MAX == 0xffffffff
#      define DBSON_INT_IS_32B
#  endif
#endif

#ifdef HAVE_STDBOOL
#  include <stdbool.h>
#else
#   define true 1
#   define false 0
#   define bool int
#endif

// Debugging tools
#include <stdio.h>
#ifdef __GNUC__
#  define  DBSON_DEBUG(msg) fprintf(stderr, \
                "DBSON-DEBUG: %s, line: %u, function: %s, file: %s\n", \
                msg, (unsigned)__LINE__, __FUNCTION__, __FILE__)
#else // __GNUC__
#  ifdef DBSON_CVERS_99
#      define  DBSON_DEBUG(msg) fprintf(stderr, \
                   "DBSON-DEBUG: %s, line: %u, function: %s, file: %s\n", \
                   msg, (unsigned)__LINE__, __func__, __FILE__)
#  else
#     define  DBSON_DEBUG(msg) fprintf(stderr, \
                   "DBSON-DEBUG: %s, line: %u, file: %s\n", \
                   msg, (unsigned)__LINE__, __FILE__)
#  endif
#endif // !__GNUC__

// Advancedment of void*
#ifdef __GNUC__
#  define DBSON_ADV_PTR(ptr, off) (ptr + off)
#else // __GNUC__
#  define DBSON_ADV_PTR(ptr, off) ((char*)ptr + off)
#endif // !__GNUC__

#include <stdlib.h> 


#endif // DBSON_COMPILER_INFO_H