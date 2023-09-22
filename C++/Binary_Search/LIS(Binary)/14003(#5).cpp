#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    vector<int> seq(n);
    for(int i=0; i<n; i++) scanf("%d", &seq[i]);
    vector<int> temp(n);
    vector<int> pos(n);
    
    int vec_size = 1;
    temp[0] = seq[0];
    for(int i=1; i<n; i++){
        int start = 0, end = vec_size-1;
        while(start < end){
            int mid = (start+end)/2;
            if(seq[i] > temp[mid])
                start = mid+1;
            else end = mid;
        }
        pos[i] = start;
        if(start != vec_size - 1) temp[start] = seq[i];
        else if(temp[start] >= seq[i]) temp[start] = seq[i];
        else{
            temp[start+1] = seq[i]; vec_size++;
            pos[i]++;
        }
    }
    cout << vec_size << endl;
    int cnt = vec_size;
    vector<int> ans(cnt);
    for(int i=n-1; i>=0; i--){
        if(pos[i] == cnt -1){
            ans[cnt-1] = seq[i]; cnt--;
        }
        if(cnt <= 0) break;
    }
    for(int i=0; i<vec_size; i++) printf("%d ", ans[i]);
}