#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    unordered_map<char, string> russian = {
        {'B', "v"}, {'E', "ye"}, {'H', "n"}, {'P', "r"},
        {'C', "s"}, {'Y', "u"},  {'X', "h"},
    };
    string russian_word;
    cin >> russian_word;
    for (int i = 0; i < russian_word.size(); i++) {
        char temp = russian_word[i];
        if (russian.find(temp) == russian.end()) {
            cout << (char)(temp - ('A' - 'a'));
        } else
            cout << russian[temp];
    }
}
