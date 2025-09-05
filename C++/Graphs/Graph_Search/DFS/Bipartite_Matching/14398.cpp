#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 201

int N;
vector<ll> odd_sticks;
vector<ll> even_sticks;
vector<int> odd_to_even[MAX];
int even_to_odd[MAX];
bool visited[MAX];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool matching(int odd) {
    if (visited[odd]) return false;
    visited[odd] = true;
    for (auto even : odd_to_even[odd]) {
        if (even_to_odd[even] == -1 || matching(even_to_odd[even])) {
            even_to_odd[even] = odd;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll temp; cin >> temp;
        if (temp & 1) odd_sticks.push_back(temp);
        else even_sticks.push_back(temp);
    }

    for (int i = 0; i < odd_sticks.size(); i++) {
        for (int j = 0; j < even_sticks.size(); j++) {
            ll hypot_sq = odd_sticks[i] * odd_sticks[i] + even_sticks[j] * even_sticks[j];
            ll hypot = sqrt(hypot_sq);
            if (hypot * hypot == hypot_sq && gcd(odd_sticks[i], even_sticks[j]) == 1) odd_to_even[i].push_back(j);
        }
    }

    for (int i = 0; i < MAX; i++) 
        even_to_odd[i] = -1;
    
    for (int i = 0; i < odd_sticks.size(); i++) {
        for (int j = 0; j < odd_sticks.size(); j++)
            visited[j] = false;
        matching(i);
    }

    int res = 0;
    for (int i = 0; i < even_sticks.size(); i++) {
        if (even_to_odd[i] >= 0)
            res++;
    }
    cout << res << "\n";






}