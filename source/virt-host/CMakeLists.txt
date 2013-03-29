include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-host_SRCS
    main.cpp
    protocol_host.cpp
    host_parser.cpp
    virtual_host.cpp)

add_executable(virt-host ${virt-host_SRCS})

target_link_libraries(virt-host core ${Boost_LIBRARIES})

install(TARGETS virt-host DESTINATION /usr/bin)
