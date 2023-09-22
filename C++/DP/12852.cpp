#include <bits/stdc++.h>
using namespace std;
int dp[1000001][2];
void change_dp(int curr, int target){
    if(dp[curr][0] > dp[target][0] + 1){
        dp[curr][0] = dp[target][0] + 1; dp[curr][1] = target;
    }
}
int main(){
    int n; cin >> n;
    dp[1][0] = 0; dp[1][1] = 0;
    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][0] + 1; dp[i][1] = i-1;
        if(i%6 == 0){
            change_dp(i, i/2); change_dp(i, i/3);
        }
        else if(i%2 == 0){
            change_dp(i, i/2);
        }
        else if(i%3 == 0){
            change_dp(i, i/3);
        }
    }
    cout << dp[n][0] << endl;
    printf("%d", n);
    while(dp[n][1]){
        printf(" %d", dp[n][1]); n = dp[n][1];
    }
}