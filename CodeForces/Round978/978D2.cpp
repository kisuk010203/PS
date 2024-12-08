#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;
int query(int a, int b) {
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}
void ans(int x) {
    cout << "! " << x << "\n";
    cout.flush();
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        bool flag = false;
        while(n > 5) {
            int a = query(n-1, n);
            int b = query(n, n - 1);
            if(a == b) {
                n -= 2;
            } else {
                int c = query(n-2, n);
                int d = query(n, n - 2);
                if(c == d) {
                    ans(n - 1);
                    flag = true;
                    break;
                } else {
                    ans(n);
                    flag  = true;
                    break;
                }
            }
        }
        if(flag) continue;
        if(n==3) {
            int a = query(1, 2);
            int b = query(2, 1);
            int c = query(2, 3);
            int d = query(3, 2);
            if(a != b && c != d)  ans(2);
            else if(a != b) ans(1);
            else ans(3);
        }
        if(n == 4) {
            int a = query(1, 2);
            int b = query(2, 1);
            if(a == b) {
                int c = query(2, 3);
                int d = query(3, 2);
                if(c == d) ans(4);
                else ans(3);
            } else {
                int c = query(2, 3);
                int d = query(3, 2);
                if(c == d) ans(1);
                else ans(2);
            }
        }
        else if(n == 5) {
            int a = query(1, 2);
            int b = query(2, 3);
            int c = query(3, 1);
            if((a+b+c) % 2 == 1) { // no imp
                int d = query(3, 4);
                int e = query(4, 3);
                if(d == e) ans(5);
                else ans(4);
            } else {
                int d = query(2, 1);
                int e = query(1, 3);
                if(a != d && c != e) ans(1);
                else if(a!=d && c == e) ans(2);
                else ans(3);
            }
        }
    }
}