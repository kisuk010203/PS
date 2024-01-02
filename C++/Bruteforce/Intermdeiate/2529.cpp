#include <bits/stdc++.h>
using namespace std;
int k;
vector<bool> comp;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int k; cin >> k;
    vector<bool> comp;
    for(int i=0; i<k; i++){
        char temp;
        cin >> temp;
        comp.push_back((temp == '<') ? 0 : 1);
    }

}
