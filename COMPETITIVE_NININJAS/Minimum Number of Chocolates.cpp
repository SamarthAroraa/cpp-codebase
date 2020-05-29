#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int getMin(int *arr, int n){
   // sort(arr,arr+n);
   // for(int i=0;i<n;i++){
   // 	cout<<arr[i]<<" ";
   // }
   int sum=0;
   int choc[n];
   choc[0]=1;
   // sum+=choc[0];
   for(int i=1;i<n;i++){
   	if(arr[i]>arr[i-1]){
   		choc[i] = choc[i-1]+1; 
   	}
   	else{
   		choc[i]= 1;
   	}
   	// deb(i)
   	// deb(choc[i])
   	// sum+=choc[i];
   }
for(int i=n-2;i>=0;i--){
   	if(arr[i]>arr[i+1] and choc[i]<=choc[i+1]){
   		choc[i] = choc[i+1]+1; 
   	}
   	sum+=choc[i];
   	// deb(i)
   	// deb(choc[i])
   	// sum+=choc[i];
   }

return sum+choc[n-1];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	int*arr= new int[n];
	for(int i=0;i<n;i++){
   	cin>>arr[i];
   }
   int k= getMin(arr,n);
   cout<<k;
return 0;
}