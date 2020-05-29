#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

class Worker{
public:
	ll ti,xi,yi;
	// Worker(ll ti,ll xi,ll yi){
	// 	this->ti=ti;
	// 	this->xi=xi;
	// 	this->yi=yi;
	// }
};
bool timesort(Worker a ,Worker b){
	if(a.ti!=b.ti)
	return a.ti<b.ti;
else if(a.yi!=b.yi)return a.yi>b.yi;
else return a.xi<b.xi;
}

ll mincost(Worker arr[],ll d , ll n){
	sort(arr,arr+n,timesort);
	for(ll i=0;i<n;i++)
		{deb(arr[i].ti)
			deb(arr[i].xi)
			deb(arr[i].yi)
			cerr<<endl;
		}
	ll cost=0;
	// double curratio=(double)arr[0].yi/arr[0].xi;
	ll remaining= d- arr[0].yi;
	cost= arr[0].xi;
	ll curr= arr[0].yi;
		for(ll i=1;i<n;i++){
			if(remaining<=0)
				break;
			if(arr[i].yi>curr){
				curr= arr[i].yi;
				cost+=arr[i].xi;
				
			}
			remaining-=curr;
	}

return cost;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	ll d;
	cin>>d;
	Worker arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i].ti;
		cin>>arr[i].xi;
		cin>>arr[i].yi;
	}
	cout<<mincost(arr, d, n);

return 0;
}