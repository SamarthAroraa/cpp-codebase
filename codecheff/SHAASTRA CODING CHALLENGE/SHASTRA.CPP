#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
ll t;

cin>>t;
while(t--){
	ll n;
	cin>>n;
	ll pairs=0;
	std::vector<ll> ast(n);
	for(ll i=0;i<n;i++){
		cin>>ast[i];
	}
	    sort(ast.begin(), ast.end(), greater<ll>()); 

	   for(ll i=0;i<n;i++){
	   	float half=ast[i]/2.0;
	   	cerr<<half<<endl;
	   	ll j=i+1;
	   	while(ast[j]>=half and j<n){
	   		// cerr<<ast[j]<< " " <<ast[i]<< " "<<half<<endl;
	   		j++;
	   		pairs++;
	   	}  
	   }
cout<<pairs<<endl;
}

return 0;
}