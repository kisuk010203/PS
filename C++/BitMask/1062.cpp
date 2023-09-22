#include <bits/stdc++.h>
using namespace std;
int n, k;
int curr;
int word_bits[50];

int backtracking(int start, int cnt){
    int temp = 0;
    if(cnt == k){
        for(int i=0; i<n; i++){
            if((word_bits[i]&curr) == word_bits[i]) temp++;
        }
        return temp;
    }
    for(int i=start; i<26; i++){
        if((curr & (1<<i)) == 0){
            curr |= (1<<i);
            temp = max(temp, backtracking(i+1, cnt+1));
            curr &= ~(1<<i);
        }
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        for(char c : word){
            word_bits[i] |= (1<<(c - 'a'));
        }
    }
    if(k<5){
        cout << 0;
        return 0;
    }
    char necc[5] = {'a', 'c', 'i', 'n', 't'};
    for(auto i : necc){
        curr |= (1<<(i-'a'));
    }
    cout << backtracking(0, 5) << endl;
}
