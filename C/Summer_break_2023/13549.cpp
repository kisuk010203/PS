#include <bits/stdc++.h>
using namespace std;
#define INF -1
int duration[200001];
bool is_valid(int k, int curr) { return k >= 0 && k <= 200000 && (duration[k] == INF || duration[k] > duration[curr]); }
int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    deque<int> bfs_queue;
    deque<int> teleport;
    memset(duration, INF, sizeof(duration));

    bfs_queue.push_back(n);

    duration[n] = 0;

    while (!bfs_queue.empty()) {
        int curr = bfs_queue.front();
        bfs_queue.pop_front();
        if(is_valid(curr+1, curr)){
            bfs_queue.push_back(curr+1);
            duration[curr+1] = duration[curr] + 1;
        }
        if(is_valid(curr-1, curr)){
            bfs_queue.push_back(curr-1);
            duration[curr-1] = duration[curr] + 1;
        }
        if(is_valid(curr*2, curr)){
            bfs_queue.push_front(curr*2);
            duration[curr*2] = duration[curr];
        }
    }
    cout << duration[k] << endl;

    return 0;
}
