#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct Trie {
    bool is_leaf;
    ll leaf_num;
    Trie *child[2];

    Trie() { // constructor
        is_leaf = false;
        child[0] = nullptr;
        child[1] = nullptr;
    }

    ~Trie() { // destructor
        delete child[0];
        delete child[1];
    }

    void insert_pattern(string pattern, ll num) {
        Trie *curr = this;
        for (int i = 0; i < pattern.size(); i++) {
            int val = pattern[i] - '0';
            if (curr->child[val] == nullptr) {
                curr->child[val] = new Trie;
            }
            curr = curr->child[val];
        }

        curr->leaf_num = num;
        curr->is_leaf = true;
    }

    ll query(string curr_str, ll curr_num) {
        Trie *curr = this;
        for (int i = 0; i < curr_str.size(); i++) {
            int val = curr_str[i] - '0';
            if (curr->child[val ^ 1] != nullptr) {
                curr = curr->child[val ^ 1];
            } else {
                curr = curr->child[val];
            }
        }
        return curr->leaf_num ^ curr_num;
    }
} Trie;
int t, n;
ll a, k;
vector<int> seq;
vector<string> strings;
ll ans;
void init() {
    seq.clear();
    strings.clear();
    k = 0;
    ans = 0;
}
string int_to_string(int num) { return bitset<32>(num).to_string(); }
void find_answer(Trie *root) {
    for (int i = 0; i <= n; i++) {
        ll query_result = root->query(strings[i], seq[i]);
        ans = max(ans, query_result);
    };
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        init();
        Trie *root = new Trie();
        cin >> n;
        seq.push_back(0);
        strings.push_back(int_to_string(0));
        for (int i = 0; i < n; i++) {
            cin >> a;
            k ^= a;
            seq.push_back(k);
            string new_string = int_to_string(k);
            strings.push_back(new_string);
        }
        for (int i = 0; i <= n; i++) {
            root->insert_pattern(strings[i], seq[i]);
        }
        find_answer(root);
        cout << ans << "\n";
        delete root;
        /* code */
    }
    return 0;
}
