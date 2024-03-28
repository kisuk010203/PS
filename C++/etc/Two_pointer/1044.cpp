#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> players(N);
    for (int i = 0; i < N; i++) {
        cin >> players[i];
    }
    vector<pll> left_players[N / 2 + 1];
    vector<pll> right_players[N / 2 + 1];

    for (int i = 0; i < (1 << N / 2); i++) {
        int left_cnt = 0, right_cnt = 0;
        ll left_weight = 0, right_weight = 0;
        for (int j = 0; j < N / 2; j++) {
            if (i & (1 << j)) {
                left_weight += players[j];           // 작은게 나중에 옴
                right_weight += players[N / 2 + j];  // 작은게 나중에 옴
                left_cnt++, right_cnt++;
            }
        }
        left_players[left_cnt].push_back({i, left_weight});
        right_players[right_cnt].push_back({right_weight, i});
    }
    for (int i = 0; i < N / 2; i++) {
        sort(right_players[i].begin(), right_players[i].end());
    }

    ll ans_i = 0, ans_j = 0, ans_min = LONG_LONG_MAX;
    for (int i = 0; i < N / 2; i++) {
        for (pll item : left_players[i]) {
            int j = N / 2 - i;
            vector<pll>::iterator ub = upper_bound(
                right_players[j].begin(), right_players[j].end(), item.second);
            vector<pll>::iterator lb = lower_bound(
                right_players[j].begin(), right_players[j].end(), item.second);
            if (ub == right_players[j].end()) {
                if (lb == right_players[j].end())
                    continue;
                int idx = lb - right_players[j].begin();
                if (ans_min >= abs(right_players[j][idx].first - item.second)) {
                    ans_min = abs(right_players[j][idx].first - item.second);
                    ans_i = item.first;
                    ans_j = right_players[j][idx].second;
                }
            } else if (lb == right_players[j].end()) {
                int idx = ub - right_players[j].begin();
                if (ans_min >= abs(right_players[j][idx].first - item.second)) {
                    ans_min = abs(right_players[j][idx].first - item.second);
                    ans_i = item.first;
                    ans_j = right_players[j][idx].second;
                }
            } else {
                int idx = lb - right_players[j].begin();
                if (ans_min >= abs(right_players[j][idx].first - item.second)) {
                    ans_min = abs(right_players[j][idx].first - item.second);
                    ans_i = item.first;
                    ans_j = right_players[j][idx].second;
                }
                idx = ub - right_players[j].begin();
                if (ans_min >= abs(right_players[j][idx].first - item.second)) {
                    ans_min = abs(right_players[j][idx].first - item.second);
                    ans_i = item.first;
                    ans_j = right_players[j][idx].second;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i < N / 2) {
            if ((1 << i) & ans_i)
                cout << "1 ";
            else
                cout << "2 ";
        } else {
            if ((1 << i - N / 2) & ans_j)
                cout << "1 ";
            else
                cout << "2 ";
        }
    }
}
