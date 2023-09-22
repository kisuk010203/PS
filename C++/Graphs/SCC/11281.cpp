#include <bits/stdc++.h>
using namespace std;
#define MAX 20004
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
    cin >> ver_num >> edge_num;
    for(int i=0; i<edge_num; i++){
        int a, b; cin >> a >> b;
        if(a>0 && b>0){
            adj[a-1+ver_num].push_back(b-1);
            adj[b-1+ver_num].push_back(a-1);
        }
        else if(a>0){
            adj[a-1+ver_num].push_back(-1*b-1+ver_num);
            adj[-1*b -1].push_back(a-1);
        }
        else if(b>0){
            adj[b-1+ver_num].push_back(-1*a-1+ver_num);
            adj[-1*a-1].push_back(b-1);
        }
        else{
            adj[-1*a-1].push_back(-1*b-1+ver_num);
            adj[-1*b-1].push_back(-1*a-1+ver_num);
        }
    }
    ver_num *= 2;
    fill(searched, searched+ver_num, -1);
    fill(scc_num, scc_num+ver_num, -1);
    for(int i=0; i<ver_num; i++){
        if(searched[i] == -1){
            SCC(i);
        }
    }
    bool ans = true;
    for(int i=0; i<ver_num/2; i++){
        if(scc_num[i] == scc_num[i+ver_num/2]){
            ans = false; break;
        }
    }
    cout << ans << '\n';
    if(ans == 1){
        int value[MAX/2];
        fill(value, value+MAX/2, -1);
        pair<int, int> p[MAX];
        for(int i=0; i<ver_num; i++){
            p[i] = make_pair(scc_num[i], i);
        }
        sort(p, p+ver_num);
        for(int i=ver_num-1; i>=0; i--){
            int idx = p[i].second;
            int idx_mod = idx%(ver_num/2);
            if(value[idx_mod] == -1)
                value[idx_mod] = idx/(ver_num/2);
        }
        for(int i=0; i<ver_num/2; i++){
            cout << value[i] << ' ';
        }
    }
}