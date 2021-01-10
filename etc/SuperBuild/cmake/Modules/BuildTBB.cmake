include(ExternalProject)

#set(TBB_VERSION "2020.3")
#if (APPLE)
#    set(TBB_URL "http://github.com/intel/tbb/releases/download/v${TBB_VERSION}/tbb-${TBB_VERSION}-mac.tgz")
#elseif (WIN32)
#    set(TBB_URL "http://github.com/intel/tbb/releases/download/v${TBB_VERSION}/tbb-${TBB_VERSION}-win.zip")
#else()
#    set(TBB_URL "http://github.com/intel/tbb/releases/download/v${TBB_VERSION}/tbb-${TBB_VERSION}-lin.tgz")
#endif()
#
#ExternalProject_Add(
#    TBB
#    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/TBB
#    URL ${TBB_URL}
#    CONFIGURE_COMMAND ""
#    BUILD_COMMAND ""
#    INSTALL_COMMAND "${CMAKE_COMMAND}" -E copy_directory
#        <SOURCE_DIR>/tbb
#        ${CMAKE_INSTALL_PREFIX}
#    BUILD_ALWAYS OFF)

set(TBB_BUILD_SHARED ON)
set(TBB_BUILD_STATIC OFF)
if(NOT BUILD_SHARED_LIBS)
    set(TBB_BUILD_SHARED OFF)
    set(TBB_BUILD_STATIC ON)
endif()

ExternalProject_Add(
    TBB
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/TBB
    GIT_REPOSITORY "https://github.com/wjakob/tbb.git"
    CMAKE_ARGS
        -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_PREFIX}/lib
        -DCMAKE_PREFIX_PATH=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_POLICY_DEFAULT_CMP0091:STRING=NEW
        -DCMAKE_FIND_FRAMEWORK=${CMAKE_FIND_FRAMEWORK}
        -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
        -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
        -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
        -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
        -DTBB_BUILD_SHARED=${TBB_BUILD_SHARED}
        -DTBB_BUILD_STATIC=${TBB_BUILD_STATIC}
        -DTBB_BUILD_TESTS=OFF)
