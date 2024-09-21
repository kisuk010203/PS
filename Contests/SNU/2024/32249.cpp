#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    char alice[n][m];
    char bob[n][m];
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
            alice[i][j] = temp[j];
    }
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
            bob[i][j] = temp[j];
    }
    int final_row_alice = 0, final_row_bob = 0;
    for (int i = 0; i < m; i++) {
        if (alice[n - 1][i] == 'B')
            final_row_alice++;
        if (bob[n - 1][i] == 'A')
            final_row_bob++;
    }

    if (final_row_alice == 0 && final_row_bob != 0)
        cout << "Bob\n";
    else
        cout << "Alice\n";

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        if (r1 == n - 1 && alice[r1][c1] == 'B')
            final_row_alice--;
        if (r2 == n - 1 && bob[r2][c2] == 'A')
            final_row_bob--;
        swap(alice[r1][c1], bob[r2][c2]);
        if (r1 == n - 1 && alice[r1][c1] == 'B')
            final_row_alice++;
        if (r2 == n - 1 && bob[r2][c2] == 'A')
            final_row_bob++;
        if (final_row_alice == 0 && final_row_bob != 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
}