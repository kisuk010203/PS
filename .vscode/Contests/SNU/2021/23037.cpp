#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int s; cin >> s;
    int res = 0;
    for(int i=0; i<5; i++){
        int temp = s%10; s/=10;
        res += (temp*temp*temp*temp*temp);
    }
    cout << res;
    return 0;
}
