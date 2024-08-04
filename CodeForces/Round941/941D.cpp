#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "25\n";
            for (int i = 1; i <= 24; i++) {
                cout << (1 << i) << " ";
            }
            cout << "3\n";
            continue;
        }
        int power_under_k = 0;
        int power_over_n  =0;
        while (k >> power_under_k)
            power_under_k++;
        while (n >> power_over_n)
            power_over_n++;
        power_under_k--;
        vector<int> answer;
        for (int i = 0; i < power_over_n; i++) {
            if(i != power_under_k)
                answer.push_back(1 << i);
        }
        answer.push_back(k - (1 << power_under_k));
        answer.push_back(k + 1);
        answer.push_back(k + 1 + (1 << power_under_k));
        cout << answer.size() << "\n";
        for (auto item : answer)
            cout << item << " ";
        cout << "\n";
    }
}