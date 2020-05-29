#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

ll findSubarraySum(ll arr[], ll n, ll sum) 
{ 
    
    unordered_map<ll, ll> prevSum; 
  
    ll res = 0; 
  
    ll currsum = 0; 
  
    for (ll i = 0; i < n; i++) { 
  
        
        currsum += arr[i]; 
  
        if (currsum == sum)  
            res++;         
  
        if (prevSum.find(currsum - sum) !=  
                                  prevSum.end())  
            res += (prevSum[currsum - sum]); 
          
  
        prevSum[currsum]++; 
    } 
  
    return res; 
} 
  
int main(){
	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
		
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
	ll po2[n];
	for(ll i=0;i<n;i++){
		ll count=0;
		ll temp=arr[i];
		while(temp%2==0 and temp!=0){
			count++;
			temp/=2;
		}
		po2[i]=count;
		// cerr<<po2[i]<<" ";
	}
	// cerr<<"\n";
	int total=n*(n+1)/2;
	ll k=findSubarraySum(po2,n,1);
	cout<<total-k<<"\n";
	total=0;
}

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}