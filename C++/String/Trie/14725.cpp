#include <bits/stdc++.h>
using namespace std;
typedef struct trie {
    string item;
    vector<trie *> children;
} trie;

bool comp_trie(const trie *a, const trie *b) { return a->item < b->item; }
void insert(trie *root, vector<string> key, int index) {
    if (index == key.size())
        return;
    for (auto child : root->children) {
        if (child->item == key[index]) {
            insert(child, key, index + 1);
            return;
        }
    }
    trie *new_node = new trie;
    new_node->item = key[index];
    root->children.push_back(new_node);
    insert(new_node, key, index + 1);
}
void print_trie(trie *root, int depth) {
    if (depth >= 0) {
        for (int i = 0; i < depth; i++) {
            cout << "--";
        }
        cout << root->item << "\n";
    }
    sort(root->children.begin(), root->children.end(), comp_trie);
    for (auto child : root->children) {
        print_trie(child, depth + 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    trie *dummy_root = new trie;
    dummy_root->item = "dummy";

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<string> children;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string string_temp;
            cin >> string_temp;
            children.push_back(string_temp);
        }
        insert(dummy_root, children, 0);
    }
    print_trie(dummy_root, -1);
}
