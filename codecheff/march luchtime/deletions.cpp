#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll maxgood(string str, ll k, ll x){
	unordered_map<char, int> freq;
	ll n=str.length();
	ll good=0;
	for(ll i=0;i<n;i++){
		freq[str[i]]++;
		if(freq[str[i]]>x){
			if(k==0)
				break;
			else{
				k-=1;
				continue;
			}
		}
		good++;

	}
	return good;
}
ll main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		ll k,x;
		cin>>k>>x;
		cout<<maxgood(str,k,x)<<"\n";
	}

return 0;
}