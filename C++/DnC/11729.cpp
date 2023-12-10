#include <bits/stdc++.h>
using namespace std;
void hanoi(int start, int dest, int n) {
    if (n == 0)
        return;
    int inter = 6 - (start + dest);
    hanoi(start, inter, n - 1);
    cout << start << " " << dest << "\n";
    hanoi(inter, dest, n - 1);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    cout << (1 << N) - 1 << "\n";
    hanoi(1, 3, N);

}
