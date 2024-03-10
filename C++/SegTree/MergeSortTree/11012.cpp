#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100010];
vector<int> tree[1<<18];
const int h = 1<<17;
void add(int x,  int v){
  x |= h; tree[x].push_back(v);
}
void build(){
    for(int i=h-1; i>=1; i--){
        tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
        merge(tree[i*2].begin(), tree[i*2].end(), tree[i*2+1].begin(), tree[i*2+1].end(), tree[i].begin());
    }
}
int query(int left, int right, int k){
    int ret = 0;
    while(left <= right){
        if(left%2 == 1){
            ret += tree[left].end() - upper_bound(tree[left].begin(), tree[left].end(), k);
            left++;
        }
        if(right%2 == 0){
            ret += tree[right].end() - upper_bound(tree[right].begin(), tree[right].end(), k);
            right--;
        }
        left/=2, right/=2;
    }
    return ret;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        add(i, arr[i]);
    }
    build();
    int m; cin >> m;
    while (m--){
        int i, j, k; cin >> i >> j >> k;
        cout << query(i+h, j+h, k) << '\n';
    }
}
