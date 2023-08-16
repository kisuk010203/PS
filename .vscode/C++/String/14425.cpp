#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int ans = 0;
    vector<string> find_set;
    for(int i=0; i<n; i++){
        string temp; cin >> temp;
        find_set.push_back(temp);
    }
    sort(find_set.begin(), find_set.end());
    while(m--){
        string temp; cin >> temp;
        bool flag = false;
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(temp == find_set[mid]){
                flag = true;
                break;
            }
            else if(temp > find_set[mid]) left = mid+1;
            else right = mid-1;
        }
        if(flag)
            ans++;
    }
    cout << ans;
}
