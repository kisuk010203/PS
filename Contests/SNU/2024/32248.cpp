#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> cycle;
pair<bool, int> find(int target) {
    for (int i = 0; i < cycle.size(); i++) {
        if (cycle[i] == target)
            return {true, i};
    }
    return {false, -1};
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll t;
    cin >> n >> t;
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
    }

    int start = 0;
    while (!find(start).first) {
        cycle.push_back(start);
        start = nxt[start];
    }
    pair<bool, int> find_start = find(start);
    int cycle_len = cycle.size() - find_start.second;
    int cycle_start = find_start.second;
    if (t < cycle_start) {
        cout << cycle[t] + 1;
    } else {
        t -= cycle_start;
        t %= cycle_len;
        cout << cycle[cycle_start + t] + 1;
    }
}