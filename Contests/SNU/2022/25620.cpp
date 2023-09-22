#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    int N, Q; cin >> N >> Q;
    int zero_cnt = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<N; i++){ 
        ll temp; cin >> temp;
        pq.push(temp);
    }
    while(Q--){
        int x, y; cin >> x >> y;
        if(y == 1) continue;
        vector<ll> temp;
        while(!pq.empty() && (pq.top() <= x)){
            temp.push_back(pq.top());
            pq.pop();
        }
        if(y == 0){
            zero_cnt += temp.size();
            continue;
        }
        for(auto item : temp){
            pq.push(item * y);
        }
    }
    while(zero_cnt--) cout << 0 << ' ';
    while(!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}
