#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


ll  merge(ll  arr[], ll  left, ll  m, ll  right){
	ll  temp[right-left+1];
	
	int left_s=0;
	ll  total=0;
	ll  i=left,j=m,k=0;
	while(i<m and j<right+1 ){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i];
			left_s+=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
			total+= left_s;

		}
	}
	while(i<m){
		temp[k++]=arr[i++];
	}
	while(j<right+1){
		temp[k++]=arr[j++];
		total+=left_s;

	}
	
	for(ll  i=left,k=0;i<=right;i++,k++){
		arr[i] = temp[k];
	}
	for(ll  i=0;i<k;i++){
		cerr<<temp[i]<<" ";
	}
	deb(total)
	cerr<<endl; 
	return total;


}

ll  mergeSort(ll  A[],ll  l, ll  r){

	if(r>l){
		ll  m= (l+r)/2;
		ll  inv_r= mergeSort(A,m+1,r);
		ll  inv_l=mergeSort(A,l,m);
		ll  self=merge(A,l,m+1,r);

	// cerr<<inv_l + inv_r + self<<endl;
	
	return inv_l + inv_r + self;
}
return 0;
}

long long solve(ll  A[], ll  n)
{
	ll  inversions= mergeSort(A,0,n-1);
return inversions;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		cout<<solve(arr,n)<<endl;

	}
return 0;
}