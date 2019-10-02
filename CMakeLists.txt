# Project dbson main cmake file

cmake_minimum_required(VERSION 3.3)

project(dbson VERSION 0.0.1)

if(DEFINED ENV{DBSON_HOME})
     message("-- Will install dbson binaries and libraries to location: " $ENV{DBSON_HOME})
	 set(CMAKE_INSTALL_PREFIX, $ENV{DBSON_HOME})
else(DEFINED ENV{DBSON_HOME})
     message("-- Will install dbson binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX, ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{DBSON_HOME})

# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

find_file(HAVE_STDINT_HEADER stdint.h)
if(HAVE_STDINT_HEADER)
   message("** stdint.h found")
   add_definitions(-DDBSON_HAVE_STDINT_HEADER)
else(HAVE_STDINT_HEADER)
   message("** stdint.h not found")
endif(HAVE_STDINT_HEADER)

find_file(HAVE_WCHAR_HEADER wchar.h)

if(HAVE_WCHAR_HEADER)
   message("** wchar.h found")
   add_definitions(-DDBSON_HAVE_WCHAR_H)
else(HAVE_WCHAR_HEADER)
   message("** wchar.h not found")
endif(HAVE_WCHAR_HEADER)

find_file(HAVE_STDBOOL_HEADER stdbool.h)

if(HAVE_STDBOOL_HEADER)
   message("** stdbool.h found")
   add_definitions(-DDBSON_HAVE_STDBOOL)
else(HAVE_STDBOOL_HEADER)
   message("** stdbool.h not found")
endif(HAVE_STDBOOL_HEADER)

CHECK_TYPE_SIZE("int" CTYPE_INT)
if(CTYPE_INT STREQUAL "0")
   message("** sizeof int not detectable")
else(CTYPE_INT STREQUAL "0")
   message("~~ sizeof int is ${CTYPE_INT}")
   add_definitions(-DDBSON_SIZEOF_INT=${CTYPE_INT})
endif(CTYPE_INT STREQUAL "0")

# Options
option(WITH_testing "Allows tests to be run" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)


