#include <iostream>
using namespace std;
typedef long long ll;
ll x[4];
ll y[4];
int ccw(int i, int j, int k) {
    ll a = x[i] * y[j] + x[j] * y[k] + x[k] * y[i] -
           (x[j] * y[i] + x[k] * y[j] + x[i] * y[k]);
    return (a > 0) ? 1 : ((a == 0) ? 0 : -1);
}
int main() {
    for (int i = 0; i < 4; i++)
        cin >> x[i] >> y[i];
    int a = ccw(0, 1, 2) * ccw(0, 1, 3);
    int b = ccw(2, 3, 0) * ccw(2, 3, 1);
    double denom =
        (x[0] - x[1]) * (y[2] - y[3]) - (y[0] - y[1]) * (x[2] - x[3]);
    double nom1 = (x[0] * y[1] - x[1] * y[0]) * (x[2] - x[3]) -
                  (x[0] - x[1]) * (x[2] * y[3] - x[3] * y[2]);
    double nom2 = (x[0] * y[1] - x[1] * y[0]) * (y[2] - y[3]) -
                  (y[0] - y[1]) * (x[2] * y[3] - x[3] * y[2]);
    if (a != 1 && b != 1) {
        if (a == 0 && b == 0) { // one line
            int flag = 0, one_point = 0;
            int d = min(x[0], x[1]), e = max(x[0], x[1]);
            int f = min(x[2], x[3]), g = max(x[2], x[3]);
            if (d < f) {
                flag = (e >= f);
                one_point = e == f;
            }

            else if (d == f) {
                flag = 1;
                one_point = ((d == e) || (g == f));
            }

            else {
                flag = (g >= d);
                one_point = (g == d);
            }
            d = min(y[0], y[1]), e = max(y[0], y[1]);
            f = min(y[2], y[3]), g = max(y[2], y[3]);
            if (d < f) {
                flag = flag && (e >= f);
                one_point &= e == f;
            } else if (d == f) {
                flag = flag && 1;
                one_point &= ((d == e) || g == f);
            } else {
                flag = flag && (g >= d);
                one_point &= (d == g);
            }
            cout << flag << '\n';
            if (denom != 0 && flag == 1) {
                printf("%.9f %.9f", nom1 / denom, nom2 / denom);
            } else if (flag == 1 && one_point) {
                pair<int, int> p1 = make_pair(x[0], y[0]);
                pair<int, int> p2 = make_pair(x[1], y[1]);
                pair<int, int> p3 = make_pair(x[2], y[2]);
                pair<int, int> p4 = make_pair(x[3], y[3]);
                if (p1 == p3 || p1 == p4)
                    cout << p1.first << ' ' << p1.second;
                else
                    cout << p2.first << ' ' << p2.second;
            }
            return 0;
        }
        // not one line
        cout << 1 << '\n';
        printf("%.9f %.9f", nom1 / denom, nom2 / denom);
        return 0;
    } else
        cout << 0;
}
