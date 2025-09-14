#include <bits/stdc++.h>
using namespace std;
int num_operands;
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
void backtracking(vector<int> &nums, vector<char> &operands) {
    assert(nums.size() == operands.size() + 1);
    if (operands.size() == 0) {
        MAX_RES = max(MAX_RES, nums[0]);
        return;
    }
    for (int i = 0; i < operands.size(); i++) {
        vector<int> new_nums;
        vector<char> new_operands;
        for (int j = 0; j < nums.size(); j++) {
            if (j != i && j != (i + 1)) {
                new_nums.push_back(nums[j]);
            } else if (j == i) {
                new_nums.push_back(process(nums[i], nums[i + 1], operands[i]));
            }
        }
        for (int j = 0; j < operands.size(); j++) 
            if (j != i) 
                new_operands.push_back(operands[j]);
        backtracking(new_nums, new_operands);
    }

}
int main() {
    int n; cin >> n;
    num_operands = n >> 1;    
    string s; cin >> s;
    vector<int> nums;
    vector<char> operands;
    for (int i = 0; i < n; i++) {
        char item = s[i];
        if (i % 2 == 0) nums.push_back(item - '0');
        else operands.push_back(item);
    }
    backtracking(nums, operands);
    cout << MAX_RES << "\n";
}