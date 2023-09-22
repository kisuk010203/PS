#include <iostream>
using namespace std;
typedef long long ll;
ll x[4];
ll y[4];
int ccw(int i, int j, int k){
    ll a = x[i]*y[j]+x[j]*y[k]+x[k]*y[i] - (x[j]*y[i]+x[k]*y[j]+x[i]*y[k]);
    return (a>0) ? 1 : -1;
}
int main(){
    for(int i=0; i<4; i++) cin >> x[i] >> y[i];
    int a = ccw(0,1,2)*ccw(0,1,3);
    int b = ccw(2,3,0)*ccw(2,3,1);
    if(a == -1 && b == -1) cout << 1;
    else cout << 0;
}
