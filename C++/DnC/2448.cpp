#include <bits/stdc++.h>
using namespace std;
bool arr[3072][6144];
void draw_star(int row, int col, int size) {
    if (size == 3) {
        for (int i = 0; i < 5; i++) {
            arr[row][col + i] = true;
        }
        arr[row - 1][col + 1] = arr[row - 1][col + 3] = true;
        arr[row - 2][col + 2] = true;
        return;
    }
    draw_star(row, col, size / 2);
    draw_star(row, col + size, size / 2);
    draw_star(row - size / 2, col + size / 2, size / 2);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<3072; i++){
        for(int j=0; j<6144; j++){
            arr[i][j] = false;
        }
    }
    draw_star(n - 1, 0, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n; j++){
            cout << (arr[i][j] ? "*" : " ");
        }cout << "\n";
    }
}
