#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (ll)(1e9 + 7)
int main(int argc, char const *argv[])
{
    ll N,K; cin >> N >> K;
    ll quo = 0;
    ll temp = N;
    while (temp--){
        string op1, op2; cin >> op1 >> op2;
        ll num1  = 0, num2 = 0;
        for(int i=1; i<op1.length(); i++){
            num1 = num1*10 + op1[i] - '0';
        }
        for(int i=1; i<op2.length(); i++){
            num2 = num2*10 + op2[i] - '0';
        }
        if(op1[0] == op2[0]){
            if(op1[0] == '+'){
                ll sel = max(num1, num2);
                if(quo < N+1){
                    quo += (K+sel)/MOD;
                }
                K = (K+sel)%MOD;

            }
            else if(op1[0] == '-'){
                ll sel = min(num1, num2);
                if(K < sel && quo == 0){
                    K=0;
                }
                else if(K<sel){
                    quo--;
                    K = (K+MOD-sel);
                }
                else{
                    K -= sel;
                }
            }
            else{
                ll sel = max(num1, num2);
                if(sel == 0){
                    K = 0; quo = 0;
                }
                else{
                    if(quo < N+1){
                        quo *= sel;
                        quo += (K*sel)/MOD;
                    }
                    K = (K*sel) % MOD;
                }
            }
        }
        else if(op1[0] == '+' && op2[0] == '-'){
            if(quo < N+1){
                quo += (K+num1)/MOD;
            }
            K = (K + num1) % MOD;

        }
        else if(op1[0] == '-' && op2[0] == '+'){
            if(quo < N+1){
                quo += (K+num2)/MOD;
            }
            K = (K + num2) % MOD;

        }
        else if(op1[0] == '-' && op2[0] == '*'){
            if(num2 == 0){
                if(quo == 0 && K < num1){
                    quo = 0; K = 0;
                }
                else if(K>=num1){
                    K -= num1;
                }
                else{
                    quo--; K = K + MOD - num1;
                }
            }
            else{
                if(quo < N+1){
                    quo *= num2;
                    quo += (K*num2)/MOD;
                }
                K = (K*num2) % MOD;
            }
        }
        else if(op1[0] == '*' && op2[0] == '-'){
            if(num1 == 0){
                if(quo == 0 && K < num2){
                    quo = 0; K = 0;
                }
                else if(K>=num2){
                    K -= num2;
                }
                else{
                    quo--; K = K + MOD - num2;
                }
            }
            else{
                if(quo < N+1){
                    quo *= num1;
                    quo += (K*num1)/MOD;
                }
                K = (K*num1) % MOD;
            }
        }
        else if(op1[0] == '+' && op2[0] == '*'){
            if(num2 == 0 || num2 == 1){
                if(quo < N+1){
                    quo += (K+num1)/MOD;
                }
                K = (K + num1) % MOD;
            }
            else if(quo > 0 || K*(num2-1) > num1){
                if(quo < N+1){
                    quo *= num2;
                    quo += (K*num2)/MOD;
                }
                K = (K*num2) % MOD;
            }
            else{
                if(quo < N+1){
                    quo += (K+num1)/MOD;
                }
                K = (K + num1) % MOD;
            }
        }
        else{
            if(num1 == 0 || num1 == 1){
                if(quo < N+1){
                    quo += (K+num2)/MOD;
                }
                K = (K + num2) % MOD;

            }
            else if(quo > 0 || K*(num1-1) > num2){
                if(quo < N+1){
                    quo *= num1;
                    quo += (K*num1)/MOD;
                }
                K = (K*num1) % MOD;
            }
            else{
                if(quo < N+1){
                    quo += (K+num2)/MOD;
                }
                K = (K + num2) % MOD;

            }
        }
    }
    cout  << K;
    return 0;
}
