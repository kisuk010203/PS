#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int N, done;
int cost[20][20];
int dp[20][1<<20];
int duty(int curr, int done_bit){
    if(done_bit == done){
        return 0;
    }
    if(dp[curr][done_bit] != 0) return dp[curr][done_bit];
    dp[curr][done_bit] = INF;
    for(int i=0; i<N; i++){
        if((done_bit >> i)%2) continue;
        int temp = duty(curr+1, done_bit | (1<<i));
        dp[curr][done_bit] = min(dp[curr][done_bit], temp + cost[curr][i]);
    }
    return dp[curr][done_bit];
}
int main(int argc, char const *argv[])
{
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cin >> N; done = (1<<N)-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin  >> cost[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));

    cout << duty(0, 0);
    return 0;
}
