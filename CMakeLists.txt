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

# Fix the install path
set(CMAKE_INSTALL_PREFIX /usr)

# Build type by default is Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

# Find Linux packages
find_package(Boost 1.40 COMPONENTS system regex program_options REQUIRED)

# Linux paths and libs
set(COMMON_LIBDIR )
set(COMMON_INCLUDE_DIRS
    ${Boost_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/source/core)

# CXXFLAGS and CMAKE_C_FLAGS
set(CMAKE_CXX_FLAGS "-D__LINUX__ -Wvla -Wl,-z,defs -fPIC -std=c++0x")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -fomit-frame-pointer -funroll-loops -pipe")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D__DEBUG__ -O0 -g")
set(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS_RELEASE})

# Targets for the deb packages building
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(DEB_DIR ${BIN_DIR}/deb)
set(DEBIAN_DIR ${PROJECT_SOURCE_DIR}/debian)

add_custom_target(deb-clean
    COMMAND -rm -rf ${DEBIAN_DIR}/simscreen
    COMMAND -rm -rf ${DEB_DIR}
    COMMAND find bin -name \"*.dsc\" | xargs rm -f
    COMMAND find bin -name "*.changes" | xargs rm -f
    COMMAND find bin -name "*.deb" | xargs rm -f
    COMMAND find bin -name "*.tar.gz" | xargs rm -f
)

add_custom_target(deb
    COMMAND mkdir -p ${DEB_DIR}
    COMMAND dpkg-buildpackage -rfakeroot -b -uc -us
    COMMAND mv -f ../*.changes ../*.deb ${DEB_DIR}
)

# Subdirs
add_subdirectory(source)
