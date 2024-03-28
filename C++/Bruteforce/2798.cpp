#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max_res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int temp = arr[i] + arr[j] + arr[k];
                if (temp <= m && temp > max_res)
                    max_res = temp;
            }
        }
    }
    cout << max_res;
    return 0;
}
