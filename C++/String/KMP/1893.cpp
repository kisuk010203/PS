#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define P_MAX 50000
int pi[P_MAX];
int n, m;
void initPi(const string& P){
    pi[0] = 0;
    int j=0;
    for(int i=1; i<m; i++){
        while(j>0 && P[i]!=P[j])
            j = pi[j-1];
        if(P[i] == P[j]) pi[i] = ++j;

    }
}
bool KMP(const string& order, unordered_map<char, int> ordermap, const string& T, const string& P){
    int ans = 0;
    int start_max = n-m;
    int search_max = m;
    int start = 0, search = 0;
    while(start <= start_max){
        if(ans>1) return false;
        while(search < search_max){
            if(T[start+search] == P[search]){
                search++; continue;
            }
            break;
        }
        if(search == search_max) {
            ans++;
        }
        if(search == 0){
            start++; continue;
        }
        start = start + search - pi[search-1];
        search = pi[search-1];
    }
    return ans==1;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        string order; cin >> order; int order_size = order.size();
        unordered_map<char, int> ordermap;
        for(int i=0; i<order.length(); i++){
            ordermap.emplace(order[i], i);
        }
        string T, P; cin >> P >> T;
        n = T.length(), m = P.length();
        memset(pi, 0, sizeof(pi));
        initPi(P);
        vector<int> ans_vec;
        for(int i=0; i<order_size; i++){
            if(KMP(order, ordermap, T, P)) ans_vec.push_back(i);
            for(int j=0; j<m; j++){
                int idx = ordermap.at(P[j]);
                if(idx == order_size-1) P[j] = order[0];
                else P[j] = order[idx+1];
            }
        }
        if(ans_vec.size() == 0) cout << "no solution\n";
        else if(ans_vec.size() == 1)
            cout << "unique: " << ans_vec[0] << '\n';
        else{
            cout << "ambiguous:";
            for(auto item : ans_vec) cout << ' ' << item;
            cout << '\n';
        }

    }
}
