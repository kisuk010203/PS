#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string curr = "0";
    for (int i = 0; i < m; i++) {
        int len = curr.size();
        if (curr[len - 1] == '0') {
            curr += "2";
        } else if (curr[0] == '0') {
            curr = "2" + curr;
        } else {
            string temp = "";
            for (int j = 0; j < len; j++) {
                temp += (curr[j] == '0' ? "2" : "0");
            }
            curr = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < curr.size())
            cout << curr[i] << " ";
        else
            cout << "4 ";
    }
}
