#include <bits/stdc++.h>
using namespace std;
int N, M;
char board[1200][1200];
bool is_conn(int i, int j, int mode){
    switch (mode){
    case 0: //up
        if(i == 0) return false;
        return (board[3*i-1][3*j+1] == '#');
    case 1: //down
        if(i == N-1) return false;
        return (board[3*i+3][3*j+1] == '#');
    case 2: //left
        if(j==0) return false;
        return (board[3*i+1][3*j-1] == '#');
    case 3: //right
        if(j == M-1) return false;
        return (board[3*i+1][3*j+3] == '#');
    }
    return false;
}
int main(int argc, char const *argv[]){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<3*N; i++){
        cin >> board[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if((i+j)%2 == 0) continue;
            bool flag = false;
            for(int mode=0; mode<4; mode++){
                flag = flag || is_conn(i, j, mode);
            }
            if(flag) board[3*i+1][3*j+1] = '#';
            if(is_conn(i, j, 0)) 
                board[3*i][3*j+1] = '#';
            if(is_conn(i, j, 1))
                board[3*i+2][3*j+1] = '#';
            if(is_conn(i, j, 2))
                board[3*i+1][3*j] = '#';
            if(is_conn(i, j, 3))
                board[3*i+1][3*j+2] = '#';
        }
    }
    for(int i=0; i<3*N; i++){
        for(int j=0; j<3*M; j++) cout << board[i][j];
        cout << '\n';
    }
    return 0;
}
