#include <bits/stdc++.h>
using namespace std;
int N;
int white, blue;
#define MAX 128
bool paper[MAX][MAX];
int exp(int n){
    int ret = 1;
    for(int i=0; i<n; i++){
        ret *= 2;
    }
    return ret;
}
void partition(int row, int col, int sz){
    if(sz == 1){
        if(paper[row][col]) blue++;
        else white++;
        return;
    }
    int num = 0;
    for(int i=row; i<row+sz; i++){
        for(int j=col; j<col+sz; j++){
            num += (int)(paper[i][j]);
        }
    }
    if(num == 0){
        white++; return;
    }
    else if(num == sz*sz){
        blue++; return;
    }
    partition(row, col, sz/2);
    partition(row+sz/2, col, sz/2);
    partition(row, col+sz/2, sz/2);
    partition(row+sz/2, col+sz/2, sz/2);
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    white = 0; blue = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> paper[i][j];
    partition(0, 0, N);
    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}
