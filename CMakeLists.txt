cmake_minimum_required(VERSION 3.17)
project(CMPEProject)

include_directories(/usr/local/opt/curl/include/)


set(CMAKE_CXX_STANDARD 17)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

add_executable(CMPEProject ImageDownload.cpp)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(CMPEProject ${CURL_LIBRARIES})