#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string &s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1])
            return false;
    }
    return true;
}
void check_password(vector<string> words) {
    int words_size = words.size();
    for (int i = 0; i < words_size; i++) {
        for (int j = 0; j < words_size; j++) {
            if (i == j)
                continue;
            string temp = words[i] + words[j];
            if (is_palindrome(temp)) {
                cout << words[i] + words[j] << "\n";
                return;
            }
        }
    }
    cout << "0\n";
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        vector<string> words;
        int words_size;
        cin >> words_size;
        for (int i = 0; i < words_size; i++) {
            string temp;
            cin >> temp;
            words.push_back(temp);
        }
        check_password(words);
    }
}
