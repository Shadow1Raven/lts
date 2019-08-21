cmake_minimum_required(VERSION 3.8)
project(lts)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

set(LTS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(LTS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(LTS_SOURCES
	${LTS_SOURCE_DIR}/main.cpp
)

set(LTS_INCLUDES
	${LTS_INCLUDE_DIR}/lts/main.hpp
)

include_directories(${LTS_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SDL2_INCLUDES})

add_executable(${PROJECT_NAME} ${LTS_SOURCES} ${LTS_INCLUDES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_link_libraries(${PROJECT_NAME} OpenGL)
target_link_libraries(${PROJECT_NAME} SDL2)

