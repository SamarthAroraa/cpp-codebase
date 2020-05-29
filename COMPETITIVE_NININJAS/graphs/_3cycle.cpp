#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int solve(int n,int m,vector<int>u,vector<int>v){
	int Graph[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Graph[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		Graph[u[i]-1][v[i]-1]=1;
		Graph[v[i]-1][u[i]-1 ]=1;
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){			
			if(Graph[i][j]==1){

				for(int k=0;k<n;k++){

					if(k==i or k==j)
						continue;
					if(Graph[j][k]){
						if(Graph[k][i]){
							count++;
							
						}
					}
				}
			}
		}
	}


return count/5;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;

return 0;
}