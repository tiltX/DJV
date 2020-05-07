include(ExternalProject)

# Tag: 5.1.0
set(RtAudio_GIT_TAG d27f257b4bc827e4152cdc4d69a2e22084204afd)

set(RtAudio_ARGS
    -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_PREFIX_PATH=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_INSTALL_LIBDIR=lib
    -DCMAKE_DEBUG_POSTFIX=
    -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
    -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
    -DBUILD_SHARED_LIBS=${RtAudio_SHARED_LIBS}
    -DRTAUDIO_BUILD_TESTING=FALSE)
ExternalProject_Add(
    RtAudio
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/RtAudio
    GIT_REPOSITORY https://github.com/thestk/rtaudio.git
    GIT_TAG ${RtAudio_GIT_TAG}
    CMAKE_ARGS ${RtAudio_ARGS})
