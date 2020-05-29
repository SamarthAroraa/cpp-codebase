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
	    int n;
	    cin>>n;
	    int maxval=INT_MIN;
	    for(int i=0;i<n;i++){
	    	int k;
	    	cin>>k;
	    	maxval=max(k,maxval);
	    }
	cout<<maxval<<endl;
	
	}


return 0;
}