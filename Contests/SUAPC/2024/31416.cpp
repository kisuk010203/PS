#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int queries;
    cin >> queries;
    while (queries--) {
        int ta, tb, va, vb;
        cin >> ta >> tb >> va >> vb;
        int time_d = 0, time_s = 0;
        time_d += tb * vb;
        time_s = time_d / ta * ta;
        va -= time_d / ta;
        if (va <= 0) {
            cout << time_d << '\n';
            continue;
        }
        int time = max(time_d + ta * (va / 2), time_s + ta * (va / 2 + va % 2));
        cout << time << '\n';
    }
}