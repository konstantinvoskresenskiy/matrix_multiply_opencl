#include "matrix_multiply.h"
#include <cassert>
#include <iostream>

void test_can_multiply() {
    std::cout << "Тест: проверка возможности умножения..." << std::endl;
    
    // Совместимые матрицы
    std::vector<std::vector<int>> A = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> B = {{5, 6}, {7, 8}};
    assert(MatrixMultiplier::canMultiply(A, B) == true);
    
    // Несовместимые матрицы
    std::vector<std::vector<int>> C = {{1, 2, 3}};
    std::vector<std::vector<int>> D = {{4, 5}};
    assert(MatrixMultiplier::canMultiply(C, D) == false);
    
    std::cout << "✓ Проверка возможности умножения пройдена" << std::endl;
}

void test_multiply() {
    std::cout << "Тест: умножение матриц..." << std::endl;
    
    std::vector<std::vector<int>> A = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> B = {{5, 6}, {7, 8}};
    std::vector<std::vector<int>> expected = {{19, 22}, {43, 50}};
    
    auto result = MatrixMultiplier::multiply(A, B);
    
    assert(result.size() == expected.size());
    assert(result[0].size() == expected[0].size());
    assert(result[0][0] == expected[0][0]);
    assert(result[0][1] == expected[0][1]);
    assert(result[1][0] == expected[1][0]);
    assert(result[1][1] == expected[1][1]);
    
    std::cout << "✓ Умножение матриц пройдено" << std::endl;
}

int main() {
    std::cout << "=== Запуск базовых тестов ===" << std::endl;
    
    test_can_multiply();
    test_multiply();
    
    std::cout << "=== Все базовые тесты пройдены! ===" << std::endl;
    return 0;
}