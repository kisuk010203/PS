#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 51
vector<int> eaten_list[MAX << 1];
struct shark {
    ll x, y, z;
};
int assign[MAX];
bool visited[MAX];
struct shark shark_list[MAX];
bool dfs(int x) {
    for(auto y : eaten_list[x]) {
        if(visited[y]) continue;
        visited[y] = true;
        if(assign[y] == -1 || dfs(assign[y])) {
            assign[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> shark_list[i].x >> shark_list[i].y >> shark_list[i].z;
    }
    for(int i  = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(shark_list[i].x == shark_list[j].x && shark_list[i].y == shark_list[j].y && shark_list[i].z == shark_list[j].z) {
                if(i < j) {
                    eaten_list[i].push_back(j);
                    eaten_list[i + n].push_back(j);
                }
                else {
                    eaten_list[j].push_back(i); 
                    eaten_list[j + n].push_back(i);
                }
            } else if(shark_list[i].x >= shark_list[j].x && shark_list[i].y >= shark_list[j].y && shark_list[i].z >= shark_list[j].z) {
                eaten_list[i].push_back(j);
                eaten_list[i + n].push_back(j);
            }
        }
    }

    int res = 0;
    fill(assign, assign + MAX, -1);
    for(int i = 0; i < 2 *n; i++) {
        for(int j = 0; j < n; j++) visited[j] = false;
        if(dfs(i)) res++;
    }
    cout << n - res << "\n";
}