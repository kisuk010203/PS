#include <bits/stdc++.h>
using namespace std;
#define PRIME 10007

int main(int argc, char const* argv[]) {
    int n;
    cin >> n;
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(1);
    for (int i = 2; i <= n; i++) {
        int temp = dp[i - 1] + dp[i - 2] * 2;
        dp.push_back(temp % PRIME);
    }
    cout << dp[n];
    return 0;
}
