#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct {
    int from, to;
} Edge;
typedef struct disjoint_set {
    vector<int> parent, rank;
    disjoint_set(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            ++rank[v];
    }
} disjoint_set;

vector<Edge> edges[5];
vector<pair<int, int>> school_weights;
unordered_map<string, vector<int>> school_weight_to_counts;
int n, m, q;

string encode_school_weight() {
    string s = "";
    for (int i = 0; i < 5; i++) {
        s += to_string(school_weights[i].second);
    }
    return s;
}
void kruskal() {
    disjoint_set sets(n);
    vector<int> counts;
    for (auto weight_school : school_weights) {
        int school = weight_school.second;
        ll count = 0;
        for (auto edge : edges[school]) {
            int from = edge.from;
            int to = edge.to;
            if (sets.find(from) == sets.find(to))
                continue;
            sets.merge(from, to);
            count++;
        }
        counts.push_back(count);
    }
    school_weight_to_counts[encode_school_weight()] = counts;
}

ll run_memoized_kruskal() {
    ll ret = 0;
    string encoded = encode_school_weight();
    if (school_weight_to_counts.find(encoded) ==
        school_weight_to_counts.end()) {
        kruskal();
    }
    for (int i = 0; i < 5; i++) {
        ret += (ll)school_weights[i].first *
               (ll)school_weight_to_counts[encoded][i];
    }
    return ret;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int from, to;
        char school;
        cin >> from >> to >> school;
        edges[school - 'A'].push_back({from - 1, to - 1});
    }

    while (q--) {
        school_weights.clear();
        for (int i = 0; i < 5; i++) {
            int weight;
            cin >> weight;
            school_weights.push_back({weight, i});
        }
        sort(school_weights.begin(), school_weights.end());
        ll ret = run_memoized_kruskal();
        cout << ret << '\n';
    }
}
