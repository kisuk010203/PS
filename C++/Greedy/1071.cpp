#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
int arr[MAX]; // counting array
int before;
int get_min() {
    for (int i = 0; i < MAX; i++) {
        if (arr[i] != 0)
            return i;
    }
    return -1; // empty
}
bool is_possible(int leftover, int key) {
    if (before + 1 == key)
        return 0;
    if (arr[key + 1] == 0)
        return 1;
    int cnt = arr[key] + arr[key + 1];
    if (cnt == leftover)
        return 0;
    return 1;
}
void curr_index(int curr_min){
    cout << curr_min << " ";
    arr[curr_min]--;
    before = curr_min;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }

    before = -2;
    for (int i = 0; i < n; i++) {
        int curr_min = get_min();
        if (is_possible(n - i, curr_min)) {
            curr_index(curr_min);
        } else {
            for (int new_min = curr_min + 1; new_min < MAX; new_min++) {
                if (arr[new_min] == 0)
                    continue;
                if (is_possible(n - i, new_min)) {
                    curr_index(new_min);
                    break;
                }
            }
        }
    }
}
