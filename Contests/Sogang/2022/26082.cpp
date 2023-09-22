#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int adv_price, adv_eff, war_price;
    cin >> adv_price >> adv_eff >> war_price;
    int war_eff = adv_eff / adv_price * war_price * 3;
    cout << war_eff;
}
