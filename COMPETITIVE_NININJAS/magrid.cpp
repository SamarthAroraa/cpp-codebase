#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void print(int **grid,int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cerr<<grid[i][j]<<" ";
		}
	cerr<<endl;
}
cerr<<"************************\n";}

int magic_grid(int ** grid, int r,int c){
	int **dp= new int*[r];
	for(int i=0;i<r;i++){
		dp[i]= new int[c];
	}

// memo pad initialization
dp[r-1][c-1]=1;
for(int j=r-2;j>=0;j--){
	if(dp[j+1][c-1] - grid[j+1][c-1]>0)
	dp[j][c-1]=dp[j+1][c-1] - grid[j+1][c-1];
	else 
		dp[j][c-1]= 1;
	}
	
	for(int j=c-2;j>=0;j--){
	if(dp[r-1][j+1] - grid[r-1][j+1]>0)
	dp[r-1][j]=dp[r-1][j+1] - grid[r-1][j+1];
	else 
		dp[r-1][j]= 1;
}
for(int i= r-2;i>=0;i--){
	for(int j=c-2;j>=0;j--){
		int choice1= min(dp[i+1][j]-grid[i+1][j], dp[i][j+1]- grid[i][j+1]);
		int choice2= max(dp[i+1][j]- grid[i+1][j], dp[i][j+1]- grid[i][j+1]);
		if(choice1>0)
			dp[i][j]= choice1;
		// else if(choice2>0)
		// 	dp[i][j]= choice2;
		else 
			dp[i][j]=1;

	}
	print(dp,r,c);
}
if(dp[0][0]!= INT_MAX)
return dp[0][0];
else return -1;


}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
int t;
cin>>t;
while(t--){
	int r,c;
	cin>>r>>c;
	int ** grid= new int*[r];
	for(int i=0;i<r;i++){
		grid[i] = new int[c];
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>grid[i][j];
		}
	}
	cout<<magic_grid(grid,r,c)<<endl;
}
return 0;
}