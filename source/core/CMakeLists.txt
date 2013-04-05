include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(core_LIB_SRCS
    connection.cpp
    connection_impl.cpp
    functions.cpp
    program_options.cpp
    thread.cpp
    scenario_conclusion.cpp
    scenario_parser.cpp
    udp_connection_impl.cpp
    virtual_device.cpp)

add_library(core SHARED ${core_LIB_SRCS})

target_link_libraries(core serial pthread rt ${Boost_LIBRARIES})

install(TARGETS core DESTINATION /usr/lib/${PROJECT_NAME})
