include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(vdb_core_LIB_SRCS
    functions_vdb.cpp
    program_options.cpp
    scenario_conclusion.cpp
    scenario_parser.cpp
    serial_connection.cpp
    udp_connection.cpp
    virtual_device.cpp)

add_library(vdb_core SHARED ${vdb_core_LIB_SRCS})

target_link_libraries(vdb_core serial pthread ${Boost_LIBRARIES})

install(TARGETS vdb_core DESTINATION /usr/lib/${PROJECT_NAME})
