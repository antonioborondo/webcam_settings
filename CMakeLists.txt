cmake_minimum_required(VERSION 3.22.3)

project(webcam_settings VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_CMAKE ${CMAKE_BINARY_DIR}/conan.cmake)

if(NOT EXISTS ${CONAN_CMAKE})
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake" ${CONAN_CMAKE}
        EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
        TLS_VERIFY ON
    )
endif()

include(${CONAN_CMAKE})

conan_cmake_configure(
    CONANFILE conanfile.txt
    GENERATORS cmake_find_package
)

conan_cmake_autodetect(settings)

conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

find_package(opencv REQUIRED)

add_executable(webcam_settings
    src/main.cpp
)

target_link_libraries(webcam_settings
    PRIVATE
    opencv::opencv
)
