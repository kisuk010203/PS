#include <iostream>
using namespace std;
typedef long long ll;
ll x[6];
ll y[6];
int ccw(int i, int j, int k){
    ll a = x[i]*y[j]+x[j]*y[k]+x[k]*y[i] - (x[j]*y[i]+x[k]*y[j]+x[i]*y[k]);
    return (a>0) ? 1 : ((a==0)? 0: -1);
}
int between(int par){
    return (x[par] >= x[2]) && (y[par] >= y[3]) && (x[par] <= x[3]) && (y[par] <= y[2]);
}
int segment_meet(int start_x, int end_x, int start_y, int end_y){
    int a = ccw(start_x, end_x, start_y)*ccw(start_x, end_x, end_y);
    int b = ccw(start_y, end_y, start_x)*ccw(start_y, end_y, end_x);

    if(a !=1 && b !=1){
        if(a == 0 && b == 0){
            int flag = 0;
            int d = min(x[start_x], x[end_x]), e = max(x[start_x], x[end_x]);
            int f = min(x[start_y], x[end_y]), g = max(x[start_y], x[end_y]);
            if(d<f)
                flag = (e>=f);

            else if(d==f)
                flag = 1;

            else
                flag = (g>=d);
            d = min(y[start_x], y[end_x]), e = max(y[start_x], y[end_x]);
            f = min(y[start_y], y[end_y]), g = max(y[start_y], y[end_y]);
            if(d<f)
                flag = flag && (e>=f);

            else if(d==f)
                flag = flag &&1;

            else
                flag = flag && (g>=d);
            return flag;
        }
        return 1;
    }
    return 0;
}
int main(){
    for(int i=0; i<4; i++) cin >> x[i] >> y[i];
    x[4] = x[2], y[4] = y[3], x[5] = x[3], y[5] = y[2];

    if(between(0) && between(1)){
        cout << "T"; return 0;
    }

    int a = segment_meet(0,1,2,4);
    int b = segment_meet(0,1,3,4);
    int c = segment_meet(0,1,3,5);
    int d = segment_meet(0,1,2,5);
    cout << a << b << c << d <<endl;
    if(a || b || c || d) cout << "T";
    else cout << "F";
}
