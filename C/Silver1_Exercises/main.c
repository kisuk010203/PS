//2178
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 103
#define INF 30000
#define min(a,b) a<b?a:b
int n, m;
int lab[MAX][MAX];
int distance[MAX][MAX];
typedef struct pair{
    int row, col;
    struct pair *link;
}pair;
typedef struct queue{
    pair *front, *rear;
}queue;
int inBound(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
pair *initpair(int x, int y){
    pair *temp = (pair*)malloc(sizeof(pair));
    temp->row = x;
    temp->col = y;
    temp->link = NULL;
    return temp;
}
queue *initQueue(){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}
void enQueue(queue *q, int x, int y){
    pair *temp = initpair(x, y);
    if(!q->rear){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->link = temp;
    q->rear = temp;
}
pair* deQueue(queue *q){
    if(!q->front) return NULL;
    pair *temp = q->front;
    q->front = q->front->link;
    if(!q->front) q->rear = NULL;
    return temp;
}

int main(){
    scanf("%d %d", &n, &m);
    char rowstring[105];
    for(int i=0; i<n; i++){
        scanf("%s",rowstring);
        for(int j=0; j<m; j++){
            lab[i][j] = rowstring[j] - '0';
            distance[i][j] = INF;
        }
    }


    queue *q = initQueue();

    enQueue(q, 0, 0);
    distance[0][0] = 0;

    while(q->front){
        pair *temp = deQueue(q);
        int x = temp->row;
        int y = temp->col;
        for(int i=x-1; i<=x+1; i++)
            if(inBound(i, y) && distance[i][y] == INF && lab[x][y]){
                distance[i][y] = 1 + distance[x][y];
                enQueue(q, i, y);
            }
        for(int i=y-1; i<=y+1; i++)
            if(inBound(x, i) && distance[x][i] == INF && lab[x][y]){
                distance[x][i] = 1 + distance[x][y];
                enQueue(q, x, i);
            }
    }

    printf("%d", distance[n-1][m-1]+1);
}
*/


