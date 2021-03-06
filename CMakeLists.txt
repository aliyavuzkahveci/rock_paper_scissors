cmake_minimum_required(VERSION 3.13)

# set project name
set(TARGET_NAME rock_paper_scissors)
project (${TARGET_NAME} VERSION "0.0.1" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
set(BUILD_SHARED_LIBS ON)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  option(INSTALL_GMOCK "Install Googletest's GMock?" OFF)
  option(INSTALL_GTEST "Install Googletest's GTest?" OFF)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# setting output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# adding /include dir  
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# collecting headers and sources
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_EXTENSION)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/include HEADER_EXTENSION)

# adding headers and sources
add_executable(${TARGET_NAME} ${SOURCE_EXTENSION} ${HEADER_EXTENSION})

# tests
add_subdirectory(test)
