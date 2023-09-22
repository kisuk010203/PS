#include <bits/stdc++.h>
using namespace std;
vector<queue<string>> parrots;
queue<string> parser() {
    string temp;
    getline(cin, temp);
    istringstream iss(temp);
    string token;
    queue<string> parse_queue;
    while (iss >> token) {
        parse_queue.push(token);
    }
    return parse_queue;
}
bool is_possible(int n) {
    queue<string> target = parser();
    while (!target.empty()) {
        string token = target.front();
        bool for_exited = false;
        for (int i = 0; i < n; i++) {
            if (!parrots[i].empty() && parrots[i].front() == token) {
                for_exited = true;
                parrots[i].pop();
                break;
            }
        }
        if (!for_exited)
            return false;
        target.pop();
    }
    for (int i = 0; i < n; i++) {
        if (!parrots[i].empty())
            return false;
    }

    return true;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        queue<string> parse_queue = parser();
        parrots.push_back(parse_queue);
    }

    bool ans = is_possible(n);
    cout << (ans ? "P" : "Imp") << "ossible\n";
}
