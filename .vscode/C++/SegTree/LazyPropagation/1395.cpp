#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int n, m;
int segtree[MAX*4];
bool lazy[MAX*4];
void init(){
    for(int i=0; i<4*MAX; i++){
        segtree[i] = 0;
        lazy[i] = false;
    }
}
void update_lazy(int node, int start, int end){
    if(lazy[node]){
        segtree[node] = (end-start+1) - segtree[node];
        if(start != end){
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
    }
    lazy[node] = false;
}
void update_range(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(start > right || end < left) return;
    else if(start >=left && end <=right){
        segtree[node] = (end-start+1) - segtree[node];
        if(start != end){
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }return;
    }
    int mid = (start+end)/2;
    update_range(node*2, start, mid, left, right);
    update_range(node*2+1, mid+1, end, left, right);
    segtree[node] = segtree[node*2] + segtree[node*2+1];
}
int getsum(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(start > right || end < left) return 0;
    if(start >=left && end <=right) return segtree[node];
    int mid = (start+end)/2;
    return getsum(node*2, start, mid, left, right) + getsum(node*2+1, mid+1, end, left, right);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    init();
    for(int i=0; i<m; i++){
        int mode, left, right; cin >> mode >> left >> right;
        if(mode == 0){
            update_range(1, 0, n-1, left-1, right-1);
        }
        else{
            cout << getsum(1, 0, n-1, left-1, right-1) << '\n';
        }
    }
}