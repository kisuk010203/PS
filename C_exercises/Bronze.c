// #include <stdio.h>
// int main(){
//     int a[9];
//     for(int i=0; i<9; i++){
//         scanf("%d", &a[i]);
//     }
//     int idx = 0, max = a[0];
//     for(int i = 1; i<9; i++){
//         if (max < a[i]){
//             idx = i;
//             max = a[i];
//         }
//     }
//     printf("%d\n", max);
//     printf("%d", idx + 1);
// }

// #include <stdio.h>
// #include <math.h>
// int findMinMoves(long long dist){
//     if (dist == 1 || dist == 2) return dist;
//     long long j = (int) (sqrt(dist)+0.5);
//     return (dist > j*j) ? 2*j : 2*j-1;
// }
// int main(){
//     int t;
//     scanf("%d", &t);
//     long long x, y;
//     for(int i = 0 ; i < t ; i++){
//         scanf("%lld %lld", &x, &y);
//         printf("%lld\n", findMinMoves(y - x));
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// int isSquare(int n){
//     int b = sqrt(n);
//     return n == b*b;
// }
// int main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
//     int** arr = (int**)malloc(sizeof(int*)*n);
//     for(int i=0; i<n; i++){
//         char s[10] = "";
//         arr[i] = (int*)malloc(sizeof(int)*m);
//         scanf("%s", s);
//         for(int j = 0; j<m; j++){
//             arr[i][j] = s[j] -'0';
//         }
//     }
// }

// #include <stdio.h>
// #define min(a, b) a>b?b:a
// int arr[100][100] = {-1};
// int d[100] = {1};
// int choose(int n, int k){
//     if (arr[n][k] != -1) return arr[n][k];
//     else{
//         return (arr[n-1][k-1] + arr[n-1][k])%1000000;
//     }
// }
// int main(){
//     for(int i = 0; i<100; i++){
//         arr[i][0] = 1;
//         arr[i][1] = i;
//         arr[i][i] = 1;
//     }
//     int n;
//     scanf("%d", &n);
//     if(n<=2) printf("%d", d[n]*n);
//     else{
//         for(int idx = 3; idx<=n; idx++){
//             int s = 0;
//             for(int i = 0; i<idx; i+=2){
//                 s += ((d[i]*d[idx-i-1])%1000000 * arr[idx-1][min(i, idx-i-1)])%1000000;
//             }
//             d[idx] = s;
//         }
//         printf("%d", (2*d[n])%1000000);
//     }
// }

#include <stdio.h>
#define bound 1000000
#define min(a,b) a>b?b:a
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i<t ; i++){
        int arr[bound], frobnum = 0, frobcnt = 0, consec = 0;
        int brr[4];
        scanf("%d %d %d %d",brr, brr+1, brr+2, brr+3);
        arr[0] = 1;
        for(int j = 1; j<=bound; j++){
            for(int k = 0; k<4; k++){
                int t = 0;
                if(brr[k] <= i && arr[i-k]){
                    arr[i] = 1;
                    consec++;
                    t=1;
                    break;
                }
            }
            if(t==0){
                arr[i] = 0;
                frobcnt ++;
                frobnum =  i;
            }
        }
    int m = brr[0];
    for(int i=1; i<4; i++) m = min(brr[i], m);
    if(consec < m){
        frobnum = -1;
    }
    printf("%d\n", frobcnt);
    printf("%d\n", frobnum);

    }

}
