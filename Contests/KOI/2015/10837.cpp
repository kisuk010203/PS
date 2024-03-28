#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int k, c;
    cin >> k >> c;
    while (c--) {
        int M, N;
        cin >> M >> N;
        if ((M < N && N > M + (k - M + 1) / 2) ||
            (M > N && M > N + (k - N + 2) / 2))
            cout << "0\n";
        else
            cout << "1\n";
    }

    return 0;
}
