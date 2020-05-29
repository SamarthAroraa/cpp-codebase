#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
#define NMAX 55
using namespace std;
char cake[NMAX][NMAX];
bool visited[NMAX][NMAX];
int x[]={-1,1,0,0};
int y[]={0,0,1,-1};

int rec(int i, int j, int n){
	// visited[i][j]=1;
	if(i>=n or j>=n or i<0 or j<0)
		return 0;
	if(visited[i][j] or cake[i][j]=='0'){
		return 0;
	}
	visited[i][j]=1;
	int total=0;
	for(int k=0;k<4;k++){
		total+=(rec(i+x[k],j+y[k],n));
		deb(x[k])
		deb(y[k])
	}
return total+1;
}
int solve(int n,char cake[NMAX][NMAX]){
	// cerr<<"a\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			visited[i][j]=0;
	}
	int mxsize=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			// cerr<<"c\n";
			if(cake[i][j]=='1' and !visited[i][j]){
				// cerr<<'b'<<endl;
				mxsize= max(mxsize, rec(i,j,n));
			}
		}
	}
return mxsize;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;

return 0;
}