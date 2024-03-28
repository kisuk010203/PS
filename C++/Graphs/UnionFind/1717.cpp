#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int root[MAX];
int find(int x) {
    if (root[x] == x)
        return x;
    else
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        root[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            unite(b, c);
        else {
            bool ret = (find(c) == find(b));
            if (ret)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
