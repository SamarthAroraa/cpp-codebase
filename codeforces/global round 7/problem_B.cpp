#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void make_a(ll b[],std::vector<ll>&a,int n ){
	// ll n= b.size();
	a[0]=b[0];
	ll global_max=max(a[0],(ll)0);
	for(ll i=1;i<n;i++){
		a[i]=(global_max+b[i]);
		cout<<a[i]<<" ";
		global_max= max(global_max,a[i]);
		deb(global_max)
		deb(b[i])
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;

	ll b[n];
	for(ll i=0;i<n;i++){
		cin>>b[i];
		cerr<<b[i]<<" ";
	}
	std::vector<ll> a(n);
	make_a(b,a,n);

return 0;
}