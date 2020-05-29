#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll gcd(ll a, ll b){
	if(b==0)
		return a;
	if(a<b){
		return gcd(b,a);
	}
	return gcd(b,a%b);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--){
	ll a;string b;
	cin>>a>>b;
	ll total=(b[0]-'0')%a;
	// deb(b[0]-'0')
	for(ll i=1;i<b.length();i++){
		total= ((ll)(total*10)%a + (ll)(b[i]-'0') % a) %a;
	}
	deb(total)

	cout<<gcd(a,total)<<"\n";
}


	 
return 0;
}