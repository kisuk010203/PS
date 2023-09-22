#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct talk_compare{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
        if(a.first < b.first) return 1;
        else if (a.first == b.second) return (a.second < b.second);
        return 0;
    }
};
int main(){
    int num; cin >> num;
    vector<pair<int, int>> talk(num);
    priority_queue<int, vector<int>, greater<int>> room;
    for(int i=0; i<num; i++) cin >> talk[i].first >> talk[i].second;
    sort(talk.begin(), talk.end(), talk_compare());
    room.push(talk[0].second);
    for(int i=1; i<num; i++){
        if(room.top() <= talk[i].first) room.pop();
        room.push(talk[i].second);
    }
    cout << room.size() <<endl;
}
