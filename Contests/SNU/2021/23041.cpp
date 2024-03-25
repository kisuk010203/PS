#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(int argc, char const* argv[]) {
    ll M, N;
    cin >> M >> N;
    if (M == 0 || N == 0) {
        cout << (M + N) * (M + N);
        return 0;
    }
    ll v2 = 1;
    while ((M % 2 == 0) && (N % 2 == 0)) {
        M /= 2;
        N /= 2;
        v2 *= 2;
    }
    ll lat = gcd(M, N) * v2;
    if ((M % 2 == 1) && (N % 2 == 1)) {
        cout << lat * lat * 2;
    } else
        cout << lat * lat;

    return 0;
}
