#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
int root[MAX];
int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    root[y] = x;
}
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        root[i] = i;
    }
    int end = 10101010;
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        if (end != 10101010)
            continue;
        if (find(x) == find(y))
            end = min(end, i);
        else
            unite(x, y);
    }
    if (end == 10101010)
        cout << 0;
    else
        cout << end;
    return 0;
}
