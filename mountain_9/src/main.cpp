#include "include/solver.hpp"
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

double fn(double x) {
    return 1. / (1. + 5. * x * x);
}

double cubic_spline(int j, double x, std::vector<double> &xVec, std::vector<double> &yVec, std::vector<double> &epsVec) {
    double a = (xVec[j + 1] - x) / (xVec[j + 1] - xVec[j]);
    double b = (x - xVec[j]) / (xVec[j + 1] - xVec[j]);
    double c = ((std::pow(a, 3.0) - a) * std::pow(xVec[j + 1] - xVec[j], 2.0)) / 6;
    double d = ((std::pow(b, 3.0) - b) * std::pow(xVec[j + 1] - xVec[j], 2.0)) / 6;

    return a * yVec[j] + b * yVec[j + 1] + c * epsVec[j] + d * epsVec[j + 1];
}

int main() {
    std::vector<double> x = {-7. / 8., -5. / 8., -3. / 8., -1. / 8., 1. / 8., 3. / 8., 5. / 8., 7. / 8.};
    double distance = x[1] - x[0];
    int size = x.size();

    std::vector<double> fx(size, 0);

    std::vector<double> eps(size - 2, 0);
    std::vector<double> a(eps.size() - 1, 1);
    std::vector<double> b(eps.size(), 4);
    std::vector<double> c(eps.size() - 1, 1);
    std::vector<double> d(eps.size());

    for (int i = 0; i < size; i++) {
        fx[i] = fn(x[i]);
    }

    for (std::size_t i = 0; i < eps.size(); i++) {
        d[i] = 6.0 / (distance * distance) * (fx[i] - 2 * fx[i + 1] + fx[i + 2]);
    }

    eps = solve(a, b, c, d);

    eps.push_back(0);
    eps.insert(eps.begin(), 0);

    // for (double e : eps) {
    //     std::cout<<e<<std::endl;
    // }

    std::vector<double> plot_data_x = linspace(x[0],x[x.size()-1], 1024);

    for (std::size_t i = 0; i < plot_data_x.size(); i++) {
        int j;

		if (i == plot_data_x.size() - 1)
			j = (int)((plot_data_x[i] - x[0]) / (x[1] - x[0]) - 1);
		else
			j = (int)((plot_data_x[i] - x[0]) / (x[1] - x[0]));

        std::cout<<plot_data_x[i]<<"\t"<<cubic_spline(j, plot_data_x[i], x, fx, eps)<<std::endl;
    }

    // std::cout<<cubic_spline(5, 5./8.,x,fx,eps);
}
