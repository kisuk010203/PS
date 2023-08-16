#include <bits/stdc++.h>
using namespace std;
#define MAX 360000
int pi[MAX];
bool T[2*MAX];
bool P[MAX];
int m, n;
void initPi(){
    pi[0] = 0;
    int j=0;
    for(int i=1; i<m; i++){
        while(j>0 && P[i]!=P[j])
            j = pi[j-1];
        if(P[i] == P[j]) pi[i] = ++j;
        
    }
}
bool KMP(){
    int start_max = MAX;
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
            return true;
        }
        if(search == 0){
            start++; continue;
        }
        start = start + search - pi[search-1]; 
        search = pi[search-1];
    }
    return false;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    memset(T, false, sizeof(T));
    memset(P, false, sizeof(P));
    cin >> m;
    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        T[temp] = 1; T[temp+MAX] = 1;
    }
    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        P[temp] = 1;
    }
    m = MAX; n = MAX*2;
    initPi();
    bool ans = KMP();
    if(ans) cout << "possible";
    else cout << "impossible";
}