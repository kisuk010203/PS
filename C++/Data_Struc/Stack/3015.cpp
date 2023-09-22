#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    ll *arr = new ll[n];
    ll *stack = new ll[n+1];
    ll top = n+1, ans = 0;
    for(ll i=0; i<n; i++) cin >> arr[i];
    stack[n] = arr[0]; top--;
    for(ll i=1; i<n; i++){
        ll idx = upper_bound(stack+top, stack+n+1, arr[i]) - (stack+top-1);
        ll idx2 = lower_bound(stack+top, stack+n+1, arr[i]) - stack;
        ans += (idx== n+2-top ? n+1-top : idx);
        if(arr[i] < stack[top])
            stack[--top] = arr[i];
        else{
            stack[idx2-1] = arr[i];
            top = idx2-1;
        }

    }
    cout << ans;
}
