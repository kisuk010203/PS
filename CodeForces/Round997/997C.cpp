#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    vector<int> v[101];
    for(int i = 10; i <= 100; i += 2) {
        rep(j, 0, i/2) v[i].push_back(1);
        rep(j, 0, 2) v[i].push_back(2);
        rep(j, 0, i/2 - 2) v[i].push_back(1);
    }
    for(int i = 13; i <= 100; i+=2) {
        rep(j, 0, i/2) v[i].push_back(1);
        rep(j, 0, 2) v[i].push_back(2);
        rep(j, 0, i/2 - 2) v[i].push_back(1);
        v[i].push_back(3);
    }
    v[6] = {1, 1, 2, 3, 1, 2};
    v[7] = {1, 1, 2, 3, 1, 2, 3};
    v[8] = {2, 2, 1, 2, 3, 4, 1, 1};
    v[9] = {7, 3, 3, 7, 5, 3, 7, 7, 3};
    v[11] = {7, 3, 3, 7, 5, 3, 7, 7, 3, 7, 4};


    while(T--) {
        int n; cin >> n;
        each(a, v[n]) cout << a << " ";
        cout << "\n";
    }
}