#include <bits/stdc++.h>
using namespace std;
#define INF -1
int duration[200001];
bool is_valid(int k) {
    return k >= 0 && k <= 200000 && duration[k] == INF;
}
int main(int argc, char const* argv[]) {
    int n, k;
    cin >> n >> k;
    queue<int> bfs_queue;
    memset(duration, INF, sizeof(duration));

    bfs_queue.push(n);
    duration[n] = 0;

    while (!bfs_queue.empty() && duration[k] == INF) {
        int curr = bfs_queue.front();
        bfs_queue.pop();
        int next_item[3] = {curr + 1, curr - 1, curr * 2};
        for (int item : next_item) {
            if (is_valid(item)) {
                bfs_queue.push(item);
                duration[item] = duration[curr] + 1;
            }
        }
    }
    cout << duration[k] << endl;

    return 0;
}
