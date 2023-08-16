#include <bits/stdc++.h>
#define MAX 100009
#define INF 1000000008
using namespace std;
typedef pair<int, int> pl;
int n, m;
int arr[MAX];
int min_segtree[MAX*3];
int max_segtree[MAX*3];
void init(int node, int start, int end){
    if(start == end){
        min_segtree[node] = max_segtree[node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    init(node*2, start, mid); init(node*2 +1, mid+1, end);
    min_segtree[node] = min(min_segtree[2*node], min_segtree[2*node +1]);
    max_segtree[node] = max(max_segtree[2*node], max_segtree[node*2 +1]); return;
}
pl find_ans(int node, int start, int end, int left, int right){
    if(left > end || right < start) return make_pair(INF, 0);
    else if(left <= start && end <= right) return make_pair(min_segtree[node], max_segtree[node]);
    int mid = (start+end)/2;
    pl front = find_ans(2*node, start, mid, left, right) , back = find_ans(2*node+1, mid+1, end, left, right);
    return make_pair(min(front.first, back.first), max(front.second, back.second));
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    init(1, 0, n-1);
    int a, b; pl ans;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        ans = find_ans(1, 0, n-1, a-1, b-1);
        printf("%d %d\n", ans.first, ans.second);
    }
}