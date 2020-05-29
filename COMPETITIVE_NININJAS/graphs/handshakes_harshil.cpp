#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

ll main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	ll k=3,m=4;
	// k is number of people who do not like every1
	// m is the number of people each of the k people dislikes
	std::vector<unordered_set<int> > liking_list(n+1);
	//constructing the list of all the people who cannot shake hands
	for(ll i=0;i<k;i++){
		ll number;
		cin>>number;
		for(ll j=0;j<m;j++){
			ll second;
			cin>>second;
			//access that friend's liking list and add the disliked person
			liking_list[number].insert(second);
			//also add the first person to the 2nd person's list coz he can't shake hands with the first either
			liking_list[second].insert(number);
		}
	}
ll ans=0;
//calculating list by N c 2 formula
for(ll i=1;i<=n;i++){
	ll set_size= liking_list[i].size();
	//set size is basically the number of people he cannot shake hands with
	deb(i)
	deb(set_size)
	ans+=(n-set_size)*(n-set_size-1)/2;

}
ans/=2; //kyunki jab a to b ka shake add karenge to wo b to a mein firse count ho jaega
cout<<ans<<"\n";


return 0;
}