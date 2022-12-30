#include <iostream>
#include <vector>
#include <cmath>
#define R_SCALE 10000

double calculate_lj(std::vector<double> &x, int j) {
    std::size_t size = x.size();
    double a = 1.;
    double b = 1.;

    for (std::size_t i = 0; i < size; i++) {
        if (i == j)
            continue;
        a*=-x[i];
        b*=x[j] -x[i];
    }
    return a/b;
}

int main() {
    std::vector<double> x = {0.062500, 0.187500, 0.312500, 0.437500, 0.562500, 0.687500, 0.812500, 0.937500};
    std::vector<double> fx = {0.687959, 0.073443, -0.517558, -1.077264, -1.600455, -2.080815, -2.507266, -2.860307};


    std::size_t size = x.size();
    std::vector<double> fj(size, 0);
    std::vector<double> fj_prev = fx;

    std::vector<double> a(size, 0);

    std::vector<double> lj_results(size, 0);
    
    for (int i = 0; i < size; i++) {
        lj_results[i] = calculate_lj(x, i);
        a[0] += lj_results[i] * fx[i];
    }
    
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fj[j] = (fj_prev[j] - a[i-1])/x[j];
            a[i] += lj_results[j] * fj[j];
        }
        fj_prev = fj;
    }
    
    // for (int i = a.size() - 1; i>= 0; i--) {
    //     std::cout<<std::round(a[i]*R_SCALE)/R_SCALE<<"*x^"<<i<<" + ";
    // }
    // std::cout<<std::endl;

    for (double e : a ) {
        std::cout<<std::round(e*R_SCALE)/R_SCALE<<std::endl;
    }
    return 0;
}
