#include <bits/stdc++.h>
using namespace std;
#define MAX 501
int N, TREE_CNT;
bool searched[MAX];
vector<int> adj[MAX];
bool dfs(int start, int succ){
    bool flag = true;
    searched[start] = 1;
    for(auto child : adj[start])
        if(!searched[child])
            flag &= dfs(child, start);
        else if(searched[child] && succ != child)
            flag = false;
    return flag;
}
void clear_adj(){
    for(int i=0; i<MAX; i++)
        adj[i].clear();
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int test_Cnt = 0;
    while(true){
        int N, M; cin >> N >> M;
        test_Cnt++;
        if(N==0 && M== 0) return 0;
        clear_adj();
        memset(searched, 0, sizeof(searched));
        TREE_CNT = 0;
        for(int i=0; i<M; i++){
            int a, b; cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        for(int i=0; i<N; i++){
            if(!searched[i]){
                if (dfs(i, i)) 
                    TREE_CNT++;
            }
        }
            if(TREE_CNT == 0)
                cout << "Case " << test_Cnt << ": No trees.\n";
            else if(TREE_CNT == 1){
                cout << "Case " << test_Cnt << ": There is one tree.\n";
            }
            else{
                cout << "Case " << test_Cnt << ": A forest of " << TREE_CNT << " trees.\n";
            }
        
    }
}
