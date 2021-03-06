include(ExternalProject)

set(JPEG_DEPS ZLIB)
if(NOT WIN32)
    set(JPEG_DEPS ${JPEG_DEPS} NASM)
endif()

set(JPEG_ENABLE_SHARED ON)
set(JPEG_ENABLE_STATIC OFF)
if(NOT BUILD_SHARED_LIBS)
    set(JPEG_ENABLE_SHARED OFF)
    set(JPEG_ENABLE_STATIC ON)
endif()

set(JPEG_ARGS
    -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_PREFIX}/lib
    -DCMAKE_PREFIX_PATH=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_POLICY_DEFAULT_CMP0091:STRING=NEW
    -DCMAKE_FIND_FRAMEWORK=${CMAKE_FIND_FRAMEWORK}
    -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
    -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
    -DCMAKE_MSVC_RUNTIME_LIBRARY=${CMAKE_MSVC_RUNTIME_LIBRARY}
    -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
    -DENABLE_SHARED=${JPEG_ENABLE_SHARED}
    -DENABLE_STATIC=${JPEG_ENABLE_STATIC})
if(CMAKE_CXX_STANDARD)
    set(JPEG_ARGS ${JPEG_ARGS} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD})
endif()

ExternalProject_Add(
    JPEG
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/JPEG
    DEPENDS ${JPEG_DEPS}
    URL "http://sourceforge.net/projects/libjpeg-turbo/files/2.0.6/libjpeg-turbo-2.0.6.tar.gz?download"
    PATCH_COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/JPEG-patch/CMakeLists.txt
        ${CMAKE_CURRENT_BINARY_DIR}/JPEG/src/JPEG/CMakeLists.txt
    CMAKE_ARGS ${JPEG_ARGS})
