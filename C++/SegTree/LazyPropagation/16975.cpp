#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000
ll arr[MAX];
ll segtree[MAX*4];
ll lazy[MAX*4];

ll init(int node, int start, int end){
    if(start == end) return segtree[node] = arr[start];
    int mid = (start+end)/2;
    return segtree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end);
}
void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){
        segtree[node] += (end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right, ll diff){
    update_lazy(node, start, end);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        segtree[node] += (end-start+1)*diff;
        if(start!= end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (start+end)/2;
    update_range(node*2, start, mid, left, right, diff);
    update_range(node*2+1, mid+1, end, left, right, diff);
    segtree[node] = segtree[node*2] + segtree[node*2+1];
}
ll getsum(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segtree[node];
    int mid = (start+end)/2;
    return getsum(node*2, start, mid, left, right) + getsum(node*2+1, mid+1, end, left, right);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];
    init(1, 0, n-1);
    cin >> m;
    for(int i=0; i<m; i++){
        int mode; cin >> mode;
        if(mode == 1){
            int start, end; ll diff; cin >> start >> end >> diff;
            update_range(1, 0, n-1, start-1, end-1, diff);
        }
        else{
            int idx; cin >> idx;
            cout << getsum(1, 0, n-1, idx-1, idx-1) << '\n';
        }
    }

}
