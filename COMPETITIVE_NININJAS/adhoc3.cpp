#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int k=0,l=0;
int minc(std::vector<int> arr, int a){
	int inc=0;
	int dec=0;
	// for(int j=0;j<i;j++){
	// 	inc+=(a-arr[j]);
	// }
	for(int j=0;j<arr.size();j++){
		if(arr[j]>a)
		dec+=(arr[j]- a);
	else
		inc+=(a-arr[j]);	
	}
	if(dec>inc)
		return INT_MAX;
	else {
		return k*(dec) + l*(inc-dec);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n>>k>>l;
	int mini=INT_MAX, maxi= INT_MIN;
	std::vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		// mini= min(mini, arr[i]);
		// maxi= max(maxi, arr[i]);

	}
	sort(arr.begin(),arr.end());
	mini= arr[0];
	maxi=arr[n-1];
	int mincst=INT_MAX;
	for(int i=mini;i<=maxi;i++){
		int temp=mincst;
			mincst= min(mincst, minc(arr, i));
			// if(mincst!=temp){
				deb(arr[i])
					deb(mincst)
			// }

	}
	deb(k)
	deb(l)
	cout<<mincst;



return 0;
}