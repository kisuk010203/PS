#include <bits/stdc++.h>
using namespace std;
typedef struct Trie {
    bool is_leaf;
    Trie *fail;
    Trie *children[26];
    Trie() {
        is_leaf = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        fail = nullptr;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }
};
void insert(Trie* root, string word, int idx) {
    if(idx == word.size()) {
        root->is_leaf = true;
        return;
    }
    int next_idx = word[idx] - 'a';
    if(root -> children[next_idx]) {
        insert(root->children[next_idx], word, idx + 1);
    } else {
        Trie *new_trie = new Trie();
        root->children[next_idx] = new_trie;
        insert(new_trie, word, idx + 1);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    Trie *root = new Trie();
    for(int i=0; i<n; i++){
        string word; cin >> word;
        insert(root, word, 0);
    }
    queue<Trie*> q;
    q.push(root);
    while(!q.empty()) {
        Trie *cur = q.front(); q.pop();
        for(int i=0; i<26; i++){
            if(cur -> children[i]) {
                Trie *next = cur -> children[i];
                if(cur == root) next->fail = root;
                else {
                    Trie *dest = cur->fail;
                    while(dest != root && !dest->children[i]) 
                        dest = dest->fail;
                    if(dest->children[i]) dest = dest->children[i];
                    next->fail = dest;
                }
                if(next->fail->is_leaf) {
                    next->is_leaf = true;
                }
                q.push(next);
            }
        }
    }
    int m; cin >> m;
    while(m--) {
        string word; cin >> word;
        Trie *cur = root;
        bool ans = false;
        for(int i=0; i<word.size(); i++) {
            int next_idx = word[i] - 'a';
            while(cur != root && !cur->children[next_idx])
                cur = cur->fail;
            if(cur->children[next_idx]) cur = cur->children[next_idx];
            if(cur->is_leaf) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    delete root;
}