#include <bits/stdc++.h>
using namespace std;
int N,M,dep;
vector <int> adj_list[100001];
bool visited[100001];
int depth[100001];
int par[100001][20];

void DFS(int point) {
    visited[point] = true;
    for(auto child:adj_list[point]) {
        if(!visited[child]) {
            int exp = 1;
            par[child][0] = point;
            while(par[par[child][exp-1]][exp-1]!=0) {
                par[child][exp] = par[par[child][exp-1]][exp-1];
                exp++;
            }
            depth[child] = depth[point] + 1;
            DFS(child);
        }
    }
}


int main() {
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N;
    for(int i=1;i<N;i++) {
        int v1,v2;
        cin>>v1>>v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    DFS(1);
    cin>>M;
    while(M--) {
        int v1,v2;
        cin>>v1>>v2;
        if(depth[v1]<depth[v2])
            swap(v1,v2);
        if(depth[v1]>depth[v2]) {
            int dep = depth[v1]-depth[v2];
            while(dep>0) {
                for(int i=19;i>=0;i--) {
                    if((1<<i)<=dep) {
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

        if(v1 != v2) v1 = par[v1][0];
        cout<<v1<<"\n";
    }
}
