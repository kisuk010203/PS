#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

pair<int, int> prefix_and_suffix(string word, char key) {
    int len = word.length();
    int prefix = INF, suffix = INF;
    for (int i = 0; i < len; i++) {
        if (word[i] == key) {
            suffix = len - i - 1;
            prefix = min(prefix, i);
        }
    }
    return {prefix, suffix};
}
int main(int argc, char const *argv[]) {
    int n;
    cin >> n; // Read the value of n from input
    string candidates[n];
    int prefix[26];
    int suffix[26];
    int answer[26];
    int result = INF;

    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    memset(prefix, INF, sizeof(prefix));
    memset(suffix, INF, sizeof(suffix));
    memset(answer, INF / 2, sizeof(answer));

    for (string &candidate : candidates) {
        int len = candidate.length();

        for (int key = 0; key < 26; key++) {
            pair<int, int> curr = prefix_and_suffix(candidate, key + 'a');
            answer[key] = min(answer[key], min(suffix[key] + curr.first,
                                               prefix[key] + curr.second));
            prefix[key] = min(prefix[key], curr.first);
            suffix[key] = min(suffix[key], curr.second);
        }
    }

    for (int item : answer) {
        result = min(item, result);
    }
    if (result >= INF / 2)
        result = -1;
    cout << result << endl;
    return 0;
}
