#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
using ll = long long;

ll arr[MAX];
ll gcdSeg[MAX << 2];
ll addSeg[MAX << 2];
ll lazySg[MAX << 2];

ll initSeg(int cur, int st, int en, ll *seg, decltype(__gcd<ll>) op) {
    if (st == en)
        return seg[cur] = arr[st];
    int mid {(st + en) >> 1};
    return seg[cur] = op(initSeg(cur * 2, st, mid, seg, op), initSeg(cur * 2 + 1, mid + 1, en, seg, op));
}
void update_lazy(int cur, int st, int en, ll *sg, ll *lz) {
    if (lz[cur] != 0) {
        sg[cur] += (en - st + 1) * lz[cur];
        if (st != en) {
            lz[cur * 2] += lz[cur];
            lz[cur * 2 + 1] += lz[cur];
        }
        lz[cur] = 0;
    }
}
void update_range_lazy(int cur, int st, int en, int l, int r, ll diff, ll *sg, ll *lz) {
    update_lazy(cur, st, en, sg, lz);
    if (l > en || r < st) return;
    if (l <= st && en <= r) {
        sg[cur] += (en - st + 1) * diff;
        if (st != en) {
            lz[cur * 2] += diff;
            lz[cur * 2 + 1] += diff;
        }
        return;
    }
    int mid {(st + en) >> 1};
    update_range_lazy(cur * 2, st, mid, l, r, diff, sg, lz);
    update_range_lazy(cur * 2 + 1, mid + 1, en, l, r, diff, sg, lz);
    sg[cur] = sg[cur * 2] + sg[cur * 2 + 1];
}
void update(int cur, int st, int en, int idx, ll diff, ll *sg, decltype(__gcd<ll>) op) {
    if (idx < st || idx > en) return;
    if (st == en) {
        sg[cur] += diff;
        return;
    }

    int mid {(st + en) >> 1};
    update(cur * 2, st, mid, idx, diff, sg, op);
    update(cur * 2 + 1, mid + 1, en, idx, diff, sg, op);
    sg[cur] = op(
        sg[cur * 2], sg[cur * 2 + 1]
    );
}

ll query(int cur, int st, int en, int l, int r, ll *sg, ll *lz, decltype(__gcd<ll>) op, bool useLz) {
    if (useLz)
        update_lazy(cur, st, en, sg, lz);
    if (l > en || r < st)
        return 0;
    if (l <= st && en <= r) 
        return sg[cur];
    int mid {(st + en) >> 1};
    ll lval = query(cur * 2, st, mid, l, r, sg, lz, op, useLz);
    ll rval = query(cur * 2 + 1, mid + 1, en, l, r, sg, lz, op, useLz);
    return op(lval, rval);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;

    auto _add = [](ll a, ll b) { return a + b; };
    auto myGcd = [](ll a, ll b) { return __gcd(abs(a), abs(b)); };

    // Make diff array
    arr[0] = 0;
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        arr[i] = temp - prev;
        prev = temp;
    }

    memset(addSeg, 0, sizeof(addSeg));
    memset(gcdSeg, 0, sizeof(gcdSeg));
    memset(lazySg, 0, sizeof(lazySg));


    initSeg(1, 0, n, gcdSeg, myGcd);
    initSeg(1, 0, n, addSeg, _add);
    int q; cin >> q;
    while(q--) {
        ll t, st, en;
        cin >> t >> st >> en;
        if (t == 0) {
            ll a_st = query(1, 0, n, 0, st, addSeg, lazySg, _add, true);
            ll other_gcd = query(1, 0, n, st + 1, en, gcdSeg, gcdSeg, myGcd, false);
            ll res = myGcd(a_st, other_gcd);
            cout << res << "\n";

        } else { // adding t to st..en
            update(1, 0, n, st, t, gcdSeg, myGcd);
            update_range_lazy(1, 0, n, st, st, t, addSeg, lazySg);
            update(1, 0, n, en + 1, -t, gcdSeg, myGcd);
            update_range_lazy(1, 0, n, en + 1, en + 1, -t, addSeg, lazySg);
        }
    }


}
