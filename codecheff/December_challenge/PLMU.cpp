#include<bits/stdc++.h>
#include<unordered_map>
#define ll unsigned long long
using namespace std;
// ll x=1000000000;
// ll compute_y(ll x){
// 	// float c=x/(x-1);
// 	// ll k= c;
// 	// cerr<<c-k<<" "<<x<<endl;
// 	ll j=x-1;
	
// 	cerr<<x%(j)<<" "<< endl;
// 	if(x%(j)==0){
// 		// coue

// 		ll y=x/(x-1);
// 		return y;
// 	}
// 	else return -1;
// }

long pairs(std::vector<ll> v){
	// cerr<<compute_y(1000000000);
	long ans=0;
	// unordered_map<ll,bool> done;

	unordered_map<ll,int> freq;
	int n=v.size();
	for(int i=0;i<n;i++){
		freq[v[i]]++;
	}

	// for(int i=0;i<n;i++){
	// 	if(!done[v[i]]){
	// 		done[v[i]]=1;
	// 	if(v[i]==1) continue;
	// 	ll y=compute_y(v[i]);
	// 	cerr<<y<<" "<<v[i]<<endl;
	// 	if(y!=-1){
	// 		ans+=freq[y];
	// 		if(y==v[i]) ans--;	
	// 	}
	// }
		
	// }
	ans= freq[0]*(freq[0]-1)/2 + freq[2]*(freq[2]-1)/2;

return ans;
}


// long pairs(std::vector<ll> v){
// //O(n^2)
// long ans=0;	
// 	unordered_map<ll,bool> done;
// 	for(int i=0;i<v.size();i++){
// 		if(!done[v[i]]){
// 			done[v[i]]=1;
// 		int j=i-1;
// 		if(i!=0){
// 			// j=0;
		
// 		while(j>=0){
// 				cerr<<v[j]*v[i]<<" "<<v[j]+v[i]<<endl;

// 			if(v[j]*v[i]==v[j]+v[i]){
// 				ans++;
// 			}
// 		j--;
// 	}
// }
//  j=i+1;
//  if(i!=v.size()-1){
// 		while(j<v.size()){
// 			if(v[j]*v[i]==v[j]+v[i]){
// 				ans++;
// 			}
// 		j++;
// 	}
// }
// }
// 	}
// return ans;
// }
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<ll> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
	cout<<pairs(v)<<endl;

	}
return 0;

}
