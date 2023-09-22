//2839
/*
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int cnt = 0, flag = 1;
    while(n>0){
        if(n>=13){
            cnt ++;
            n -=5;
        }
        else if (n%5 == 0){
            cnt += (n/5);
            n = 0;
        }
        else if (n == 8 || n == 11){
            cnt += ((n-5)/3 + 1);
            n = 0;
        }
        else if (n%3 !=0){
            flag = 0;
            break;
        }
        else{
            n-=3;
            cnt++;
        }
    }
    if(flag) printf("%d", cnt);
    else printf("-1");
}*/

//11399
/*
#include <stdio.h>
int main(){
    int n;
    int arr[1000];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf(" %d", arr+i);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) ans += (n-i)*arr[i];
    printf("%d", ans);
}*/

//11047
/*
#include <stdio.h>
int coin[10];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", coin+i);
    int start = n-1, cnt = 0;
    while(k>0 && start >=1){
        cnt += k/coin[start];
        k %= coin[start--];
    }
    printf("%d", cnt+k);
}*/

//2217
/*
#include <stdio.h>
#define ropeMAX 100010
#define max(a,b) (a>b)?a:b
int weight[ropeMAX];
int temp[ropeMAX];
void mergeSort(int p, int r);
void merge(int p, int q, int r);
void mergeSort(int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(p , q);
        mergeSort(q+1, r);
        merge(p, q, r);
    }
}
void merge(int p, int q, int r) {
    int i = p, j = q+1, k = p;
    while(i<=q && j<=r) {
        if(weight[i] <= weight[j]) temp[k++] = weight[i++];
        else temp[k++] = weight[j++];
    }
    while(i<=q) temp[k++] = weight[i++];
    while(j<=r) temp[k++] = weight[j++];
    for(int a = p; a<=r; a++) weight[a] = temp[a];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", weight+i);
    mergeSort(0, n-1);
    int ans = 0;
    for(int i=n-1; i>=0; i--) ans = max(ans, (n-i)*weight[i]);
    printf("%d", ans);
}*/

//1789
/*
#include <stdio.h>
int main(){
    long long n, ans = 1;
    scanf("%lld", &n);
    while(1){
        if(n - ans * (ans+1) / 2 >= ans+1) ans++;
        else break;
    }
    printf("%lld", ans);
}*/

//1715
/*
#include <stdio.h>
int heapCnt;
void insertHeap(int *heap, int data, int heapCnt){
	int ind = heapCnt;
	while(ind!=1 && data<heap[ind/2]){
		heap[ind] = heap[ind/2];
		ind/=2;
	}
	heap[ind] = data;
}
int deleteHeap(int *heap){
	int c = heap[heapCnt], temp = heap[1];
	heapCnt--;
	int ind = 2;
	while(ind<=heapCnt){
		if(ind < heapCnt && heap[ind] > heap[ind+1])
			ind++;
		if(c<=heap[ind]){
			break;
		}
		heap[ind/2] = heap[ind];
		ind*=2;
	}
	heap[ind/2] = c;
	return temp;
}
int main(){
	int heap[100010];
	int ans = 0;
    int n; scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int temp; scanf("%d", &temp);
		insertHeap(heap, temp, ++heapCnt);
	}
	while(heapCnt > 1){
        int a = deleteHeap(heap);
        int b = deleteHeap(heap);
        insertHeap(heap, a+b, ++heapCnt);
        ans += (a+b);
	}
	printf("%d", ans);
}*/

//1927
/*
#include <stdio.h>
int heapCnt;
void insertHeap(int *heap, int data, int heapCnt){
	int ind = heapCnt;
	while(ind!=1 && data<heap[ind/2]){
		heap[ind] = heap[ind/2];
		ind/=2;
	}
	heap[ind] = data;
}
void deleteHeap(int *heap){
    if(!heapCnt){
        printf("0\n");
        return;
    }
	int c = heap[heapCnt], temp = heap[1];
	heapCnt--;
	int ind = 2;
	while(ind<=heapCnt){
		if(ind < heapCnt && heap[ind] > heap[ind+1])
			ind++;
		if(c<=heap[ind]){
			break;
		}
		heap[ind/2] = heap[ind];
		ind*=2;
	}
	heap[ind/2] = c;
	printf("%d\n", temp);
}
int main(){
	int heap[100010];
	int ans = 0;
    int n; scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int temp; scanf("%d", &temp);
		if(temp == 0) deleteHeap(heap);
		else insertHeap(heap, temp, ++heapCnt);
	}
}*/

//11279
/*
#include <stdio.h>
int heapCnt;
void insertHeap(int *heap, int data, int heapCnt){
	int ind = heapCnt;
	while(ind!=1 && data>heap[ind/2]){
		heap[ind] = heap[ind/2];
		ind/=2;
	}
	heap[ind] = data;
}
void deleteHeap(int *heap){
    if(!heapCnt){
        printf("0\n");
        return;
    }
	int c = heap[heapCnt], temp = heap[1];
	heapCnt--;
	int ind = 2;
	while(ind<=heapCnt){
		if(ind < heapCnt && heap[ind] < heap[ind+1])
			ind++;
		if(c>=heap[ind]){
			break;
		}
		heap[ind/2] = heap[ind];
		ind*=2;
	}
	heap[ind/2] = c;
	printf("%d\n", temp);
}
int main(){
	int heap[100010];
	int ans = 0;
    int n; scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int temp; scanf("%d", &temp);
		if(temp == 0) deleteHeap(heap);
		else insertHeap(heap, temp, ++heapCnt);
	}
}*/

