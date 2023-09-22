#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    int ans = 0, n = s.length();
    for(int i=0; i<n; i++){
        switch (s[i])
        {
        case 'c':
            if(i<n-1 && (s[i+1] == '=' || s[i+1] == '-'))
                ans++, i++;
            else ans++;
            break;
        case 'd':
            if(i<n-1 && s[i+1] == '-')
                ans++, i++;
            else if(i<n-2 && s[i+1] == 'z' && s[i+2] == '=')
                ans++, i+=2;
            else ans++;
            break;
        case 'l':
        case 'n':
            if(i<n-1 && (s[i+1] == 'j'))
                ans++, i++;
            else ans++;
            break;
        case 's':
        case 'z':
            if(i<n-1 && (s[i+1] == '='))
                ans++, i++;
            else ans++;
            break;
            
        default:
            ans++;
            break;
        }
    }
    cout << ans;
}