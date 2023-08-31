#include <bits/stdc++.h>
using namespace std;
typedef struct chip {
    int price;
    int weight;
} chip;
double evaluate_effective(chip chips) {
    double net_weight = chips.weight * 10;
    double net_price = chips.price * 10;
    double discount = net_price >= 5000 ? 500 : 0;
    return net_weight / (net_price - discount);
}
void max3(double s, double n, double u) {
    if (s > n && s > u) {
        cout << "S\n";
    } else if (n > s && n > u) {
        cout << "N\n";
    } else
        cout << "U\n";
}
int main(int argc, char const *argv[]) {
    chip s, n, u;
    cin >> s.price >> s.weight;
    cin >> n.price >> n.weight;
    cin >> u.price >> u.weight;
    max3(evaluate_effective(s), evaluate_effective(n), evaluate_effective(u));
    return 0;
}
