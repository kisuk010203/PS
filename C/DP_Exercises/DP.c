
/*#include <stdio.h>
#define MAX 1000
typedef long long ll;
int n;
ll arr[MAX];
ll dp[MAX][MAX];
ll min(ll a, ll b){
    return (a<b)?a:b;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld %lld", arr+i, arr+n);
    }
    for(int i=0; i<n-1; i++) {
        dp[i][i+1] = arr[i]*arr[i+1]*arr[i+2];
    }
    for(int d=2; d<=n; d++){
        for(int j=0; j<=n-d-1; j++){
            ll m = dp[j][j+1] + dp[j+2][j+d] + arr[j]*arr[j+d+1]*arr[j+2];
            for(int temp = 1; temp<d-1 ; temp++){
                m = min(dp[j][j+temp]+ dp[j+temp+1][j+d] + arr[j]*arr[j+d+1]*arr[j+temp+1], m);
            }
            dp[j][j+d] = m;
        }
    }
    printf("%lld", dp[0][n-1]);
}*/

//9095
/*
#include <stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int n;
        scanf("%d", &n);
        int dp[12] = {0};
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            dp[i] += dp[i-1];
            if(i>=2) dp[i] += dp[i-2];
            if(i>=3) dp[i] += dp[i-3];
        }
        printf("%d\n", dp[n]);
    }
}*/

//11726
/*
#include <stdio.h>
int main(){
    int n; scanf("%d", &n);
    int dp[1001] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] += dp[i-1];
        if(i>=2) dp[i] += dp[i-2];
        dp[i] %= 10007;
    }
    printf("%d", dp[n]);
}*/

//9251
/*
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
}*/

//2133
/*
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int dp1[31] = {0}; int dp2[31] = {0};
    dp1[0] = 1; dp2[1] = 1; dp2[2] = 0; dp1[2] = 3;
    for(int i=3; i<=n; i++){
        dp1[i] = 2*dp2[i-1] + dp1[i-2];
        dp2[i] = dp1[i-1] + dp2[i-2];
    }
    printf("%d", dp1[n]);
}*/

//14002
/*
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

}*/

//11066
/*
#include <stdio.h>
int main(){
    int t; scanf("%d", &t);
    for(int zz=0; zz<t; zz++){
        int k; scanf("%d", &k);
        int book[500]; for(int i=0; i<k; i++) scanf(" %d", book+i);
        int subsum[500][500] = {0};
        int dp[500][500] = {0};
        for(int i=0; i<k; i++)
            for(int j=i; j<k; j++){
                if(j==i) subsum[i][j] = book[i];
                else subsum[i][j] = subsum[i][j-1] + book[j];
            }
        for(int j=0; j<k; j++){
            for(int i=j-1; i>=0; i--){
                int m = dp[i+1][j] + subsum[i][i]+subsum[i+1][j];
                for(int mid = i; mid<j; mid++){
                    int temp = dp[i][mid] + dp[mid+1][j] + subsum[i][mid]+subsum[mid+1][j];
                    m = (m>temp)?temp:m;
                }
                dp[i][j] = m;
            }
        }
        printf("%d\n", dp[0][k-1]);
    }
}*/

//5582
/*
#include <stdio.h>
#include <string.h>
int main(){
    char s1[4001];
    char s2[4001];
    scanf("%s", s1); scanf("%s", s2);
    int dp[4001][4001] = {0};
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int ans=0;
    for(int j=0; j<n2; j++){
        dp[0][j] = s1[0] == s2[j];
    }
    for(int i=1; i<n1; i++){
        dp[i][0] = s1[i] == s2[0];
    }
    for(int i=1; i<n1; i++){
        for(int j=1; j<n2; j++){
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = 0;
        }
    }
    for(int i=0; i<n1; i++) for(int j=0; j<n2; j++) ans = (ans>dp[i][j])? ans:dp[i][j];
    printf("%d", ans);
}*/

//7579
/*
#include <stdio.h>
#define INF 20000
int max(int a, int b){return (a>b)?a:b;}
int n, m;
int mem[101];
int cost[101];
int dp[101][INF];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf(" %d", mem+i);
    for(int i=0; i<n; i++) scanf(" %d", cost+i);
    for(int j=0; j<INF; j++){
        dp[0][j] = (j>=cost[0])? mem[0] :0;
        for(int i=1; i<n; i++){
            if(j < cost[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + mem[i]);
        }
        if(dp[n-1][j] >= m){
            printf("%d\n", j);
            break;
        }
    }
}*/

//10942
/*
#include <stdio.h>
int n, m;
int arr[2000];
int dp[2001][2001];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf(" %d", arr+i);
    scanf("%d", &m);
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int dist = 1; dist <= n-1; dist++){
        for(int i=0; i<n-dist; i++){
            if(dist == 1) dp[i][i+dist] = (arr[i] == arr[i+dist]);
            else dp[i][i+dist] = (arr[i] == arr[i+dist]) ? dp[i+1][i+dist-1] : 0;
        }
    }
    for(int t=0; t<m; t++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a-1][b-1]);
    }
}*/

//1915
/*
#include <stdio.h>
int n, m;
int arr[1001][1001];
int dp[1001][1001];
int min(int a, int b, int c){
    int temp = (a<b)?a:b;
    return (temp<c)?temp:c;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        char get[1000];
        scanf("%s", get);
        for(int j=0; j<m; j++) arr[i][j] = get[j] -'0';
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0) dp[i][j] = arr[i][j];
            else if(arr[i][j]) dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) +1;
            ans = (ans>dp[i][j])?ans:dp[i][j];
        }
    }
    printf("%d", ans*ans);
}*/

//10422
#include <stdio.h>
typedef long long ll;
#define MOD 1000000007
ll fact(int n){
    ll ans = 1;
    for(int i=1; i<=n; i++) ans = (ans*i)%MOD;
    return ans;
}
ll getpow(ll base, ll power){
    if(!power) return 1;
    ll temp = getpow(base, power/2);
    if(power%2) return ((temp*temp)%MOD *base)%MOD;
    return (temp*temp)%MOD;
}
int main(){
    int t; scanf("%d", &t);
    for(int k=0; k<t; k++){
        int n; scanf("%d", &n);
        if(n%2){
            printf("0\n");
            continue;
        }
        ll facn = fact(n), fack = fact(n/2), inv = getpow(n/2+1, MOD-2);
        fack = getpow(fack, MOD-2);
        ll comb = ((facn * fack)%MOD)*fack %MOD;
        printf("%lld\n", (comb*inv)%MOD);
    }
}
