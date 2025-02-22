#include <bits/stdc++.h>
using namespace std;

class BinaryTrie {
    private:
        class Node {
            public:
                Node *child [2];
                int cnt;
                Node() {
                    child[0] = child[1] = nullptr;
                    cnt = 0;
                }
                ~Node() {
                    for (int i = 0; i < 2; i++) {
                        if (child[i]) {
                            delete child[i];
                        }
                    }
                }
        };
        Node *root;
    
    public:
        BinaryTrie() {
            root = new Node();
        }
        ~BinaryTrie() {
            delete root;
        }
    void insert(int x) {
        Node *cur = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!(cur->child[bit]))
                cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->cnt++;
        }
    }
    void erase(int x) {
        Node *cur = root;
        Node *prv = root;
        
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit]) return;
    
            prv = cur;
            cur = cur->child[bit];
            cur->cnt--;
    
            if (cur->cnt == 0) { 
                prv->child[bit] = nullptr; 
                delete cur;
                return;
            }
        }
    }
    int search_max_diff(int x) {
        Node *cur = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if(cur->child[!bit] && cur->child[!bit]->cnt > 0) {
                ans |= (1 << i);
                cur = cur->child[!bit];
            }
            else
                cur = cur->child[bit];
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    BinaryTrie trie;
    int m; cin >> m;
    trie.insert(0);
    while(m--) {
        int mode, x; cin >> mode >> x;
        if(mode == 1) trie.insert(x);
        else if(mode == 2) trie.erase(x);
        else cout << trie.search_max_diff(x) << "\n";
    }
}