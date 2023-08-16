//7576
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
#define INF 5000
#define max(a,b) a>b?a:b
int tomato[MAX][MAX];
int ans[MAX][MAX];
int n, m;
typedef struct pair{
    int row, col;
    struct pair *link;
}pair;
typedef struct queue{
    pair *front, *rear;
}queue;
int inbound(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}
pair *initpair(int x, int y){
    pair *temp = (pair*)malloc(sizeof(pair));
    temp->row = x;
    temp->col = y;
    temp->link = NULL;
    return temp;
}
queue *initqueue(){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}
void enqueue(queue *q, int x, int y){
    pair *temp = initpair(x, y);
    if(!q->rear){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->link = temp;
    q->rear = temp;
}
pair *dequeue(queue *q){
    if(!q->front) return NULL;
    pair *temp = q->front;
    q->front = q->front->link;
    if(!q->front) q->rear = NULL;
    return temp;
}
int main(){
    scanf("%d %d", &m, &n);
    int istomato = 0;
    queue *q = initqueue();
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            scanf(" %d", &tomato[i][j]);
            ans[i][j] = INF;
            if(tomato[i][j] == 1){
                istomato = 1;
                enqueue(q, i, j);
                ans[i][j] = 0;
            }
        }
    if(!istomato){
        printf("-1");
        return 0;
    }
    while(q->front){
        pair *temp = dequeue(q);
        int x = temp->row;
        int y = temp->col;
        for(int i=x-1; i<x+2; i++)
        if(inbound(i, y) && !tomato[i][y] && ans[i][y] == INF){
            tomato[i][y] = 1;
            ans[i][y] = 1+ans[x][y];
            enqueue(q, i, y);
        }
        for(int i=y-1; i<y+2; i++)
        if(inbound(x, i) && !tomato[x][i] && ans[x][i] == INF){
            tomato[x][i] = 1;
            ans[x][i] = 1+ans[x][y];
            enqueue(q, x, i);
        }
    }
    int far=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(tomato[i][j]!=-1)
                far = max(far, ans[i][j]);
    if(far == INF) printf("-1");
    else printf("%d", far);
}*/

//7569
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define INF 5000
#define max(a,b) a>b?a:b
int tomato[MAX][MAX][MAX];
int ans[MAX][MAX][MAX];
int n, m, k;
typedef struct pair{
    int height, row, col;
    struct pair *link;
}pair;
typedef struct queue{
    pair *front, *rear;
}queue;
int inbound(int h, int x, int y){
    return x>=0 && y>=0 && h>=0 && x<n && y<m && h<k;
}
pair *initpair(int h, int x, int y){
    pair *temp = (pair*)malloc(sizeof(pair));
    temp->row = x;
    temp->col = y;
    temp->height = h;
    temp->link = NULL;
    return temp;
}
queue *initqueue(){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}
void enqueue(queue *q, int h, int x, int y){
    pair *temp = initpair(h, x, y);
    if(!q->rear){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->link = temp;
    q->rear = temp;
}
pair *dequeue(queue *q){
    if(!q->front) return NULL;
    pair *temp = q->front;
    q->front = q->front->link;
    if(!q->front) q->rear = NULL;
    return temp;
}
int main(){
    scanf("%d %d %d", &m, &n, &k);
    int istomato = 0;
    queue *q = initqueue();
    for(int h=0; h<k; h++)
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            scanf(" %d", &tomato[h][i][j]);
            ans[h][i][j] = INF;
            if(tomato[h][i][j] == 1){
                istomato = 1;
                enqueue(q, h, i, j);
                ans[h][i][j] = 0;
            }
        }
    if(!istomato){
        printf("-1");
        return 0;
    }
    while(q->front){
        pair *temp = dequeue(q);
        int h = temp->height;
        int x = temp->row;
        int y = temp->col;
        for(int i=x-1; i<x+2; i++)
        if(inbound(h, i, y) && !tomato[h][i][y] && ans[h][i][y] == INF){
            tomato[h][i][y] = 1;
            ans[h][i][y] = 1+ans[h][x][y];
            enqueue(q, h, i, y);
        }
        for(int i=y-1; i<y+2; i++)
        if(inbound(h, x, i) && !tomato[h][x][i] && ans[h][x][i] == INF){
            tomato[h][x][i] = 1;
            ans[h][x][i] = 1+ans[h][x][y];
            enqueue(q, h, x, i);
        }
        for(int i=h-1; i<h+2; i++)
        if(inbound(i, x, y) && !tomato[i][x][y] && ans[i][x][y] == INF){
            tomato[i][x][y] = 1;
            ans[i][x][y] = 1+ans[h][x][y];
            enqueue(q, i, x, y);
        }
    }
    int far=0;
    for(int h=0; h<k; h++)
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(tomato[h][i][j]!=-1)
                far = max(far, ans[h][i][j]);
    if(far == INF) printf("-1");
    else printf("%d", far);
}*/


