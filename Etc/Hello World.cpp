#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "500 1\n";
    vector<int> ret;
    for (int i = 1; i <= 500; i += 2) {
        ret.push_back(i + 1);
        ret.push_back(i);
    }
    for (int i = 0; i < 500; ++i) {
        cout << ret[i];
        if (i < 499)
            cout << ' ';
    }
}
