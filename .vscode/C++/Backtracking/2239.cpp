#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
int seq[81];
bool done;
int remain(){
    for(int i=0; i<9; i++) for(int j=0; j<9; j++) if(arr[i][j] == 0) return 10*i+j+1;
    return 0;
}
int isPossible(int x, int y, int val){
    for(int i=0; i<9; i++) if(i!=x && arr[i][y] == val) return 0;
    for(int i=0; i<9; i++) if(i!=y && arr[x][i] == val) return 0;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++){
        if((i!= x%3 || j!= y%3) && arr[3*(x/3) + i][3*(y/3) + j] == val) return 0;
    }
    return 1;
}
void backtracking(){
    if(done) return;
    int temp = remain();
    if(temp == 0){
        for(int i=0; i<9; i++){
            for(int j=0; j<9;j++) printf("%d", arr[i][j]);
            printf("\n");
        }
        done = true;
    }
    int x = temp/10, y = temp%10 - 1;
    for(int i=1; i<10; i++){
        if(isPossible(x, y, i)){
            arr[x][y] = i;
            backtracking();
        } 
        arr[x][y] = 0;
    }
}
int main(){
    done = false;
    for(int i=0; i<9; i++){
        char temp[30];
        scanf("%s", temp);
        for(int j=0; j<9; j++) arr[i][j] = temp[j] - '0';
    }
    backtracking();
}