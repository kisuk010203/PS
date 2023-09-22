#include <bits/stdc++.h>
#define MAX 100009
#define INF 1000000008
using namespace std;
int n, m;
int arr[MAX];
int min_tree[MAX*3];
void init(int node, int start, int end){
    if(start == end){
        min_tree[node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    init(node*2, start, mid); init(node*2 +1, mid+1, end);
    min_tree[node] = min(min_tree[2*node], min_tree[2*node +1]); return;
}
int find_ans(int node, int start, int end, int left, int right){
    if(left > end || right < start) return INF;
    else if(left <= start && end <= right) return min_tree[node];
    int mid = (start+end)/2;
    int front = find_ans(2*node, start, mid, left, right) , back = find_ans(2*node+1, mid+1, end, left, right);
    return min(front, back);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    init(1, 0, n-1);
    int a, b, ans;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        ans = find_ans(1, 0, n-1, a-1, b-1);
        printf("%d\n", ans);
    }
}
