#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int rooms[5];
    memset(rooms, 0, sizeof(rooms));
    for (int i = 0; i < n; i++) {
        int sex, grade;
        cin >> sex >> grade;
        if (grade <= 2)
            rooms[0]++;
        else if (grade <= 4)
            rooms[sex + 1]++;
        else
            rooms[sex + 3]++;
    }
    int room_cnt = 0;
    for (int i = 0; i < 5; i++) {
        room_cnt += rooms[i] / k;
        if (rooms[i] % k != 0)
            room_cnt++;
    }
    cout << room_cnt << "\n";
}