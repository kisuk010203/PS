#include <bits/stdc++.h>
using namespace std;
vector<char> stk;
bool is_end_ppap() {
    int n = stk.size();
    return (stk[n - 1] == 'P' && stk[n - 2] == 'A' && stk[n - 3] == 'P' &&
            stk[n - 4] == 'P');
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string ppap;
    cin >> ppap;
    for (int i = 0; i < ppap.size(); i++) {
        stk.push_back(ppap[i]);
        while (stk.size() >= 4 && is_end_ppap()) {
            for (int i = 0; i < 4; i++) {
                stk.pop_back();
            }
            stk.push_back('P');
        }
    }
    if (stk.size() == 1 && stk[0] == 'P') {
        cout << "PPAP";
    } else {
        cout << "NP";
    }
}
