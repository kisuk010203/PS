#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> groups;
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        vector<int> group(k);
        for(int j = 0; j < k; j++) {
            cin >> group[j];
            group[j]--;
        }
        groups.push_back(group);
    }
    vector<int> final_state(n);
    vector<int> first_state(n);
    for(int i = 0; i < n; i++) {
        cin >> final_state[i];
        first_state[i] = final_state[i];
    }

    for(int i = m - 1; i >= 0; i--) {
        bool is_zero_group = false;
        for(int item : groups[i]) 
            if(first_state[item] == 0){ is_zero_group = true; break; }
        if(is_zero_group) {
            for(int item : groups[i]) {
                first_state[item] = 0;
            }
        }
    }


    vector<int> curr_state(n);
    for(int i = 0; i < n; i++) {
        curr_state[i] = first_state[i];
    }
    for(int i = 0; i < m; i++) {
        bool is_zero_group = true;
        for(int item : groups[i]) {
            if(curr_state[item]) is_zero_group = false;
        }
        if(!is_zero_group) {
            for(int item : groups[i]) {
                curr_state[item] = 1;
            }
        }
    }

    bool is_possible = true;
    for(int i = 0; i < n; i++) {
        if(curr_state[i] != final_state[i]) {
            is_possible = false;
            break;
        }
    }
    
    if(is_possible) {
        cout << "YES\n";
        for(int item : first_state) cout << item << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }

}