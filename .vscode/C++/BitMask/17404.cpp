#include <bits/stdc++.h>
using namespace std;
int N;
int red[1000]; int green[1000]; int blue[1000];
int rr[1000]; int rg[1000]; int rb[1000];
int gb[1000]; int gg[1000]; int gr[1000];
int bb[1000]; int bg[1000]; int br[1000];
int min3(int a, int b, int c){
    return ((a<b) ? (a<c ? a : c) : (b<c ? b : c));
}
int min6(){
    int temp1 = min3(rr[N-1], rg[N-1], rb[N-1]);
    int temp2 = min3(gr[N-1], gb[N-1], gg[N-1]);
    int temp3 = min3(bg[N-1], bb[N-1], br[N-1]);
    return min3(temp1, temp2, temp3);
}
void sethouse(int start){
    if(start == N-1){
        rr[start] = bb[start] = gg[start] = 10000001;
        rb[start] = min(bb[start-1], gb[start-1]) + red[start];
        rg[start] = min(bg[start-1], gg[start-1]) + red[start];
        gr[start] = min(br[start-1], rr[start-1]) + green[start];
        gb[start] = min(bb[start-1], rb[start-1]) + green[start];
        br[start] = min(gr[start-1], rr[start-1]) + blue[start];
        bg[start] = min(gg[start-1], rg[start-1]) + blue[start];
    }
    else if(start == 0){
        rr[start] = red[start]; bb[start] = blue[start]; gg[start] = green[start];
        rb[start] = br[start] = bg[start] = 
        gb[start] = rg[start] = gr[start] = 10000001;
    }
    else{
        rr[start] = min(br[start-1], gr[start-1]) + red[start];
        rb[start] = min(bb[start-1], gb[start-1]) + red[start];
        rg[start] = min(bg[start-1], gg[start-1]) + red[start];
        gr[start] = min(br[start-1], rr[start-1]) + green[start];
        gb[start] = min(bb[start-1], rb[start-1]) + green[start];
        gg[start] = min(bg[start-1], rg[start-1]) + green[start];
        br[start] = min(gr[start-1], rr[start-1]) + blue[start];
        bb[start] = min(gb[start-1], rb[start-1]) + blue[start];
        bg[start] = min(gg[start-1], rg[start-1]) + blue[start];
    }

}
int main(int argc, char const *argv[])
{
    cin >> N;
    for(int i=0; i<N; i++) cin >> red[i] >> green[i] >> blue[i];
    for(int i=0; i<N; i++) sethouse(i);
    cout << min6();
    return 0;
}
