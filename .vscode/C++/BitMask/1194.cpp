#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tup;
int n, m;
char maze[51][51];
int x_diff[4] = {1, -1, 0, 0};
int y_diff[4] = {0, 0, 1, -1};
bool visited[51][51][1<<6];
int in_bounds(int r, int c){
    return ((r>=0 && r<n) && (c>=0 && c<m));
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> maze[i];
    
    int start_x, start_y;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j] == '0'){
                start_x = i, start_y = j;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    queue<tup> que; que.push(make_tuple(start_x, start_y, 0, 0));
    visited[start_x][start_y][0] = 1;
    while(!que.empty()){
        tup temp = que.front();
        int x = get<0>(temp);
        int y = get<1>(temp);
        int cnt = get<2>(temp);
        int keys = get<3>(temp);
        que.pop();

        if(maze[x][y] == '#') continue;
        else if(maze[x][y] == '1'){
            cout << cnt;
            return 0;
        }
        else if(maze[x][y] >= 'a' && maze[x][y] <= 'f'){
            keys |= (1<<(maze[x][y] - 'a'));
        }
        else if(maze[x][y] >= 'A' && maze[x][y] <= 'F'){
            if((keys & (1<<(maze[x][y] - 'A'))) == 0) continue;
        }
        for(int i = 0; i<4; i++){
            if(in_bounds(x+x_diff[i], y+y_diff[i]) && (visited[x+x_diff[i]][y+y_diff[i]][keys] == 0) && (maze[x+x_diff[i]][y+y_diff[i]] != '#')){
                que.push(make_tuple(x+x_diff[i], y+y_diff[i], cnt+1, keys));
                visited[x+x_diff[i]][y+y_diff[i]][keys] = 1;
            } 
                
        }
    }
    cout << -1;
}