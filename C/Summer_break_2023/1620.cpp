#include <bits/stdc++.h>
using namespace std;
int string_formatter(string temp) {
    int ret = 0;
    for (int i = 0; i < temp.length(); i++) {
        ret = ret * 10 + temp[i] - '0';
    }
    return ret;
}
int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    unordered_map<int, string> int_to_string;
    unordered_map<string, int> string_to_int;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        int_to_string[i] = temp;
        string_to_int[temp] = i;
    }

    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        if (temp[0] >= '0' && temp[0] <= '9') {
            int index = string_formatter(temp);
            cout << int_to_string[index] << "\n";
        } else
            cout << string_to_int[temp] << "\n";
    }

    return 0;
}
