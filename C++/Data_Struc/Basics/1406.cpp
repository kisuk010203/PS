#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<char> left_stack;
    vector<char> right_stack;

    string temp;
    cin >> temp;
    for (auto item : temp)
        left_stack.push_back(item);

    int tests;
    cin >> tests;
    while (tests--) {
        char op;
        cin >> op;
        switch (op) {
            case 'L':
                if (!left_stack.empty()) {
                    right_stack.push_back(left_stack.back());
                    left_stack.pop_back();
                }
                break;
            case 'D':
                if (!right_stack.empty()) {
                    left_stack.push_back(right_stack.back());
                    right_stack.pop_back();
                }
                break;
            case 'B':
                if (!left_stack.empty())
                    left_stack.pop_back();
                break;
            case 'P':
                char alpha;
                cin >> alpha;
                left_stack.push_back(alpha);
                break;
            default:
                break;
        }
    }
    for (auto item : left_stack)
        cout << item;
    while (!right_stack.empty()) {
        cout << right_stack.back();
        right_stack.pop_back();
    }
}
