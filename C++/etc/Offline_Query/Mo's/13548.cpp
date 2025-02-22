#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> Query;
#define MAX 100001
int freq[MAX];
int freq_cnt[MAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int q; cin >> q;
    vector<Query> queries;
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        queries.push_back({{l - 1, r - 1}, i});
    }
    int block = sqrt(n);
    sort(queries.begin(), queries.end(), [&](Query a, Query b) {
        if(a.first.first / block != b.first.first / block) return a.first.first / block < b.first.first / block;
        return a.first.second < b.first.second;
    });
    int l = 0, r = -1;
    memset(freq, 0, sizeof(freq));
    memset(freq_cnt, 0, sizeof(freq_cnt));
    freq_cnt[0] = n;
    int ans[q];
    int cur_ans = 0;
    for(auto query : queries) {
        int left = query.first.first;
        int right = query.first.second;
        int idx = query.second;
        while(l > left) {
            l--;
            freq_cnt[freq[arr[l]]]--;
            freq[arr[l]]++;
            freq_cnt[freq[arr[l]]]++;
            cur_ans = max(cur_ans, freq[arr[l]]);
        }
        while(l < left) {
            freq_cnt[freq[arr[l]]]--;
            if(cur_ans == freq[arr[l]] && freq_cnt[freq[arr[l]]] == 0) cur_ans--;
            freq[arr[l]]--;
            freq_cnt[freq[arr[l]]]++;
            l++;
        }
        while(r < right) {
            r++;
            freq_cnt[freq[arr[r]]]--;
            freq[arr[r]]++;
            freq_cnt[freq[arr[r]]]++;
            cur_ans = max(cur_ans, freq[arr[r]]);
        }
        while(r > right) {
            freq_cnt[freq[arr[r]]]--;
            if(cur_ans == freq[arr[r]] && freq_cnt[freq[arr[r]]] == 0) cur_ans--;
            freq[arr[r]]--;
            freq_cnt[freq[arr[r]]]++;
            r--;
        }
        ans[idx] = cur_ans;
    }
    for(auto i : ans) cout << i << "\n";
}