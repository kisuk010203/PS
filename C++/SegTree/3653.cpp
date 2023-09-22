#include <bits/stdc++.h>
#define MAX 20
using namespace std;
int n, m;
int arr[MAX];
int seg[MAX*4];
int init(int node, int start, int end){
    if(start == end){
        return seg[node] = (int)(start<n);
    }
    int mid = (start+end)/2;
    return seg[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}
void update(int node, int start, int end, int idx, int dif){
    if(idx < start || idx > end) return;
    seg[node] += dif;
    if(start != end){
        int mid = (start +end)/2;
        update(node*2, start, mid, idx, dif);
        update(node*2+1, mid+1, end, idx, dif);
    }
}
int find_ans(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    else if(left <= start && end <= right) return seg[node];
    int mid = (start+end)/2;
    return find_ans(2*node, start, mid, left, right) + find_ans(2*node+1, mid+1, end, left, right);
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for(int i=0; i<n; i++) arr[i] = n-1-i;
        for(int i=n; i<MAX; i++) arr[i] = 0;
        init(1, 0, n+m-1);
        for(int j=0; j<m; j++){
            int idx; cin >> idx; idx--;
            cout << find_ans(1, 0, n-1+m, arr[idx], n-1+j)-1 << ' ';
            update(1, 0, n+m-1, n+j, 1);
            update(1, 0, n+m-1, arr[idx], -1);
            arr[idx] = n+j;
        }
        cout << '\n';
    }

}
    