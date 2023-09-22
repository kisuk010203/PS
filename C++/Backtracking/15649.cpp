#include <bits/stdc++.h>
using namespace std;
#define MAX 8
int back_seq[MAX];
int n, m;
bool isvalid(int count, int key){
    for(int i=0; i<count; i++){
        if(back_seq[i] == key) return false;
    }
    return true;
}
void backtracking(int count){
    if(count == m){
        for(int i=0; i<m; i++) cout << back_seq[i] << ' ';
        cout << '\n';
    }
    else if(count == 0){
        for(int i=1; i<=n; i++){
            back_seq[0] = i;
            backtracking(1);
        }
    }
    else{
        for(int i=1; i<=n; i++){
            if(isvalid(count, i)){
                back_seq[count] = i;
                backtracking(count+1);
            }
        }
    }

}
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    backtracking(0);
    return 0;
}
