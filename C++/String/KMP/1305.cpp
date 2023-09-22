#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
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
    cin >> m;
    string P; cin >> P;
    initPi(P);
    cout << m-pi[m-1] << '\n';
}
