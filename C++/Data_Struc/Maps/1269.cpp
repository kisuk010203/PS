#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    set<int> A, B;
    int cnt = 0;
    int A_size, B_size;
    cin >> A_size >> B_size;
    for (int i = 0; i < A_size; i++) {
        int temp;
        cin >> temp;
        A.insert(temp);
    }
    for (int i = 0; i < B_size; i++) {
        int temp;
        cin >> temp;
        B.insert(temp);
    }
    for (auto item : A) {
        if (B.find(item) == B.end())
            cnt++;
    }
    for (auto item : B) {
        if (A.find(item) == A.end())
            cnt++;
    }
    cout << cnt;
}
