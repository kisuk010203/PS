#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;
#define NMAX 100001
int arr[2][NMAX];
int count_vote(int i, int mode) {
    int cnt = 0;
    if(mode == 5) 
        cnt = arr[0][i] + arr[0][i+1] + arr[0][i+2];
    else if(mode    == 6) {
        cnt = arr[1][i] + arr[1][i+1] + arr[1][i+2];
    }
    else {
        cnt = arr[0][i] + arr[0][i+1] +
            arr[1][i] + arr[1][i+1];
    }
    switch (mode) {
        case 1:
            cnt -= arr[0][i+1];
            break;
        case 2:
            cnt -= arr[1][i];
            break;
        case 3:
            cnt -= arr[1][i+1];
            break;
        case 4:
            cnt -= arr[0][i];
            break;
    }   
    return (cnt >= 2 ? 1 : 0);
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        rep(i, 0, 2) {
            string temp; cin >> temp;
            rep(j, 0, n) arr[i][j] = (int)(temp[j] == 'A');
        }
        int dp[n+1][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        dp[1][0] = dp[2][0] = 0;
        dp[1][1] = count_vote(0, 3);
        dp[1][2] = count_vote(0, 1);
        dp[2][1] = dp[2][2] = 0;
        for(int i = 3; i <= n; i++) {
            dp[i][0] = max({
                dp[i-3][0] + count_vote(i-3, 5) + count_vote(i-3, 6) ,
                dp[i-2][1] + count_vote(i-2, 4),
                dp[i-2][2] + count_vote(i-2, 2)
            });
            dp[i][1] = max(
                dp[i-1][0] + count_vote(i-1, 3),
                dp[i-3][1] + count_vote(i-2, 5) + count_vote(i-3, 6)
            );
            dp[i][2] = max(
                dp[i-1][0] + count_vote(i-1, 1),
                dp[i-3][2] + count_vote(i-2, 6) + count_vote(i-3, 5)
            );
        }
        cout << dp[n][0] << "\n";
    }
}