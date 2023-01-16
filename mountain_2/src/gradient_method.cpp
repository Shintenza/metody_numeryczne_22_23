#include "include/gradient_method.hpp"

void conjugate_gradient_method(std::vector<double> a1, std::vector<double> a2, std::vector<double> a3,
                               std::vector<double> a4, std::vector<double> a5, std::vector<double> &x, std::vector<double> e) {
    std::vector<double> r = vector_diff(e, optimised_mul(a1, a2, a3, a4, a5, x));
    std::vector<double> p = r;
    std::vector<double> tmpX(x);

    double alpha = 0.;
    double beta = 0.;
    double diff;
    
    while (vector_norm(r) > EPS) {
        alpha = vector_mul(r, r) / vector_mul(p, optimised_mul(a1, a2, a3, a4, a5, p));
        std::vector<double> r_k = vector_diff(r, vector_mul(alpha, optimised_mul(a1, a2, a3, a4, a5, p)));
        beta = (vector_mul(r_k, r_k) / vector_mul(r, r));
        std::vector<double> p_k = vector_sum(r_k, vector_mul(beta, p));
        std::vector<double> x_k = vector_sum(x, vector_mul(alpha, p));

        r = r_k;
        p = p_k;
        x = x_k;
        diff = vector_norm(vector_diff(x, tmpX));
        std::copy(x.begin(), x.end(), std::back_inserter(tmpX));
        // std::cout<<std::setprecision(10)<<diff<<std::endl;
    }
}
