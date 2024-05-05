#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> b(n * n);
        vector<int> answer;
        for (int i = 0; i < n * n; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        int start = b[0];
        for (int i = 0; i < n; i++) {
            int curr = b[0] + c * i;
            for (int j = 0; j < n; j++) {
                answer.push_back(curr);
                curr += d;
            }
        }
        sort(answer.begin(), answer.end());
        bool flag = true;
        for (int i = 0; i < n * n; i++) {
            if (answer[i] != b[i]) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
    }
}