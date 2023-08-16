//1874 BOJ
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 100500
//#define CharMAX 200500
//typedef struct stack{
//    int top;
//    int data[MAX];
//}stack;
//stack* init(){
//    stack *s = (stack*)malloc(sizeof(stack));
//    s->top = 0;
//    return s;
//}
//int isEmpty(stack *s){
//    return s->top == 0;
//}
//int pop(stack* s){
//    return isEmpty(s) ? 0 : s->data[--s->top];
//}
//int peek(stack*s){
//    return isEmpty(s) ? 0 : s->data[s->top-1];
//}
//void push(stack* s, int n){
//    s->data[s->top++] = n;
//}
//int main(){
//    int n;
//    int arr[MAX];
//    char oper[CharMAX];
//    stack *num = init();
//    scanf("%d", &n);
//    for(int i=0; i<n; scanf("%d", arr+(i++)));
//    int i=1, j=0, charidx = 0, flag = 1;
//    while(i<=n && j<n){
//        if(isEmpty(num) || peek(num) != arr[j]){
//            push(num, i++);
//            oper[charidx++] = '+';
//        }
//        else if(peek(num) == arr[j]){
//            pop(num);
//            oper[charidx++] = '-';
//            j++;
//        }
//    }
//    while(j<n){
//        flag = (pop(num) == arr[j++]);
//        if(flag)
//            oper[charidx++] = '-';
//        else break;
//    }
//    if(flag)
//        for(int i=0; oper[i]; i++) printf("%c\n", oper[i]);
//    else printf("NO");
//}

//2667
//#include <stdio.h>
//#define MAX 30
//int arr[MAX][MAX];
//int component[900];
//int cnt, n, tempcnt;
//char temp[MAX];
//int remain(){
//    for(int i=0; i<n; i++)
//        for(int j=0; j<n; j++)
//            if(arr[i][j]) return 100*i+j+1;
//    return 0;
//}
//void dfs(int x, int y){
//    if(!arr[x][y])
//        return;
//    tempcnt++;
//    arr[x][y] = 0;
//    for(int i=y-1; i<y+2; i++)
//        if(i>=0 && i<n && arr[x][i])
//        dfs(x, i);
//    for(int i=x-1; i<x+2; i++)
//        if(i>=0 && i<n && arr[i][y])
//        dfs(i, y);
//}
//int main(){
//    scanf("%d", &n);
//    for(int i=0; i<n; i++){
//        scanf("%s", temp);
//        for(int j=0; j<n; j++)
//            arr[i][j] = temp[j] - '0';
//    }
//    while(remain()){
//        int idx = remain();
//        tempcnt = 0;
//        dfs(idx/100, idx%100 - 1);
//        component[cnt++] = tempcnt;
//    }
//    for(int i=0; i<cnt; i++){
//        for(int j=i+1; j<cnt; j++){
//            if(component[j] < component[i]){
//                int temp = component[j];
//                component[j] = component[i];
//                component[i] = temp;
//            }
//        }
//    }
//    printf("%d\n", cnt);
//    for(int i=0; i<cnt; i++)
//        printf("%d\n", component[i]);
//}

//2805
//#include <stdio.h>
//#define MAX 2000500
//#define max(a, b) a>b?a:b
//typedef long long ll;
//ll arr[MAX];
//ll n, m;
//ll cut(ll tree, ll saw){
//    return tree>saw ? tree-saw : 0;
//}
//ll getsum(ll saw){
//    ll ans = 0;
//    for(ll i=0; i<n; i++){
//        ans += cut(arr[i], saw);
//    }
//    return ans;
//}
//int main(){
//    scanf("%lld %lld", &n, &m);
//    for(ll i=0; i<n; i++) scanf(" %lld", arr+i);
//    ll left = 0, right = 0;
//    for(ll i=0; i<n; i++) right = max(right, arr[i]);
//    ll cm = 0;
//    while(left<=right){
//
//        ll mid = (left+right)/2;
//
//        ll curr = getsum(mid);
//        if(curr<m) right = mid-1;
//        else if(curr>m){
//            cm = max(cm, mid);
//            left = mid+1;
//        }
//        else{
//            cm = mid;
//            break;
//        }
//    }
//    printf("%lld", cm);
//}

