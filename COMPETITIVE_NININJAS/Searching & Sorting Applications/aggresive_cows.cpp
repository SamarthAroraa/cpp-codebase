#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

bool check(std::vector<ll> stalls,ll  d, ll  c){
	
	ll  count=1;
	ll  prev=stalls[0];
	for(ll  i=1;i< stalls.size();i++){
		if(stalls[i]-prev>=d){
			count++;
			prev= stalls[i];
			deb(prev)
			deb(d)
		}
		if(count==c)
			return true;
	}
	deb(c)

	return 0;
// else return 1;
}
ll  binary_s(std::vector<ll> stalls, ll  c){
	ll  low, high;
	sort(stalls.begin(), stalls.end());
	// deb(stalls[0])
	// deb(stalls[stalls.size()-1])
	low=stalls[0];high=stalls[stalls.size()-1]-stalls[0];
	// deb(low)
	// deb(high)
	ll  mid; 
	ll ans=-1;
	while(low<=high){
		deb(low)
		deb(high)
		mid=(low+high)/2;
		if(check(stalls,mid,c)){
			low= mid+1;
			ans=mid;

		}
		else{
			high= mid-1;
		}
	}
return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  t;
	cin>>t;
	while(t--){
	ll  n;
	cin>>n;
	ll  c;
	cin>>c;

	std::vector<ll> stalls(n);
	for(ll  i=0;i<n;i++)
		cin>>stalls[i];


cout<<binary_s(stalls,c)<<endl;
}
return 0;
}