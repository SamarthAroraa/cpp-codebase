#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
#define MAXN 102
using namespace std;
const string target="CODINGNINJA";

// void getcoord(char Graph[][MAXN], int i,int j,int&x, int&y,int index, int M, int N,bool visited[MAXN][MAXN]){


// 	//upcheck
// 	if(i!=0){
// 	if(Graph[i-1][j]==target[index] and !visited[i-1][j]){
// 		x=i-1;
// 		y=j;
// 		cerr<<1<<endl;

// 		return;
// 			}
// 	}
// 	//up left diagonal check
// 	if(i!=0 and j!=0){
// 	 if(Graph[i-1][j-1]== target[index] and !visited[i-1][j-1]){
// 		x=i-1;
// 		cerr<<2<<endl;
// 		y=j-1;
// 		return;
// 	}
// 	}
// 	//right check
// 	 if(j!=M-1){
// 		if(Graph[i][j+1]==target[index] and !visited[i][j+1]){
// 			x=i;
// 			y=j+1;
// 		cerr<<3<<endl;

// 			return;
// 		}
// 	}
// 	//bottom right diagonal check
			

// 	if(j!=M-1 and i!=N-1){
// 		if(Graph[i+1][j+1]==target[index] and !visited[i+1][j+1]){
// 			x=i+1;
// 		cerr<<4<<endl;
// 			y=j+1;
// 			return;
// 		}
// 	}
// 	//bottom check
// 	if(i!=N-1){
// 		if(Graph[i+1][j]==target[index] and !visited[i+1][j]){
// 			x=i+1;
// 			y=j;
// 		cerr<<5<<endl;

// 			return;
// 		}
// 	}
// 	//bottom left diagonal check
// 	if(j!=0 and i!=N-1){
// 		if(Graph[i+1][j-1]==target[index] and !visited[i+1][j-1]){
// 			x=i+1;
// 			y=j-1;
// 		cerr<<6<<endl;

// 			return;
// 		}
// 	}
// 	//left check
// 	if(j!=0 ){
// 		if(Graph[i][j-1]==target[index] and !visited[i][j-1]){
// 			x=i;
// 		cerr<<7<<endl;
// 			y=j-1;
// 			return;
// 		}
// 	}
// 	//up right diagonal check
// 	if(j!=M-1 and i!=0){
// 		if(Graph[i-1][j+1]==target[index] and !visited[i-1][j+1]){
// 			x=i-1;
// 		cerr<<8<<endl;

// 			y=j+1;
// 			return;
// 		}
// 	}
// 	cerr<<9<<endl;
// 	return;
// }





bool recursive(char Graph[][MAXN], int i, int j,int index,int N, int M, bool visited[MAXN][MAXN]){
	visited[i][j]=1;
	if(index==target.length())
		return true;
	int x=-1,y=-1;
	if(i!=0){
	if(Graph[i-1][j]==target[index] and !visited[i-1][j]){
		x=i-1;
		y=j;
		// cerr<<1<<endl;
		if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
			}
	}

	//up left diagonal check
	if(i!=0 and j!=0){
	 if(Graph[i-1][j-1]== target[index] and !visited[i-1][j-1]){
		x=i-1;
		// cerr<<2<<endl;
		y=j-1;
		if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
			}
		// return;
	}
	//right check
	 if(j!=M-1){
		if(Graph[i][j+1]==target[index] and !visited[i][j+1]){
			x=i;
			y=j+1;
		cerr<<3<<endl;
		if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
			}

			// return;
		}
	

	//bottom right diagonal check
			

	if(j!=M-1 and i!=N-1){
		if(Graph[i+1][j+1]==target[index] and !visited[i+1][j+1]){
			x=i+1;
		cerr<<4<<endl;
			y=j+1;
			if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
			}
		}

		//bottom check
	if(i!=N-1){
		if(Graph[i+1][j]==target[index] and !visited[i+1][j]){
			x=i+1;
			y=j;
		cerr<<5<<endl;
			if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
			
		}
	}

	if(j!=0 and i!=N-1){
		if(Graph[i+1][j-1]==target[index] and !visited[i+1][j-1]){
			x=i+1;
			y=j-1;
		cerr<<6<<endl;
			if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
		}
	}
	
	if(j!=0 ){
		if(Graph[i][j-1]==target[index] and !visited[i][j-1]){
			x=i;
		cerr<<7<<endl;
			y=j-1;
			if(recursive(Graph,x,y,index+1,N,M,visited))
			return true;
		}
	}
	if(j!=M-1 and i!=0){
		if(Graph[i-1][j+1]==target[index] and !visited[i-1][j+1]){
			x=i-1;
		cerr<<8<<endl;

			y=j+1;
			if(recursive(Graph,x,y,index+1,N,M,visited))
				return true;		}
	}

	// getcoord(Graph, i,j,x,y,index,M,N,visited);
	
		visited[i][j]=0;
		return false;
	



}
int solve(char Graph[][MAXN],int N, int M)
{
	//step 1: find 'C'
	bool visited[MAXN][MAXN];

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(Graph[i][j]=='C')
			{
				cerr<<'a'<<endl;
				if(recursive(Graph, i,j,1,N,M,visited))
					return 1;
			}
		}
	}
return 0;
}

int main()
{	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}


