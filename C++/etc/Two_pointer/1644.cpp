#include <bits/stdc++.h>
using namespace std;
#define MAX 4000009
bool arr[MAX];
vector<int> prime;
int n;
int main() {
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i <= n; i++)
        arr[i] = true;
    arr[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!arr[i])
            continue;
        for (int j = 2; j * i <= n; j++)
            arr[i * j] = false;
        prime.push_back(i);
    }
    int start = 0, end = 0, cnt = 0, ter = prime.size(), curr = 0;
    while (start <= end) {
        if (curr == n) {
            cnt++;
        }
        if (curr > n || end == ter) {
            curr -= prime[start];
            start++;
        } else {
            curr += prime[end];
            end++;
        }
    }
    cout << cnt;
}
