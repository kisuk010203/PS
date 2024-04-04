#include <bits/stdc++.h>
using namespace std;

vector<int> vec[100001];
int num[100001], cnt;
bool ans = true;
int find_reachable_min(int node, int parent) {
    int ret = num[node] = ++cnt;
    int cycles = 0;
    for (int v : vec[node]) {
        if (v == parent)
            continue;
        if (num[v]) {
            ret = min(ret, num[v]);
            cycles++;
        } else {
            int tmp = find_reachable_min(v, node);
            ret = min(ret, tmp);
            if (num[node] > tmp)
                cycles++;
        }
    }
    if (cycles >= 2)
        ans = false;
    return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    find_reachable_min(1, 1);
    cout << (ans ? "Cactus\n" : "Not cactus\n");

    return 0;
}