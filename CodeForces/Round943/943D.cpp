#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void push_cycle(vector<ll> &perm, vector<ll> &cycle, ll pos) {
    cycle.push_back(pos);
    while (perm[pos] != cycle[0]) {
        pos = perm[pos];
        cycle.push_back(pos);
    }
}
ll get_answer(vector<ll> &score, vector<ll> &perm, ll pos, ll k) {
    vector<ll> cycle;
    push_cycle(perm, cycle, pos);
    ll max_answer = 0;
    ll accum_sum = 0;
    for (ll i = 0; i < min((ll)cycle.size(), k); i++) {
        accum_sum += score[cycle[i]];
        max_answer = max(max_answer, accum_sum + (k - i - 1) * score[cycle[i]]);
    }
    return max_answer;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--) {
        ll n, k, p_b, p_s;
        cin >> n >> k >> p_b >> p_s;
        vector<ll> perm(n + 1);
        vector<ll> score(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> perm[i];
        }
        for (ll i = 1; i <= n; i++) {
            cin >> score[i];
        }
        ll answer_b = get_answer(score, perm, p_b, k);
        ll answer_s = get_answer(score, perm, p_s, k);
        if (answer_b > answer_s)
            cout << "Bodya\n";
        else if (answer_b < answer_s)
            cout << "Sasha\n";
        else
            cout << "Draw\n";
    }
}