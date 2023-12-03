#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

const double PI = acos(-1.0);
using cd = complex<double>;

void fft(vector<cd> &a, bool invert) {
    int n = a.size();

    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; ++j) {
                cd u = a[i + j], v = a[i + j + len] * (invert ? conj(w) : w);
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }
        }
    }

    if (invert) {
        for (int i = 0; i < n; ++i)
            a[i] /= n;
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    int n = 1;
    while (n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;

    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];

    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());

    return result;
}

int main() {
    vector<int> a = {1, 2, 3}; // coefficients of first polynomial
    vector<int> b = {4, 5, 6}; // coefficients of second polynomial

    vector<int> result = multiply(a, b);

    // Output the result
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
