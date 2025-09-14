#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool compare(const pii &a, const pii &b) {
    if (a.second == b.second)
        return a.first > b.first;
    else return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; cin >> N >> K;
    vector<pii> games(N);
    for (int i = 0; i < N; i++) cin >> games[i].first >> games[i].second;
    sort(games.begin(), games.end(), compare);

    int cnt = 0;
    int myEnd = -1;
    multiset<int> endTime;
    for (auto &[st, en] : games) {
        if (myEnd >= st) {
            continue;
        }

        auto bound = endTime.lower_bound(st);
        if (!endTime.empty() && bound != endTime.begin() && *(--bound) < st) {
            endTime.erase(bound);
            endTime.insert(en);
        } else if (endTime.size() < K - 1) {
            endTime.insert(en);
        } else {
            cnt++;
            myEnd = en;
        }
    }
    cout << cnt << "\n";
}