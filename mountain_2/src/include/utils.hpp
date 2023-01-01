#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

#define EPS 0.0000000001

double vector_norm(std::vector<double> vec);
void display_vector(std::vector<double> vec);
double vector_mul(std::vector<double> v1, std::vector<double> v2);
std::vector<double> vector_mul(double a, std::vector<double> v1);
std::vector<double> vector_sum(std::vector<double> v1, std::vector<double> v2);
std::vector<double> vector_diff(std::vector<double> v1, std::vector<double> v2);
std::vector<double> optimised_mul(std::vector<double> a1, std::vector<double> a2, std::vector<double> a3, std::vector<double> a4, std::vector<double> a5, std::vector<double> v);
