#include <bits/stdc++.h>
using namespace std;
#define MAXN 3232
bool visited[MAXN];    // A visited in this scope
int match[MAXN];       // B to A
vector<int> adj[MAXN]; // A to B
char board[MAXN][MAXN];
int n, m;
int di[6] = {-1, 0, 1, -1, 0, 1};
int dj[6] = {-1, -1, -1, 1, 1, 1};
bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && board[i][j] == '.';
}
int encode(int i, int j) { return n * (j / 2) + i; }
void fill_adj() {
    for (int i = 0; i < MAXN; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j += 2) {
            if (!is_valid(i, j))
                continue;
            for (int k = 0; k < 6; k++) {
                if (is_valid(i + di[k], j + dj[k])) {
                    adj[encode(i, j)].push_back(encode(i + di[k], j + dj[k]));
                }
            }
        }
    }
}
bool dfs(int st) {
    if (visited[st])
        return false;
    visited[st] = true;
    for (int child : adj[st]) {
        if (match[child] == -1 || dfs(match[child])) {
            match[child] = st;
            return true;
        }
    }
    return false;
}
int count_possible() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.')
                cnt++;
        }
    }
    return cnt;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; j < m; j++)
                board[i][j] = temp[j];
        }

        fill_adj();
        fill(match, match + MAXN, -1);

        for (int i = 0; i < n * (m - m / 2); i++) {
            fill(visited, visited + MAXN, false);
            dfs(i);
        }
        int res = 0;
        for (int i = 0; i < n * (m / 2); i++) {
            if (match[i] >= 0)
                res++;
        }
        res = count_possible() - res;
        cout << res << "\n";
    }
}