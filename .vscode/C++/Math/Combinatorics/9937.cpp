#include <bits/stdc++.h>
using namespace std;
#define PRIME 1000000007
typedef long long ll;
ll select_three(ll n) { return n * (n - 1) * (n - 2) / 6 % PRIME; }
ll select_two(ll n) { return n * (n - 1) / 2 % PRIME; }
void create_or_add(unordered_map<double, ll> &map, double slope) {
    auto idx = map.find(slope);
    if (idx != map.end()) {
        idx->second++;
    } else {
        map[slope] = 1;
    }
}
int main(int argc, char const *argv[]) {
    unordered_map<double, ll> slope;
    int n;
    cin >> n;
    ll infinite_slope = 0;
    for (int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            infinite_slope++;
        else {
            create_or_add(slope, b / a);
        }
    }
    ll ret = select_three(n);
    ll parallels = (select_three(infinite_slope) +
                    select_two(infinite_slope) * (n - infinite_slope)) %
                   PRIME;
    for (const auto &pair : slope) {
        ll value = pair.second;
        ll temp = select_three(value) + select_two(value) * (n - value) % PRIME;
        parallels = (parallels + temp) % PRIME;
    }
    ret = (ret + PRIME - parallels) % PRIME;
    cout << ret << "\n";
    return 0;
}
