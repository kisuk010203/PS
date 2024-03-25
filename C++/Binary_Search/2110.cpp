#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll house[200000];
int n, c;
bool isPossible(int gap) {
    int idx = 0, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (house[i] - house[idx] >= gap) {
            cnt++;
            idx = i;
        }
    }
    return (cnt >= c);
}
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> house[i];
    sort(house, house + n);
    ll start = 1, end = house[n - 1] * 2;
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (isPossible(mid))
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << ((start + end) / 2);
}
