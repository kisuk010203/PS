#include <bits/stdc++.h>
using namespace std;
#define MAX 101010
typedef long long ll;
ll N, K;
ll cow[MAX];
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for(ll i=0; i<N; i++) cin >> cow[i];
    ll dp[MAX];
    deque<p> dq;
    dq.push_back(make_pair(0, cow[0]));
    for(int i=2; i<=n; i++){
        
        cout << " " << dq.front().second;
    }
    for(int i=0; i<K-1; i++){
        if(i==0) dp[i] = cow[i];
        else{
            dp[i] = dp[i-1] + cow[i];
            while(!dq.empty() && dq.back().second >= cow[i]) dq.pop_back();
            dq.push_back(make_pair(i, cow[i]));
        }
    }
    for(int i==K; i<N; i++){
        if(dq.front().first <= i-K) dq.pop_front();
        while(!dq.empty() && dq.back().second >= cow[i]) dq.pop_back();
        dq.push_back(make_pair(i, cow[i]));
        dp[i] = 
    }
    return 0;
}

