#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        bool counted[n];
        int count = 0;
        memset(counted, false, sizeof(counted));
        for(int i=0; i<n; i++){
            int temp; cin >> temp; temp--;
            if (counted[temp] == true) {
                count++;
            }
            else counted[temp] = true;
        }
        cout << count << "\n";
    }
}