#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> numbers;
vector<pair<int, int>> mex_query;
int ans;
void make_zero(int left, int right) {
    for (int i = left; i <= right; i++) {
        if (numbers[i] > 0) {
            mex_query.push_back({i, i});
        }
    }
}
void make_consecutive(int left, int right) { // already initialized as zero
    if (left == right)
        return;
    make_consecutive(left + 1, right);
    mex_query.push_back({left + 1, right});
    for(int i = left + 1; i <= right - 1; i++)
        mex_query.push_back({i, i});
    make_consecutive(left, right - 1);
}
void print_sequence(int left, int right) {
    make_zero(left, right);
    make_consecutive(left, right);
    mex_query.push_back({left, right});
}

int answer(int left, int right) {
    if (left > right)
        return 0;
    int length = right - left + 1;
    int max_index = left;
    for (int i = left + 1; i <= right; i++) {
        if (numbers[i] > numbers[max_index]) {
            max_index = i;
        }
    }
    int divided_max_value = answer(left, max_index - 1) +
                            answer(max_index + 1, right) + numbers[max_index];
    int undivided_max_value = length * length;
    return max(divided_max_value, undivided_max_value);
}
void solve(int left, int right) {
    if (left > right)
        return;
    int length = right - left + 1;
    int max_index = left;
    for (int i = left + 1; i <= right; i++) {
        if (numbers[i] > numbers[max_index]) {
            max_index = i;
        }
    }
    int divided_max_value = answer(left, max_index - 1) +
                            answer(max_index + 1, right) + numbers[max_index];
    int undivided_max_value = length * length;
    if (divided_max_value >= undivided_max_value) {
        solve(left, max_index - 1);
        solve(max_index + 1, right);
    } else
        print_sequence(left, right);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    int ans = answer(0, n - 1);
    solve(0, n - 1);
    cout << ans << " " << mex_query.size() << "\n";
    for (auto p : mex_query) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}