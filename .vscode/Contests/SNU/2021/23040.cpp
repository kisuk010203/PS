#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
int N;
bool redblack[MAX];
vector<int> adj[MAX];
int root[MAX];
int sz[MAX];
int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}
void unite(int x, int y){
    x = find(x); y = find(y);
    if(x!=y){
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        root[y] = x;
    }
    root[y] = x;
}
int main(int argc, char const *argv[])
{
    long long ans = 0;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    string rb; cin >> rb;
    for(int i=0; i<N; i++){
        redblack[i] = (rb[i] == 'B');
        sz[i] = 1; root[i] = i;
    }
    for(int i=0; i<N; i++){
        for(auto item : adj[i]){
            if(!redblack[i] && !redblack[item])
                unite(i, item);
        }
    }
    for(int i=0; i<N; i++){
        if(!redblack[i]) continue;
        for(auto item : adj[i]){
            if(!redblack[item]){
                ans += sz[find(item)];
            }
        }
    }
    cout << ans;
    return 0;
}
