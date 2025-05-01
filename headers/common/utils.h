#ifndef UTILS_H
#define UTILS_H

#include <glm/glm.hpp>
#include <iostream>

namespace Utils {

    template<typename MatType>
    void PrintMat(const MatType& mat) {
        constexpr int COLUMNS = MatType::col_type::length(); // glm is column-major
        constexpr int ROWS = MatType::row_type::length();

        for (int i = 0; i < 4; i++) {
            std::cout << "| ";
            for (int j = 0; j < 4; j++) {
                float val = mat[j][i];
                if (std::abs(val) < 1e-6f) val = 0.0f;
                std::cout << val << " ";
            }
            std::cout << "|" << std::endl;
        }
    }

    template<typename VecType>
    void PrintVec(const VecType& vec) {
        constexpr int SIZE = VecType::length();

        std::cout << "( ";
        for (int i = 0; i < SIZE; ++i) {
            float val = vec[i];
            if (std::abs(val) < 1e-6f) val = 0.0f;
            std::cout << val << " ";
        }
        std::cout << ")\n";
    }

}

#endif