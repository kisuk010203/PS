#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ull mat[100000], ans=0;
    for(int i=0; i<n; i++) cin >> mat[i];
    int rnk = 0;
    for(int lead = 59; lead >=0 && rnk<n; lead--){
        if(rnk >=n) break;
        if(~mat[rnk] & 1ULL << lead){//mat[rnk]'s lead = 0
            int pivot = -23;
            for(int i=rnk+1; i<n; i++){
                if(mat[i] & 1ULL << lead){
                    pivot = i; break;
                }
            }
            if(pivot >=0) mat[rnk] ^= mat[pivot];
            else continue;
        }

        for(int i=0; i<n; i++){
            if(rnk != i && (mat[i] & 1ULL << lead)) mat[i] ^= mat[rnk];
        }rnk++;
    }
    for(int i=0; i<n; i++)
        ans ^= mat[i];
    cout << ans << '\n';
}
