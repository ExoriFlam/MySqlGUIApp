cmake_minimum_required(VERSION 3.10)

project(MySqlGUIApp)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIRS})

include_directories(/usr/include/mysql-cppconn-8)
link_directories(/usr/lib/mysql-cppconn-8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(MySqlGUIApp ${SOURCES})

target_compile_options(MySqlGUIApp PRIVATE -I/usr/local/include;-I/usr/local/include/FL/images;-I/usr/local/include/jpeg;-I/usr/include/uuid;-I/usr/include/freetype2;-I/usr/include/libpng16;-D_LARGEFILE_SOURCE;-D_LARGEFILE64_SOURCE;-D_THREAD_SAFE;-D_REENTRANT)
target_link_libraries(MySqlGUIApp -L/usr/local/lib;-lfltk_images;-lpng;-lz;-lpng16;-lz;-lfltk_jpeg;-lfltk;-lXrender;-lXft;-lfontconfig;-lXinerama;-pthread;-lpthread;-lm;-lX11;mysqlcppconn)