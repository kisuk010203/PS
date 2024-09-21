#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
bool visited[MAXN];    // A visited in this scope
int match[MAXN];       // B to A
vector<int> adj[MAXN]; // A to B
bool prime[2001];
int n, m;
void prime_test() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i < 45; i++) {
        if (!prime[i])
            continue;
        for (int j = i * 2; j <= 2000; j += i) {
            prime[j] = false;
        }
    }
}
bool dfs(int st) {
    if (visited[st])
        return false;
    visited[st] = true;
    for (int child : adj[st]) {
        if (match[child] == -1 || dfs(match[child])) {
            match[child] = st;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    prime_test();

    int results[n] = {0};
    vector<int> possibles;

    for (int i = 1; i < n; i++) {

        if (!prime[arr[0] + arr[i]])
            continue;
        for (int i = 0; i < MAXN; i++) {
            adj[i].clear();
        }
        vector<int> odds;
        vector<int> evens;
        for (int j = 1; j < n; j++) {
            if (i == j)
                continue;
            if (arr[j] % 2 == 0)
                evens.push_back(arr[j]);
            else
                odds.push_back(arr[j]);
        }

        for (int j = 0; j < odds.size(); j++) {
            for (int k = 0; k < evens.size(); k++) {
                if (prime[odds[j] + evens[k]])
                    adj[j].push_back(k);
            }
        }
        fill(match, match + MAXN, -1);
        for (int j = 0; j < odds.size(); j++) {
            fill(visited, visited + MAXN, false);
            dfs(j);
        }
        for (int j = 0; j < evens.size(); j++) {
            if (match[j] >= 0)
                results[i]++;
        }

        if (results[i] == n / 2 - 1)
            possibles.push_back(arr[i]);
    }

    sort(possibles.begin(), possibles.end());
    for (auto item : possibles)
        cout << item << " ";
    if (possibles.empty())
        cout << -1;
}