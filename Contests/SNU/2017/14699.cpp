#include <bits/stdc++.h>
using namespace std;
#define MAX 5001
int height[MAX];
int dp[MAX];
bool comp(int i, int j) { return height[i] > height[j]; }
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> vertices;
    vector<int> edges[MAX];
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        height[i + 1] = temp;
        vertices.push_back(i + 1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (height[a] > height[b])
            swap(a, b);
        edges[a].push_back(b);
    }
    sort(vertices.begin(), vertices.end(), comp);

    for (int idx : vertices) {
        dp[idx] = 1;
        for (int adj : edges[idx]) {
            dp[idx] = max(dp[idx], dp[adj] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i + 1] << "\n";
    }
}