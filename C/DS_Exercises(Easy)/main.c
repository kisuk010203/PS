//9012
/*
#include <stdio.h>
#define MAX 60
int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        char para[MAX];
        scanf("%s", para);
        int open = 0, flag = 1;
        for(int i=0; para[i]; i++){
            if(para[i] == '(') open++;
            else open--;
            if(open<0){
                flag = 0;
                break;
            }
        }
        if(flag && open == 0) printf("YES\n");
        else printf("NO\n");
    }
}
*/

//10828
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
typedef struct stack{
    int top;
    int arr[MAX];
}stack;
stack *initstack(){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->top = -1;
    return temp;
}
void isEmpty(stack *s){
    printf("%d\n", s->top == -1);
}
void size(stack *s){
    printf("%d\n", s->top + 1) ;
}
void push(stack *s, int item){
    s->arr[++s->top] = item;
}
void pop(stack *s){
    if(s->top == -1) printf("-1\n");
    else printf("%d\n", s->arr[s->top--]);
}
void peek(stack *s){
    if(s->top == -1) printf("-1\n");
    else printf("%d\n", s->arr[s->top]);
}
int main(){
    int comm;
    stack *s = initstack();
    scanf("%d", &comm);
    for(int i=0; i<=comm; i++){
        char temp[20];
        gets(temp);
        switch(temp[0]){
            case 't':
                peek(s);
                break;
            case 'e':
                isEmpty(s);
                break;
            case 's':
                size(s);
                break;
            case 'p':
                if(temp[1] == 'o'){
                    pop(s);
                    break;
                }
                else{
                    int item = 0;
                    for(int i=5; temp[i]; i++)item = item*10 + temp[i] - '0';
                    push(s, item);
                    break;
                }
        }
    }
}*/

//10845
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 20020
typedef struct queue{
    int head, rear;
    int arr[MAX];
}queue;
queue *init(){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->head = 0;
    temp->rear = -1;
    return temp;
}
void push(queue *q, int item){
    q->arr[++q->rear] = item;
}
void pop(queue *q){
    if(q->head > q->rear){
        printf("-1\n"); return;
    }
    printf("%d\n", q->arr[q->head++]);
}
void size(queue *q){
    printf("%d\n", q->rear-q->head+1);
}
void empty(queue *q){
    printf("%d\n", q->head > q->rear);
}
void back(queue *q){
    if(q->head > q->rear){
        printf("-1\n"); return;
    }
    printf("%d\n", q->arr[q->rear]);
}
void front(queue *q){
    if(q->head > q->rear){
        printf("-1\n"); return;
    }
    printf("%d\n", q->arr[q->head]);
}
int main(){
    int t;
    scanf("%d", &t);
    queue *q = init();
    for(int i=0; i<=t; i++){
        char temp[20];
        gets(temp);
        switch(temp[0]){
        case 'f':
            front(q);
            break;
        case 's':
            size(q);
            break;
        case 'e':
            empty(q);
            break;
        case 'b':
            back(q);
            break;
        case 'p':
            if(temp[1] == 'o'){
                pop(q);
                break;
            }
            else{
                int item = 0;
                for(int j=5; temp[j]; j++) item = item*10 + temp[j] - '0';
                push(q, item);
                break;
            }
        }
    }
}*/


//1920
/*
#include <stdio.h>
#define MAX 100300
int arr[MAX];
int sorted[MAX];
int target[MAX];
void merge(int arr[], int m, int mid, int n);
void mergesort(int arr[], int m, int n){
    int mid = (m+n)/2;
    if(n-m >= 1){
		mergesort(arr, m, mid);
		mergesort(arr, mid+1, n);
		merge(arr, m, mid, n);
	}
}
void merge(int arr[], int m, int mid, int n){
    int i = m, j = mid+1, k = m;
	while(i<=mid && j<=n){
		if(arr[i]<=arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}
	if(i>mid) for(;j<=n; sorted[k++] = arr[j++]);
	else for(;i<=mid;sorted[k++] = arr[i++]);
	for(int t = m ; t<=n ; arr[t] = sorted[t++]);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf(" %d", arr+i);
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) scanf(" %d", target+i);
    mergesort(arr, 0, n-1);
    for(int i=0; i<m; i++){
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(mid < target[i]) left = mid+1;
            else if(mid>target[i]) right = mid-1;
            else{
                left = mid;
                break;
            }
        }
        printf("%d\n", arr[left] == target[i]);

    }
}*/

#include <stdio.h>
int main(){
    printf("Hello world!");
}
