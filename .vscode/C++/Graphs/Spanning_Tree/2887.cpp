#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
typedef struct disjoint_set{
    vector<int> parent, rank;
    disjoint_set(int n) : parent(n), rank(n, 1){
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }
}disjoint_set;
typedef tuple<int, int, int, int> tu;
int V;
vector<tuple<int, int, int, int>> x, y, z;
bool cmp_x(tu a, tu b){
    return get<1>(a) < get<1>(b);
}
bool cmp_y(tu a, tu b){
    return get<2>(a) < get<2>(b);
}
bool cmp_z(tu a, tu b){
    return get<3>(a) < get<3>(b);
}
int kruskal(){
    int ret = 0;
    vector<pair<int, pair<int, int>>> edges;
    for(int u=0; u<V-1; u++){
        edges.push_back(make_pair(abs(get<1>(x[u])-get<1>(x[u+1])), make_pair(get<0>(x[u]), get<0>(x[u+1]))));
        edges.push_back(make_pair(abs(get<2>(y[u])-get<2>(y[u+1])), make_pair(get<0>(y[u]), get<0>(y[u+1]))));
        edges.push_back(make_pair(abs(get<3>(z[u])-get<3>(z[u+1])), make_pair(get<0>(z[u]), get<0>(z[u+1]))));
    }
    sort(edges.begin(), edges.end());
    disjoint_set sets(V);
    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        ret += cost;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V;
    int a, b, c;
    for(int i=0; i<V; i++){
        cin >> a >> b >> c;
        tuple<int, int, int, int> temp = make_tuple(i, a, b, c);
        x.push_back(temp);
        y.push_back(temp);
        z.push_back(temp);
    }
    sort(x.begin(), x.end(), cmp_x);
    sort(y.begin(), y.end(), cmp_y);
    sort(z.begin(), z.end(), cmp_z);
    int ret = kruskal();
    cout << ret;
}
