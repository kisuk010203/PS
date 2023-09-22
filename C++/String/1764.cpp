#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<string> hear;
    vector<string> see;
    vector<string> ans_vec;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        hear.push_back(temp);
    }
    sort(hear.begin(), hear.end());
    for(int i=0; i<m; i++){
        string temp;
        cin >> temp;
        see.push_back(temp);
    }
    sort(see.begin(), see.end());
    int hear_idx=0, see_idx = 0, ans = 0;
    while(hear_idx < n && see_idx < m){
        if(hear[hear_idx] == see[see_idx]){
            ans_vec.push_back(hear[hear_idx]);
            hear_idx++, see_idx++;
            ans++;
        }
        else if(hear[hear_idx] < see[see_idx]){
            hear_idx++;
        }
        else see_idx++;
    }
    cout << ans << '\n';
    for(string temp : ans_vec)
        cout << temp << '\n';
}