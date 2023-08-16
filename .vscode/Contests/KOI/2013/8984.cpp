#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define MAX (int)(1e5 + 7)
ll dptop[MAX];
ll dpdown[MAX];
p line[MAX];
ll downval[MAX];
ll topval[MAX];
bool comp(p a, p b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
int main(int argc, char const *argv[]){
    memset(dptop, 0, sizeof(dptop));
    memset(dpdown, 0, sizeof(dpdown));
    ll N, L; cin >> N >> L;
    for(int i=0; i<N; i++){
        ll t, d; cin >> t >> d;
        line[i] = make_pair(t, d);
        topval[i] = t; downval[i] = d;
    }
    sort(topval, topval+N); sort(downval, downval+N); sort(line, line+N, comp);
    for(int i=0; i<N; i++){
        ll topdx = lower_bound(topval, topval+N, line[i].first) - topval;
        ll downdx = lower_bound(downval, downval+N, line[i].second) - downval;
        ll temp = abs(line[i].first - line[i].second) + L;
        ll temp2 = dptop[topdx];
        dptop[topdx] = max(dptop[topdx], temp + dpdown[downdx]);
        dpdown[downdx] = max(dpdown[downdx], temp + temp2);
    }
    ll ans = -1;
    for(int i=0; i<N; i++){
        ans = (ans > dptop[i]) ? ans : dptop[i];
        ans = (ans > dpdown[i]) ? ans : dpdown[i];
    }
    cout << ans;
    return 0;
}