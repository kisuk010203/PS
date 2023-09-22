#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
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
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        int F; cin >> F;
        for(int i=0; i<MAX; i++){
            sz[i] = 1; root[i] = i;
        }
        unordered_map<string, int> name_map; int cnt = 0;
        while (F--){
            string s, p; cin >> s >> p;
            if(name_map.find(s) == name_map.end())
                name_map[s] = cnt++;
            if(name_map.find(p) == name_map.end())
                name_map[p] = cnt++;
            unite(name_map[s], name_map[p]);
            int f1 = find(name_map[p]);
            int f2 = find(name_map[s]);
            cout << max(sz[f1], sz[f2]) << '\n';
        }

    }

    return 0;
}
