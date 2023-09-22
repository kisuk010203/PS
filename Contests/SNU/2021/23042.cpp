#include <bits/stdc++.h>
using namespace std;
#define MOD (long long)(1e9 +7)
typedef long long ll;
int main(int argc, char const *argv[])
{
    int N; cin >> N;
    ll *arr = new ll[N];
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=30; i>=0; i--){
        int cnt = 0;
        for(int j=0; j<N; j++){
            if((arr[j] >> i)%2) cnt++;
        }
        for(int j=0; j<N; j++){
            if(j<cnt)
                arr[j] = arr[j]|(1<<i);
            else arr[j] = arr[j]&~(1<<i);
        }
    }
    ll res = 1;
    for(int i=0; i<N; i++){
        res = (res*arr[i])%MOD;
    }
    cout << res;
    return 0;
}
