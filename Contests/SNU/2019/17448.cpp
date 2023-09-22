#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
vector<ll> arr;
ll n, k;

ll get_exp(ll base, ll expo) {
    if (expo == 0)
        return 1;
    ll temp = get_exp(base, expo / 2);
    if (expo % 2 == 0) {
        return (temp * temp) % MOD;
    }
    return ((temp * temp) % MOD * base) % MOD;
}

ll get_inverse(ll base) { return get_exp(base, MOD - 2); }

ll get_diff(ll a, ll b, ll c) {
    ll temp = (abs(arr[a]) * abs(arr[b])) % MOD;
    return (temp * get_inverse(abs(arr[c]))) % MOD;
}

bool comp(ll a, ll b) {
    if (abs(a) == abs(b)) {
        return a > b;
    }
    return abs(a) > abs(b);
}

ll use_not_toggle() {
    ll ret = 1;
    int positive_count = 0;
    int coin = k - 1;
    for (int i = 0; i < n && coin > 0; i++) {
        if (arr[i] != 0) {
            ret *= abs(arr[i]);
            coin--;
        }
        ret %= MOD;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), comp);

    if (k >= n + 1) {
        ll ans = use_not_toggle();
        cout << ans << "\n";
        return 0;
    }

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                cout << -arr[i] << "\n";
                return 0;
            }
        }
        cout << "1\n";
        return 0;
    }

    int positive_count = 0, last_positive = -1, last_negative = -1,
        first_positive = -1, first_negative = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i] > 0) {
            positive_count++;
            last_positive = i;
        } else if (arr[i] < 0) {
            last_negative = i;
        }
    }
    for (int i = k; i < n; i++) {
        if (arr[i] > 0 && first_positive == -1)
            first_positive = i;
        else if (arr[i] < 0 && first_negative == -1)
            first_negative = i;
    }

    if (positive_count % 2 == 0) {
        ll ans = use_not_toggle();
        if (arr[k - 1] != 0)
            ans = (ans * abs(arr[k - 1])) % MOD;
        cout << ans << "\n";
        return 0;
    }
    vector<long double> candidates;
    if (first_positive >= 0 && last_negative >= 0) {
        candidates.push_back(
            abs((long double)(arr[k - 1] * arr[first_positive]) /
                arr[last_negative]));
    }
    if (first_negative >= 0 && last_positive >= 0) {
        candidates.push_back(
            abs((long double)(arr[k - 1] * arr[first_negative]) /
                arr[last_positive]));
    }
    candidates.push_back(1);

    sort(candidates.begin(), candidates.end(), greater<long double>());
    if (candidates[0] == 1) {
        ll ans = use_not_toggle();
        cout << ans << "\n";
        return 0;
    }
    if (candidates[0] == abs((long double)(arr[k - 1] * arr[first_negative]) /
                             arr[last_positive])) {
        ll temp = use_not_toggle();
        ll diff = get_diff(k - 1, first_negative, last_positive);
        temp = (temp * diff) % MOD;
        cout << temp << "\n";
        return 0;
    }
    ll temp = use_not_toggle();
    ll diff = get_diff(k - 1, first_positive, last_negative);
    temp = (temp * diff) % MOD;
    cout << temp << "\n";
    return 0;

    return 0;
}
