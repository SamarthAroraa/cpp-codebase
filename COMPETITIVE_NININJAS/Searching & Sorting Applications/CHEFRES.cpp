#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll  waiting(std::vector<pair <ll , ll > > times, ll  p_i){
	ll  n= times.size();

	// ll  wait=INT_MAX;
	// for(ll  i=0;i<n;i++){
	// 	if(p_i>=times[i].first and p_i < times[i].second){
	// 		return 0;
	// 	}
	// 	else if(p_i< times[i].first){
	// 		wait= min(wait, times[i].first - p_i);
	// 	}
	// }
	int pos= lower_bound(times.begin(), times.end(), make_pair(p_i,(ll)0))-times.begin();
	cerr<<pos<<endl;
	if(pos==0)
		return times[0].first - p_i;
	if(times[pos-1].second > p_i) 
		return 0;
	if(pos==n){
		return -1;
	}
	return times[pos].first-p_i;
// return wait;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  t;
	cin>>t;
	while(t--){ 
		ll  n,m;
		cin>>n>>m;
		std::vector<pair <ll ,ll > > times(n);
		for(ll  i=0;i<n;i++){
			ll  l,r;
			cin>>l>>r;
			times.push_back(make_pair(l,r));
		}
		sort(times.begin(), times.end());

		// std::vector<ll > arrivals(m);
		for(ll  i=0;i<m;i++){
			ll  p_i;
			cin>>p_i;
			cout<<waiting(times,p_i)<<endl;
		}
	
	}

return 0;
}