#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int ans = 0;
    while (t--){
        string s; cin >> s;
        int arr[26];
        for(int i=0; i<26; i++) arr[i] = -1;
        bool flag = true;
        for(int i=0; i<s.length(); i++){
            int idx = s[i] - 'a';
            if(arr[idx] == -1 || arr[idx] == i-1) {
                arr[idx] = i;
                continue;
            }
            flag = false;
            break;
        }
        ans += (int)flag;
    }
    cout << ans;
}