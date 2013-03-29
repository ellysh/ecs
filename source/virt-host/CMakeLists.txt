include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-host_SRCS
    main.cpp
    protocol_uso.cpp
    uso_parser.cpp
    virtual_uso.cpp)

add_executable(virt-host ${virt-host_SRCS})

target_link_libraries(virt-host vdb_core ${Boost_LIBRARIES})

install(TARGETS virt-host DESTINATION /usr/bin)
