#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if ((n + 1) % (n % 100) == 0)
            cout << "Good\n";
        else
            cout << "Bye\n";
    }
}
