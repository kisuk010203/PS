#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    double ans = 0.0;
    double pi = M_PI;
    double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (dist >= r1 + r2) {
        cout << "0.000";
    } else if (r1 >= dist + r2) {
        printf("%.3lf", r2 * r2 * pi);
    } else if (r2 >= dist + r1) {
        printf("%.3lf", r1 * r1 * pi);
    } else {
        double theta1 =
            acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist));
        double theta2 =
            acos((r2 * r2 + dist * dist - r1 * r1) / (2 * r2 * dist));
        double area1 = r1 * r1 * theta1 - (r1 * r1 * sin(2 * theta1)) / 2;
        double area2 = r2 * r2 * theta2 - (r2 * r2 * sin(2 * theta2)) / 2;
        ans = area1 + area2;
        ans = round(ans * 1000) * 0.001;
        printf("%.3lf\n", ans);
    }
}
