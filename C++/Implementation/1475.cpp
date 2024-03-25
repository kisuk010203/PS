#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    int ans = 0;
    unordered_map<int, int> number_map;
    for (int i = 0; i < 9; i++) {
        number_map[i] = 0;
    }
    string room_number;
    cin >> room_number;
    for (char item : room_number) {
        int num_item = item - '0';
        if (item == '6' || item == '9') {
            if (number_map[6] > number_map[9]) {
                number_map[9]++;
            } else
                number_map[6]++;
        } else {
            number_map[item]++;
        }
    }
    for (const auto& pair : number_map) {
        ans = max(ans, pair.second);
    }
    cout << ans << "\n";
    return 0;
}
