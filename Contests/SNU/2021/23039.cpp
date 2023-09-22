#include <bits/stdc++.h>
using namespace std;
int N;
typedef pair<int, int> p;
vector<p> adj;
bool is_in(int a, int b){
    a = a%5; b = b%5;
    p test = make_pair(a, b);
    p test2 = make_pair(b, a);
    for(auto item : adj){
        if(item == test || item == test2) return true;
    }
    return false;
}
int get_ans(){
    if(N == 10) return -1;
    int cnt = 0;
    for(int i=0; i<5; i++){
        if(is_in(i, i+2) && is_in(i+1, i+3)) cnt++;
    }
    if(cnt == 0) return 0;
    if(cnt < 5) return 1;
    return 2;
}
int main(int argc, char const *argv[]){
    cin >> N;
    for(int i=0; i<N; i++){
        int a, b; cin >> a >> b;
        adj.push_back(make_pair(a-1, b-1));
    }
    cout << get_ans();
    return 0;
}
