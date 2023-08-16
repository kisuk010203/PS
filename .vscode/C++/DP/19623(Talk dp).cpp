#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int,int> talk;
bool compare(talk a, talk b){
    return get<1>(a) < get<1>(b);
}
int max(int a, int b){ return (a>b) ? a : b; }
int main(){
    int num; cin >> num;
    vector <talk> talk_vec;
    vector <int> compat(num);
    vector <int> dp(num);
    for(int i=0; i<num; i++){
        int a, b, c; cin >> a >> b >> c;
        talk_vec.push_back(make_tuple(a,b,c));
    }
    sort(talk_vec.begin(), talk_vec.end(), compare);
    compat[0] = -1;
    for(int i=1; i<num; i++){
        compat[i] = -1;
        int start = 0, end = num-1;
        int mid;
        while(start+1 < end){
            mid = (start+end)/2;
            if(get<0>(talk_vec[i]) >= get<1>(talk_vec[mid]))
                start = mid;
            else
                end = mid-1;
        }
        if(get<0>(talk_vec[i]) >= get<1>(talk_vec[end])) compat[i] = end;
        else if(get<0>(talk_vec[i]) >= get<1>(talk_vec[start]))compat[i] = start;
        else compat[i] = -1;
    }
    dp[0] = get<2>(talk_vec[0]);
    for(int i=1; i<num; i++){
        if(compat[i] == -1) dp[i] = max(dp[i-1], get<2>(talk_vec[i]));
        else dp[i] = max(dp[i-1], dp[compat[i]] + get<2>(talk_vec[i]));
    }
    cout << dp[num-1];

}