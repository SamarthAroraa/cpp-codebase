
#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
  
   
// Function to return LCM of two numbers  
  ll lcm(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }  


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
	ll n,m;
	cin>>n>>m;
	std::vector<ll > arr(n);
	ll dynlcm=1;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		dynlcm=lcm(dynlcm,arr[i]);
	}
	// deb(dynlcm)
	ll candidate=1;
	for(ll k=1;k<=m;k++){
		if(lcm(k,dynlcm)>dynlcm){
			candidate=k;
		}
	}
	cout<<candidate<<"\n";
	// deb(lcm(candidate,dynlcm))
}

return 0;
}

