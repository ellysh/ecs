include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(core_LIB_SRCS
    functions.cpp
    program_options.cpp
    thread.cpp
    scenario_conclusion.cpp
    scenario_parser.cpp
    serial_connection.cpp
    udp_connection.cpp
    virtual_device.cpp)

add_library(core SHARED ${core_LIB_SRCS})

target_link_libraries(core serial pthread ${Boost_LIBRARIES})

install(TARGETS core DESTINATION /usr/lib/${PROJECT_NAME})
