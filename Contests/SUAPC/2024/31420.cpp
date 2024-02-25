#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string, int> pair_to_cnt;
int n, T;
string s;
string substring(int index) {
    string ss;
    ss.push_back(s[index]);
    ss.push_back(s[index + 1]);
    return ss;
}
ll get_cnt(int start, int end) {
    for(auto item : pair_to_cnt){
        pair_to_cnt[item.first] = 0;
    }
    int l = start, r = start;
    int type_cnt = 0;
    ll ret = 0;
    for (int l = start; l < end; l++) {
        if (l != start) {
            if(--pair_to_cnt[substring(l-1)] == 0){
                type_cnt--;
            }
        }
        while (type_cnt < T) {
            if (r == end)
                return ret;
            if(pair_to_cnt[substring(r)]++ == 0){
                type_cnt++;
            }
            r++;
        }
        ret += (end - r + 1);
    }
    return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> T;
    for(int i=0; i<T; i++) {
        string temp;
        cin >> temp;
        if (pair_to_cnt.find(temp) == pair_to_cnt.end()) {
            pair_to_cnt[temp] = 0;
        }
    }

    vector<int> bad_index; // i in bad_index : (i, i+1) is not in pair_to_cnt
    vector<pair<int, int>> connected;
    for (int i = 0; i < n - 1; i++) {
        if (pair_to_cnt.find(substring(i)) == pair_to_cnt.end()) {
            bad_index.push_back(i);
        }
    }
    int start = 0;
    for (auto item : bad_index) {
        if (item != start) {
            connected.push_back({start, item});
        }
        start = item + 1;
    }
    connected.push_back({start, n - 1});
    ll ret = 0;
    for (auto start_end : connected) {
        ret += get_cnt(start_end.first, start_end.second);
    }
    cout << ret << '\n';
}