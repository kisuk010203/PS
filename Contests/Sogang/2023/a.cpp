#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << upper_bound(arr.begin(), arr.end(), 5) - arr.begin() << endl;
    cout << upper_bound(arr.begin(), arr.end(), 6) - arr.begin() << endl;
    cout << upper_bound(arr.begin(), arr.end(), 7) - arr.begin() << endl;
    cout << upper_bound(arr.begin(), arr.end(), 3) - arr.begin() << endl;
}