//11286
/*
#include <stdio.h>
int abs(int a){return (a>0)?a:-1*a;}
int greater(int a, int b){
    if(abs(a) < abs(b)) return 0;
    else if (abs(a) > abs(b)) return 1;
    return a>=b;
}
int heapCnt;
void insertHeap(int *heap, int data, int heapCnt){
	int ind = heapCnt;
	while(ind!=1 && greater(heap[ind/2], data)){
		heap[ind] = heap[ind/2];
		ind/=2;
	}
	heap[ind] = data;
}
void deleteHeap(int *heap){
    if(!heapCnt){
        printf("0\n");
        return;
    }
	int c = heap[heapCnt], temp = heap[1];
	heapCnt--;
	int ind = 2;
	while(ind<=heapCnt){
		if(ind < heapCnt && greater(heap[ind], heap[ind+1]))
			ind++;
		if(greater(heap[ind], c)){
			break;
		}
		heap[ind/2] = heap[ind];
		ind*=2;
	}
	heap[ind/2] = c;
	printf("%d\n", temp);
}
int main(){
	int heap[100010];
	int ans = 0;
    int n; scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int temp; scanf("%d", &temp);
		if(temp == 0) deleteHeap(heap);
		else insertHeap(heap, temp, ++heapCnt);
	}
}*/

//1655
/*
#include <stdio.h>
int max(int a, int b){return (a>b)?a:b;}
int leftHeapCnt, rightHeapCnt;
void insertLeftHeap(int *heap, int data, int leftHeapCnt){//maxheap
	int ind = leftHeapCnt;
	while(ind!=1 && heap[ind/2]<= data){
		heap[ind] = heap[ind/2];
		ind/=2;
	}
	heap[ind] = data;
}
void insertRightHeap(int *heap, int data, int rightHeapCnt){//minheap
    int ind = rightHeapCnt;
    while(ind!=1 && heap[ind/2] >= data){
        heap[ind] = heap[ind/2];
        ind/=2;
    }
    heap[ind] = data;
}
int deleteRightHeap(int *heap){
	int c = heap[rightHeapCnt], temp = heap[1];
	rightHeapCnt--;
	int ind = 2;
	while(ind<=rightHeapCnt){
		if(ind < rightHeapCnt && heap[ind] > heap[ind+1])
			ind++;
		if(c<=heap[ind]){
			break;
		}
		heap[ind/2] = heap[ind];
		ind*=2;
	}
	heap[ind/2] = c;
	return temp;
}
int deleteLeftHeap(int *heap){
	int c = heap[leftHeapCnt], temp = heap[1];
	leftHeapCnt--;
	int ind = 2;
	while(ind<=leftHeapCnt){
		if(ind < leftHeapCnt && heap[ind] < heap[ind+1])
			ind++;
		if(c>=heap[ind]){
			break;
		}
		heap[ind/2] = heap[ind];
		ind*=2;
	}
	heap[ind/2] = c;
	return temp;
}
int main(){
	int leftHeap[100010];
	int rightHeap[100010];
    int n; scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int temp; scanf("%d", &temp);
		if(i==1) insertLeftHeap(leftHeap, temp, ++leftHeapCnt);
		else if(i%2 == 0){
            int peek = deleteLeftHeap(leftHeap);
            insertRightHeap(rightHeap, max(temp, peek), ++rightHeapCnt);
            insertLeftHeap(leftHeap, temp+peek-max(temp, peek), ++leftHeapCnt);
		}
		else{
            int peekright = deleteRightHeap(rightHeap);
            insertRightHeap(rightHeap, max(temp, peekright), ++rightHeapCnt);
            insertLeftHeap(leftHeap, temp+peekright - max(temp, peekright), ++leftHeapCnt);
		}
		printf("%d\n", leftHeap[1]);
	}

}*/


//15903
/*
#include <stdio.h>
#define MAX 2000
typedef long long ll;
ll heap[MAX];
ll heapcnt;
void push(ll data){
	ll idx = ++heapcnt;
    while(idx!=1 && heap[idx/2] >= data){
        heap[idx] = heap[idx/2];
        idx/=2;
    }
    heap[idx] = data;
}
ll pop(){
	ll c = heap[heapcnt], temp = heap[1], idx = 2;
	heapcnt--;
	while(idx<=heapcnt){
		if(idx < heapcnt && heap[idx] > heap[idx+1]) idx++;
		if(c<=heap[idx]) break;
		heap[idx/2] = heap[idx];
		idx*=2;
	}
	heap[idx/2] = c;
	return temp;
}
int main(){
	ll n, m, ans = 0;
	scanf("%lld %lld", &n, &m);
	for(ll i=0; i<n; i++){
		ll temp;
		scanf(" %lld", &temp);
		push(temp);
	}
	for(ll i=0; i<m; i++){
		ll a = pop();
		ll b = pop();
		push(a+b); push(a+b);
	}
	for(ll i=1; i<=n; i++) ans += heap[i];
	printf("%lld", ans);
}*/
