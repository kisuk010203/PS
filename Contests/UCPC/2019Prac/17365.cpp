#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
class Node {
  public:
    char data;
    int words = 0;
    vector<Node *> siblings;
};
class Trie {
  public:
    Node *root = new Node;
    void push(string str) { insert(str, 0, root); }
    void insert(string str, int idx, Node *node) {
        node->words++;
        if (idx >= str.length())
            return;
        int next = -1;
        for (int i = 0; i < node->siblings.size(); i++) {
            if (str[idx] == node->siblings[i]->data) {
                next = i;
                break;
            }
        }
        if (next != -1) {
            insert(str, idx + 1, node->siblings[next]);
        } else {
            Node *newNode = new Node;
            newNode->data = str[idx];
            newNode->words = 0;
            node->siblings.push_back(newNode);
            insert(str, idx + 1, newNode);
        }
    }
};
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    Trie *trie = new Trie;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        trie->push(temp);
    }
    string target;
    cin >> target;
    int target_len = target.length();
    ll dp[target_len + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= target_len; i++) {
        Node *root = trie->root;
        int cnt = 0;
        while (cnt < i && root->words != 0) {
            int next = -1;
            for (int j = 0; j < root->siblings.size(); j++) {
                if (root->siblings[j]->data == target[target_len + cnt - i]) {
                    next = j;
                    break;
                }
            }
            if (next == -1)
                break;
            dp[i] = (dp[i] +
                     (root->siblings[next]->words * dp[i - 1 - cnt]) % MOD) %
                    MOD;
            cnt++;
            root = root->siblings[next];
        }
    }
    cout << dp[target_len] << "\n";
}