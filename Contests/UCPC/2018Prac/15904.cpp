#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    string target = "UCPC";
    int idx = 0;
    getline(cin, s);
    for (char curr : s) {
        if (curr == target[idx]) {
            idx++;
        }
        if (idx == 4) {
            cout << "I love UCPC";
            return 0;
        }
    }
    cout << "I hate UCPC";
}