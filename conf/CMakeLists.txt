install(DIRECTORY .
    DESTINATION /usr/share/${PROJECT_NAME}
    FILES_MATCHING PATTERN *.vd?)

install(FILES ${PROJECT_NAME}.conf DESTINATION /etc/ld.so.conf.d)
