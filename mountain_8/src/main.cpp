#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
std::vector<double> linspace(T start_in, T end_in, int num_in) {

    std::vector<double> linspaced;

    double start = static_cast<double>(start_in);
    double end = static_cast<double>(end_in);
    double num = static_cast<double>(num_in);

    if (num == 0) {
        return linspaced;
    }
    if (num == 1) {
        linspaced.push_back(start);
        return linspaced;
    }

    double delta = (end - start) / (num - 1);

    for (int i = 0; i < num - 1; ++i) {
        linspaced.push_back(start + delta * i);
    }
    linspaced.push_back(end); // I want to ensure that start and end
                              // are exactly the same as the input
    return linspaced;
}

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