//1654
//#include <stdio.h>
//#define kmax 20000
//#define max(a, b) a>b?a:b
//typedef long long ll;
//ll k, n;
//ll arr[kmax];
//ll getcount(ll len){
//    if(!len) return -1;
//    ll ans = 0;
//    for(ll i=0; i<k; i++) ans += (arr[i]/len);
//    return ans;
//}
//int main(){
//    scanf("%lld %lld", &k, &n);
//    ll left = 1, right = 0, cm = 0;
//    for(ll i=0; i<k; i++) scanf("%lld", arr+i);
//    for(ll i=0; i<k; i++) right = max(right, arr[i]);
//    while(left<=right){
//        ll mid = (left+right)/2;
//        ll curr = getcount(mid);
//        if(curr<n) right = mid-1;
//        else {
//            cm = max(cm, mid);
//            left = mid+1;
//        }
//    }
//    printf("%lld", cm);
//}


//11055
//#include <stdio.h>
//#define MAX 1010
//#define max(a,b) a>b?a:b
//int seq[MAX];
//int dp[MAX];
//
//int main(){
//    int n;
//    scanf("%d", &n);
//    for(int i=0; i<n; i++) scanf(" %d", seq+i);
//    dp[n-1] = seq[n-1];
//    for(int i=n-2; i>=0; i--){
//        dp[i] = seq[i];
//        for(int j=i+1; j<n; j++){
//            if(seq[i] < seq[j]) dp[i] = max(dp[i], seq[i]+dp[j]);
//        }
//    }
//    int ans = 0;
//    for(int i=0; i<n; i++) ans = max(ans, dp[i]);
//    printf("%d", ans);
//}

//11722
//#include <stdio.h>
//#define MAX 1010
//#define max(a, b) a>b?a:b
//int seq[MAX];
//int dp[MAX];
//
//int main(){
//    int n;
//    scanf("%d", &n);
//    for(int i=0; i<n; i++) scanf(" %d", seq+i);
//    dp[n-1] = 1;
//    for(int i=n-2; i>=0; i--){
//        dp[i] = 1;
//        for(int j=i+1; j<n; j++){
//            if(seq[i] > seq[j]) dp[i] = max(dp[i], 1+dp[j]);
//        }
//    }
//    int ans = 0;
//    for(int i=0; i<n; i++) ans = max(ans, dp[i]);
//    printf("%d", ans);
//}

//11051
//#include <stdio.h>
//#define MAX 1010
//#define max(a, b) a>b?a:b
//int dp[MAX][MAX];
//int setdp(int n, int k){
//    if(dp[n][k])
//        return dp[n][k];
//    if(n==1) return k<=1;
//    dp[n][k] = (setdp(n-1, k-1) + setdp(n-1, k))%10007;
//    return dp[n][k];
//}
//int main(){
//    int n, k;
//    scanf("%d %d", &n, &k);
//    for(int i=0; i<=n; i++){
//        dp[i][0] = 1;
//        dp[i][i] = 1;
//    }
//    int ans = setdp(n,k);
//    printf("%d", ans);
//
//}


//2004
//#include <stdio.h>
//int findfive(int n){
//    int ans = 0;
//    while(n>0){
//        n/=5;
//        ans += n;
//    }
//    return ans;
//}
//int findtwo(int n){
//    int ans = 0;
//    while(n>0){
//        n/=2;
//        ans += n;
//    }
//    return ans;
//}
//int findzero(int n, int m){
//    int numfive = findfive(n) - findfive(m) - findfive(n-m);
//    int numtwo = findtwo(n) - findtwo(m) - findtwo(n-m);
//    return numfive>numtwo?numtwo:numfive;
//}
//int main(){
//    int n, m;
//    scanf("%d %d", &n, &m);
//    printf("%d", findzero(n, m));
//}

