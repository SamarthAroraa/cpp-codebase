#include<bits/stdc++.h>
// #include<vector>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll unsigned long long
// using namespace std;



using namespace std; 
  
void SelectActivities(vector<ll>s,vector<ll>f){ 
// Vector to store results. 
    vector<pair<ll,ll> >ans; 

  
// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 
  
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >p; 
  
    for(ll i=0;i<s.size();i++){ 
        // Pushing elements in priority queue where the key is f[i] 
        p.push(make_pair(f[i],s[i])); 
    } 
  
    auto it = p.top(); 
    ll start = it.second; 
    ll end = it.first; 
    p.pop(); 
    ans.push_back(make_pair(start,end)); 
  
    while(!p.empty()){ 
        auto itr = p.top(); 
        p.pop(); 
        if(itr.second > end){ 
            start = itr.second; 
            end = itr.first; 
            ans.push_back(make_pair(start,end)); 
        } 
    } 
    cerr << "Following Activities should be selected. " << endl << endl; 
  	ll count= ans.size();

    for(auto itr=ans.begin();itr!=ans.end();itr++){ 
        cerr << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << endl; 
    } 
    if(count==1)
    	cout<<"-1"<<endl;
   else
   {
   	cout<<s.size()-count<<endl;
   }
} 
  
// Driver program 
int main() 
{ 

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

    vector<ll> s(n);
    vector<ll> f(n);
    for(ll i=0;i<n;i++){
    	cin>>s[i]>>f[i];
    }
    SelectActivities(s,f); 
}
  
    return 0; 
} 