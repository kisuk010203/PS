#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll M, N, L;
    cin >> M >> N >> L;
    ll cnt = 0;
    ll* hunter = new ll[M];
    for (ll i = 0; i < M; i++) {
        cin >> hunter[i];
    }
    sort(hunter, hunter + M);
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        ll lb_idx = lower_bound(hunter, hunter + M, a) - hunter;
        if (lb_idx == M) {
            if (a - hunter[M - 1] + b <= L)
                cnt++;
        } else if (lb_idx == 0) {
            if (hunter[lb_idx] - a + b <= L)
                cnt++;
        } else {
            if ((hunter[lb_idx] - a + b <= L) ||
                (a - hunter[lb_idx - 1] + b <= L))
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
