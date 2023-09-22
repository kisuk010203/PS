#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m;
int combdp[2001][2001];
int main(){
    cin >> n >> k >> m;
    ll ret = 1;
    for(int i=0; i<=m; i++){
        combdp[i][0] = 1;
    }
    combdp[1][1] = 1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=i; j++){
            combdp[i][j] = (combdp[i-1][j-1] + combdp[i-1][j])%m;
        }
    }
    while(n>0){
        ret = (ret*combdp[n%m][k%m])%m;
        n/=m; k/=m;
    }
    cout << ret;
}
