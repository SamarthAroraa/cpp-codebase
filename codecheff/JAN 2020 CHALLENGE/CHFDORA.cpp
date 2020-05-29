#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

bool check(ll i, std::vector< std::vector<ll> > matrix, ll n, ll m, ll x,ll y){
	if(x-i >-1 and x+i<m and y+i<n and y-i>-1 ){
		if(matrix[y][x-i]== matrix[y][x+i] and matrix[y+i][x]== matrix[y-i][x])
			return 1;
	}
			
	
	return 0;
}

ll ans(std::vector< std::vector< ll> > matrix, ll n, ll m){
	ll count=m*n;
	for(ll y=1;y<n-1;y++){
		for(ll x=1;x<m-1;x++){
			ll i=1; 
			while(check(i,matrix,n,m,x,y)){
				i++;
			count++;
		}
		}
	}
return count;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		std::vector<std::vector<ll> > matrix(n, std::vector<ll> (m));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				cin>>matrix[i][j];
			}

		}
		cout<<ans(matrix,n,m)<<endl;
	}

return 0;
}