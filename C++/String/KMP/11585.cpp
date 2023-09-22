#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int pi[MAX];
char T[2*MAX];
char P[MAX];
int n;
void initPi(){
    pi[0] = 0;
    int j=0;
    for(int i=1; i<n; i++){
        while(j>0 && P[i]!=P[j])
            j = pi[j-1];
        if(P[i] == P[j]) pi[i] = ++j;

    }
}
int KMP(){
    int start_max = n-1;
    int search_max = n;
    int ans=0;
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
        }
        if(search == 0){
            start++; continue;
        }
        start = start + search - pi[search-1];
        search = pi[search-1];
    }
    return ans;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    memset(T, false, sizeof(T));
    memset(P, false, sizeof(P));
    cin >> n;
    for(int i=0; i<n; i++){
        char temp; cin >> temp;
        T[i] = temp; T[i+n] = temp;

    }
    for(int i=0; i<n; i++){
        char temp; cin >> temp;
        P[i] = temp;
    }
    initPi();
    int ans = KMP();
    int ans_c = ans, n_c = n;
    while(ans_c != 0){
        int temp = n_c % ans_c;
        n_c = ans_c;
        ans_c = temp;
    }
    int nom = ans/n_c, denom = n/n_c;
    cout << nom << '/' << denom;
}
