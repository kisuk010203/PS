#include <bits/stdc++.h>
using namespace std;
#define max_V 10001
#define INF 2147483647
int V, E;
vector<pair<int, int>> adj[max_V];

int prim(){
    vector<bool> added(V, false);
    vector<int> minWeight(V, INF), parent(V, -1);
    int ret = 0;
    minWeight[0] = parent[0] = 0;
    for(int iter = 0; iter<V; iter++){
        int u = -1;
        for(int v=0; v<V; v++)
            if(!added[v] && (u ==-1 || minWeight[u] > minWeight[v]))
                u = v;
        ret += minWeight[u]; added[u] = true;
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first, weight = adj[u][i].second;
            if(!added[v] && minWeight[v] > weight){
                parent[v] = u;
                minWeight[v] = weight;
            }
        }               
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V >> E; 
    int a, b, weight;
    for(int i=0; i<E; i++){
        cin >> a >> b >> weight;
        adj[a-1].push_back(make_pair(b-1, weight));
        adj[b-1].push_back(make_pair(a-1, weight));
    }
    int ret = prim();
    cout << ret;


}