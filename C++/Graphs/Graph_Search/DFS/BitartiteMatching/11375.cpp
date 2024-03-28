#include <bits/stdc++.h>
using namespace std;
int n, m;
#define MAX 1001
vector<int> work_list[MAX];
int empl[MAX];
bool visited[MAX];

bool matching(int man) {
    if (visited[man])
        return false;
    visited[man] = true;
    for (auto work : work_list[man]) {
        if (empl[work] == -1 || matching(empl[work])) {
            empl[work] = man;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp, work;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            cin >> work;
            work_list[i].push_back(work);
        }
        sort(work_list[i].begin(), work_list[i].end());
    }
    for (int i = 0; i < MAX; i++)
        empl[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            visited[j] = false;
        matching(i);
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (empl[i] >= 0)
            res++;
    cout << res;
}
