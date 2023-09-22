#include <stdio.h>
#include <string.h>
using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}
int max_3(int a, int b, int c){
    return max(max(a, b), c);
}
int main(){
    char s1[1001];
    char s2[1002];
    scanf("%s", s1); scanf("%s", s2);
    int dp[1000][1000] = {0};
    int prev[1000][1000] = {0};
    int n1 = strlen(s1), n2 = strlen(s2);
    dp[0][0] = (s1[0] == s2[0]);
    for(int j=1; j<n2; j++){
        dp[0][j] = max((int)(s1[0] == s2[j]), dp[0][j-1]);
        if(dp[0][j] == (s1[0] == s2[j])) prev[0][j] = s1[0] - 'A';
        else prev[0][j] = -2;
    }
    for(int i=1; i<n1; i++){
        dp[i][0] = max((int)(s1[i] == s2[0]), dp[i-1][0]);
        if(dp[i][0] == (s1[i] == s2[0])) prev[i][0] = s1[i] - 'A';
        else prev[i][0] = -1;
    }
    for(int i=1; i<n1; i++){
        for(int j=1; j<n2; j++){
            dp[i][j] = max_3(dp[i-1][j], dp[i][j-1], (int) (s1[i] == s2[j])+dp[i-1][j-1]);
            if((int) (s1[i] == s2[j])+dp[i-1][j-1] == dp[i][j])
                prev[i][j] = s1[i] - 'A';
            else if(dp[i-1][j] == dp[i][j]) prev[i][j] = -1;
            else prev[i][j] = -2;
        }
    }
    int ans = dp[n1-1][n2-1];
    printf("%d\n", ans);
    int x = n1-1, y = n2-1;
    while(ans){
        if(prev[x][y] >= 0){
            ans--;
            printf("%c", 'A' + prev[x][y]);
        }
        else if(prev[x][y] == -1) x--;
        else y--;
    }
}
