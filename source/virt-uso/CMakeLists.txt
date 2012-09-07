include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-uso_SRCS
    main.cpp
    virtual_uso.cpp)

add_executable(virt-uso ${virt-uso_SRCS})

target_link_libraries(virt-uso vdb_core ${Boost_LIBRARIES})

install(TARGETS virt-uso DESTINATION bin)
