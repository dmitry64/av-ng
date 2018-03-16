cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set (CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT /workspace/boost/boost_1_66_0)
#set(BOOST_LIBRARYDIR /workspace/boost/boost_1_66_0/stage/lib)
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)


FIND_PACKAGE( Boost 1.54 COMPONENTS thread
    system
    log
    log_setup
    program_options REQUIRED )

project(av-ng)

add_subdirectory(pipeline)
include_directories(${CMAKE_SOURCE_DIR}/pipeline/templates)
add_executable(${PROJECT_NAME} "main.cpp")
