#include <bits/stdc++.h>
using namespace std;
int MAX_RES = INT_MIN;
int process(int num1, int num2, char operand) {
    switch(operand) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
    return 0;
}
bool check_ones(int bitmask) {
    for (int i = 0; i < 31; i++) {
        int mask1_res = bitmask & (1 << i);
        int mask2_res = bitmask & (1 << i + 1);
        if (mask1_res && mask2_res)
            return false;
    }
    return true;
}
void process_bitmask(int bitmask, vector<int> &nums, vector<int> &operands) {
    int res = nums[0];
    for (int i = 0; i < operands.size(); i++) {
        if (bitmask && (1 << i)) {
            
        } else {
            res = process(res, nums[i + 1], operands[i]);
        }
    }
}
int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> nums;
    vector<char> operands;
    for (int i = 0; i < n; i++) {
        char item = s[i];
        if (i % 2 == 0) nums.push_back(item - '0');
        else operands.push_back(item);
    }
    for (int bitmask = 0; bitmask < (1 << operands.size()); bitmask++) {
        if (!check_ones(bitmask)) continue;

    }

}