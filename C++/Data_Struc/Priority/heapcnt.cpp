#include <bits/stdc++.h>
using namespace std;
int cnt;
int arr[11] = {0,10,9,8,8,8,5,4,3,2,1};
void percolateDown(int i, int n){
    cnt++;
    int child = 2*i;
    int rchild = 2*i+1;
    if(child<=n){
        if((rchild <= n) && arr[child] < arr[rchild]){
            child = rchild;
        }
        if(arr[i] < arr[child]) {
            swap(arr[i], arr[child]);
            percolateDown(child, n);
        }
    }
}

void heapsort(int n){
    for(int i=n/2; i>= 1;i--){
        percolateDown(i, n);

    }cout << cnt << endl;
    for(int size=n; size>=2; size--){
        swap(arr[1], arr[size-1]);
        percolateDown(1, size-1);
        cout << cnt << endl;
    }
}
int main(){
    heapsort(10);
    cout << cnt;
}
