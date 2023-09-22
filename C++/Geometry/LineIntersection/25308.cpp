#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ccw(ll i, ll j, ll k){
    ll temp = (i+k)*(i+k)*j*j - 2*i*i*k*k;
    return (temp>=0);
}
int main(int argc, char const *argv[])
{
    ll arr[8];
    ll ans = 0, cnt = 0;
    for(ll i=0; i<8; i++)
        cin >> arr[i];
    ll idx[8] = {0,1,2,3,4,5,6,7};
    do{
        bool temp = true;
        for(ll i=0; i<8; i++){
            ll a = i;
            ll b = ((i+1)%8);
            ll c = ((i+2)%8);
            temp = temp && ccw(arr[idx[a]], arr[idx[b]], arr[idx[c]]);
        }
        if(temp) ans++;
    } while (next_permutation(idx, idx+8));
    cout << ans;
}
