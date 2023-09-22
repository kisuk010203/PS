#include <bits/stdc++.h>
using namespace std;
#define MAX 1000003
typedef long long ll;
ll segtree[MAX*4];
void update(ll node, ll start, ll end, ll idx, ll num){
    if(idx < start || idx > end) return;
    segtree[node] += num;
    if(start != end){
        ll mid = (start +end)/2;
        update(node*2, start, mid, idx, num);
        update(node*2+1, mid+1, end, idx, num);
    }
}
ll getcandy(ll node, ll start, ll end, ll idx){
    if(start == end){ 
        update(1, 0, MAX-1, start, -1);
        return start;
    }
    ll mid = (start+end)/2;
    if(segtree[2*node] < idx){
        return getcandy(2*node+1, mid+1, end, idx-segtree[2*node]);
    }
    return getcandy(2*node, start, mid, idx);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test; cin >> test;
    ll mode, order, num;
    for(ll i=0; i<test; i++){
        cin >> mode >> order;
        if(mode == 1){
            cout << getcandy(1, 0, MAX-1, order)+1 << "\n";
        }
        else if(mode == 2){
            cin >> num;
            update(1, 0, MAX-1, order-1, num);
        }
    }
}

