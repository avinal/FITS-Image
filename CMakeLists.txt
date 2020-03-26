cmake_minimum_required(VERSION 2.8.12)
project(Createme)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/)

add_executable(FitsImage src/main.cpp src/FitsImage)
TARGET_LINK_LIBRARIES(FitsImage ${CONAN_LIBS} cfitsio.lib)