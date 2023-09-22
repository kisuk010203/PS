#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
ll numbers[15];
ll exps[15];
ll expsMOD[751];
ll dp[1<<15][100];
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(int argc, char const *argv[])
{
    vector<string> stringset;
    memset(dp, 0, sizeof(dp));
    memset(numbers, 0, sizeof(numbers));
    dp[0][0] = 1;
    expsMOD[0] = 1;
    cin >> N;

    for(ll i=0; i<N; i++){
        string temp; cin >> temp;
        stringset.push_back(temp);
    }
    cin >> K;
    for(ll i=1; i<=750; i++){
        expsMOD[i] = (expsMOD[i-1]*10)%K;
    }
    for(ll i=0; i<N; i++){
        string temp = stringset[i];
        exps[i] = temp.size();
        for(ll j=0; j<exps[i]; j++){
            numbers[i] += (temp[exps[i]-j-1]-'0')*expsMOD[j];
            numbers[i] %= K;
        }
    }
    for(ll temp = 0; temp < (1<<N); temp++){
        ll expss = 0;
        for(ll i=0; i<N; i++)
            if((temp>>i)%2) expss += exps[i];
        for(ll i=0; i<N; i++){
            if((temp >> i)%2) continue;
            ll added = (expsMOD[expss] * numbers[i])%K;
            for(ll j=0; j<K; j++){
                dp[(temp | (1<<i))][((j+added)%K)] += dp[temp][j];
            }
        }
    }
    ll ans = dp[(1<<N)-1][0];
    ll denom = 1;
    for(int i=2; i<=N; i++){
        denom *= i;
    }
    ll g = gcd(ans, denom);
    cout << ans/g << '/' << denom/g;
    return 0;
}
