#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int* color = new int[N + 1];
    fill(color, color + N + 1, 0);
    color[1] = 1;
    int cnt = 2;
    for (int i = 2; i <= N; i++) {
        if (color[i] == 0) {
            for (int j = i; j <= N; j += i)
                color[j] = cnt;
            cnt++;
        }
    }
    cout << cnt - 1 << '\n';
    for (int i = 1; i <= N; i++)
        cout << color[i] << ' ';
    return 0;
}
