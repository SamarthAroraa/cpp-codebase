#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool check(int n,int maze[][20],int r,int c){
	
	return maze[r][c]; 
}


bool run(int n,int maze[][20],int r,int c,std::vector<vector <bool> > &ans ){
for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cerr<<ans[i][j]<< " ";
		}
		cerr<<endl;


	}
if(c==n-1 and r==n-1){
	cerr<<1<<endl;
	ans[n-1][n-1]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<< " ";
		}
		cout<<endl;


	}
	cout<<endl;
	return 1;
}
else if(c>=n or r>=n or c<0 or r<0){


	cerr<<2<<endl;
	return 0;
}
	bool res=0;
	// if(check(n,maze, c, r)){
	// 	ans[r][c]=1;
	// 	if(run(n,maze, r, c+1, ans)){
	// 			return 1;
	// 		}
	// 	ans[r][c]=0;
	// 	ans[r+1][c]=1;
	// 	if(run(n,maze, r+1, c, ans)){
	// 			return 1;
	// 		}
	// 	ans[r+1][c]=0;

	// }
if(maze[r][c] and ans[r][c]==0){
	ans[r][c]=1;
	// maze[r][c]=0/;
	if(run(n,maze,r,c+1,ans)){
		// maze[r][c+1]=0;

		res=1;

	}
	if(run(n,maze,r,c-1,ans)){
		// maze[r][c-1]=0;

		res=1;

	}
	if(run(n,maze,r+1,c,ans)){
		// maze[r+1][c]=0;

		res=1;
	}
	 if(run(n,maze,r-1,c,ans)){
		res=1;
		// maze[r-1][c]=0;


	}
	
	ans[r][c]=0;

	// maze[r][c]=1;
	return res;
	
}



	return res;

	
}
void ratInAMaze(int maze[][20], int n){

std::vector<std::vector<bool> > ans(n, std::vector<bool>(n,0) );
run(n,maze,0,0,ans);


}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int maze[n][20];
	for(int i=0;i<n;i++){for(int j=0;j<n;j++)cin>>maze[i][j];}
	ratInAMaze(maze,n);

return 0;
}