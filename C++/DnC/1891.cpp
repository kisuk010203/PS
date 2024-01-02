#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int d;
string cipher;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> d >> cipher;
    ll x, y;
    cin >> x >> y;

    ll result_x = 0, result_y = 0;
    for (int i = 0; i < d; i++) {
        switch (cipher[i]) {
        case '1':
            result_y |= (1L << (d - i - 1));
            break;
        case '2':
            break;
        case '3':
            result_x |= (1L << (d - i - 1));
            break;
        case '4':
            result_x |= (1L << (d - i - 1));
            result_y |= (1L << (d - i - 1));
            break;
        default:
            break;
        }
    }
    ll new_x = result_x - y;
    ll new_y = result_y + x;
    if (new_x < 0 || new_y < 0 || new_x >= (1L << d) || new_y >= (1L << d)) {
        cout << -1;
        return 0;
    }
    for (int i = d - 1; i >= 0; i--) {
        ll target = 1L << i;
        if ((new_x & target) && (new_y & target)) {
            cout << 4;
        } else if (!(new_x & target) && (new_y & target)) {
            cout << 1;
        } else if ((new_x & target) && !(new_y & target)) {
            cout << 3;
        } else
            cout << 2;
    }
}
