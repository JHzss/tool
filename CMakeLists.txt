cmake_minimum_required(VERSION 3.13)
project(tool)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV)

add_executable(pickimage pickImage.cpp)
target_link_libraries(pickimage ${OpenCV_LIBS})

add_executable(pickKITTIPose pickKITTIPose.cpp)
target_link_libraries(pickKITTIPose ${OpenCV_LIBS})

add_executable(getPfromK getPfromK.cpp)
target_link_libraries(getPfromK ${OpenCV_LIBS})