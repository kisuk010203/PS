#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
char dungeon[50][50];
int n, m, s;
int main(int argc, char const *argv[])
{
    cin >> n >> m >> s;
    for(int i=0; i<n; i++) cin >> dungeon[i];
    string name; cin >> name;
    unordered_map<char, vector<p>> count_dungeon;
    unordered_map<char, int> count_name;
    for(auto item : name){
        if(count_name.find(item) == count_name.end()){
            count_name[item] = 1;
        }
        else count_name[item]++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char item = dungeon[i][j];
            if(count_dungeon.find(item) == count_dungeon.end()){
                count_dungeon[item] = {make_pair(i,j)};
            }
            else count_dungeon[item].push_back(make_pair(i,j));
        }
    }
    int C=2500, L;
    for(auto item : count_name){
        char target = item.first;
        C = min(C, (count_dungeon[target].size())/count_name[target]);
        
    }
    cout << C;
    return 0;
}
