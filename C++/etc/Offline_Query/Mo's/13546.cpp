#include <bits/stdc++.h>
using namespace std;
int block_size;
typedef struct Query {
    int l, r, idx;
    bool operator<(Query other) {
        if (l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return r < other.r;
    }
} Query;

vector<int> v;
vector<Query> queries;
vector<int> ans;
vector<int> freq; // freq[i] = number of distance i in current range
vector<int> sqrt_freq; // sqrt decomposition for freq
vector<list<int>> deq_vec;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;    
    block_size = sqrt(n);
    int block_size = sqrt(k + 1);
    v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    int Q; cin >> Q;
    
    queries.resize(Q);
    ans.resize(Q);
    freq.resize(n + 1 + block_size * 10, 0);
    sqrt_freq.resize((n + 1) / block_size + 1, 0);
    deq_vec.resize(k + 1);

    for(int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        queries[i] = {l, r, i};
    }
    sort(queries.begin(), queries.end());
    

    int cur_l = 0, cur_r = -1;
    for(auto query : queries) {
        int l = query.l;
        int r = query.r;
        int idx = query.idx;
        while(cur_r > r) { // need to delete
            
            int item = v[cur_r];
            if(!deq_vec[item].empty()) {
                int original_item_len = deq_vec[item].back() - deq_vec[item].front();
                freq[original_item_len]--;
                sqrt_freq[original_item_len / block_size]--;
                deq_vec[item].pop_back();
                if(!deq_vec[item].empty()) {
                    int new_item_len = deq_vec[item].back() - deq_vec[item].front();
                    freq[new_item_len]++;
                    sqrt_freq[new_item_len / block_size]++;
                }
                
                
                
            }
            
            cur_r--;
        }
        while(cur_r < r) { // need to add
            cur_r++;
            int item = v[cur_r];

            if(!deq_vec[item].empty()) {
                int original_item_len = deq_vec[item].back() - deq_vec[item].front();
                freq[original_item_len]--;
                sqrt_freq[original_item_len / block_size]--;
            }

            assert(deq_vec[item].empty()  || deq_vec[item].back() < cur_r);
            deq_vec[item].push_back(cur_r);
            int new_item_len = deq_vec[item].back() - deq_vec[item].front();
            
            freq[new_item_len]++;
            sqrt_freq[new_item_len / block_size]++;
        }

        while (cur_l < l) { // need to delete
            int item = v[cur_l];
            if(!deq_vec[item].empty()) {
                int original_item_len = deq_vec[item].back() - deq_vec[item].front();
                deq_vec[item].pop_front();
                freq[original_item_len]--;
                sqrt_freq[original_item_len / block_size]--;
                if(!deq_vec[item].empty()) {
                    int new_item_len = deq_vec[item].back() - deq_vec[item].front();
                    freq[new_item_len]++;
                    sqrt_freq[new_item_len / block_size]++;
                }
                
            }

            cur_l++;
        }
        while (cur_l > l) {// need to add
            cur_l--;
            int item = v[cur_l];
            if(!deq_vec[item].empty()) {
                int original_item_len = deq_vec[item].back() - deq_vec[item].front();
                freq[original_item_len]--;
            sqrt_freq[original_item_len / block_size]--;
            }
            assert(deq_vec[item].empty()  || deq_vec[item].front() > cur_l);
            deq_vec[item].push_front(cur_l);
            int new_item_len = deq_vec[item].back() - deq_vec[item].front();
            freq[new_item_len]++;
            sqrt_freq[new_item_len / block_size]++;
        }


        int ans_val = 0;
        bool flag  = false;
        for (int i = sqrt_freq.size() - 1; i >= 0; i--) {
            if (flag) break;
            if (sqrt_freq[i] > 0) {
                for (int j = (i + 1) * block_size - 1; j >= i * block_size; j--) {
                    if (freq[j] > 0) {
                        ans_val = j;
                        flag = true;
                        break;
                    }
                }
            }
        }
        ans[idx] = ans_val;
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }

}