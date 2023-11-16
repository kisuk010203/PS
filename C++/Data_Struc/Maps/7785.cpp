#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    unordered_map<string, bool> status;
    vector<string> current;
    int n;
    cin >> n;
    while (n--) {
        string name, activity;
        cin >> name >> activity;
        if (activity == "enter") {
            status[name] = true;
        } else {
            status.erase(name);
        }
    }
    for (auto item : status) {
        current.push_back(item.first);
    }
    sort(current.begin(), current.end(), greater<string>());
    for (auto item : current) {
        cout << item << "\n";
    }
}
