#include <bits/stdc++.h>
using namespace std;
int n;
int max_res, min_res;
int arr[11];
int oper[4]; //+-x/
int back_seq[10];
bool isvalid(int count, int key){
    int temp=0;
    for(int i=0; i<count; i++){
        if(back_seq[i] == key) temp++;
    }
    return (temp<oper[key]);
}
void backtracking(int count){
    if(count == n-1){
        int res = arr[0];
        for(int i=0; i<n-1; i++){
            int temp = arr[i+1], op = back_seq[i];
            switch(op){
                case 0 : 
                    res += temp; break;
                case 1 :
                    res -= temp; break;
                case 2 :
                    res *= temp; break;
                case 3 :
                    res /= temp; break;
            }
        }
        max_res = max(res, max_res);
        min_res = min(res, min_res);
    }
    else{
        for(int i=0; i<4; i++){
            if(isvalid(count, i)){
                back_seq[count] = i;
                backtracking(count+1);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> oper[i];
    }
    min_res = 1e9, max_res = -1e9;
    backtracking(0);
    cout << max_res << '\n' << min_res;
}