#include <bits/stdc++.h>
using namespace std;
#define MAXN 101010
int parent[MAXN];
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x > y)
        swap(x, y);
    parent[y] = x;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int g, p;
    cin >> g >> p;

    for (int i = 0; i <= g; i++)
        parent[i] = 0;

    int cnt = 0;
    bool flag = true;

    for (int i = 0; i < p; i++) {
        int gate_limit;
        cin >> gate_limit;
        if (!flag)
            continue;
        if (parent[gate_limit] == 0) {
            cnt++;
            parent[gate_limit] = gate_limit;
            if (parent[gate_limit - 1] != 0)
                merge(gate_limit, gate_limit - 1);
            if (gate_limit < g && parent[gate_limit + 1] != 0)
                merge(gate_limit, gate_limit + 1);
        } else {
            int max_block = find(gate_limit);
            if (max_block == 1)
                flag = false;
            else {
                cnt++;
                parent[max_block - 1] = max_block - 1;
                if (parent[max_block - 2])
                    merge(max_block - 1, max_block - 2);
                if (max_block <= g && parent[max_block])
                    merge(max_block - 1, max_block);
            }
        }
    }
    cout << cnt;
}