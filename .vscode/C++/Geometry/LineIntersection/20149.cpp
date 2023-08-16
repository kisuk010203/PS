#include <iostream>
using namespace std;
typedef long long ll;
ll x[4];
ll y[4];
int ccw(int i, int j, int k){
    ll a = x[i]*y[j]+x[j]*y[k]+x[k]*y[i] - (x[j]*y[i]+x[k]*y[j]+x[i]*y[k]);
    return (a>0) ? 1 : ((a==0)? 0: -1);
}
int main(){
    for(int i=0; i<4; i++) cin >> x[i] >> y[i];
    int a = ccw(0,1,2)*ccw(0,1,3);
    int b = ccw(2,3,0)*ccw(2,3,1);
    if(a !=1 && b !=1){
        if(a == 0 && b == 0){
            int flag = 0;
            int d = min(x[0], x[1]), e = max(x[0], x[1]);
            int f = min(x[2], x[3]), g = max(x[2], x[3]);
            if(d<f)
                flag = (e>=f);
            
            else if(d==f)
                flag = 1;
            
            else
                flag = (g>=d); 
            d = min(y[0], y[1]), e = max(y[0], y[1]);
            f = min(y[2], y[3]), g = max(y[2], y[3]);
            if(d<f)
                flag = flag && (e>=f);
            
            else if(d==f)
                flag = flag &&1;
            
            else
                flag = flag && (g>=d); 
            cout << flag; return 0;
        }
        cout << 1; return 0;
    } 
    else cout << 0;
}