//1699
//#include <stdio.h>
//#define MAX 100100
//#define min(a, b) a<b?a:b
//int dp[MAX];
//int main(){
//    int n;
//    scanf("%d", &n);
//    for(int i=1; i*i<=n; i++) dp[i*i] = 1;
//    for(int i=2; i<=n; i++){
//        if(!dp[i]) dp[i] = 1000;
//        for(int j=1; j*j<i; j++){
//                dp[i] = min(dp[i], 1 + dp[i-j*j]);
//        }
//    }
//    printf("%d", dp[n]);
//}

//1780
//#include <stdio.h>
//#define MAX 2187
//int arr[MAX][MAX];
//int brr[3];
//void paper(int x, int y, int size){
//    int ind = arr[x][y], flag = 0;
//    for(int i=0; i<size; i++)
//    for(int j=0; j<size; j++){
//        if(arr[x+i][y+j] != ind){
//            flag = 1;
//            break;
//        }
//    }
//    if(!flag) brr[ind+1]++;
//    else{
//        size/=3;
//        for(int i=0; i<3; i++)
//            for(int j=0; j<3; j++)
//                paper(x+i*size, y+j*size, size);
//    }
//}
//int main(){
//    int size;
//    scanf("%d", &size);
//    for(int i=0; i<size; i++)
//        for(int j=0; j<size; j++)
//            scanf(" %d", &arr[i][j]);
//    paper(0, 0, size);
//    printf("%d\n%d\n%d", brr[0], brr[1], brr[2]);
//}

//6603
//#include <stdio.h>
//#include <stdlib.h>
//int arr[13];
//int main(){
//    while(1){
//        int n;
//        scanf("%d",&n);
//        if(n==0) break;
//        for(int i=0; i<n; i++) scanf(" %d",arr+i);
//        for(int a=0; a<n-5; a++){
//            for(int b=a+1; b<n-4; b++){
//                for(int c=b+1; c<n-3; c++){
//                    for(int d=c+1; d<n-2; d++){
//                        for(int e=d+1; e<n-1; e++){
//                            for(int f=e+1; f<n; f++){
//                                printf("%d %d %d %d %d %d\n",arr[a],arr[b],arr[c],arr[d],arr[e],arr[f]);
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        printf("\n");
//    }
//}


//18870
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 1000050
//int size;
//int sorted[MAX];
//int arr[MAX];
//int brr[MAX];
//int seq[MAX];
//void merge(int arr[], int m, int mid, int n);
//void mergesort(int arr[], int m, int n){
//    int mid = (m+n)/2;
//    if(n-m >= 1){
//		mergesort(arr, m, mid);
//		mergesort(arr, mid+1, n);
//		merge(arr, m, mid, n);
//	}
//}
//void merge(int arr[], int m, int mid, int n){
//    int i = m, j = mid+1, k = m;
//	while(i<=mid && j<=n){
//		if(arr[i]<=arr[j]) sorted[k++] = arr[i++];
//		else sorted[k++] = arr[j++];
//	}
//	if(i>mid) for(;j<=n; sorted[k++] = arr[j++]);
//	else for(;i<=mid;sorted[k++] = arr[i++]);
//	for(int t = m ; t<=n ; arr[t] = sorted[t++]);
//}
//int main(){
//    scanf("%d", &size);
//    for(int i=0; i<size; i++) scanf(" %d", arr+i);
//    for(int i=0; i<size; i++) brr[i] = arr[i];
//    mergesort(arr, 0, size-1);
//    seq[0] = sorted[0];
//    int cnt = 0;
//    for(int i=1; i<size; i++){
//        if(sorted[i] != seq[cnt]) seq[++cnt] = sorted[i];
//    }
//
//    for(int i=0; i<size; i++){
//        int left = 0, right = cnt;
//        while(left<=right){
//            int mid = (left+right)/2;
//            int curr = seq[mid];
//            if(curr<brr[i]) left = mid+1;
//            else right = mid-1;
//        }
//        printf("%d ",left);
//    }
//
//}

