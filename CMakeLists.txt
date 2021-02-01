cmake_minimum_required(VERSION 3.0.0)
project(DistanceEstimationCpp VERSION 0.1.0)

include(CTest)
enable_testing()

# Adding opencv packges threading and opencv it self
find_package(OpenCv REQUIRED)
find_package(Threads REQUIRED)
add_executable(DistanceEstimationCpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Setting CPP VERSION and Standards

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Providing Path of Opencv Include Dir and Project, files Dir

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(DistanceEstimationCpp  ${OpenCV_LIBS} ${CMAKE_THREADS_LIB_INIT})