#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100100
typedef pair<ll, ll> p;
int N;
p points[MAX];
int ccw(p temp, p a, p b){
    ll ret = temp.first*a.second + a.first*b.second + b.first*temp.second
    -(temp.second*a.first + a.second*b.first + b.second*temp.first);
    if(ret == 0) return 0;
    return ((ret > 0) ? 1 : -1);
}
int CCW_two(p a, p b){
    p temp = points[0];
    return ccw(temp, a, b);
}
bool ysort(const p &a, const p &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
bool CCW_twosort(const p&a, const p&b){
    if(CCW_two(a, b) == 0){
        ll d1 = (a.first-points[0].first)*(a.first-points[0].first)
            + (a.second-points[0].second)*(a.second-points[0].second);
        ll d2 = (b.first-points[0].first)*(b.first-points[0].first)
            + (b.second-points[0].second)*(b.second-points[0].second);
        return d1 < d2;
    }
    else return CCW_two(a, b) > 0;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int a, b; cin >> a >> b;
        points[i] = {a, b};
    }
    sort(points, points+N, ysort);
    sort(points+1, points+N, CCW_twosort);
    // cout << "------------------------------\n";
    // for(int i=0; i<N; i++)
    //     cout << points[i].first << ' ' << points[i].second << endl;
    vector<p> stk;
    stk.push_back(points[0]);
    stk.push_back(points[1]);
    for(int i=2; i<N; i++){
        while(stk.size()>=2 && ccw(points[i], stk[stk.size()-2], stk[stk.size()-1]) <= 0)
            stk.pop_back();
        stk.push_back(points[i]);
    }
    cout << stk.size() << '\n';
    // for(auto item : stk){
    //     cout << item.first << ' ' << item.second << '\n';
    // }
}
