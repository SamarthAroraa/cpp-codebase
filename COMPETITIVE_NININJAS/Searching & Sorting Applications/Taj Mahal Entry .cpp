#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

ll  ans(std::vector<ll > q){
	ll  global_t=INT_MAX;
	ll  shop;
	ll  t;
	ll  n= q.size();
	for(ll  i=0;i<n;i++){
		if(q[i]<=i)
			t=0;
		else if((q[i]-i)%n==0)
		t=(q[i]-i)/n;
	else
		t=(q[i]-i)/n+1;
	// deb(t)
	// deb(i)
	if(t<global_t){
		// deb(global_t)
		global_t=t;
		shop=i+1;
		// deb(global_t)
		// deb(i)
		}
	}
	
	return shop;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  n;
	cin>>n;
	std::vector<ll > q(n);
	for(ll  i=0;i<n;i++){
		cin>>q[i];

	}
	cout<<ans(q);

return 0;
}