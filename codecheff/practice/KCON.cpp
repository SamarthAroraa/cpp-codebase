
#include<bits/stdc++.h>
#include <algorithm>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
 

ll  kadane(ll arr[], ll  n)
{
	ll  global_max=INT_MIN;
	ll  currmax=0;
	for(ll  i=0;i<n;i++){
		currmax = currmax+arr[i];
		// deb(currmax)
		global_max= max(global_max,currmax);
        
        if(currmax<0)
            currmax = 0;
	}
return global_max;
}

ll  bss(ll arr[], ll  n){
	ll  cur_sum=0;
	ll  max_sum=INT_MIN;
	for(int i=n-1;i>=0;i--){
		cur_sum+=arr[i];
		max_sum=max(cur_sum,max_sum);
	}
return max_sum;

}

ll  bps(ll arr[], ll  n){
	ll  cur_sum=0;
	ll  max_sum=INT_MIN;
	for(int i=0;i<n;i++){
		cur_sum+=arr[i];
		max_sum=max(cur_sum,max_sum);
	}
return max_sum;
}
int  main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  t;
	cin>>t;
	while(t--){
		ll  n,k;
		cin>>n>>k;
		ll  sum=0;
		ll arr[n];
		for(ll  j=0;j<n;j++){
			cin>>arr[j];
			sum+=arr[j];
		}
		if(k==1){
			cout<<kadane(arr,n)<<endl;
		}
		else if(sum<0){
			cout<<max(bss(arr,n)+bps(arr,n), kadane(arr,n))<<endl;

		}
		else{
			
			cout<<max(bss(arr,n)+bps(arr,n)+ (k-2)*sum, kadane(arr,n))<<endl;
		}

		deb(kadane(arr,n))
		deb(bps(arr,n))
		deb(bss(arr,n))
		// cerr<<k<<endl;
		// delete [] arr;
	}


return 0;
}