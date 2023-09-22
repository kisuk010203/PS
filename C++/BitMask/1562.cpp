#include <bits/stdc++.h>
using namespace std;
int n;
#define MOD 1000000000
int dp[10][101][(1<<10)];
int main(){
    cin >> n;
    if(n<10){
        cout << 0; return 0;
    }
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<10; i++) dp[i][1][(1<<i)] = 1;
    for(int len=2 ; len<=n; len++){
        for(int start = 0; start<10; start++){
            for(int state = 0; state<(1<<10); state++){
                if(state & (1<<start)){
                    if(start != 0){
                    dp[start][len][state] = (dp[start-1][len-1][state]
                        +dp[start-1][len-1][state & ~(1<<start)])%MOD;
                    }
                    if(start != 9){
                        dp[start][len][state] += (dp[start+1][len-1][state] +
                        dp[start+1][len-1][state & ~(1<<start)])%MOD;
                        dp[start][len][state]%=MOD;
                    }
                }
                
            }
        }
    }
    int ans = 0;
    for(int i=1; i<10; i++) ans = (ans + dp[i][n][(1<<10)-1])%MOD;
    cout << ans;
}