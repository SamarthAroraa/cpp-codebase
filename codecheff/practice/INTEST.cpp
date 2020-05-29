#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
	ll n,k;
	ll count=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{	ll num;
	cin>>num;
	if(num%k==0){
		count++;
	}

	}

cout<<count<<endl;
}
return 0;
}

