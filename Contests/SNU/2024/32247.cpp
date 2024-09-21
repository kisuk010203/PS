#include <bits/stdc++.h>
using namespace std;
typedef struct obst {
    int type, x, height;
} obst;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<obst> arr(m);
    for (int i = 0; i < m; i++) {
        int type, x, height;
        cin >> type >> x >> height;
        arr[i] = {type, x, height};
    }
    sort(arr.begin(), arr.end(),
         [](obst first, obst second) -> bool { return first.x < second.x; });
    int y = 0;
    int obst_idx = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << y << "\n";
        if (obst_idx < m && i + 1 == arr[obst_idx].x) {
            int type = arr[obst_idx].type;
            int height = arr[obst_idx].height;
            if (type == 0) {
                if (y >= height + 2)
                    y--;
                else
                    y = height + 1;
            }
            if (type == 1) {
                if (y > height) {
                    cout << "adios\n";
                    exit(0);
                }
                y--;
            }
            obst_idx++;
        } else
            y--;
    }
    cout << (y <= 0 ? "stay" : "adios");
}