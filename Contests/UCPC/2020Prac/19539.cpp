#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int s = 0;
    vector<int> v(n);
    for(int i = 0; i < n ; i++) {
        cin >> v[i];
        s += v[i];   
    }
    if(s % 3 != 0) {
        cout << "NO\n";
        return 0;
    }
    int a = s / 3;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (v[i] / 2);
    }
    cout << (cnt >= a ? "YES\n" : "NO\n");
}