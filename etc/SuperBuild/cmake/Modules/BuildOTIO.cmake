include(ExternalProject)

set(OTIO_ARGS
    -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_PREFIX_PATH=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_POLICY_DEFAULT_CMP0091:STRING=NEW
    -DCMAKE_FIND_FRAMEWORK=${CMAKE_FIND_FRAMEWORK}
    -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
    -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
    -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS})
set(OTIO_DEPENDS ${OTIO_DEPENDS})
ExternalProject_Add(
    OTIO
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/OTIO
    DEPENDS ${OTIO_DEPENDS}
    GIT_REPOSITORY https://github.com/PixarAnimationStudios/OpenTimelineIO.git
    PATCH_COMMAND
        ${CMAKE_COMMAND} -E tar xf
        ${CMAKE_SOURCE_DIR}/OTIO-patch.tar.gz
    CMAKE_ARGS ${OTIO_ARGS})

