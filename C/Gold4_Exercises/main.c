//9663 N-Queen
/*
#include <stdio.h>
#define MAX 15
int queen[MAX];
int cnt;
int n;
int possible(int r, int c){
    for(int i=0; i<r; i++)
        if(queen[i] == c || queen[i]-c == i-r || queen[i]-c == r-i) return 0;
    return 1;
}
void dfs(int r){
    if(r == n){
        cnt++;
        return;
    }
    for(int c=0; c<n; c++){
        queen[r] = c;
        if(possible(r,c)) dfs(r+1);
    }
}
int main(){
    scanf("%d", &n);
    dfs(0);
    printf("%d", cnt);
}*/

//11054
/*
#include <stdio.h>
#define MAX 1010
#define max(a,b) a>b?a:b
int idp[MAX];
int ddp[MAX];
int seq[MAX];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf(" %d", seq+i);
    ddp[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        ddp[i] = 1;
        for(int j=i+1; j<n; j++)
            if(seq[j] < seq[i]) ddp[i] = max(ddp[i], 1+ddp[j]);
    }
    idp[0] = 1;
    for(int i=1; i<n; i++){
        idp[i] = 1;
        for(int j=0; j<i; j++)
            if(seq[j] < seq[i]) idp[i] = max(idp[i], 1+idp[j]);
    }
    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, idp[i]+ddp[i]-1);
    printf("%d", ans);
}*/

//1987
/*
#include <stdio.h>
#define MAX 20
char board[MAX][MAX];
char path[500];
int foundalpha[26];
int r, c, maxlen;
int isPossible(int idx, int x, int y){
    int temp = x>=0 && x<r && y>=0 && y<c;
    if(temp == 0) return 0;
    return 1 - foundalpha[board[x][y] - 'A'];
}
void backtracking(int idx, int x, int y){
    if(idx == r*c){
        maxlen = r*c;
        return;
    }
    path[idx] = board[x][y];
    foundalpha[board[x][y] - 'A'] = 1;
    int flag = 0;
    for(int i=-1; i<2; i++){
         if(isPossible(idx, x+i, y)){
             backtracking(idx+1, x+i, y); flag = 1;
             foundalpha[board[x+i][y] - 'A'] = 0;
         }
    }
    for(int i=-1; i<2; i++){
         if(isPossible(idx, x, y+i)){
             backtracking(idx+1, x, y+i); flag = 1;
             foundalpha[board[x][y+i] - 'A'] = 0;
         }
    }
    if(flag == 0){
        maxlen = (maxlen>(idx+1)) ? maxlen : idx+1;
        return;
    }
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++) scanf("%s", board[i]);
    backtracking(0, 0, 0);
    printf("%d", maxlen);
}
*/

//1753
/*
#include <stdio.h>
#define vMAX 20010
#define eMAX 300020
#define INF 1e9
int v, e, start;
typedef struct edge{
    int start, end, weight;
    int prev;
}edge;
typedef struct heapnode{
    int dist, end;
}heapnode;
edge edges[eMAX];
heapnode heap[eMAX];
int to[vMAX];
int distance[vMAX];
int heapCnt;
void push(heapnode data){
    int idx = ++heapCnt;
    while (idx!=1 && heap[idx/2].dist >= data.dist){
        heap[idx] = heap[idx/2];
        idx /= 2;
    }
    heap[idx].dist = data.dist; heap[idx].end = data.end;
}
heapnode pop(){
    heapnode ret = heap[1];
    heapnode temp = heap[heapCnt--];
    int idx = 2;
    while(idx<=heapCnt){
		if(idx < heapCnt && heap[idx].dist > heap[idx+1].dist) idx++;
		if(temp.dist <= heap[idx].dist) break;
		heap[idx/2] = heap[idx];
		idx*=2;
	}
	heap[idx/2] = temp;
    return ret;
}
void dijkstra(int start){
    for(int i=1; i<=v; i++) distance[i] = INF;
    distance[start] = 0;
    heapnode temp = {0, start};
    push(temp);
    while(heapCnt > 0){
        heapnode curr = pop();
        int x = curr.end;
        if(curr.dist > distance[x]) continue;
        for(int i = to[curr.end]; i; i = edges[i].prev){
            int y = edges[i].end, w = edges[i].weight;
            if(distance[y] > distance[x] + w){
                distance[y] = distance[x] + w;
                heapnode tempa = {distance[y], y};
                push(tempa);
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &v, &e, &start);
    for(int i=1; i<=e; i++){
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);
        edges[i].prev = to[edges[i].start];
        to[edges[i].start] = i;
    }
    dijkstra(start);
    for(int i=1; i<=v; i++){
        if(distance[i] == INF) printf("INF\n");
        else printf("%d\n", distance[i]);
    }
}*/


//2580
/*
#include <stdio.h>
int arr[9][9];
int seq[81];
int end;
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
    if(end) return;
    int temp = remain();
    if(temp == 0){
        for(int i=0; i<9; i++){
            for(int j=0; j<9;j++) printf("%d ", arr[i][j]);
            printf("\n");
        }
        end = 1;
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
    for(int i=0; i<9; i++){
        char temp[30];
       gets(temp);
        for(int j=0; j<9; j++) arr[i][j] = temp[2*j] - '0';
    }
    backtracking();
}*/

//14500
#include <stdio.h>
int n, m;
int res;
int max(int a, int b){ return (a>b)?a:b;}
int arr[500][500];
void tetromino(int mode){
    if(mode == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<m-3; j++){
                int ans = 0;
                for(int k=0; k<4; k++) ans += arr[i][j+k];
                res = max(res, ans);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n-3; j++){
                int ans = 0;
                for(int k=0; k<4; k++) ans += arr[i+k][j];
                res = max(res, ans);
            }
        }
    }
    else if(mode == 2){
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                int ans = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
                res = max(res, ans);
            }
        }
    }
    else if(mode == 3){
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-1; j++){
                int ans = arr[i][j] + arr[i+1][j] + arr[i+2][j] + max(arr[i][j+1], arr[i+2][j+1]);
                int ans2 = arr[i][m-j-1] + arr[i+1][m-j-1] + arr[i+2][m-j-1] + arr[i+2][m-j-2];
                int resa = max(ans, ans2);
                res = max(res, resa);
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m-2; j++){
                int ans = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
                int ans2 = arr[n-i-1][j] + arr[n-i-1][j+1] + arr[n-i-1][j+2] + arr[n-i-2][j+1];
                int resa = max(ans, ans2);
                res = max(res, resa);
            }
        }
    }
    else if(mode == 4){

    }
    else if(mode == 5){
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-1; j++){
                int ans = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
                int ans2 = arr[i][m-j-1] + arr[i+1][m-j-1] + arr[i+2][m-j-1] + arr[i+1][m-j-2];
                int resa = max(ans, ans2);
                res = max(res, resa);
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m-2; j++){
                int ans = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
                int ans2 = arr[n-i-1][j] + arr[n-i-1][j+1] + arr[n-i-1][j+2] + arr[n-i-2][j+1];
                int resa = max(ans, ans2);
                res = max(res, resa);
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        char temp[20000];
        gets(temp);
        int cnt = 0, idx = 0, ans = 0;
        while(cnt < m){
            if(temp[idx] == ' ' || temp[idx] == '\0'){
                arr[i][cnt] = ans;
                cnt++;
                idx++;
                ans = 0;
                continue;
            }
            ans = ans*10 + temp[idx] -'0';
            idx++;
        }
    }

}
