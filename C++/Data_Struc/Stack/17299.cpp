#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int* arr = new int[n];
    int* nfge = new int[n];
    unordered_map<int, int> F;
    vector<int> temp_stack;
    memset(nfge, 0, sizeof(nfge));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (F.find(arr[i]) == F.end())
            F[arr[i]] = 1;
        else
            F[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        while (!temp_stack.empty() && F[arr[temp_stack.back()]] < F[arr[i]]) {
            nfge[temp_stack.back()] = arr[i];
            temp_stack.pop_back();
        }
        if (i < n - 1 && F[arr[i]] < F[arr[i + 1]])
            nfge[i] = arr[i + 1];
        else
            temp_stack.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (nfge[i] == 0)
            cout << -1 << ' ';
        else
            cout << nfge[i] << ' ';
    }
    return 0;
}
