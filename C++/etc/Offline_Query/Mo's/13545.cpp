#include <bits/stdc++.h>
using namespace std;

const int block_size = 400;
const int bucket_size = 550;

struct Query{
	int l, r, idx;
	bool operator < (const Query &other) const {
		if(l / block_size != other.l / block_size) return l < other.l;
		return r < other.r;
	}
};

int n, q;
vector<Query> queries;
vector<int> v(100100);
vector<int> ans(100100);
vector<int> freq(200200);
vector<int> sqrt_freq(bucket_size);
vector<list<int>> deq_vec(200200);

void increment(int x, int dir){
	auto &dq = deq_vec[v[x]];
	if(!dq.empty()){
		int len = dq.back() - dq.front();
		freq[len]--;
		sqrt_freq[len / block_size]--;
	}
	if(!dir) dq.push_front(x);
	else dq.push_back(x);
	int len = dq.back() - dq.front();
	freq[len]++; 
	sqrt_freq[len / block_size]++;
}

void decrement(int x, int dir){
	auto &dq = deq_vec[v[x]];
	int len = dq.back() - dq.front();
	freq[len]--; sqrt_freq[len / block_size]--;
	if(!dir) dq.pop_front();
	else dq.pop_back();
	if(!dq.empty()){
		len = dq.back() - dq.front();
		freq[len]++; sqrt_freq[len / block_size]++;
	}
}

int query(){
	for(int i = bucket_size - 1; i >= 0; i--){
		if(sqrt_freq[i] == 0) continue;
		for(int j = block_size - 1; j >= 0; j--){
			if(freq[i * block_size + j] > 0){
				return i * block_size + j;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v[0] = n;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i-1];
	} 
	cin >> q;
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		queries.push_back({l - 1, r, i});
	}
	sort(queries.begin(), queries.end());

	auto [l, r, idx] = queries[0];
	for(int i = l; i <= r; i++){
		increment(i, 1);
	}
	ans[idx] = query();

	for(int i = 1; i < q; i++){
		auto [cur_l, cur_r, idx] = queries[i];
		while(cur_l < l) increment(--l, 0);
		while(r < cur_r) increment(++r, 1);
		while(l < cur_l) decrement(l++, 0);
		while(cur_r < r) decrement(r--, 1);
		ans[idx] = query();
	}

	for(int i = 0; i < q; i++) cout << ans[i] << "\n";
}
