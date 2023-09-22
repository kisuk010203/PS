#include<iostream>
using namespace std;
#define MAX 1020
int n, cntodd;
int adj[MAX][MAX];
int endpos[MAX];
void dfs(int start){
    for(int &end = endpos[start]; end <= n; end++){
        while(adj[start][end]){
            adj[start][end]--;
            adj[end][start]--;
            dfs(end);
        }
    }
    cout << start << ' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            cin >> adj[i][j];
            sum+=adj[i][j];
        }
        if(sum%2) cntodd++;
    }
    if(cntodd)
        cout << -1;
    else{
        for(int i=1; i<=n; i++) endpos[i]=1;
        dfs(1);
    }
}
