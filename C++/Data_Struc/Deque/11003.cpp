#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int arr[5000007];
int n, l;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> l;
    for(int i=1; i<=n; i++) cin >> arr[i];
    deque<p> dq;

    dq.push_back(make_pair(1, arr[1])); cout << arr[1];
    for(int i=2; i<=n; i++){
        if(dq.front().first <= i-l) dq.pop_front();
        while(!dq.empty() && dq.back().second >= arr[i]) dq.pop_back();
        dq.push_back(make_pair(i, arr[i]));
        cout << " " << dq.front().second;
    }
}
