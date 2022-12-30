#include "include/utils.hpp"
#include "include/gauss_seidel.hpp"
#include "include/gradient_method.hpp"

#include <iostream>
#include <vector>

#define STARTING_VALUE 0


int main() {
    std::vector<double> a1(124, 1);
    std::vector<double> a2(127, 1);
    std::vector<double> a3(128, 4);
    std::vector<double> a4(127, 1);
    std::vector<double> a5(124, 1);

    std::vector<double> e(128, 1);

    std::vector<double> x(128, STARTING_VALUE);
    gauss_seidel_adjusted(a1, a2, a3, a4, a5, x, e);
    // std::cout<<"======A======"<<std::endl;
    display_vector(x);

    std::vector<double> x1(128, STARTING_VALUE);
    conjugate_gradient_method(a1, a2, a3, a4, a5, x1, e);
    // std::cout<<"======B======"<<std::endl;
    display_vector(x1);

    return 0;
}
