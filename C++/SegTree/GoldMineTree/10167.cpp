#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
struct Point {
    int x, y, w;
};
struct TreeNode {
    ll sum, lmax, rmax, tmax;
};

Point p[3001];
vector<pair<int, int>> x, y, yy[3001];
TreeNode seg[12004];

TreeNode Update(int idx, int val, int n, int l, int r) {
    if (r < idx || idx < l)
        return seg[n];

    if (l == r && l == idx) {
        seg[n].sum += val, seg[n].lmax += val, seg[n].rmax += val,
            seg[n].tmax += val;
        return seg[n];
    }

    int mid = (l + r) / 2;
    TreeNode left, right;
    left = Update(idx, val, n * 2, l, mid);
    right = Update(idx, val, n * 2 + 1, mid + 1, r);

    seg[n].sum = left.sum + right.sum;
    seg[n].lmax = max(left.lmax, left.sum + right.lmax);
    seg[n].rmax = max(right.rmax, right.sum + left.rmax);
    seg[n].tmax = max({left.tmax, right.tmax, left.rmax + right.lmax});
    return seg[n];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tx, ty, tw;
        cin >> tx >> ty >> tw;
        x.push_back({tx, i});
        y.push_back({ty, i});
        p[i].w = tw;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int num = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && x[i - 1].first != x[i].first)
            num++;
        p[x[i].second].x = num;
    }

    num = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && y[i - 1].first != y[i].first)
            num++;
        p[y[i].second].y = num;
    }

    for (int i = 0; i < N; i++)
        yy[p[i].y].push_back({p[i].x, p[i].w});

    ll res = 0;
    for (int sy = 0; sy < N; sy++) {
        for (int i = 0; i < 12004; i++) {
            TreeNode temp;
            temp.sum = 0, temp.lmax = 0, temp.rmax = 0, temp.tmax = 0;
            seg[i] = temp;
        }

        for (int ey = sy; ey < N; ey++) {
            for (int i = 0; i < yy[ey].size(); i++) {
                int hx = yy[ey][i].first, hy = ey, hw = yy[ey][i].second;

                Update(hx, hw, 1, 0, N - 1);
            }

            res = max(res, seg[1].tmax);
        }
    }

    cout << res;
    return 0;
}