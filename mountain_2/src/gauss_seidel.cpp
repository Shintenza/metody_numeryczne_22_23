#include "include/gauss_seidel.hpp"

void gauss_seidel_adjusted(std::vector<double> a1, std::vector<double> a2, std::vector<double> a3,
                           std::vector<double> a4, std::vector<double> a5, std::vector<double> &x, std::vector<double> e) {
    for (int i = 0; i < 100; i++) {
        x[0] = (e[0] - x[1] - x[4]) / a3[0];

        for (int j = 1; j < 4; j++) {
            x[j] = (e[j] - x[1 + j] - x[4 + j]) / a3[j];
        }

        for (int j = 4; j < 124; j++) {
            x[j] = (e[j] - x[j - 4] - x[j - 1] - x[j + 1] - x[j + 4]) / a3[j];
        }

        for (std::size_t j = 124; j < e.size() - 1; j++) {
            x[j] = (e[j] - x[j - 4] - x[j - 1] - x[j + 1]) / a3[j];
        }

        x[127] = (e[127] - x[123] - x[126]) / a3[127];
    }
}
