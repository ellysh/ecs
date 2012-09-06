include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-dashboard_SRCS
    main.cpp
    functions_vdb.cpp
    program_options.cpp
    scenario_parser.cpp
    udp_connection.cpp
    virtual_controller.cpp)

add_executable(virt-dashboard ${virt-dashboard_SRCS})

target_link_libraries(virt-dashboard ${Boost_LIBRARIES})

install(TARGETS virt-dashboard DESTINATION bin)
