#include <bits/stdc++.h>
using namespace std;

#define F(i)                                                                   \
    for (int _##i = 0; _##i < 3; _##i++) {                                     \
        swap(pieces[i][0], pieces[i][1]);                                                \
        swap(pieces[i][1], pieces[i][2]);
#define I(x1, y1, x2, y2, x3, y3, x4, y4) \
	if (pieces[x1][y1] != pieces[x2][y2] || pieces[x1][y1] != pieces[x3][y3] || pieces[x1][y1] != pieces[x4][y4]) return 0;
array<char, 3> pieces[8];
bool is_cube() {
    I(0, 1, 1, 1, 2, 1, 3, 1);
    I(0, 0, 1, 2, 4, 0, 5, 1);
    I(0, 2, 3, 0, 4, 1, 7, 0);
    I(2, 0, 3, 2, 6, 0, 7, 1);
    I(1, 0, 2, 2, 5, 0, 6, 1);
    I(4, 2, 5, 2, 6, 2, 7, 2);
    return 1;
}
bool can_be_cube() {
    sort(pieces, pieces+8);
    do {
        F(1) F(2) F(3) F(4) F(5) F(6) F(7) if(is_cube()) return true;
    }}}}}}}
    } while (next_permutation(pieces + 1, pieces + 8));
    return false;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 8; i++) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }
    cout << (can_be_cube() ? "YES\n" : "NO\n");
}
