#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        vector<int> accum(n + 1, 0);
        vector<pii> accum_index_pair;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            accum[i] = accum[i - 1] ^ a[i];
            accum_index_pair.push_back({accum[i], i});
        }
        sort(accum_index_pair.begin(), accum_index_pair.end());
        while (q--) {
            int l, r;
            cin >> l >> r;
            int sum_all = accum[r] ^ accum[l - 1];
            if (sum_all == 0) {
                cout << "YES\n";
                continue;
            }
            int first_cut = upper_bound(accum_index_pair.begin(),
                                        accum_index_pair.end(), make_pair(accum[r], l - 1)) -
                            accum_index_pair.begin();
            if (first_cut == n || accum_index_pair[first_cut].first != accum[r] || accum_index_pair[first_cut].second > r) {
                cout << "NO\n";
                continue;
            }
            int second_cut = upper_bound(accum_index_pair.begin(),
                                         accum_index_pair.end(), make_pair(accum[l-1], accum_index_pair[first_cut].second)) -
                             accum_index_pair.begin();
            if(second_cut == n || accum_index_pair[second_cut].first != accum[l-1] || accum_index_pair[second_cut].second > r) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
        }
        cout << "\n";
    }
}