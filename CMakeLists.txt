# Release build type:
# cmake -D CMAKE_BUILD_TYPE=Release CMakeLists.txt
#
# Debug build type (by default):
# cmake -D CMAKE_BUILD_TYPE=Debug CMakeLists.txt
# or
# cmake CMakeLists.txt
#
# For build with mingw compiler:
# cmake -D CMAKE_MINGW=1 CMakeLists.txt
#
# Remove the CMakeCache file for CMAKE_MINGW undefine

cmake_minimum_required(VERSION 2.6)
project(virt-dashboard)

find_package(PkgConfig)
pkg_check_modules(LIBSERIAL REQUIRED libserial)
find_package(Boost 1.40 COMPONENTS system regex program_options REQUIRED)

set(COMMON_INCLUDE_DIRS
    ${Boost_INCLUDE_DIR}
    ${LIBSERIAL_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/source/core)

set(COMMON_LIBDIR
    ${LIBSERIAL_LIBDIR})

# Build type by default is Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

# CXXFLAGS and CMAKE_C_FLAGS
set(CMAKE_CXX_FLAGS "-D__LINUX__ -Wvla -Wl,-z,defs -fPIC -std=c++0x")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -fomit-frame-pointer -funroll-loops -pipe")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D__DEBUG__ -O0 -g")
set(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS_RELEASE})

add_subdirectory(source)
add_subdirectory(conf)
add_subdirectory(scripts)

include(CMakeListsDeb.txt)
