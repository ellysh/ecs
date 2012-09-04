include_directories(${COMMON_INCLUDE_DIRS})

link_directories(${COMMON_LIBDIR})

set(virt-dashboard_SRCS
    virt-dashboard.cpp
    program_options.cpp
    udp_connection.cpp)

add_executable(virt-dashboard ${virt-dashboard_SRCS})

target_link_libraries(virt-dashboard ${Boost_LIBRARIES})

install(TARGETS virt-dashboard DESTINATION bin)
