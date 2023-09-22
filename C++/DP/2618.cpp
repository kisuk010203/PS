#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 20000008
int n, w; 
int arr[MAX][MAX][2]; // i case (j case, i case) first car moved : k
int problem[MAX][2][2];
int carSeq[MAX];
void setcar(int i, int j, int ans, int mode){
    if(i==1) return;
    if(j != i-1){
        carSeq[i-1] = carSeq[i];
        setcar(i-1, j, arr[i-1][j][mode], mode);
    }
    else{
        for(int k=0; k<j; k++){
            int temp = arr[j][k][mode] + abs(problem[i][0][mode] - problem[k][0][mode])
            + abs(problem[i][1][mode] - problem[k][1][mode]);
            if(temp == arr[i][j][mode]){
                carSeq[i-1] = 3-carSeq[i];
                setcar(j, k, arr[j][k][mode], mode);
                return;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    for(int i=1; i<w+1; i++){
        int r, c; cin >> problem[i][0][0] >> problem[i][1][0];
        problem[i][1][1] = problem[i][1][0];
        problem[i][0][1] = problem[i][0][0];
    }
    problem[0][0][0] = n; problem[0][1][0] = n;
    problem[0][0][1] = 1; problem[0][1][1] = 1;
    arr[1][0][0] = abs(problem[1][0][0]-1) + abs(problem[1][1][0]-1);
    arr[1][0][1] = abs(problem[1][0][1]-n) + abs(problem[1][1][1]-n);
    for(int i=2; i<w+1; i++){
        for(int j=0; j<i; j++){
            if(j!=i-1){
                arr[i][j][0] = arr[i-1][j][0] 
                + abs(problem[i-1][0][0]-problem[i][0][0]) + abs(problem[i-1][1][0]-problem[i][1][0]);
                arr[i][j][1] = arr[i-1][j][1] 
                + abs(problem[i-1][0][1]-problem[i][0][1]) + abs(problem[i-1][1][1]-problem[i][1][1]);
            }
            else{
                arr[i][j][0] = INF;
                arr[i][j][1] = INF;
                int temp, tempa;
                for(int k=0; k<j; k++){
                    temp = arr[j][k][0] + abs(problem[i][0][0] - problem[k][0][0])
                    + abs(problem[i][1][0] - problem[k][1][0]);
                    tempa = arr[j][k][1] + abs(problem[i][0][1] - problem[k][0][1])
                    + abs(problem[i][1][1] - problem[k][1][1]);
                    arr[i][j][0] = min(arr[i][j][0], temp);
                    arr[i][j][1] = min(arr[i][j][1], tempa);
                }
            }
        }
    }
    int ans = INF;
    for(int k=0; k<w; k++){
        ans = min(ans, arr[w][k][0]);
        ans = min(ans, arr[w][k][1]);
    }
    cout << ans << '\n';
    carSeq[w] = 2;
    int startCar = -1, res = -1;
    for(int k=0; k<w; k++){
        int fl = -1;
        for(int sk=0; sk<2; sk++)
            if(ans == arr[w][k][sk]){
                startCar = sk+1;
                res = k;
                fl = 0;
                break;
            }
        if(fl == 0) break;
    }
    setcar(w, res, ans, startCar-1);
    if(startCar == carSeq[1])
        for(int i=1; i<=w; i++)
            cout << carSeq[i] << '\n';
    else
        for(int i=1; i<=w; i++)
            cout << 3- carSeq[i] << '\n';
        
}