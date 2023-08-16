#include <bits/stdc++.h>
using namespace std;
int vertex_num, edge_num;
int scc_count, vetrtex_count;
vector<int> adj[10001];
vector<int> stk;
int scc_num[10001];
int searched[10001];
int SCC(int start){
    int ret = searched[start] = vetrtex_count++;
    stk.push_back(start);
    for(auto item : adj[start]){
        if(searched[item] == -1){
            ret = min(ret, SCC(item));
        }
        else if(scc_num[item] == -1)
            ret = min(ret, searched[item]);
    }
    if(ret == searched[start]){
        while(true){
            int temp = stk.back();
            stk.pop_back();
            scc_num[temp] = scc_count;
            if(temp == start) break;
        }
        scc_count++;
    }
    return ret;
}
int main(){
    cin >> vertex_num >> edge_num;
    for(int i=0; i<edge_num; i++){
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    fill(searched, searched+vertex_num, -1);
    fill(scc_num, scc_num+vertex_num, -1);
    for(int i=0; i<vertex_num; i++){
        if(searched[i] == -1){
            SCC(i);
        }
    }
    
    cout << scc_count << "\n";
    vector<int> scc_vec[scc_count];
    for(int i=0; i<vertex_num; i++){
        scc_vec[scc_num[i]].push_back(i+1);
    }
    vector<pair<int, int>> sort_vec;
    for(int i=0; i<scc_count; i++){
        sort_vec.push_back(make_pair(scc_vec[i][0], i));
    }
    sort(sort_vec.begin(), sort_vec.end());
    for(int i=0; i<scc_count; i++){
        for(auto item : scc_vec[sort_vec[i].second])
            cout << item << ' ';
        cout << -1 << '\n';
    }
}