cmake_minimum_required(VERSION 3.5)
project(WxWidgetsTemplateApp_main)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")


set( WXTA ${CMAKE_CURRENT_SOURCE_DIR} )
set( DUP_FIND_BUILD_ROOT ${CMAKE_SOURCE_DIR} )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set( DUP_FIND_RUN_DIR ${WXTA}/runDir )
set( DUP_FIND_DEPS ${WXTA}/deps )

set(wxBUILD_INSTALL OFF CACHE BOOL "" FORCE)
set(wxBUILD_SAMPLES ALL CACHE BOOL "WX SAMPLES" FORCE)
set(wxBUILD_SHARED OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/wxWidgets)

add_subdirectory(WxWidgetsTemplateApp)
