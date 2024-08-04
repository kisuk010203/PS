#include <bits/stdc++.h>
using namespace std;
int check(string s) {
    char first_char = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != first_char)
            return 0;
    }
    return (first_char == 'B') ? 1 : 2;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            grid.push_back(s);
        }
        string first_coll,last_coll;
        for (int i = 0; i < n; i++) {
            first_coll.push_back(grid[i][0]);
            last_coll.push_back(grid[i][m-1]);
        }
        int first_row = check(grid[0]);
        int last_row = check(grid[n - 1]);
        int first_col = check(first_coll);
        int last_col = check(last_coll);
        if (first_row + last_row == 3 || first_col + last_col == 3) {
            cout << "NO\n";

        } else
            cout << "YES\n";
    }
}