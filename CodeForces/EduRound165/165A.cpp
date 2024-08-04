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
        bool best_friend_mutual = false;
        vector<int> best_friend(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> best_friend[i];
            best_friend[i]--;
            if (best_friend[best_friend[i]] == i)
                best_friend_mutual = true;
        }
        cout << (best_friend_mutual ? 2 : 3) << "\n";
    }
}