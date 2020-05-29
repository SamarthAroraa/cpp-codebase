#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};
int visited[MAXN][MAXN];

bool eligible(char board[][MAXN], int n, int m, int i, int j, char curr){
    if(i>=0 && j>=0 && i<n && j<m && board[i][j]==curr)
        return true;
    return false;
}

int path_helper(char board[][MAXN], int n, int m, int i, int j, int fromx, int fromy, char curr){
    if(i>n || j>m)
        return 0;
    if(visited[i][j] == 1)
        return 1;
    if(board[i][j] != curr)
        return 0;

    visited[i][j] = 1;
    for(int k = 0 ; k < 4 ; k++){
        int dx = i + xdir[k];
        int dy = j + ydir[k];
        if(eligible(board,n,m,dx,dy,curr) && (dx!=fromx || dy!=fromy)){
            if(path_helper(board, n, m, dx, dy, i, j, curr) == 1)
                return 1;
        }
    }
    return 0;
}

int solve(char board[][MAXN],int n, int m)
{
    int ans = 0;
    memset(visited,0,sizeof(visited));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visited[i][j] != 1){
                char curr = board[i][j];
                ans = path_helper(board, n, m, i, j, -1, -1, curr);
                if(ans==1)
                    return 1;
            }
        }
    }
    return ans;
}

int main()
{
	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
	
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}