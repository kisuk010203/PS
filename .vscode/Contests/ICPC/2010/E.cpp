#include <bits/stdc++.h>
using namespace std;
#define MOD 9999991
typedef long long ll;
ll combdp[21][21];
ll comb(int n, int k){// dp for comb
    if(combdp[n][k] != -1) return combdp[n][k];
    if(n<k) return combdp[n][k] = 0;
    if(n == k || k == 0) return combdp[n][k] = 1;
    return combdp[n][k] = (comb(n-1, k) + comb(n-1, k-1))%MOD;
}
ll tree_num(int *arr, int n, int idx, int start, int end){
    if(start >= end || idx == -1) return 1;
    int cnt = 0; // left count
    int allcnt = 0; // all count in range(start, end)
    int firstleft = -1, firstright = -1; // first left index, first right index
    for(int i=idx+1; i<n; i++){
        if(start <= arr[i] && arr[i] <= end){
            allcnt++;
            if(arr[i] < arr[idx] && firstleft == -1) firstleft = i;
            if(arr[i] > arr[idx] && firstright == -1) firstright = i;
            if(arr[i] < arr[idx]) cnt++;
        }
    }
    ll left = tree_num(arr, n, firstleft, start, arr[idx]-1);
    ll right = tree_num(arr, n, firstright, arr[idx]+1, end);
    ll ans = (left*right)%MOD;
    ans = (ans*comb(allcnt, cnt))%MOD;
    //printf("%d %d %d %lld %lld\n", idx, start, end, ans, comb(n-idx-1, cnt));
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    for(int i=0; i<20; i++) for(int j=0; j<20; j++) combdp[i][j] = -1;
    while (t--)
    {
        int n; cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        //cout << "TEST " << t << endl;
        cout << tree_num(arr, n, 0, 1, n) << '\n';

    }
}