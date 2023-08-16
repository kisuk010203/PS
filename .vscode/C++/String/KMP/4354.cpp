#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int pi[MAX];
int ans, m;
void initPi(string P){
    pi[0] = 0;
    int j=0;
    for(int i=1; i<m; i++){
        while(j>0 && P[i]!=P[j])
            j = pi[j-1];
        if(P[i] == P[j]) pi[i] = ++j;
        
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    while(true){
        memset(pi, 0, sizeof(pi));
        string P; getline(cin, P);
        if(P == ".") break;
        m = P.length();
        initPi(P); int quo = m-pi[m-1];
        if(m%quo) cout << 1 << "\n";
        else cout << m/quo << '\n';
    }
}