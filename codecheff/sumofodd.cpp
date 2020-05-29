#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void solve(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		if(n==2 or k>sqrt(n)){
			cout<<"NO\n";
			continue;
		}
		if((((k&1)==0) and ((n&1)==0)) or (((k&1)!=0) and ((n&1)!=0)))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	solve();

return 0;
}