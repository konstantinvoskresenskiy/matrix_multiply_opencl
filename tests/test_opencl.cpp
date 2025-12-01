#include "matrix_multiply.h"
#include <iostream>
#include <cassert>

void test_opencl_initialization() {
    std::cout << "Тест: инициализация OpenCL..." << std::endl;
    
    // Простой тест для проверки что OpenCL работает
    std::vector<std::vector<int>> A = {{1}};
    std::vector<std::vector<int>> B = {{2}};
    
    try {
        auto result = MatrixMultiplier::multiply(A, B);
        assert(result[0][0] == 2);
        std::cout << "Инициализация OpenCL прошла успешно" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Тест OpenCL пропущен: " << e.what() << std::endl;
    }
}

void test_different_sizes() {
    std::cout << "Тест: умножение матриц разных размеров..." << std::endl;
    
    // 1x2 * 2x1 = 1x1
    std::vector<std::vector<int>> A = {{1, 2}};
    std::vector<std::vector<int>> B = {{3}, {4}};
    auto result1 = MatrixMultiplier::multiply(A, B);
    assert(result1.size() == 1);
    assert(result1[0].size() == 1);
    assert(result1[0][0] == 11);
    
    // 2x1 * 1x2 = 2x2
    std::vector<std::vector<int>> C = {{1}, {2}};
    std::vector<std::vector<int>> D = {{3, 4}};
    auto result2 = MatrixMultiplier::multiply(C, D);
    assert(result2.size() == 2);
    assert(result2[0].size() == 2);
    assert(result2[0][0] == 3 && result2[0][1] == 4);
    assert(result2[1][0] == 6 && result2[1][1] == 8);
    
    std::cout << "Тест разных размеров пройден" << std::endl;
}

void test_zero_matrix() {
    std::cout << "Тест: умножение нулевых матриц..." << std::endl;
    
    std::vector<std::vector<int>> A = {{0, 0}, {0, 0}};
    std::vector<std::vector<int>> B = {{1, 2}, {3, 4}};
    auto result = MatrixMultiplier::multiply(A, B);
    
    assert(result[0][0] == 0 && result[0][1] == 0);
    assert(result[1][0] == 0 && result[1][1] == 0);
    
    std::cout << " Тест нулевых матриц пройден" << std::endl;
}

void test_identity_matrix() {
    std::cout << "Тест: умножение на единичную матрицу..." << std::endl;
    
    std::vector<std::vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> I = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    auto result = MatrixMultiplier::multiply(A, I);
    
    assert(result.size() == 2);
    assert(result[0].size() == 3);
    assert(result[0][0] == 1 && result[0][1] == 2 && result[0][2] == 3);
    assert(result[1][0] == 4 && result[1][1] == 5 && result[1][2] == 6);
    
    std::cout << " Тест единичной матрицы пройден" << std::endl;
}

int main() {
    std::cout << "Запуск OpenCL тестов" << std::endl;
    
    test_opencl_initialization();
    test_different_sizes();
    test_zero_matrix();
    test_identity_matrix();
    
    std::cout << " Все OpenCL тесты пройдены!" << std::endl;
    return 0;
}