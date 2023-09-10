project(CSHAPE3D)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_executable(${PROJECT_NAME} testCShape3d.cpp 
cbox.cpp ccylinder.cpp ccone.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
