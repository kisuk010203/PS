#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    for(int i=1; i<n; i++){
        int temp = i, ans = temp;
        while (temp>0)
        {
            ans += temp%10;
            temp/=10;
        }
        if(ans == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
