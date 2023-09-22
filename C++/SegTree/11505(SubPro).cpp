#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int n, m, k;

ll init(ll *segtree, ll *arr, int node, int start, int end){
    if(start == end) return segtree[node] = arr[start];
    int mid = (start+end)/2;
    ll front = init(segtree, arr, 2*node, start, mid), back = init(segtree, arr, 2*node+1, mid+1, end);
    return segtree[node] = (front*back)%MOD;
}
ll get_pro(ll *segtree, ll node, int start, int end, int left, int right){
    if(start > right || end < left) return 1;
    else if(start >= left && end <= right) return segtree[node];
    int mid = (start+end)/2;
    return (get_pro(segtree, node*2, start, mid, left, right) * get_pro(segtree, node*2+1, mid+1, end, left, right))%MOD;
}
int main(){
    cin >> n >> m >> k;
    ll *arr = new ll[n]; for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    ll *segtree = new ll[4*n];
    init(segtree, arr, 1, 0, n-1);
    int a, b, c;
    for(int i=0; i<m+k; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1){
            update(segtree, arr, 1, 0, n-1, b-1, c);
            arr[b-1] = c;
        }
        else{
            printf("%lld\n", get_pro(segtree, 1, 0, n-1, b-1, c-1));
        }
    }

}

