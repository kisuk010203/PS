#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pos;
typedef struct {
    pos red;
    pos blue;
    int level;
} State;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    pos red, blue, hole;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j];
            if (arr[i][j] == 'R') {
                red = {i, j};
            } else if (arr[i][j] == 'B') {
                blue = {i, j};
            } else if (arr[i][j] == 'O') {
                hole = {i, j};
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<State> q;
    q.push({red, blue, 0});

    while (!q.empty() && q.front().level < 10) {
        State curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pos next_red = curr.red;
            pos next_blue = curr.blue;
            int red_count = 0;
            int blue_count = 0;
            while (arr[next_red.first + dx[i]][next_red.second + dy[i]] !=
                       '#' &&
                   next_red != hole) {
                next_red.first += dx[i];
                next_red.second += dy[i];
                red_count++;
            }
            while (arr[next_blue.first + dx[i]][next_blue.second + dy[i]] !=
                       '#' &&
                   next_blue != hole) {
                next_blue.first += dx[i];
                next_blue.second += dy[i];
                blue_count++;
            }
            if (next_blue == hole) {
                continue;
            }
            if (next_red == hole) {
                cout << curr.level + 1 << "\n";
                return 0;
            }
            if (next_red == next_blue) {
                if (red_count > blue_count) {
                    next_red.first -= dx[i];
                    next_red.second -= dy[i];
                } else {
                    next_blue.first -= dx[i];
                    next_blue.second -= dy[i];
                }
            }
            q.push({next_red, next_blue, curr.level + 1});
        }
    }
    cout << -1;
}