#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

int n;
cin>>n;
int maxi=INT_MIN;
int max_i=0;
int e;
int arr[n];
for(int i=0;i<n;i++){
cin>>e;
arr[i]=e;
}
int mxprofit=INT_MIN;
for(int i=0;i<n;i++){
	int mini=INT_MAX;
	for(int j=0;j<i;j++){
		if(arr[j]<mini){
			mini=arr[j];
		}
		if(arr[i]-mini>mxprofit){
			mxprofit=arr[i]-mini;
		}
	}
}
cout<<mxprofit<<endl;
return 0;
}