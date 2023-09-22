#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    char data;
    vector<Node *> siblings;
};
class Trie {
  private:
    Node *root = new Node;

  public:
    void push(string str) { insert(str, 0, root); }
    void insert(string str, int idx, Node *node) {
        if (idx >= str.length())
            return;
        int next = -1;
        for (int i = 0; i < node->siblings.size(); i++) {
            if (str[idx] == node->siblings[i]->data) { // when same character
                next = i;
                break;
            }
        }
        if (next != -1)
            insert(str, idx + 1, node->siblings[next]);
        else // if no same character, add as a child
        {
            Node *newNode = new Node;
            newNode->data = str[idx];
            node->siblings.push_back(newNode);
            insert(str, idx + 1, newNode);
        }
    }

    bool search(string str) { return findWord(str, 0, root); }

    bool findWord(string str, int idx, Node *node) {
        if (idx >= str.length())
            return true;
        int next = -1;
        for (int i = 0; i < node->siblings.size(); i++) {
            if (str[idx] == node->siblings[i]->data) {
                next = i;
                break;
            }
        }
        if (next != -1)
            return findWord(str, idx + 1, node->siblings[next]);
        else
            return node->siblings.empty();
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        Trie *myTrie = new Trie;
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            if (i > 0 && myTrie->search(temp))
                flag = false;
            myTrie->push(temp);
        }
        if (flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}