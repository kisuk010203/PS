#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int x = 0;
    int t; cin >> t;
    while (t--){
        string mode; cin >> mode;
        int elm;
        if(mode != "all" && mode != "empty"){
            cin >> elm;
        }
        if(mode == "add")
            x = x | (1<<elm);
        else if(mode == "check")
            cout << (x>>elm)%2 << '\n';
        else if(mode == "remove")
            x = x & ~(1<<elm);
        else if(mode == "toggle")
            x = x^(1<<elm);
        else if(mode == "all")
            x = (1<<21)-2;
        else
            x = 0;
    }
    return 0;
}
