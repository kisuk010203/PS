#include <iostream>
using namespace std;
typedef long long ll;
ll x[4];
ll y[4];
int ccw(int i, int j, int k){
    ll a = x[i]*y[j]+x[j]*y[k]+x[k]*y[i] - (x[j]*y[i]+x[k]*y[j]+x[i]*y[k]);
    return (a>0) ? 1 : ((a==0)?0 :-1);
}
int main(){
    for(int i=0; i<3; i++) cin >> x[i] >> y[i];
    cout << ccw(0,1,2);
}