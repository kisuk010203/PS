#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll k;
int seq[510];
ll cnt[510];
int lis[510];
vector<int> kth_lis;
void GetLis(int start, int skip){
    if(start != 0) kth_lis.push_back(start);
    if(lis[start] == 1) return;
    vector<pair<int, int>> nexts;
    for(int i=start+1; i<=n; i++){
        if(seq[start] < seq[i] && lis[i] == lis[start]-1)
            nexts.push_back(make_pair(seq[i], i));
    }
    sort(nexts.begin(), nexts.end());
    for(int i=0; i<nexts.size(); i++){
        int temp = nexts[i].second;
        if(skip < cnt[temp]){
            GetLis(temp, skip);
            break;
        }
        else skip -= cnt[temp];
    }
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++) scanf("%d", seq+i+1);
    seq[0] = -10;
    cnt[n] = 1, lis[n] = 1;
    for(int i=n-1; i>=0; i--){
        cnt[i] = 1, lis[i] = 1;
        for(int j=i+1; j<=n; j++){
            if(seq[j] > seq[i] && lis[j]+1 > lis[i]){
                lis[i] = lis[j]+1;
                cnt[i] = cnt[j];
            }
            else if(seq[j] > seq[i] && lis[j]+1 == lis[i]){
                cnt[i] = cnt[i] + cnt[j];
                if(cnt[i] > 2000000000) cnt[i] = 2000000000;
            }
        }
    }
    if(cnt[0] < k){
        cout << -1; return 0;
    }
    GetLis(0, k-1);
    for(const auto& lis_el : kth_lis) cout << seq[lis_el] << " ";
}
