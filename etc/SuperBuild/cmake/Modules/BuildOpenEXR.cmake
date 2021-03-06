include(ExternalProject)

set(OpenEXR_ARGS
    -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_PREFIX_PATH=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_POLICY_DEFAULT_CMP0091:STRING=NEW
    -DCMAKE_FIND_FRAMEWORK=${CMAKE_FIND_FRAMEWORK}
    -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
    -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
    -DCMAKE_MSVC_RUNTIME_LIBRARY=${CMAKE_MSVC_RUNTIME_LIBRARY}
    -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
    -DBUILD_TESTING=OFF
    -DOPENEXR_BUILD_UTILS=OFF
    -DINSTALL_OPENEXR_DOCS=OFF)
if(CMAKE_CXX_STANDARD)
    set(OpenEXR_ARGS ${OpenEXR_ARGS} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD})
endif()

ExternalProject_Add(
    OpenEXR
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/OpenEXR
    DEPENDS IlmBase ZLIB
    GIT_REPOSITORY https://github.com/AcademySoftwareFoundation/openexr
    GIT_TAG v2.5.3
    SOURCE_SUBDIR OpenEXR
    CMAKE_ARGS ${OpenEXR_ARGS})
