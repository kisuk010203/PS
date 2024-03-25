#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int school_n, start;
    cin >> school_n;
    vector<string> school(school_n);
    vector<int> stack;
    for (int i = 0; i < school_n; i++) {
        cin >> school[i];
    }

    vector<int> adj_list[school_n];
    for (int i = 0; i < school_n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x - 1].push_back(y - 1);
        start = x - 1;
    }
    stack.push_back(start);
    while (!stack.empty()) {
        int current = stack.back();
        cout << school[current];
        stack.pop_back();
        for (int i = adj_list[current].size() - 1; i >= 0; i--) {
            stack.push_back(adj_list[current][i]);
        }
    }
    cout << '\n';
}