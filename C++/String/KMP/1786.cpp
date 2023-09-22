#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int pi[MAX];
int ans, n, m;
vector<int> ans_vec;
void initPi(string P){
    pi[0] = 0;
    int j=0;
    for(int i=1; i<m; i++){
        while(j>0 && P[i]!=P[j])
            j = pi[j-1];
        if(P[i] == P[j]) pi[i] = ++j;
        
    }
}
void KMP(string T, string P){
    int start_max = n-m;
    int search_max = m;
    int start = 0, search = 0;
    while(start <= start_max){
        while(search < search_max){
            if(T[start+search] == P[search]){
                search++; continue;
            }
            break;
        }
        if(search == search_max) {
            ans++;
            ans_vec.push_back(start+1);
        }
        if(search == 0){
            start++; continue;
        }
        start = start + search - pi[search-1]; 
        search = pi[search-1];
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    n = T.length(), m = P.length();
    initPi(P);
    KMP(T, P);
    cout << ans << '\n';
    for(auto item : ans_vec) cout << item << ' ';
}