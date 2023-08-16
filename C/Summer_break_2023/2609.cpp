#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    int gcd_a_b = gcd(a, b);
    printf("%d\n%d\n", gcd_a_b, a * b / gcd_a_b);
    return 0;
}
