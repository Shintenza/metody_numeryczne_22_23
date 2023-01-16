#include "include/utils.hpp"

double vector_norm(std::vector<double> vec) {
    double norm = 0.;
    for (double e : vec) {
        norm += e * e;
    }
    return std::sqrt(norm);
}
void display_vector(std::vector<double> vec) {
    for (double e : vec) {
        std::cout << e << std::endl;
    }
}
double vector_mul(std::vector<double> v1, std::vector<double> v2) {
    double result = 0.;
    for (std::size_t i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}
std::vector<double> vector_mul(double a, std::vector<double> v1) {
    std::vector<double> result(v1.size(), 0);
    for (std::size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] * a;
    }
    return result;
}
std::vector<double> vector_sum(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> result(v1.size(), 0);
    for (std::size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}
std::vector<double> vector_diff(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> result(v1.size(), 0);
    for (std::size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}
// funkcja mnożenia macierzy z zadania przez wektor dostosowana do jej struktury
std::vector<double> optimised_mul(std::vector<double> a1, std::vector<double> a2, std::vector<double> a3,
                                  std::vector<double> a4, std::vector<double> a5, std::vector<double> v) {
    std::vector<double> result(128, 0);

    result[0] = a3[0] * v[0] + a2[0] * v[1] + a1[0] * v[4];

    for (int i = 1; i < 4; i++) {
        result[i] = a4[i - 1] * v[i - 1] + a3[i] * v[i] + a2[i] * v[i + 1] + a1[i] * v[4 + i];
    }

    for (int i = 4; i < 124; i++) {
        result[i] = a1[i] * v[i + 4] + a2[i] * v[i + 1] + a3[i] * v[i] + a4[i - 1] * v[i - 1] + a5[i - 4] * v[i - 4];
    }

    for (std::size_t i = 124; i < a3.size() - 1; i++) {
        result[i] = a2[i] * v[i + 1] + a3[i] * v[i] + a4[i - 1] * v[i - 1] + a5[i - 4] * v[i - 4];
    }

    result[127] = a3[127] * v[127] + a4[126] * v[126] + a5[123] * v[123];

    return result;
}
