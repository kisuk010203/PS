#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll ans = 0;
void merge(int left, int right) {
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int rights = 0;
    vector<ll> temp;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            temp.push_back(v[i]);
            i++;
            ans += rights;
        } else {
            temp.push_back(v[j]);
            j++;
            rights++;
        }
    }
    while (i <= mid) {
        temp.push_back(v[i]);
        i++;
        ans += rights;
    }
    while (j <= right) {
        temp.push_back(v[j]);
        j++;
    }
    for (int i = left; i <= right; i++) {
        v[i] = temp[i - left];
    }
}
void merge_sort(int left, int right) {
    int mid = (left + right) / 2;
    if (left < right) {
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, right);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    merge_sort(0, n - 1);
    cout << ans << "\n";
}