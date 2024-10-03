#include <bits/stdc++.h>
using namespace std;
#define NMAX 200200
vector<int> adj[NMAX];
int searched[NMAX];
int adj_rumor[NMAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 1; i<=n; i++) {
        int s; cin >> s;
        while(s != 0){
            adj[i].push_back(s);
            cin >> s;
        }
    }
    int m; cin >> m;
    fill(searched, searched + NMAX, -1);
    fill(adj_rumor, adj_rumor + NMAX, 0);
    queue<int> q;
    for(int i = 0; i < m; i++) {
        int temp; cin >> temp;
        searched[temp] = 0;
        q.push(temp);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int next : adj[cur]) {
            if(searched[next] != -1) continue;
            adj_rumor[next]++;
            if(adj_rumor[next] * 2 >= adj[next].size()) {
                searched[next] = searched[cur] + 1;
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << searched[i] << " ";
    }
}