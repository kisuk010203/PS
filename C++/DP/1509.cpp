#include <bits/stdc++.h>
using namespace std;
#define MAX 2500
int ansdp[MAX];
bool isPal[MAX][MAX];
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string temp;
    cin >> temp;
    int N = temp.size();
    memset(isPal, false, sizeof(isPal));
    for (int i = 0; i < N; i++) {
        isPal[i][i] = 1;
        if (i + 1 < N && temp[i] == temp[i + 1])
            isPal[i][i + 1] = 1;
    }
    for (int dist = 2; dist < N; dist++) {
        for (int st = 0; st < N; st++) {
            if (st + dist >= N)
                break;
            isPal[st][st + dist] =
                (temp[st] == temp[st + dist]) && isPal[st + 1][st + dist - 1];
        }
    }
    ansdp[0] = 1;
    for (int i = 1; i < N; i++) {
        ansdp[i] = i + 1;
        if (isPal[0][i]) {
            ansdp[i] = 1;
            continue;
        }
        for (int j = 1; j <= i; j++) {
            if (isPal[j][i])
                ansdp[i] = min(ansdp[i], ansdp[j - 1] + 1);
        }
    }
    cout << ansdp[N - 1];

    return 0;
}
