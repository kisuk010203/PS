#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    int* card = new int[n];
    unordered_map<int, bool> cardmap;
    for (int i = 0; i < n; i++) {
        cin >> card[i];
        cardmap[card[i]] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        cout << (cardmap.find(temp) != cardmap.end()) << ' ';
    }

    return 0;
}
