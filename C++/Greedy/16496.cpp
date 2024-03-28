#include <bits/stdc++.h>
using namespace std;
bool str_compare(string a, string b) {
    return (a + b) > (b + a);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end(), str_compare);

    if (numbers[0][0] == '0') {
        cout << 0;
        return 0;
    }
    for (string str : numbers)
        cout << str;
}
