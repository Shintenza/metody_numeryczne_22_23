#include <iostream>
#include <vector>
#include "include/solver.hpp"


int main() {
    std::vector<double> a(6, 1);
    std::vector<double> b(7, 4);
    std::vector<double> c(6, 1);
    std::vector<double> d = {1, 2, 3, 4, 5, 6, 7};

    const int size = d.size();

    
    std::vector<double> answer_a = solve(a, b, c, d);

    for (double el : answer_a) {
        std::cout<<el<<std::endl;
    }

    printf("\n\n");

    // wykorzystanie wzoru Shermana-Morrisona (wykład 3 s. 52)

    std::vector<double> u = {1, 0, 0, 0, 0, 0, 1};

    b[0] -= 1.;
    b[size - 1] -= 1.;


    std::vector<double> z = solve(a, b, c, d);
    std::vector<double> q = solve(a, b, c, u);

    // stały współczynnik dla każdej iteracji pętli
    double factor = (z[0] + z[size - 1]) / (1. + q[0] + q[size - 1]);

    for (int i = 0; i < size; i++) {
        z[i] -= factor * q[i];
    }

    for (int i = 0; i < size; i++) {
        printf("%lf\n", z[i]);
    }
}

