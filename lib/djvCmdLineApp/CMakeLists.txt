set(header
    Application.h
    Namespace.h)
set(source
    Application.cpp)

add_library(djvCmdLineApp ${header} ${source})
target_link_libraries(djvCmdLineApp djvAV)
set_target_properties(
    djvCmdLineApp
    PROPERTIES
    FOLDER lib
    CXX_STANDARD 11)

#install(
#    TARGETS djvCmdLineApp
#    RUNTIME DESTINATION bin
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION lib)
#install(FILES ${header} DESTINATION djvCmdLineApp/include)

