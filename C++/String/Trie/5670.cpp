#include <bits/stdc++.h>
using namespace std;
typedef struct trie {
    bool is_leaf;
    trie* children[26];

    trie() {
        is_leaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~trie() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
} trie;
void insert(trie* root, string word, int idx) {
    if (idx == word.size()) {
        root->is_leaf = true;
        return;
    }
    int next_idx = word[idx] - 'a';
    if (root->children[next_idx] == nullptr) {
        trie* new_child = new trie();
        root->children[next_idx] = new_child;
        insert(new_child, word, idx + 1);
    } else {
        insert(root->children[next_idx], word, idx + 1);
    }
}
int count(trie* root, string word, int idx) {
    int next_idx = word[idx] - 'a';
    if (idx == word.size() && root->is_leaf)
        return 0;
    int curr_cnt = 0;
    for (auto item : root->children) {
        if (item != nullptr)
            curr_cnt++;
    }
    if (curr_cnt >= 2) {
        return 1 + count(root->children[next_idx], word, idx + 1);
    }
    if (root->is_leaf) {
        return 1 + count(root->children[next_idx], word, idx + 1);
    }
    return count(root->children[next_idx], word, idx + 1);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        double count_sum = 0;

        trie* root = new trie();

        vector<string> word_dictionary;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            word_dictionary.push_back(temp);
            insert(root, temp, 0);
        }
        for (string word : word_dictionary) {
            int count_res = count(root, word, 0);
            count_sum += count_res;
        }
        count_sum /= n;
        int curr_cnt = 0;
        for (auto item : root->children) {
            if (item != nullptr)
                curr_cnt++;
        }
        if (curr_cnt == 1)
            count_sum++;
        printf("%.2lf\n", count_sum);
        delete root;
    }
}
