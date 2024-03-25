#include <bits/stdc++.h>
using namespace std;
typedef struct talk {
    int due;
    int weight;
} talk;
bool comp(const talk& a, const talk& b) {
    return a.due > b.due;
}
struct comp_pq {
    bool operator()(const talk& a, const talk& b) {
        return a.weight < b.weight;
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    vector<talk> talks;
    priority_queue<talk, vector<talk>, comp_pq> talk_pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, w;
        cin >> w >> d;
        talks.push_back({d, w});
    }

    sort(talks.begin(), talks.end(), comp);  // sort talk decreasing due
    int due_idx = 0;
    long long ret = 0;
    for (int due_date = 10000; due_date; due_date--) {
        while (due_idx < n && talks[due_idx].due >= due_date) {
            talk_pq.push(talks[due_idx]);
            due_idx++;
        }
        if (talk_pq.empty())
            continue;
        ret += talk_pq.top().weight;
        talk_pq.pop();
    }
    cout << ret << "\n";
}