//16953
/*
#include <stdio.h>
int a, b;
int dothis(int n){
    if(n==0) return -1;
    if(n%2 == 0)
        return n/2;
    else if(n%10 == 1)
        return n/10;
    else
        return -1;
}
int main(){
    int cnt = 0, flag = 1;
    scanf("%d %d", &a, &b);
    while(1){
        b = dothis(b); cnt++;
        if(a==b) break;
        else if(b == -1){
            flag = 0;
            break;
        }
    }
    if(flag) printf("%d", cnt+1);
    else printf("-1");
}*/

//15650
/*
#include <stdio.h>
#define MAX 10
int n, m;
int seq[MAX];
void dfs(int idx){
    if(idx == m){
            for(int i=0; i<m; i++)
                printf("%d ",seq[i]);
        printf("\n");
        return;
    }
    else if(idx == 0){
        for(int i=1; i<=n-m+1; i++){
            seq[idx] = i;
            dfs(1);
        }
    }
    else{
        for(int i=seq[idx-1]+1; i<=n-m+idx+1; i++){
            seq[idx] = i;
            dfs(idx+1);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    dfs(0);
}*/


//15652
/*
#include <stdio.h>
#define MAX 10
int n, m;
int seq[MAX];
void dfs(int idx){
    if(idx == m){
            for(int i=0; i<m; i++)
                printf("%d ",seq[i]);
        printf("\n");
        return;
    }
    else if(idx == 0){
        for(int i=1; i<=n; i++){
            seq[idx] = i;
            dfs(1);
        }
    }
    else{
        for(int i=seq[idx-1]; i<=n; i++){
            seq[idx] = i;
            dfs(idx+1);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    dfs(0);
}*/


//15654
/*
#include <stdio.h>
#define MAX 10
int n, m;
int seq[MAX];
int given[MAX];
int isPossible(int idx, int r){
    for(int i=0; i<idx; i++)
        if(r == seq[i]) return 0;
    return 1;
}
void dfs(int idx){
    if(idx == m){
            for(int i=0; i<m; i++)
                printf("%d ",given[seq[i]]);
        printf("\n");
        return;
    }
    else if(idx == 0){
        for(int i=0; i<n; i++){
            seq[idx] = i;
            dfs(1);
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(isPossible(idx, i)){
                seq[idx] = i;
                dfs(idx+1);
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf(" %d", given+i);
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++){
        if(given[j] < given[i]){
            int temp = given[j];
            given[j] = given[i];
            given[i] = temp;
        }
    }
    dfs(0);
}*/

//15657
/*
#include <stdio.h>
#define MAX 10
int n, m;
int seq[MAX];
int given[MAX];
void dfs(int idx){
    if(idx == m){
            for(int i=0; i<m; i++)
                printf("%d ",given[seq[i]]);
        printf("\n");
        return;
    }
    else if(idx == 0){
        for(int i=0; i<n; i++){
            seq[idx] = i;
            dfs(1);
        }
    }
    else{
        for(int i=seq[idx-1]; i<n; i++){
                seq[idx] = i;
                dfs(idx+1);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf(" %d", given+i);
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++){
        if(given[j] < given[i]){
            int temp = given[j];
            given[j] = given[i];
            given[i] = temp;
        }
    }
    dfs(0);
}*/
/*
#include <stdio.h>
#define MAX 10
int n, m;
int seq[MAX];
int prev[MAX];
int given[MAX];
void dfs(int idx){
    if(idx == m){
        int flag = 1;
        for(int i=0; i<m; i++){
            if(given[seq[i]] != prev[i]){
                flag = 0;
                break;
            }
        }
        if(!flag){
            for(int i=0; i<m; i++){
                printf("%d ",given[seq[i]]);
                prev[i] = given[seq[i]];
            }
            printf("\n");
        }
        return;
    }
    else if(idx == 0){
        for(int i=0; i<n; i++){
            seq[idx] = i;
            dfs(1);
        }
    }
    else{
        for(int i=seq[idx-1]; i<n; i++){
                seq[idx] = i;
                dfs(idx+1);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf(" %d", given+i);
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++){
        if(given[j] < given[i]){
            int temp = given[j];
            given[j] = given[i];
            given[i] = temp;
        }
    }
    for(int i=0; i<m; i++) prev[i] = given[i];
    dfs(0);
}*/






















