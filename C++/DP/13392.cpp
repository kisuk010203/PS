#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
typedef long long ll;
int N;
int curr[MAX]; int goal[MAX];
ll dp[MAX][10];
ll setdp(int cur, int rot){
    int cnum = (rot+curr[cur])%10;
    int left = (goal[cur]-cnum+10)%10;
    int right = (cnum-goal[cur]+10)%10;
    if(cur == N-1) return dp[cur][rot] = min(left, right);
    if(dp[cur][rot] != -1) return dp[cur][rot];
    return (dp[cur][rot] = 
    min(setdp(cur+1, (rot+left)%10)+left, setdp(cur+1, rot)+right));
}
int main(int argc, char const *argv[])
{
    cin >> N;
    string currst; cin >> currst;
    string goalst; cin >> goalst;
    for(int i=0; i<N; i++){
        curr[i] = currst[i] - '0';
        goal[i] = goalst[i] - '0';
    }
    memset(dp, -1, sizeof(dp));
    ll ans = setdp(0, 0);
    cout << ans;
    return 0;
}
