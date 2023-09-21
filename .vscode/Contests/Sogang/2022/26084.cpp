#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char, ll> count_first;
void update_or_create(char key) {
    if (count_first.find(key) == count_first.end()) {
        count_first[key] = 1;
    } else
        count_first[key]++;
}
ll get_cnt(char key) {
    if (count_first.find(key) == count_first.end())
        return 0;
    return count_first[key];
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string team_name;
    cin >> team_name;
    vector<char> team;
    for (char item : team_name)
        team.push_back(item);
    sort(team.begin(), team.end());
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        update_or_create(temp[0]);
    }

    if (team[0] == team[2]) {
        ll num = get_cnt(team[0]);
        cout << (num * (num - 1) * (num - 2) / 6);
    } else if (team[0] == team[1]) {
        ll num1 = get_cnt(team[0]);
        ll num2 = get_cnt(team[2]);
        cout << (num1 * (num1 - 1) / 2) * num2;
    } else if (team[1] == team[2]) {
        ll num1 = get_cnt(team[0]);
        ll num2 = get_cnt(team[2]);
        cout << (num2 * (num2 - 1) / 2) * num1;
    } else {
        ll res = 1;
        for (ll i = 0; i < 3; i++) {
            res *= get_cnt(team[i]);
        }
        cout << res;
    }
}
