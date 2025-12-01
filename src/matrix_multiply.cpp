#include "matrix_multiply.h"
#include <iostream>

bool MatrixMultiplier::canMultiply(const std::vector<std::vector<int>>& A,
                                  const std::vector<std::vector<int>>& B) {
    if (A.empty() || B.empty())
     return false;
    
    size_t a_cols = A[0].size();
    for (const auto& row : A) {
        if (row.size() != a_cols) return false;
    }
      
    size_t b_cols = B[0].size();
    for (const auto& row : B) {
        if (row.size() != b_cols) return false;
    }
    
    return A[0].size() == B.size();
}

std::vector<std::vector<int>> MatrixMultiplier::multiply(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B) {
    
    if (!canMultiply(A, B)) {
        throw std::invalid_argument("Несовместимые размеры матриц для умножения");
    }
    
    size_t M = A.size();     
    size_t K = A[0].size();    
    size_t N = B[0].size();  
    
    std::vector<std::vector<int>> result(M, std::vector<int>(N, 0));
    
    std::cout << "Умножение матриц " << M << "x" << K << " * " << K << "x" << N << std::endl;
    
    // Временная реализация на CPU (заменится на OpenCL)
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            int sum = 0;
            for (size_t k = 0; k < K; ++k) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
    
    return result;
}