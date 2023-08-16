#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> points;
ll det(points a, points b){
    ll res =  a.first * b.second - a.second * b.first;
    return res;
}
int main(){
    int num; cin >> num;
    vector <points> point(num);
    ll res = 0;
    for(int i=0; i<num; i++){
        ll x, y; cin >> x >> y;
        point[i] = make_pair(x, y);
    }
    for(int i=0; i<num; i++) res += det(point[i], point[(i+1)%num]);
    res = (res >=0)? res : -1*res;
    cout << (res >>1) << "." << (res&1)*5;
}