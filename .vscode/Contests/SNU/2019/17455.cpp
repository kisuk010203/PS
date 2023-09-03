#include <bits/stdc++.h>
using namespace std;
#define VMAX 200200
int n, m;
string vertices;
vector<int> edges[VMAX];
vector<int> top_sort;

int in_degree[VMAX];
bool top_sort_done[VMAX];
bool has_cycle;

char get_next(char a) {
    switch (a) {
    case 'K':
        return 'D';
    case 'D':
        return 'H';
    case 'H':
        return 'K';
    default:
        return ' ';
    }
}

void get_zero_in_degree(queue<int> &top_sort_queue) {
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0 && !top_sort_done[i]) {
            top_sort_queue.push(i);
        }
    }
}
void do_top_sort() {
    queue<int> top_queue;
    get_zero_in_degree(top_queue);
    while (!top_queue.empty()) {
        int curr = top_queue.front();
        top_queue.pop();
        top_sort.push_back(curr);
        top_sort_done[curr] = true;

        for (int item : edges[curr]) {
            in_degree[item]--;
            if (in_degree[item] == 0) {
                if (top_sort_done[item]) {
                    has_cycle = true;
                } else {
                    top_queue.push(item);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(!top_sort_done[i])
            has_cycle = true;
    }
}

int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    has_cycle = false;
    memset(top_sort_done, false, sizeof(top_sort_done));
    memset(in_degree, 0, sizeof(in_degree));
    cin >> n >> m;
    cin >> vertices;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (vertices[a] == vertices[b])
            continue;
        if (vertices[b] != get_next(vertices[a])) {
            swap(a, b);
        }
        edges[a].push_back(b);
        in_degree[b]++;
    }

    do_top_sort();

    if (has_cycle) {
        cout << "-1\n";
        return 0;
    }

    int dp[n];
    for (int i = n - 1; i >= 0; i--) {
        int curr = top_sort[i];
        dp[curr] = 1;
        for (int item : edges[curr]) {
            if (vertices[item] == get_next(vertices[curr])) {
                dp[curr] = max(dp[curr], dp[item] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vertices[i] == 'K') {
            ans = max(ans, (dp[i] / 3) * 3);
        }
    }

    if (ans == 0)
        ans = -1;
    cout << ans << "\n";
    return 0;
}
