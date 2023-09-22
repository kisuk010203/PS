#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
bool compare(p a, p b){
    return a.first < b.first;
}
int main(){
    int n; cin >> n;
    int n1, n2;
    vector<p> seq(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &n1, &n2); seq[i] = make_pair(n1, n2);
    }
    sort(seq.begin(), seq.end(), compare);
    vector<int> temp(n);
    vector<int> pos(n);
    
    int vec_size = 1;
    temp[0] = seq[0].second;
    for(int i=1; i<n; i++){
        int start = 0, end = vec_size-1;
        while(start < end){
            int mid = (start+end)/2;
            if(seq[i].second > temp[mid])
                start = mid+1;
            else end = mid;
        }
        pos[i] = start;
        if(start != vec_size - 1) temp[start] = seq[i].second;
        else if(temp[start] >= seq[i].second) temp[start] = seq[i].second;
        else{
            temp[start+1] = seq[i].second; vec_size++;
            pos[i]++;
        }
    }
    printf("%d\n", n-vec_size);
    int cnt = vec_size;
    vector<int> ans(cnt);
    for(int i=n-1; i>=0; i--){
        if(pos[i] == cnt -1){
            ans[cnt-1] = seq[i].first; cnt--;
        }
        if(cnt <= 0) break;
    }
    int start = 0;
    for(int i=0; i<n; i++){
        if(start == vec_size || ans[start] != seq[i].first) printf("%d\n", seq[i].first);
        else start++;
    }
}