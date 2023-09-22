#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
#define MAX 101
bool use_date[MAX];
int dp[MAX][MAX]; // date, coupon
int n, m;
int ans;
void setdp(int date, int coupon, int cost) {
    if (date > n) {
        ans = min(ans, cost);
        return;
    }

    if (cost >= dp[date][coupon])
        return;
    dp[date][coupon] = cost;

    if (!use_date[date]) {
        setdp(date, coupon, cost);
        return;
    }
    if (coupon >= 3) {
        setdp(date + 1, coupon - 3, cost);
    }
    setdp(date + 1, coupon, cost + 10000);
    setdp(date + 3, coupon + 1, cost + 25000);
    setdp(date + 5, coupon + 2, cost + 37000);
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    memset(use_date, true, sizeof(use_date));
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        use_date[temp] = false;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    ans = INF;
    setdp(1, 0, 0);
    cout << ans << "\n";
}