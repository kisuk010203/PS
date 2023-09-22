#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> segment;
#define MAX 6010
ll ccw(p a, p b, p c) {
    ll ans = a.first * b.second + b.first * c.second + c.first * a.second -
             a.second * b.first - b.second * c.first - c.second * a.first;
    return ((ans > 0) ? 1 : -1);
}
bool llersection(segment a, segment b) {
    ll ccw1 =
        ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    ll ccw2 =
        ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
    if (ccw1 == -1 && ccw2 == -1)
        return true;
    return false;
}
ll ver_num, ver_cnt, scc_cnt;
ll scc_num[MAX];
ll searched[MAX];
vector<ll> adj[MAX];
vector<ll> stk;
ll SCC(ll start) {
    ll ret = searched[start] = ver_cnt++;
    stk.push_back(start);
    for (auto item : adj[start]) {
        if (searched[item] == -1)
            ret = min(ret, SCC(item));
        else if (scc_num[item] == -1)
            ret = min(ret, searched[item]);
    }
    if (ret == searched[start]) {
        while (true) {
            ll temp = stk.back();
            stk.pop_back();
            scc_num[temp] = scc_cnt;
            if (temp == start)
                break;
        }
        scc_cnt++;
    }
    return ret;
}
int main() {
    cin >> ver_num;
    ver_num *= 3;
    segment *line = new segment[ver_num];
    for (ll i = 0; i < ver_num; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        line[i] = make_pair(make_pair(a, b), make_pair(c, d));
    }
    for (ll i = 0; i < ver_num; i++) {
        switch (i % 3) {
        case 0:
            adj[i].push_back(i + 1 + ver_num);
            adj[i].push_back(i + 2 + ver_num);
            break;
        case 1:
            adj[i].push_back(i - 1 + ver_num);
            adj[i].push_back(i + 1 + ver_num);
            break;
        case 2:
            adj[i].push_back(i - 1 + ver_num);
            adj[i].push_back(i - 2 + ver_num);
            break;
        default:
            break;
        }
        for (ll j = i + 1; j < ver_num; j++) {
            if (llersection(line[i], line[j])) {
                adj[i + ver_num].push_back(j);
                adj[j + ver_num].push_back(i);
            }
        }
    }
    ver_num *= 2;
    fill(searched, searched + ver_num, -1);
    fill(scc_num, scc_num + ver_num, -1);
    for (ll i = 0; i < ver_num; i++) {
        if (searched[i] == -1) {
            SCC(i);
        }
    }
    bool ans = true;
    for (ll i = 0; i < ver_num / 2; i++) {
        if (scc_num[i] == scc_num[i + ver_num / 2]) {
            ans = false;
            break;
        }
    }
    if (!ans) {
        cout << -1;
        return 0;
    } else {
        ll value[MAX / 2];
        ll ret = 0;
        fill(value, value + MAX / 2, -1);
        p temp[MAX];
        for (ll i = 0; i < ver_num; i++) {
            temp[i] = make_pair(scc_num[i], i);
        }
        sort(temp, temp + ver_num);
        for (ll i = ver_num - 1; i >= 0; i--) {
            ll idx = temp[i].second;
            ll idx_mod = idx % (ver_num / 2);
            if (value[idx_mod] == -1) {
                value[idx_mod] = idx / (ver_num / 2);
                if (value[idx_mod] == 1)
                    ret++;
            }
        }
        cout << ret << '\n';
        for (ll i = 0; i < ver_num / 2; i++) {
            if (value[i] == 1)
                cout << i + 1 << ' ';
        }
    }
}
