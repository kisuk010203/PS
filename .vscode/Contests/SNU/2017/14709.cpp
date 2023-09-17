#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    bool one_three = false;
    bool one_four = false;
    bool three_four = false;
    bool is_fox = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (a == 1 && b == 3)
            one_three = true;
        else if (a == 3 && b == 4)
            three_four = true;
        else if (a == 1 && b == 4)
            one_four = true;
        else
            is_fox = false;
    }
    if (is_fox && one_three && one_four && three_four) {
        cout << "Wa-pa-pa-pa-pa-pa-pow!\n";
    } else
        cout << "Woof-meow-tweet-squeek\n";
}