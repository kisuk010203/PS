#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003
using ll = long long;

vector<vector<ll>> graph;
vector<vector<ll>> one;
vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    vector<vector<ll>> c(a.size(), vector<ll>(a.size(), 0));
    for (ll i = 0; i < a.size(); i++) 
        for (ll k = 0; k < a.size(); k++)
            for (ll j = 0; j < a.size(); j++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
    return c;
}
vector<vector<ll>> pow(vector<vector<ll>> base, ll exp) {
    if (exp == 0) return one;
    vector<vector<ll>> temp = pow(base, exp / 2);
    temp = mul(temp, temp);
    if (exp & 1) {
        return mul(temp, base);
    } return temp;
}
int main() {
    ll n, s, e, t; cin >> n >> s >> e >> t;
    graph.assign(5 * n, vector<ll>(5 * n, 0));
    one.assign(5 * n, vector<ll>(5 * n, 0));
    vector<vector<ll>> smallGraph;
    for (ll i = 0; i < n; i++) {
        string temp; cin >> temp;
        vector<ll> vtemp;
        for (ll j = 0; j < n; j++) {
            vtemp.push_back(temp[j] - '0');
        }
        smallGraph.push_back(vtemp);
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll val = smallGraph[i][j];
            if (val == 0) continue;
            val--;
            graph[i][j + n * val] = 1L;
        }
    }
    for (ll i = n; i < 5 * n; i++)
            graph[i][i - n] = 1L;
    
    for (ll i = 0; i < 5 * n; i++) one[i][i] = 1L;
    vector<vector<ll>> resGraph = pow(graph, t);
    cout << resGraph[s - 1][e - 1] << "\n";
}