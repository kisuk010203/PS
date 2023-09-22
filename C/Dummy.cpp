#include <stdio.h>
int main(){
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i=0; i<n; i++) scanf(" %d",arr+i);
    int dp[1000][2] = {0};
    dp[0][0] = 1, dp[0][1] = 0;
    int val = 1 , idx = 0;
    for(int i=1; i<n; i++){
        int mlen=0, prev;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && mlen < (dp[j][0] + 1)){
                mlen = dp[j][0] + 1;
                prev = j;
            }
        }
        if(mlen!=0){
            dp[i][0] = mlen;
            dp[i][1] = prev;
        }
        else{
            dp[i][0] = 1;
            dp[i][1] = prev;
        }
        if(dp[i][0] > val){
            val = dp[i][0];
            idx = i;
        }
    }

    printf("%d\n", val);
    int ans[1000] = {0};
    for(int m = val; m>0; m--){
        ans[m-1] = arr[idx];
        idx = dp[idx][1];
    }
    for(int i=0; i<val; i++) printf("%d ",ans[i]);

}
