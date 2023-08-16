#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int ab, bc, ca; cin >> ab >> bc >> ca;
        ll max_res = 0;
        for(int i=0; i<=min(a,b); i++){
            if(i>b) break;
            ll temp = i*ab;
            for(int j=0; j<=min(a-i, c); j++){
                temp += j*ca;
                temp += min(c-j, b-i)*bc;
                max_res = max(temp, max_res);
                temp = i*ab;
            }
        }
        cout << max_res << '\n';
    }
}