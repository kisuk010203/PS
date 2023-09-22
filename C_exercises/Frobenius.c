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