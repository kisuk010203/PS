#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string temp;
    cin >> temp;
    vector<char> v;
    for (char item : temp)
        v.push_back(item);
    sort(v.begin(), v.end(), greater<char>());
    for (char item : v)
        cout << item;
}
