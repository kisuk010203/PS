//11401
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
    int n, k; scanf("%d %d", &n, &k);
    ll facn = fact(n), fack = fact(k), facr = fact(n-k);
    fack = getpow(fack, MOD-2);
    facr = getpow(facr, MOD-2);
    printf("%lld", ((facn * fack)%MOD)*facr %MOD);
}