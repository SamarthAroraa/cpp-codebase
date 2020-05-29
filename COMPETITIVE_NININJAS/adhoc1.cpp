#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll mincost(string a,ll flip, ll rev){
	ll len= a.length();
	ll n=0;
	if(a[0]=='0' and a[1]=='1')
		n++;
	for(ll i=1;i<len;i++){
		if(a[i-1]!='0' and a[i]=='0'){
			n++;
		}
	}

deb(n)
deb(flip)
deb(rev)
return min(n*flip, (n-1)*rev + flip);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	string bin;
	ll x,y;
	cin>>x>>y;
	cin>>bin;
	
	cout<<mincost(bin,y,x);

return 0;
}