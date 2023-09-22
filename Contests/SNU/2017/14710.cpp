#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int hour, minute;
    cin >> hour >> minute;
    hour %= 30;
    if (minute % 12 == 0 && hour == minute / 12) {
        cout << "O\n";
    } else
        cout << "X\n";
}
