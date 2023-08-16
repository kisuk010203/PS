#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int ver_num, edge_num, ver_cnt, scc_cnt;
int scc_num[MAX];
int searched[MAX];
vector<int> adj[MAX];
vector<int> stk;
int SCC(int start){
    int ret = searched[start] = ver_cnt++;
    stk.push_back(start);
    for(auto item : adj[start]){
        if(searched[item] == -1)
            ret = min(ret, SCC(item));
        else if(scc_num[item] == -1)
            ret = min(ret, searched[item]);
    }
    if(ret == searched[start]){
        while (true){
            int temp = stk.back();
            stk.pop_back();
            scc_num[temp] = scc_cnt;
            if(temp == start) break;
        }
        scc_cnt++;    
    }
    return ret;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> ver_num >> edge_num;
        for(int i=0; i<edge_num; i++){
            int a, b; cin >> a >> b;
            adj[a-1].push_back(b-1);
        }
        fill(searched, searched+ver_num, -1);
        fill(scc_num, scc_num+ver_num, -1);
        for(int i=0; i<ver_num; i++){
            if(searched[i] == -1){
                SCC(i);
            }
        }
        int ans=0;
        bool value[MAX];
        fill(value, value+ver_num, false);
        pair<int, int> p[MAX];
        for(int i=0; i<ver_num; i++){
            p[i] = make_pair(scc_num[i], i);
        }
        sort(p, p+ver_num);
        for(int i=ver_num-1; i>=0; i--){
            int idx = p[i].second;
            if(!value[idx]){
                ans++;
                for(auto item : adj[idx]) value[item] = true;
            }
        }
        cout << ans;
    }
}