#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, s; cin >> n >> s;
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int start = 0, end = 0, ans = n+1, curr = 0;
    while(start <= end){
        if(curr >= s || end == n){
            if(curr >= s) ans = min(ans, end-start);
            curr -= arr[start];
            start++;
        }
        else{
            end++;
            curr += arr[end-1];
        }
    }
    if(ans == n+1) ans = 0;

    cout << ans;
}