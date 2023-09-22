#include <bits/stdc++.h>
using namespace std;
typedef bitset<101> bits;
int n, m;
int visited[21];
vector<bits> switches;
unordered_map<int, vector<int>> ans_map;

void dfs(int idx, bits sum) {
    if (idx == m) {
        int cnt = sum.count();
        int ret = cnt * 2 - n;
        if (ans_map.find(ret) == ans_map.end()) {
            vector<int> temp;
            for (int i = 0; i < m; i++) {
                if (visited[i])
                    temp.push_back(i);
            }
            ans_map[ret] = temp;
        }
        return;
    }

    visited[idx] = 0;
    dfs(idx + 1, sum);

    visited[idx] = 1;
    dfs(idx + 1, sum ^ switches[idx]);
}
int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string initial;

    cin >> n >> m;
    cin >> initial;
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        bits bit_temp(temp);
        switches.push_back(bit_temp);
    }
    bits initial_bit(initial);
    memset(visited, 0, sizeof(visited));

        dfs(0, initial_bit);
    for (int i = -n; i <= n; i++) {
        if (ans_map.find(i) == ans_map.end()) {
            cout << "-1\n";
        } else {
            vector<int> ans_vec = ans_map[i];
            cout << ans_vec.size();
            for (int item : ans_vec) {
                cout << " " << item + 1;
            }
            cout << "\n";
        }
    }

    return 0;
}
