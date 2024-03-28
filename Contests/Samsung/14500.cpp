#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define ll long long
int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
ll ans;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    ans = 0;
}
