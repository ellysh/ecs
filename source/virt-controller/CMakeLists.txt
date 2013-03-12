include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-controller_SRCS
    controller_parser.cpp
    main.cpp
    protocol_controller.cpp
    virtual_controller.cpp)

add_executable(virt-controller ${virt-controller_SRCS})

target_link_libraries(virt-controller vdb_core ${Boost_LIBRARIES})

install(TARGETS virt-controller DESTINATION /usr/bin)
