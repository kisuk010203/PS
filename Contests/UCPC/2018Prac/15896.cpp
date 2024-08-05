#include <bits/stdc++.h>
using namespace std;
#define MOD 1999
typedef pair<int, int> pii;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> brr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    int and_then_sum = 0, sum_then_and = 0;
    vector<int> crr = arr;
    vector<int> drr = brr;
    for (int i = 0; i < 5; i++) {
        vector<int> zero_crr;
        vector<int> one_crr;
        vector<int> zero_drr;
        vector<int> one_drr;
        int mask = (1 << i);
        cout << i << " " << mask << " \n";
        for (auto item : crr) {
            if (item & mask)
                one_crr.push_back(item);
            else
                zero_crr.push_back(item);
        }
        for (auto item : drr) {
            if (item & mask)
                one_drr.push_back(item);
            else
                zero_drr.push_back(item);
        }
        bool is_zero = false;
        mask--;
        if (zero_crr.size() != 0 && zero_drr.size() != 0) {
            is_zero = is_zero ||
                      ((zero_crr[0] & mask) + (zero_drr[0] & mask) < mask + 1);
        }
        if (zero_crr.size() != 0 && one_drr.size() != 0) {
            is_zero = is_zero || ((zero_crr[zero_crr.size() - 1] & mask) +
                                      (one_drr[one_drr.size() - 1] & mask) >=
                                  mask + 1);
        }
        if (one_crr.size() != 0 && zero_drr.size() != 0) {
            cout << mask << " " << (one_crr[one_crr.size() - 1] & mask) << " "
                 << (zero_drr[zero_drr.size() - 1] & mask) ;
            is_zero = is_zero || ((one_crr[one_crr.size() - 1] & mask) +
                                      (zero_drr[zero_drr.size() - 1] & mask) >=
                                  mask + 1);
                                  cout << is_zero << endl;
        }
        if (one_crr.size() != 0 && one_drr.size() != 0) {
            is_zero = is_zero ||
                      ((one_crr[0] & mask) + (one_drr[0] & mask) < mask + 1);
        }
        mask++;
        if (!is_zero)
            sum_then_and += mask;
        and_then_sum +=
            ((one_crr.size() % MOD) * (one_drr.size() % MOD) * (mask % MOD)) %
            MOD;
        and_then_sum %= MOD;
        zero_crr.insert(zero_crr.end(), one_crr.begin(), one_crr.end());
        zero_drr.insert(zero_drr.end(), one_drr.begin(), one_drr.end());
        crr = zero_crr;
        drr = zero_drr;
        cout << "Phase " << i << " crr : ";
        for (auto item : crr) {
            cout << item << " ";
        }
        cout << "\nPhase " << i << " drr : ";
        for (auto item : drr) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << and_then_sum << " " << sum_then_and;
}