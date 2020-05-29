#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

void print(int** matrix,ll numDenominations, ll value)
{
	for(ll i=0;i<=numDenominations;i++){
		for(ll j=0;j<=value;j++){
			cout<<matrix[i][j]<< " ";
		}
	cout<<endl;
}
}
ll ways(ll denominations[], ll numDenominations, ll value){
	ll **matrix= new int*[numDenominations+1];
	for(ll i=0;i<=numDenominations;i++){
		matrix[i]= new int[value+1];
	}
	matrix[0][0]=1;
	for(ll i=1;i<=numDenominations;i++){
		matrix[i][0]=1;
	}
	for(ll i=1;i<=value;i++){
		matrix[0][i]=0;
	}
	for(ll i=1;i<=numDenominations;i++){
		for(ll j=1;j<=value;j++){
			if(i>j){
				matrix[i][j]= matrix[i-1][j];
			}
			else{

				matrix[i][j] = matrix[i-1][j]+ matrix[i][j-i];
			}
		}
	print(matrix, numDenominations,value);}
	
ll val=matrix[numDenominations][value];
for(ll i=0;i<numDenominations+1;i++){
	delete [] matrix[i];
}
delete []matrix;
return (val);
}
int main(){
	#ifndef ONLINE_JUDGE2

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	ll denom[n];
	for(ll i=0;i<n;i++){
		cin>>denom[i];
	}
	ll val;
	cin>>val;
	cout<<ways(denom, n, val)<<endl;

return 0;
}