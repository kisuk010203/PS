#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> char_int_pair;
typedef long long ll;

unordered_map<char, int> char_to_int;
vector<char_int_pair> sort_vector;

bool comp(char_int_pair a, char_int_pair b) {
    return a.second > b.second;
}
void add_or_create(char key, int val) {
    if (char_to_int.find(key) == char_to_int.end()) {
        char_to_int[key] = val;
    } else
        char_to_int[key] += val;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        int len_temp = temp.size();
        int base = 1;
        for (int j = 0; j < len_temp; j++) {
            int idx = len_temp - j - 1;
            char key = temp[idx];
            add_or_create(key, base);
            base *= 10;
        }
    }

    for (const auto& item : char_to_int) {
        sort_vector.push_back({item.first, item.second});
    }

    sort(sort_vector.begin(), sort_vector.end(), comp);
    ll res = 0;
    int weight = 9;
    for (auto item : sort_vector) {
        res += item.second * weight;
        weight--;
    }
    cout << res << endl;
}
