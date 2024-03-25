#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string scores;
    cin >> scores;
    vector<p> block_size;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && scores[i] != scores[i - 1]) {
            block_size.push_back({scores[i - 1] == 'S', cnt});
            cnt = 1;
        } else {
            cnt++;
        }
    }
    block_size.push_back({scores[n - 1] == 'S', cnt});

    int curr_s = 0, curr_u = 0;
    while (!block_size.empty()) {
        while (curr_s == 0 || curr_u == 0) {
            p last = block_size.back();
            if (last.first)
                curr_s += last.second;
            else
                curr_u += last.second;
        }
    }
}
