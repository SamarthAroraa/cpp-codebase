#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll binsrch(std::vector<ll> prefix_sum,ll budget){
	ll  n = prefix_sum.size();
	ll  s=0,e=n-1,mid;
	while(s<=e){
		mid = ceil((s+e)/2.0);
		if(prefix_sum[mid]<=budget and prefix_sum[mid+1]>budget){
			return mid;
		}
		else if(prefix_sum[mid]>budget){
			e= mid-1;
		}
		else {
			s= mid;
		}
	}
	cout<<"nf"  ;
return e;}
void answer(std::vector<ll> prefix_sum, ll budget){
	// ll n= prices.size();
	ll idx= binsrch(prefix_sum, budget);
	// idx--;
	deb((idx))
	deb(budget)
// 	if((idx- prefix_sum.begin() + 1)!=0){
// 	cout<<(idx- prefix_sum.begin() + 1)<< " "<< budget - *(idx) <<endl;
// }
// else{
// 	cout<<0<<" "<< budget<<endl;
// 	cerr<<*(idx)/budget<<" "<< *idx%budget<<endl;
	// cout<<0<<" "<< budget<<endl;

	// ll momo=0; 

	// ll i=0;
	// while(i<n ){
	// 	if(budget>=prices[i]){
	// 		budget-=prices[i];
	// 		momo++;
	// 		i++;

	// 	}
	// 	else break;

	// }
	// cout<<momo<<" "<<budget<<endl;
	// if(idx!=prefix_sum.size()-1)
	if (budget<prefix_sum[0]){
		cout<<0<<" "<<budget<<endl;

	}
	else	
		cout<<idx+1<<" "<<(budget - prefix_sum[idx])<<endl;
	

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	std::vector<ll> prices(n);
	std::vector<ll> prefix_sum(n);
	cin>>prices[0];
	prefix_sum[0]=prices[0];
	deb(prefix_sum[0])

	for(ll i=1; i<n;i++){
		cin>>prices[i];
		prefix_sum[i]=prefix_sum[i-1]+ prices[i];
		deb(prefix_sum[i])
	}

	ll q;
	cin>>q;
	for(ll i=0;i<q;i++){
		ll budget;
		cin>>budget;
		answer(prefix_sum,budget);
	}


return 0;
}