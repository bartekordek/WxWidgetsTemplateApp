#cmake -DCMAKE_BUILD_TYPE=Debug
cmake_minimum_required(VERSION 3.0.0)

get_filename_component(basename ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME_CONSOLE ${basename}_console)
project(${PROJECT_NAME_CONSOLE} LANGUAGES CXX)
if (MSVC)
    set(PROJECT_NAME_WINDOWS ${basename}_windows)
    project(${PROJECT_NAME_CONSOLE} LANGUAGES CXX)

    add_compile_options(/MP)
else()
    add_compile_options(-Wall -Wextra -pedantic)
    add_definitions(-Wfatal-errors)
endif()

include_directories("inc")

file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.vert *.frag)
message("${EXEC}: ${SOURCES} ")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

add_executable(${PROJECT_NAME_CONSOLE} ${SOURCES})
if (MSVC)
add_executable(${PROJECT_NAME_WINDOWS} WIN32 ${SOURCES})
endif()

if (MSVC)
    target_compile_definitions(${PROJECT_NAME_WINDOWS} PRIVATE TEMPLATE_APP_WINDOWS_SUBSYSTEM)

    set_target_properties(
        ${PROJECT_NAME_CONSOLE}
        PROPERTIES
            OUTPUT_NAME ${PROJECT_NAME_CONSOLE}
            SUFFIX ".exe"
   )
    set_target_properties(
    ${PROJECT_NAME_WINDOWS}
    PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME_WINDOWS}
        SUFFIX ".exe"
   )
else()
    set_target_properties(
        ${PROJECT_NAME_CONSOLE}
        PROPERTIES
            OUTPUT_NAME ${PROJECT_NAME_CONSOLE}
            SUFFIX ".bin"
   )
endif()

IF(NOT APPLE AND NOT MSVC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
ENDIF()
set(DEPENDENCIES PRIVATE PRIVATE wx::core wx::base)

if(MSVC)
    target_link_options(${PROJECT_NAME_CONSOLE} PUBLIC "/INCREMENTAL:NO")
    target_link_options(${PROJECT_NAME_WINDOWS} PUBLIC "/INCREMENTAL:NO")
    target_link_libraries(${PROJECT_NAME_CONSOLE} ${DEPENDENCIES})
    target_link_libraries(${PROJECT_NAME_WINDOWS} ${DEPENDENCIES})

    set_target_properties(${PROJECT_NAME_CONSOLE} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    set_target_properties(${PROJECT_NAME_WINDOWS} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
else()
    target_link_libraries(${PROJECT_NAME_CONSOLE} ${DEPENDENCIES})
endif()

target_include_directories(${PROJECT_NAME_CONSOLE} PRIVATE inc)
target_include_directories(${PROJECT_NAME_CONSOLE} PRIVATE src)

if(MSVC)
    target_include_directories(${PROJECT_NAME_WINDOWS} PRIVATE inc)
    target_include_directories(${PROJECT_NAME_WINDOWS} PRIVATE src)
    set_property(TARGET ${PROJECT_NAME_WINDOWS} PROPERTY "VS_DEBUGGER_WORKING_DIRECTORY" "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

if (MSVC)
    target_compile_options(wxcore PRIVATE /W0)
else()
    target_compile_options(wxcore PRIVATE -w)
endif()