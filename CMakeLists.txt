cmake_minimum_required(VERSION 3.10)

project(apex VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/time/cycler.cpp
    src/thread/thread.cpp
)

add_library(apex SHARED ${SOURCES})

set_target_properties(apex PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

install(TARGETS apex
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include/apex
    FILES_MATCHING PATTERN "*.hpp"
)

# install(TARGETS apex EXPORT apexTargets)
# install(EXPORT apexTargets
#     FILE apexConfig.cmake
#     NAMESPACE apex::
#     DESTINATION lib/cmake/apex
# )