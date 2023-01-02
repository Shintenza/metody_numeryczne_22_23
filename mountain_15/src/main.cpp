#include "include/solver.hpp"
#include "include/utils.hpp"
#include <eigen3/Eigen/Dense>
#include <iostream>

void calculate_eps(std::vector<double> &eps, std::vector<double> &xValues, std::vector<double> &yValues) {
    std::size_t epsSize = eps.size();
    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> c;
    std::vector<double> d;

    for (std::size_t i = 0; i < epsSize - 1; i++) {
        b.push_back((xValues.at(i + 2) - xValues.at(i)) / 3.);
    }

    for (std::size_t i = 0; i < epsSize - 2; i++) {
        double value = (xValues.at(i + 2) - xValues.at(i + 1)) / 6;
        a.push_back(value);
        c.push_back(value);
    }

    for (std::size_t i = 0; i < epsSize - 1; i++) {
        d.push_back(((yValues.at(i + 2) - yValues.at(i + 1)) / (xValues.at(i + 2) - xValues.at(i + 1))) - ((yValues.at(i + 1) - yValues.at(i)) / (xValues.at(i + 1) - xValues.at(i))));

    }
    eps = solve(a, b, c, d);
}

double cubic_spline(int j, double x, std::vector<double> &xVec, std::vector<double> &yVec, std::vector<double> &epsVec) {
    double a = (xVec[j + 1] - x) / (xVec[j + 1] - xVec[j]);
    double b = (x - xVec[j]) / (xVec[j + 1] - xVec[j]);
    double c = ((std::pow(a, 3.0) - a) * std::pow(xVec[j + 1] - xVec[j], 2.0)) / 6;
    double d = ((std::pow(b, 3.0) - b) * std::pow(xVec[j + 1] - xVec[j], 2.0)) / 6;

    return a * yVec[j] + b * yVec[j + 1] + c * epsVec[j] + d * epsVec[j + 1];
}

int main() {
    std::vector<double> xValues;
    std::vector<double> yValues;

    read_data(xValues, yValues);
    std::size_t size = xValues.size();
    std::vector<double> eps(size-2);

    calculate_eps(eps, xValues, yValues);

    eps.push_back(0);
    eps.insert(eps.begin(), 0);

    std::vector<double> plot_data_x = linspace(xValues[0], xValues[xValues.size() - 1], 2048);

    for (std::size_t i = 0; i < plot_data_x.size(); i++) {
        int j;

        if (i == plot_data_x.size() - 1)
            j = (int)((plot_data_x[i] - xValues[0]) / (xValues[1] - xValues[0]) - 1);
        else
            j = (int)((plot_data_x[i] - xValues[0]) / (xValues[1] - xValues[0]));

        std::cout << plot_data_x[i] << "\t" << cubic_spline(j, plot_data_x[i], xValues, yValues, eps) << std::endl;
    }

    return 0;
}
