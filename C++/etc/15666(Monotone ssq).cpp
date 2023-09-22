#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m;
set<int> seq_set;
vector<int> seq_vec;
vector<int> curr(10);
void dfs(int idx, int start){
    if(idx == m){
        for(int i=0; i<m; i++) cout << curr[i] << ' ';
        cout << endl;
        return;
    }
    for(int i=start; i<seq_set.size(); i++){
        curr[idx] = seq_vec[i];
        dfs(idx+1, i);
    }
}
int main(){
    cin >> n >> m;
    vector<int> curr(m);
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        seq_set.insert(temp);
    }
    for(int item : seq_set) seq_vec.push_back(item);
    dfs(0, 0);
}
