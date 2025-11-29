cmake_minimum_required(VERSION 3.15)
project(MatrixMultiplyOpenCL)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем дебажную информацию
set(CMAKE_BUILD_TYPE Debug)

# Пакет OpenCL
find_package(OpenCL REQUIRED)

if(OpenCL_FOUND)
    message(STATUS "OpenCL found: ${OpenCL_VERSION}")
    message(STATUS "OpenCL include dir: ${OpenCL_INCLUDE_DIRS}")
    message(STATUS "OpenCL libraries: ${OpenCL_LIBRARIES}")
else()
    message(FATAL_ERROR "OpenCL not found! Please install OpenCL SDK")
endif()

# Основная программа
add_executable(matrix_multiply src/main.cpp)
target_link_libraries(matrix_multiply OpenCL::OpenCL)

# Тесты
add_executable(matrix_multiply_test tests/test_matrix_multiply.cpp)
target_link_libraries(matrix_multiply_test OpenCL::OpenCL)

configure_file(src/matrix_multiply.cl matrix_multiply.cl COPYONLY)
