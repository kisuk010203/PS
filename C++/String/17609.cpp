#include <bits/stdc++.h>
using namespace std;
int check_pseudo(string s, int left, int right, int pnum){
    if(pnum == 2) return 2;
    if(right-left <=1) return pnum;
    if(s[left] == s[right]) return check_pseudo(s, left+1, right-1, pnum);
    else{
        int left_ex = check_pseudo(s, left+1, right, pnum+1);
        int right_ex = check_pseudo(s, left, right-1, pnum+1);
        return min(left_ex, right_ex);
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int left = 0, right = s.length()-1, pnum=0;
        while(right-left>0){
            if(s[left] == s[right]){
                left++, right--; continue;
            }
            break;
        }
        if(right-left <=0) cout << 0 << '\n';
        else{
            int cleft = left+1, cright = right, cpnum=1;
            while (cright-cleft>0){
                if(s[cleft] == s[cright]){
                    cleft++, cright--; continue;
                }
                break;
            }
            if(cright-cleft<=0) cout << 1 << '\n';
            else{
                int dleft = left, dright = right-1;
                while(dright-dleft>0){
                    if(s[dleft] == s[dright]){
                        dleft++, dright--; continue;
                    }
                    break;
                }
                if(dright-dleft<=0) cout << 1 << '\n';
                else cout << 2 << '\n';
            }
            
        }
    }
}