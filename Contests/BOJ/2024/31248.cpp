#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void print_hanoi(int from, int to) {
    cout << (char)(from + 'A') << " " << (char)(to + 'A') << "\n";
}
void hanoi(int n, int from, int bypass, int target) {
    if (n == 1) {
        print_hanoi(from, target);
        return;
    }
    hanoi(n - 1, from, target, bypass);
    hanoi(1, from, bypass, target);
    hanoi(n - 1, bypass, from, target);
    return;
}
void my_hanoi(int n, int from, int bypass1, int bypass2) {
    if (n == 1) {
        print_hanoi(from, 3);
        return;
    } else if (n == 2) {
        print_hanoi(from, bypass1);
        print_hanoi(from, 3);
        print_hanoi(bypass1, 3);
        return;
    }
    hanoi(n - 2, from, bypass1, bypass2);
    hanoi(2, from, bypass1, 3);
    my_hanoi(n - 2, bypass2, from, bypass1);
    return;
}
ll answer(ll n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    return answer(n - 2) + (1 << (n - 2)) + 2;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << answer(n) << "\n";
    my_hanoi(n, 0, 1, 2);
}