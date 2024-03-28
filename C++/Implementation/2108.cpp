#include <bits/stdc++.h>
using namespace std;
void create_or_add(unordered_map<int, int>& map, int key) {
    auto iter = map.find(key);
    if (iter == map.end()) {
        map[key] = 1;
    } else {
        iter->second++;
    }
}
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    double sum = 0;
    vector<int> values;
    vector<int> populated_vector;
    unordered_map<int, int> count_map;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        values.push_back(temp);
        create_or_add(count_map, temp);
        sum += temp;
    }
    sort(values.begin(), values.end());

    int avg = round(sum / n);
    int mid = values[n / 2];
    int populated = 0;
    int range = values[n - 1] - values[0];

    int populated_value = 0;
    for (const auto& pair : count_map) {
        populated_value = max(populated_value, pair.second);
    }
    for (const auto& pair : count_map) {
        if (pair.second == populated_value) {
            populated_vector.push_back(pair.first);
        }
    }
    sort(populated_vector.begin(), populated_vector.end());
    populated = populated_vector.size() == 1 ? populated_vector[0]
                                             : populated_vector[1];

    cout << avg << "\n";
    cout << mid << "\n";
    cout << populated << "\n";
    cout << range << "\n";
    return 0;
}
