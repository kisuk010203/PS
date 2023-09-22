#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> adj_list[MAX];
bool visited[MAX];
int depth[MAX];
int par[MAX][20];

void find_depth(int curr){
    visited[curr] = true;
    for(auto child : adj_list[curr]){
        if(!visited[child]){
            int exp = 1;
            par[child][0] = curr;
            while(par[par[child][exp-1]][exp-1] != 0){
                par[child][exp] = par[par[child][exp-1]][exp-1];
                exp++;
            }
            depth[child] = depth[curr] + 1;
            find_depth(child);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    memset(par, 0, sizeof(par));
    for(int i=1; i<n; i++){
        adj_list[0].push_back(i);
        adj_list[i].push_back(0);
    }
    find_depth(0);
    while(k--){
        int mode; cin >> mode;
        if(mode == 1){//paint
            int a, b, c; cin >> a >> b >> c;
        }
        cin >> v1 >> v2;
        if(depth[v1] < depth[v2]) swap(v1, v2);
        if(depth[v1] > depth[v2]){
            int dep = depth[v1] - depth[v2];
            while(dep > 0){
                for(int i=19; i>=0; i--){
                    if(dep >= (1<<i)){
                        v1 = par[v1][i];
                        dep -= (1<<i);
                    }
                }
            }
        }
        for(int i=19;i>=0;i--){
                if(par[v1][i] != par[v2][i]){
                    v1 = par[v1][i];
                    v2 = par[v2][i];
                }
            }
        }
        if(v1 != v2) v1 = par[v1][0];
        cout<<v1<<"\n";    

}