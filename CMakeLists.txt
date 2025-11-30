# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Настройка проекта
project(MatrixMultiplyOpenCL 
    VERSION 1.0.0 
    LANGUAGES CXX
    DESCRIPTION "Умножение матриц с использованием OpenCL"
)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Настройка типа сборки по умолчанию
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Тип сборки: ${CMAKE_BUILD_TYPE}")

# Флаги компилятора
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Флаги для отладочной сборки
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -DDEBUG")

# Флаги для релизной сборки
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")

# Поиск пакета OpenCL
find_package(OpenCL REQUIRED)

if(OpenCL_FOUND)
    message(STATUS "OpenCL найден: ${OpenCL_VERSION}")
    message(STATUS "Включения OpenCL: ${OpenCL_INCLUDE_DIRS}")
    message(STATUS "Библиотеки OpenCL: ${OpenCL_LIBRARIES}")
else()
    message(FATAL_ERROR "OpenCL не найден! Установите pocl или другой OpenCL runtime")
endif()

# Директории для включения заголовков
include_directories(include)

# Основная библиотека проекта
add_library(matrix_multiply
    src/matrix_multiply.cpp
)

# Связывание с OpenCL
target_link_libraries(matrix_multiply
    PRIVATE OpenCL::OpenCL
)

# Публичные заголовки
target_include_directories(matrix_multiply
    PUBLIC include
)

# Копирование kernel файла в директорию сборки
configure_file(
    kernels/matrix_multiply.cl
    ${CMAKE_CURRENT_BINARY_DIR}/matrix_multiply.cl
    COPYONLY
)

# Включение системы тестирования
enable_testing()

# Базовые тесты (проверка функциональности)
add_executable(test_basic
    tests/test_basic.cpp
)

target_link_libraries(test_basic
    PRIVATE matrix_multiply
)

# Тесты OpenCL (проверка реализации)
add_executable(test_opencl
    tests/test_opencl.cpp
)

target_link_libraries(test_opencl
    PRIVATE matrix_multiply
)

# Добавление тестов в CTest
add_test(NAME test_basic COMMAND test_basic)
add_test(NAME test_opencl COMMAND test_opencl)

# Опциональная установка
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "Директория установки" FORCE)
endif()

# Установка библиотеки
install(TARGETS matrix_multiply
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# Установка заголовков
install(FILES include/matrix_multiply.h
    DESTINATION include
)

