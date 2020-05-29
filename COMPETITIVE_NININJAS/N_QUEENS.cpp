#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool safe(int n,vector<std::vector<int> > &board,int c,int r){
 deb(c)
 deb(r)
 // cerr<<endl;
	//rhorixontal atack
	for(int i=0;i<c;i++){
		if(board[r][i]==1)
			return 0;
	}

	// diagonal check
	int j=c-1, i=r-1;
	while(j>=0 and i>=0){
		
		if(board[i][j]==1)
			return 0;
		j--;
		i--;
	}
	j=c-1;i=r+1;
	while(j>=0 and i<n){
		
		if(board[i][j]==1)
			return 0;
	j--;
	i++;
	}
return 1;

}



bool place(int n,int c, std::vector<vector <int> >& board){
if(c>=n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		// cout<<endl;
	}
		cout<<endl;


return 1 ;
}
bool res=0;

for(int i=0;i<n;i++){

	// deb(safe(n,board,c,i))
if(safe(n,board,c,i) ) {

	board[i][c]=1;

	cerr<<endl;
	
	if(place(n,c+1,board))
	 	res=1;

	board[i][c]=0;
	

}

// board[i][c]=0;

}
return res;

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	    vector<vector<int> > board( n , vector<int> (n, 0));  

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	place(n,0,board);

return 0;
}






