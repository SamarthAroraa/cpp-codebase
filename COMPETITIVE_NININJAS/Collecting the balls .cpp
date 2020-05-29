#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool check(ll k, ll n){
	ll curr=n;
	ll sum=0;
	while(curr>0){
		sum+=(min(k,curr));
		curr-=min(k,curr);
		curr-=(curr/10);
		// deb(sum)
		// deb(curr)
	}
	if(sum>=n/2.0)
		return 1;
	return 0;
}

ll search(ll n)
{
	ll high=n,low=1;
	ll mid;
	while(low<=high){
		mid=floor((high+low)/2.0);
		deb(high)
			deb(low)
			deb(mid)

			if(high==low or mid==high or mid==low)
				break;
		if(check(mid,n))
			{
				high=mid;
			}
			else{
				low = mid + 1;
			}

	}
	return mid;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    ll n;
    cin>>n;

	cout<<search(n);

	

return 0;
}