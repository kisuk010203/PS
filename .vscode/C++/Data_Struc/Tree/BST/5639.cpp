#include <bits/stdc++.h>
using namespace std;
int nodes[10000];
void to_postorder(int start, int end){
    if(start == end){ 
        cout << nodes[start] << '\n';
        return;
    }
    else{
        int idx = lower_bound(nodes+start+1, nodes+end+1, nodes[start])-nodes;
        if(idx==end+1 || idx == start+1){
            to_postorder(start+1, end);
            cout << nodes[start] << '\n';
        }
        else {
            to_postorder(start+1, idx-1);
            to_postorder(idx, end);
            cout << nodes[start] << '\n';
        }
    }
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int node, cnt=0;
    int t;
    while(cin>>t){
        nodes[cnt++] = t;
    }
    to_postorder(0, cnt-1);
    return 0;
}
