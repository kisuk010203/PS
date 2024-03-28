#include <bits/stdc++.h>
using namespace std;
int sumItr(int n, int acc) {
    if (n <= 0)
        return acc;
    else
        return sumItr(n - 1, acc + n);
}
int get_sum(int n) {
    return sumItr(n, 0);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << get_sum(100000);
}
