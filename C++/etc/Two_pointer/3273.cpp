#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, target, cnt = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> target;
    sort(v.begin(), v.end());
    int start = 0, end = n - 1;
    while (start < end) {
        if (v[start] + v[end] < target)
            start++;
        else if (v[start] + v[end] > target)
            end--;
        else {
            cnt++, start++, end--;
        }
    }
    cout << cnt;
}
