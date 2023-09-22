#include <bits/stdc++.h>
using namespace std;
int n;
void dnc(int *inorder, int *postorder, int i_start, int i_end, int p_start, int p_end){
    int root = postorder[p_end];
    printf("%d ", root);
    if(p_start == p_end) return;
    int idx = i_start;
    for(; idx<=i_end; idx++){
        if(inorder[idx] == root) break;
    }
    if(idx == i_start){
        dnc(inorder, postorder, i_start+1, i_end, p_start, p_end-1);
    }
    else if(idx == i_end) dnc(inorder, postorder, i_start, i_end-1, p_start, p_end-1);
    else{
        dnc(inorder, postorder, i_start, idx-1, p_start, p_start+idx-1-i_start);
        dnc(inorder, postorder, idx+1, i_end, p_end-i_end+idx, p_end-1);
    }
}
int main(){
    cin >> n;
    int *inorder = new int[n];
    int *postorder = new int[n];
    for(int i=0; i<n; i++) scanf(" %d", inorder+i);
    for(int i=0; i<n; i++) scanf(" %d", postorder+i);
    int start = 0, end = n-1;
    dnc(inorder, postorder, start, end, start, end);
}