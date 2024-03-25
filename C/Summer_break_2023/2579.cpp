#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[]) {
    int dp[301][2];
    vector<int> floor_values;
    memset(dp, 0, sizeof(dp));

    int num_steps;
    cin >> num_steps;
    for (int i = 0; i < num_steps; i++) {
        int temp;
        cin >> temp;
        floor_values.push_back(temp);
    }

    dp[1][0] = floor_values[0];
    for (int i = 2; i <= num_steps; i++) {
        dp[i][1] = dp[i - 1][0] + floor_values[i - 1];
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + floor_values[i - 1];
    }

    cout << max(dp[num_steps][0], dp[num_steps][1]) << endl;

    return 0;
}
