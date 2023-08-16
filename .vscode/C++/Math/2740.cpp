#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 101
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M, K; cin >> N >> M;
    ll arr[MAX][MAX];
    ll brr[MAX][MAX];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    cin  >> M >> K;
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            cin >> brr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            ll temp = 0;
            for(int k=0; k<M; k++)
                temp += arr[i][k]*brr[k][j];
            cout << temp << ' ';
        } cout << '\n';
    }

    return 0;
}
