#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int rooms[12];
    memset(rooms, 0, sizeof(rooms));
    for (int i = 0; i < n; i++) {
        int sex, grade;
        cin >> sex >> grade;
        grade--;
        rooms[sex * 6 + grade]++;
    }
    int room_cnt = 0;
    for (int i = 0; i < 12; i++) {
        room_cnt += rooms[i] / k;
        if (rooms[i] % k != 0)
            room_cnt++;
    }
    cout << room_cnt << "\n";
}
