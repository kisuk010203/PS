#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    string winner = (n % 5 == 0 || n % 5 == 2) ? "CY" : "SK";
}
