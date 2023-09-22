#include <stdio.h>
#include <string.h>
int max(int a, int b, int c){
    int temp = (a>b)?a:b;
    return (temp>c)?temp:c;
}
int max2(int a, int b){
    return (a>b)?a:b;
}
int main(){
    char s1[1001];
    char s2[1002];
    scanf("%s", s1); scanf("%s", s2);
    int dp[1000][1000] = {0};
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    dp[0][0] = (s1[0] == s2[0]);
    for(int j=1; j<n2; j++){
        dp[0][j] = max2(s1[0] == s2[j], dp[0][j-1]);
    }
    for(int i=1; i<n1; i++){
        dp[i][0] = max2(s1[i] == s2[0], dp[i-1][0]);
    }
    for(int i=1; i<n1; i++){
        for(int j=1; j<n2; j++){
            dp[i][j] = max((s1[i] == s2[j])+dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        }
    }
    printf("%d", dp[n1-1][n2-1]);
}
