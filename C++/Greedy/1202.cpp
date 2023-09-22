#include <bits/stdc++.h>
using namespace std;
typedef struct jewel {
    int weight;
    int value;
} jewel;
bool comp(jewel a, jewel b) { return a.weight < b.weight; }
struct pq_comp {
    bool operator()(const jewel a, const jewel b) {
        if (a.value == b.value)
            return a.weight > b.weight; // weight increasing
        return a.value < b.value;       // value decreasing
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    priority_queue<jewel, vector<jewel>, pq_comp> jewel_pq;
    vector<jewel> jewels;
    vector<int> bags;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewels.push_back({w, v});
    }
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bags.push_back(c);
    }

    sort(jewels.begin(), jewels.end(), comp);
    sort(bags.begin(), bags.end());

    long long ans = 0;
    int jewel_idx = 0;
    for (int bag_idx = 0; bag_idx < k; bag_idx++) {
        while (jewel_idx < n && jewels[jewel_idx].weight <= bags[bag_idx]) {
            jewel_pq.push(jewels[jewel_idx]);
            jewel_idx++;
        }
        if (jewel_pq.empty())
            continue;
        jewel top_pq = jewel_pq.top();
        ans += top_pq.value;
        jewel_pq.pop();
    }
    cout << ans << "\n";
}