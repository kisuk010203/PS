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
        unordered_map<int, int> count;
        int distinct = 0;
        int adj_cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1)
                distinct++;
        }
        for (int x = 1;; x++) {
            if (count.find(x) == count.end())
                break;
            else
                adj_cnt++;
        }
        if (distinct == 1) {
            cout << "Alice\n";
        } else if (distinct % 2 == 0) {
            if (adj_cnt % 2 == 0 && adj_cnt < distinct)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        } else if (distinct % 2 == 1) {
            if (adj_cnt % 2 == 1 && adj_cnt < distinct)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }
}