include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-controller_SRCS
    main.cpp
    functions_vdb.cpp
    program_options.cpp
    scenario_conclusion.cpp
    scenario_parser.cpp
    udp_connection.cpp
    virtual_controller.cpp)

add_executable(virt-controller ${virt-controller_SRCS})

target_link_libraries(virt-controller ${Boost_LIBRARIES})

install(TARGETS virt-controller DESTINATION bin)
