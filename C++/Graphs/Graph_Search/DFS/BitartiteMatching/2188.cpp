#include <bits/stdc++.h>
using namespace std;
#define MAX 201
vector<int> adj_list[MAX];
int curr[MAX];
bool visited[MAX];
int n, m;
bool matching(int start){
    if(visited[start]) return false;
    visited[start] = true;
    for(auto i : adj_list[start]){
        if(curr[i] == -1 || matching(curr[i])){
            curr[i] = start; return true;
        }
    } return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<MAX; i++) curr[i] = -1;
    for(int i=0; i<n; i++){
        int temp, ver; cin >> temp;
        for(int j=0; j<temp; j++){
            cin >> ver; adj_list[i].push_back(ver);
        }
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<MAX; j++) visited[j] = false;
        matching(i);
    }
    int res = 0;
    for(int i = 1; i<=m; i++){
        if(curr[i] >=0) res++;
    }
    cout << res;
}