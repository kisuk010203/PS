#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll base, ll expo, ll mod) {
    if(expo == 0) return 1L;
    ll ret = 1L;
    ll res = pow(base, expo / 2, mod);
    ret = (res * res) % mod;
    if(expo % 2) ret = (ret * base) % mod;
    return ret;
}
ll get_rem(ll a, ll b, ll rem, ll mod) { // a * 10 ** b + rem, by mod. rem may be negative.
    ll ret = pow(10, b, mod);
    ret = (ret * a) % mod;
    ret = (ret + rem + mod * 2) % mod;
    return ret;
}
ll reduce_digit(ll a, ll b, ll rem, ll n) { // -1 ~ -(n  + 1)
    ll first_remainder = get_rem(a, b, rem, n + 1);
    ll second_remainder = get_rem(1, n - 1, 0, n + 1);
    ll next_remainder = (first_remainder + n + 1 - second_remainder) % (n + 1) - (n + 1); // negative
    return next_remainder;
}
ll get_digits(ll a) {
    ll ret = 0;
    while(a) {
        a /= 10;
        ret++;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    string s[100];
    s[1] = "1";
    s[2] = "-2";
    for(int i = 3; i < 100; i++) {
        s[i] = s[i - get_digits(i) - 1] + "-" + to_string(i);
    }

    string type_16 = "1-3-5-7-10-13-16-...";
    string type_17 = "-2-4-6-8-11-14-17...";
    string type_18 = "1-3-5-7-9-12-15-1...";


    int starting_position[10101][3]; // 17 16 18
    // starting_positon[n][0] means that the first position of type_17 in n digit numbers is 
    // 10 ** n - starting_position[n][0]
    starting_position[2][0] = -2;
    starting_position[2][1] = -3;
    starting_position[2][2] = -1;

    for(int i = 3; i < 10101; i++) {
        ll first_remainder = get_rem(1, i, 0, i + 1); // 10 ** (i-1) mod i
        ll second_remainder = get_rem(1, i - 1, 0, i + 1); // 10 ** (i-2) mod i
        ll remainder = first_remainder - second_remainder;
        starting_position[i][0] = (starting_position[i - 1][0] - remainder + 2 * (i + 1)) % (i + 1) - (i + 1);
        starting_position[i][1] = (starting_position[i - 1][1] - remainder + 2 * (i + 1)) % (i + 1) - (i + 1);
        starting_position[i][2] = (starting_position[i - 1][2] - remainder + 2 * (i + 1)) % (i + 1) - (i + 1);
        if(starting_position[i-1][0] == - 1) starting_position[i][0] = (starting_position[i][0] + 1 + i + 1) % (i + 1) - (i + 1);
        if(starting_position[i-1][1] == - 1) starting_position[i][1] = (starting_position[i][1] + 1 + i + 1) % (i + 1) - (i + 1);
        if(starting_position[i-1][2] == - 1) starting_position[i][2] = (starting_position[i][2] + 1 + i + 1) % (i + 1) - (i + 1);

    }
    
    while(T--){
        ll a, b; cin >> a >> b;
        if(b == 0 && a < 100 || b == 1 && a < 10) { // two or less dig.
            a = a * pow(10, b, 100);
            if(a < 21) {
                cout << s[a] << "\n";
                continue;
            }
            else {
                for(int i = 0; i < 17; i++)
                    cout << s[a][i];
                cout << "...\n";
                continue;
            }
        }
        

        ll n = get_digits(a) + b; // a * 10 ** b is of n-digits. 10 ** (n-1) <= a * 10 ** b < 10 ** n
        ll next_remainder = reduce_digit(a, b, 0, n); // 10 ** (n-1) + next_remainder
        next_remainder = (next_remainder + n * 2) % n - n;
        ll start_0 = starting_position[n - 1][0];
        ll start_1 = starting_position[n - 1][1];
        ll start_2 = starting_position[n - 1][2];
        if(start_0 > start_2) { // 0 1 2
            if(next_remainder > start_0 || next_remainder <= start_2) cout << type_18 << "\n";
            else if(next_remainder > start_1) cout << type_17 << "\n";
            else cout << type_16 << "\n";
        }
        else if(start_1 > start_0){ // 1 2 0 
            if(next_remainder > start_1 || next_remainder <= start_0) cout << type_17 << "\n";
            else if(next_remainder > start_2) cout << type_16 << "\n";
            else cout << type_18 << "\n";
        }
        else { // 2 0 1
            if(next_remainder > start_2 || next_remainder <= start_1) cout << type_16 << "\n";
            else if(next_remainder > start_0) cout << type_18 << "\n";
            else cout << type_17 << "\n";
        }
    }
}