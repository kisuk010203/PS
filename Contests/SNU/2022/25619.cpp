#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
#define INF LONG_LONG_MAX
typedef long long ll;
typedef pair<double, ll> edge;
struct Comparator {
    bool operator()(edge &left, edge &right) {
        return left.first > right.first;
    }
};

vector<edge> adj[MAX];
bool searched[MAX];
bool searched_dfs[MAX];
double dist[MAX];
void dfs(ll start) {
    searched_dfs[start] = true;
    for (auto item : adj[start]) {
        if (!searched_dfs[item.second]) {
            dfs(item.second);
        }
    }
}
void dijkstra(ll start) {
    dist[start] = 0;
    priority_queue<edge, vector<edge>, Comparator> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        ll curr = pq.top().second;
        double dis = pq.top().first;
        pq.pop();
        if (dist[curr] < dis || dis < 0)
            continue;
        for (int i = 0; i < adj[curr].size(); i++) {
            ll next = adj[curr][i].second;
            double nextdist = dis + adj[curr][i].first;
            if (nextdist < dist[next]) {
                dist[next] = nextdist;
                pq.push(make_pair(nextdist, next));
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> negedge;
    vector<ll> ans;
    while (M--) {
        ll a, b;
        double c, d;
        cin >> a >> b >> c >> d;
        if (c + d < 0)
            negedge.push_back(make_pair(a - 1, b - 1));
        adj[a - 1].push_back(make_pair((c + d) / 2, b - 1));
        adj[b - 1].push_back(make_pair((c + d) / 2, a - 1));
    }
    ll T;
    cin >> T;
    fill(searched, searched + MAX, false);
    fill(searched_dfs, searched_dfs + MAX, false);
    fill(dist, dist + MAX, INF);
    dfs(0);
    if (!negedge.empty()) {
        bool flag = false;
        for (auto item : negedge) {
            ll a = item.first;
            ll b = item.second;
            if (searched_dfs[a] && searched_dfs[b]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            for (int i = 1; i < N; i++)
                if (searched_dfs[i])
                    ans.push_back(i);
            cout << ans.size() << '\n';
            for (auto item : ans)
                cout << item + 1 << ' ';
            return 0;
        }
    }
    dijkstra(0);

    for (int i = 1; i < N; i++) {
        if (dist[i] <= T)
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto item : ans)
        cout << item + 1 << ' ';

    return 0;
}
