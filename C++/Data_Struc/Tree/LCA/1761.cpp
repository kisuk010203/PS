#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> p;
int N,M,dep;
vector <p> adj_list[40001];
bool visited[40001];
int depth[40001];
p par[40001][20];

void DFS(int point) {
    visited[point] = true;
    for(auto child : adj_list[point]) {
        if(!visited[child.first]) {
            int exp = 1;
            par[child.first][0] = make_pair(point, child.second);
            while(par[par[child.first][exp-1].first][exp-1].first != -1) {
                par[child.first][exp] = make_pair(par[par[child.first][exp-1].first][exp-1].first,
                    par[par[child.first][exp-1].first][exp-1].second + par[child.first][exp-1].second);                exp++;
            }
            depth[child.first] = depth[point] + 1;
            DFS(child.first);
        }
    }
}


int main() {
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N;
    for(int i=0; i<40001; i++) for(int j=0; j<20; j++) par[i][j] = make_pair(-1, -1);
    for(int i=1;i<N;i++) {
        int v1,v2; ll weight;
        cin>>v1>>v2>>weight;
        adj_list[v1].push_back(make_pair(v2, weight));
        adj_list[v2].push_back(make_pair(v1, weight));
    }
    DFS(1);
    cin>>M;
    while(M--) {
        int v1,v2;
        ll res = 0;
        cin>>v1>>v2;
        if(depth[v1]<depth[v2])
            swap(v1,v2);
        if(depth[v1]>depth[v2]) {
            int dep = depth[v1]-depth[v2];
            while(dep>0) {
                for(int i=19;i>=0;i--) {
                    if((1<<i)<=dep) {
                        res += par[v1][i].second;
                        v1 = par[v1][i].first;
                        dep -= (1<<i);
                    }
                }
            }
        }
        for(int i=19;i>=0;i--){
                if(par[v1][i].first != par[v2][i].first){
                    res += (par[v1][i].second + par[v2][i].second);
                    v1 = par[v1][i].first;
                    v2 = par[v2][i].first;
                }
            }

        if(v1 != v2) res+= (par[v1][0].second + par[v2][0].second);
        cout<<res<<"\n";
    }
}
