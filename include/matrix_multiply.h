#pragma once

#include <vector>
#include <stdexcept>

class MatrixMultiplier {
public:
    static std::vector<std::vector<int>> multiply(
        const std::vector<std::vector<int>>& A,
        const std::vector<std::vector<int>>& B);
    
    static bool canMultiply(const std::vector<std::vector<int>>& A,
                           const std::vector<std::vector<int>>& B);
};
