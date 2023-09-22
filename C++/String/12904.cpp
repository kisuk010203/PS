#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s, t; cin >> s >> t;
    while (s.length() < t.length()){
        if(t[t.length()-1] == 'A')
            t.erase(t.length()-1);
        else{
            t.erase(t.length()-1);
            reverse(t.begin(), t.end());
        }
    }
    cout << (int)s==t << '\n';
}