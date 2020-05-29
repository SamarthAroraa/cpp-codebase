#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


void print(int **matrix,int numDenominations, int value)
{
	for(ll i=0;i<numDenominations;i++){
		for(ll j=0;j<value;j++){
			cout<<matrix[i][j]<< " ";
		}
	cout<<"\n";
}
cout<<"******************\n";
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int m,n;
	cin>>m>>n;
	int** arr= new int*[m];
	for(int i=0;i<m;i++){
		arr[i]= new int[n];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	cout<<zero_square(arr,m,n);

return 0;
}