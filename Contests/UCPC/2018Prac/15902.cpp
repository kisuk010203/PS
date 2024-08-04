#include <bits/stdc++.h>
using namespace std;
#define prime 1000000007
typedef long long ll;
ll power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    ll mid = power(base, exponent >> 1);
    mid = (mid * mid) % prime;
    if (exponent & 1)
        return (mid * base) % prime;
    else
        return mid;
}
ll inverse(int base) { return power(base, prime - 2); }
int main() {
    int l, n;
    cin >> l >> n;
    vector<int> arr;
    vector<int> brr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 2)
            arr.push_back(0);
        arr.push_back(1);
    }
    arr.pop_back();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if (temp == 2)
            brr.push_back(0);
        brr.push_back(1);
    }
    brr.pop_back();

    ll dp[l + 1][2]; // dp[i][0] : 0101... dp[i][1] = 1010...
    ll fact[l + 1];
    ll comb[l + 1][l + 1];

    for (int i = 0; i < l + 1; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            comb[i][j] %= prime;
        }
    }

    fact[0] = 1;
    for (int i = 1; i <= l; i++) {
        fact[i] = (fact[i - 1] * i) % prime;
    }

    dp[0][0] = dp[0][1] = 1;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= l; i++) {
        dp[i][0] = dp[i][1] = 0;
        for (int k = 0; k < i; k += 2) {
            dp[i][0] = (dp[i][0] + ((dp[k][0] * dp[i - k - 1][1]) % prime) *
                                       comb[i - 1][k] % prime) %
                       prime;
        }
        for (int k = 1; k < i; k += 2) {
            dp[i][1] = (dp[i][1] + (dp[k][1] * dp[i - k - 1][1] % prime) *
                                       comb[i - 1][k] % prime) %
                       prime;
        }
    }

    ll ans = 1LL;
    int diff_cnt = 0;
    int left = -1;
    for (int i = 0; i < l - 1; i++) {

        if (arr[i] == brr[i])
            left = i;
        else if (i == arr.size() - 1 || arr[i + 1] == brr[i + 1]) {
            int len = i - left;
            int start = arr[left + 1];
            diff_cnt += len;
            ans = ((ans * dp[len][start]) % prime) * inverse(fact[len]) % prime;
        }
    }
    ans = (ans * fact[diff_cnt]) % prime;
    cout << diff_cnt << " " << ans << "\n";
}