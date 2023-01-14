#include <cmath>
#include <complex>
#include <iostream>
#include <vector>
using cdouble = std::complex<double>;

cdouble horner(cdouble x, std::vector<cdouble> &p) {
    cdouble result = p[p.size() - 1];
    for (int i = p.size() - 2; i >= 0; i--)
        result = result * x + p[i];

    return result;
}

std::vector<cdouble> derivative(std::vector<cdouble> &p) {
    std::vector<cdouble> d(p.size() - 1);
    for (int i = 0; i < d.size(); i++) {
        d[i] = p[i + 1] * (i + 1.);
    }

    return d;
}

cdouble laguerre(std::vector<cdouble> &p, cdouble starting_point) {
    std::vector<cdouble> d = derivative(p);
    std::vector<cdouble> d2 = derivative(d);
    cdouble z = starting_point;
    cdouble pz;
    double n = p.size() - 1;

    do {
        pz = horner(z, p);
        auto dz = horner(z, d);
        auto d2z = horner(z, d2);

        auto sqrt =
            std::sqrt((n - 1) * ((n - 1) * std::pow(dz, 2) - n * pz * d2z));

        if (std::abs(dz + sqrt) > (std::abs(dz - sqrt))) {
            z -= (n * pz) / (dz + sqrt);
        } else {
            z -= (n * pz) / (dz - sqrt);
        }

    } while (std::abs(pz) > 0.00000001);

    return z;
}

std::vector<cdouble> deflate(std::vector<cdouble> &a, cdouble root) {
    int n = a.size() - 1;
    std::vector<cdouble> b(n);

    b[n - 1] = a[n];
    for (int i = n - 1; i > 0; i--) {
        b[i - 1] = a[i] + b[i] * root;
    }

    return b;
}

std::vector<cdouble> find_roots(std::vector<cdouble> &p) {
    std::vector<cdouble> roots;
    std::vector<cdouble> p_current(p);

    while (p_current.size() > 3) {
        cdouble root = laguerre(p_current, cdouble(0., 0.));
        if (!roots.empty())
            root = laguerre(p, root);

        roots.push_back(root);
        p_current = deflate(p_current, root);
    }
    cdouble delta_sqrt = std::sqrt(p_current[1] * p_current[1] -
                                   4. * p_current[2] * p_current[0]);
    roots.push_back((-p_current[1] + delta_sqrt) / (2. * p_current[2]));
    roots.push_back((-p_current[1] - delta_sqrt) / (2. * p_current[2]));

    return roots;
}

void print(std::vector<cdouble> roots) {
    for (auto root : roots) {
        if (std::abs(root.real()) <= 0.0001)
            root -= cdouble(root.real(), 0.);
        if (std::abs(root.imag()) <= 0.0001)
            root -= cdouble(0., root.imag());
        std::cout << root << std::endl;
    }
}

int main() {
    std::vector<cdouble> a = {16, -72, -28, 558, -990, 783, -486, 243};
    std::vector<cdouble> b = {-4, -4, -12, -8, -11, -3, -1, 2, 3, 1, 1};
    std::vector<cdouble> c = {1, cdouble(0, -1), -1, cdouble(0, 1), 1};

    print(find_roots(a));
    std::cout << std::endl;
    print(find_roots(b));
    std::cout << std::endl;
    print(find_roots(c));
}
