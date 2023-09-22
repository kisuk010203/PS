// #include <stdio.h>
// int main(){
//     int a, b;
//     scanf("%d %d", &a, &b);
//     printf("a: %d, b:%d", a, b);
// }


// #include <stdio.h>
// int isPrime [100000] = {0};
// int numPrime [100000] = {0};
// int main(){
//     int A, B;
//     scanf("%d %d", &A, &B);
//     for(int i = 2; i<=B; i++) isPrime[i] = 1;
//     for(int i = 2; i*i <= B; i++){
//         for(int j = 2*i; j<=B; j += i){
//             isPrime[j] = 0;
//         }
//     }

//     int cnt = 0;
//     for(int i = 2; i<=B; i++){
//         if(isPrime[i] == 1){
//             numPrime[i] = 1;
//             continue;
//         }
//         for(int j = 2; j*j <=i; j++){
//             if(isPrime[j] == 1 && i%j == 0) {
//                 numPrime[i] = numPrime[i/j] + 1;
//                 break;
//             }

//         }
//         if (i>=A && isPrime[numPrime[i]] == 1) cnt += 1;
//     }
//     printf("%d", cnt);
// }

// #include <stdio.h>
// int main(){
//     long long int N;
//     int F;
//     scanf("%lld", &N);
//     scanf("%d", &F);
//     int x = (N-N%100)%F;
//     if(x == 0) print("00");
//     else if(F-x <10) print("0%d",F-x);
//     else print("%d", F-x);

// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 20000
// #define INF 8000000

// typedef struct node{
// 	int data;
// 	int edgenum;
// 	struct node *next;
// }node;

// typedef struct graph{
// 	int v_num;
// 	node *list[MAX];
// }graph;
// int distance[MAX];
// int searched[MAX];

// int findMin(graph *g){
// 	int min = INF + 1;
// 	int idx = -1;
// 	for(int i = 0; i<g->v_num; i++){
// 		if(distance[i] < min && searched[i] == 0){
// 			min = distance[i];
// 			idx = i;
// 		}
// 	}
// 	return idx;
// }

// void printAll(graph *g){
// 	for(int i = 0; i<g->v_num ; i++){
//         if(distance[i] < INF/2) printf("%d\n", distance[i]);
// 		else printf("INF\n");
// 	}
// }
// void dijkstra(graph *g, int start){
// 	for(int i = 0; i<g->v_num; i++){
// 		distance[i] = INF;
// 		searched[i] = 0;
// 	}
// 	for(node *n = g->list[start]; n; n = n->next)
// 		distance[n->data] = n->edgenum;

// 	searched[start] = 1;
// 	distance[start] = 0;

// 	for(int i = 0; i<g->v_num -1; i++){
// 		int nextFound = findMin(g);
// 		searched[nextFound] = 1;
// 		for(node *n = g->list[nextFound]; n; n = n->next){
// 			if(searched[n->data] == 0){
// 				if(distance[nextFound] + n->edgenum < distance[n->data]){
// 					distance[n->data] = distance[nextFound] + n->edgenum;
// 				}
// 			}

// 		}
// 	}

// }
// void init(graph *g){
// 	g->v_num = 0 ;
// 	for(int v = 0; v<MAX; v++)
// 		g->list[v] = NULL;
// }
// void edge(graph *g, int u, int v, int k){
// 	node *lnode = (node*)malloc(sizeof(node));
// 	lnode->data = v;
// 	lnode->next = g->list[u];
// 	lnode->edgenum = k;
// 	g->list[u] = lnode;
// }

// void vertex(graph *g, int v){
// 	g->v_num++;
// }


// int main(){
// 	graph *g = (graph*)malloc(sizeof(graph));
// 	init(g);
//     int vert, edges, start;
//     scanf("%d %d", &vert, &edges);
//     scanf("%d", &start);
// 	for(int i = 0; i<vert; i++)
// 		vertex(g,i);
//     for(int i = 0; i<edges; i++){
//         int x, y, z;
//         scanf("%d %d %d", &x, &y, &z);
//         edge(g, x, y, z);
//     }
// 	dijkstra(g,start-1);
// 	printAll(g);

// }


#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int arr[MAX][MAX];
int deglist[MAX];
int eulerlist[MAX*MAX*5];
int n, cnt;

void dfs(int start){
	int end = 0;
	while(deglist[start]){
		if(arr[start][end]){
			arr[start][end]--;
			arr[end][start]--;
			deglist[start]--;
			deglist[end]--;
			dfs(end);
		}
		else if(end<n-1){
			end++;
		}
	}
	eulerlist[cnt++] = start;
}
int main(){
	scanf("%d", &n);


	int cntodd = 0;
	cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %d", &arr[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		int sum=0;
		for (int j = 0; j<n ; j++){
			sum += arr[i][j];
		}
		deglist[i] = sum;
		if(sum%2 == 1){
			cntodd = 1;
			break;
		}
	}
	if(cntodd) printf("-1");
	else{
		dfs(0);
		for(int i=cnt-1; i>=0; i--) printf("%d", eulerlist[i]);
	}
}
