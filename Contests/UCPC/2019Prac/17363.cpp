#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
            arr[i][j] = temp[j];
    }
    unordered_map<char, char> rotate = {
        {'.', '.'},  {'O', 'O'}, {'-', '|'}, {'|', '-'}, {'/', '\\'},
        {'\\', '/'}, {'^', '<'}, {'<', 'v'}, {'v', '>'}, {'>', '^'}};
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++)
            cout << rotate[arr[i][j]];
        cout << "\n";
    }
}