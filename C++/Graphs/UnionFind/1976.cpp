#include <bits/stdc++.h>
using namespace std;
#define MAX 201
int root[MAX];
int arr[MAX][MAX];
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
    for (int i = 0; i < n; i++)
        root[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                unite(i, j);
        }
    }
    int prev = -1, curr = -1;
    bool flag = true;
    while (m--) {
        cin >> curr;
        curr--;
        if (prev == -1) {
            prev = curr;
        } else {
            flag = flag & (find(prev) == find(curr));
            prev = curr;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