//2293
/*
#include <stdio.h>
#define MAX 100
#define moneyMAX 10300
int n, k;
int coin[MAX];
int dp[moneyMAX];

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", coin+i);
    dp[0] = 1;
    for(int i=0; i<n; i++)
        for(int j = coin[i]; j<=k; j++)
            dp[j] += dp[j-coin[i]];
    printf("%d", dp[k]);

}*/

//5430
/*
#include <stdio.h>
#include <stdlib.h>
#define ordMAX 100100
#define arrMAX 100100
#define listMAX 500100

int main(){
    int test;
    scanf("%d", &test);
    for(int i=0; i<test; i++){
        int n;
        int arr[arrMAX];
        char ord[ordMAX];
        char arrstr[listMAX];
        scanf("%s", ord);
        scanf("%d", &n);
        scanf("%s", arrstr);
        int idx = 1, cnt = 0, temp = 0;
        while(arrstr[idx]){
            if(arrstr[idx] == ',' || arrstr[idx] == ']'){
                arr[cnt++] = temp;
                temp = 0;
                idx++;
                continue;
            }
            temp = temp*10 + arrstr[idx] - '0';
            idx++;
        }
        if(n==0){
                int flag = 1;
            for(int j=0; ord[j]; j++){
                if(ord[j] == 'D'){
                    printf("error\n");
                    flag = 0;
                    break;
                    continue;
                }
            }
            if(flag) printf("[]\n");
            continue;
        }

        int left = 0, right = n-1, flag = 1;
        for(int j=0; ord[j]; j++){
            if(ord[j] == 'R') flag *= -1;
            else if(flag == 1) left ++;
            else right--;
        }
        if(left>right+1){
            printf("error\n");
            continue;
        }
        if(flag == 1){
            printf("[");
            for(int i=left; i<=right; i++){
                if(i!=right)
                    printf("%d,",arr[i]);
                else
                    printf("%d", arr[i]);
            }

            printf("]\n");
        }
        else{
            printf("[");
            for(int i=right; i>=left; i--)
                if(i!=left)
                    printf("%d,",arr[i]);
                else
                    printf("%d", arr[i]);
            printf("]\n");
        }

    }
}*/

//10026
/*
#include <stdio.h>
#define MAX 100
char arr[MAX][MAX];
int normal[MAX][MAX];
int abnor[MAX][MAX];
int n;
void next_dfs(int x, int y, int color, int isnormal){
    if(isnormal){
        int temp =  x>=0 && y>=0 && x<n && y<n && (normal[x][y] == color);
        if(temp) dfs(x, y, color, isnormal);
        return;
    }
    else{
        int temp =  x>=0 && y>=0 && x<n && y<n && (abnor[x][y] == color);
        if(temp) dfs(x, y, color, isnormal);
        return;
    }

}
int find_color(int color, int isnormal){
    if(isnormal){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(normal[i][j] == color)
                    return 101*i+j;
        }

    }

    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(abnor[i][j] == color)
                    return 101*i+j;
        }

    }
    return -1;
}
void dfs(int x, int y, int color, int isnormal){
    if(isnormal) normal[x][y] = -1;
    else abnor[x][y] = -1;

    next_dfs(x-1, y, color, isnormal);
    next_dfs(x+1, y, color, isnormal);
    next_dfs(x, y-1, color, isnormal);
    next_dfs(x, y+1, color, isnormal);
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", arr[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'B'){
                normal[i][j] = 0;
                abnor[i][j] = 0;
            }
            else{
                abnor[i][j] = 1;
                normal[i][j] = 1 + (arr[i][j] == 'G');
            }
        }
    }
    int red=0, green=0, blue=0, brown=0;
    while (find_color(0, 1) != -1){
        int temp = find_color(0, 1);
        blue++;
        dfs(temp/101, temp%101, 0, 1);
    }
    while (find_color(1, 1) != -1){
        int temp = find_color(1, 1);
        red++;
        dfs(temp/101, temp%101, 1, 1);
    }
    while (find_color(2, 1) != -1){
        int temp = find_color(2, 1);
        green++;
        dfs(temp/101, temp%101, 2, 1);
    }
    while (find_color(1, 0) != -1){
        int temp = find_color(1, 0);
        brown++;
        dfs(temp/101, temp%101, 1, 0);
    }
    printf("%d %d", red+green+blue, brown+blue);

}*/
























