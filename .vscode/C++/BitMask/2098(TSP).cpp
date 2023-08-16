#include <bits/stdc++.h>
#define INF 1e9 
using namespace std; 

int N, cnt;
int cost[16][16];
int dp[16][1 << 16]; 

int travel(int curr, int visited_bit){
	if(visited_bit == cnt){
		if(cost[curr][0])
			return cost[curr][0];
		return INF; 
	}

	if(dp[curr][visited_bit] != 0) return dp[curr][visited_bit];

	dp[curr][visited_bit] = INF; 
	for(int i = 0; i < N; i++){
		if(cost[curr][i] == 0 || (visited_bit & (1 << i))) continue;

		int temp = travel(i, visited_bit | 1 << i); 
		dp[curr][visited_bit] = min(dp[curr][visited_bit], cost[curr][i] + temp); 
	}
	return dp[curr][visited_bit];
}

int main(){ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N;
	cnt = (1 << N) - 1;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> cost[i][j]; 
	
	memset(dp, 0, sizeof(dp));
	cout << travel(0, 1); 
}