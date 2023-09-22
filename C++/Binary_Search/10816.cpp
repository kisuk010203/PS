#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    unordered_map<int, int> hashmap;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        if(hashmap.find(temp) == hashmap.end())
            hashmap[temp] = 1;
        else hashmap[temp]++;
    }
    int m; cin >> m;
    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        if(hashmap.find(temp) == hashmap.end())
            cout << "0 ";
        else cout << hashmap[temp] << ' ';
    }


    return 0;
}
