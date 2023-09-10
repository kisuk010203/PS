#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int desired_len = n - k;
    string temp;
    cin >> temp;
    vector<char> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && k && stk.back() < temp[i]) {
            stk.pop_back();
            k--;
        }
        stk.push_back(temp[i]);
    }
    for (int i = 0; i < desired_len; i++) {
        cout << stk[i];
    }
    cout << "\n";
}
