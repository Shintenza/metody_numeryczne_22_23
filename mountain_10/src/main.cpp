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
    linspaced.push_back(end);

    return linspaced;
}

double fn(double x) { return 1. / (1. + 5. * x * x); }

double weight(int k, int d, std::vector<double> &xVec) {
    double w = 0;
    for (int i = std::max(k - d, 0); i <= k && i < xVec.size() - d; i++) {
        double mul = 1.0;
        for (int j = i; j <= i + d; j++) {
            if (j == k)
                continue;
            mul *= 1 / (xVec[k] - xVec[j]);
        }
        w += std::pow(-1, i) * mul;
    }
    return w;
}

double floater_hormann(double x, int d, std::vector<double> &xVec,
                       std::vector<double> &fx, std::vector<double> &weights) {
    double numerator = 0.0;
    double denominator = 0.0;

    for (int k = 0; k < xVec.size(); k++) {
        if (std::abs(x - xVec[k]) < 0.0001) {
            return fx[k];
        }

        double a = weights[k] / (x - xVec[k]);
        numerator += a * fx[k];
        denominator += a;
    }

    return numerator / denominator;
}

int main() {
    int d = 3;
    std::vector<double> x = {-7. / 8., -5. / 8., -3. / 8., -1. / 8.,
                             1. / 8.,  3. / 8.,  5. / 8.,  7. / 8.};
    std::vector<double> fx(x.size());
    std::vector<double> weights(x.size());

    for (int i = 0; i < x.size(); i++) {
        fx[i] = fn(x[i]);
        weights[i] = weight(i, d, x);
    }

    std::vector<double> plot_data_x = linspace(x[0], x[x.size() - 1], 1024);

    for (std::size_t i = 0; i < plot_data_x.size(); i++) {
        std::cout << plot_data_x[i] << "\t"
                  << floater_hormann(plot_data_x[i], d, x, fx, weights)
                  << std::endl;
    }
}
