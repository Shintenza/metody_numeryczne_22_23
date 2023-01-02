#include "include/solver.hpp"

std::vector<double> solve(std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> d) {
    std::size_t size = d.size();
    std::vector<double> result(size, 0);

    for (int i = 0; i < size - 1; i++) {
        double w = a[i] / b[i];
        b[i + 1] = b[i + 1] - w * c[i];
        d[i + 1] = d[i + 1] - w * d[i];
    }

    result[size - 1] = d[size - 1] / b[size - 1];

    for (int i = size - 2; i >= 0; i--) {
        result[i] = (d[i] - c[i] * result[i + 1]) / b[i];
    }
    return result;
}
