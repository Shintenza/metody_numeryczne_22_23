#include <cmath>
#include <iostream>
#include <vector>
#include "include/linspace.h"


double fn(double x) { return 1. / (1. + 5. * x * x); }

double lj(double x, std::vector<double> &xVec, double j) {
    double numerator = 1.;
    double denominator = 1.;
    for (int i = 0; i < xVec.size(); i++) {
        if (i == j)
            continue;
        numerator *= x - xVec[i];
        denominator *= xVec[j] - xVec[i];
    }
    return numerator / denominator;
}

double lagrange(double x, std::vector<double> &xVec) {
    double result = 0.;
    for (int j = 0; j < xVec.size(); j++) {
        double l = lj(x, xVec, j);
        result += l * fn(x);
    }

    return result;
}

int main() {
    std::vector<double> x = {-7. / 8., -5. / 8., -3. / 8., -1. / 8.,
                             1. / 8.,  3. / 8.,  5. / 8.,  7. / 8.};

    std::vector<double> plot_data_x = linspace(x[0], x[x.size() - 1], 1024);

    for (std::size_t i = 0; i < plot_data_x.size(); i++) {
        std::cout << plot_data_x[i] << "\t" << lagrange(plot_data_x[i], x)
                  << std::endl;
    }
}
