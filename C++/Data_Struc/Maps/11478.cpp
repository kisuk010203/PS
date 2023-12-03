#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    set<string> substrings;
    string target;
    cin >> target;
    int n = target.size();
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start < n - len + 1; start++) {
            substrings.insert(target.substr(start, len));
        }
    }
    cout << substrings.size();
}
