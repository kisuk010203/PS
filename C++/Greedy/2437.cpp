#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> weights(n);

    for(int i=0; i<n; i++){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int cumul_sum = 0;
    for(int i=0; i<n; i++){
        if(i < n && cumul_sum  + 1 < weights[i]){
            cout << cumul_sum + 1 << "\n";
            return 0;
        }
        cumul_sum += weights[i];
    }
    cout << cumul_sum + 1 << "\n";
    return 0;
}
