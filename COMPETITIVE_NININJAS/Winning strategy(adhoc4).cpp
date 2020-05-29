#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int swaps(std::vector<int> arr,int n ){
	int swaps=0;
	for(int j=n-1;j>=0;j--){
		if(arr[j]==j+1){
			continue;
		}
		else if(arr[j-1]==j+1){
			swaps+=1;
			swap(arr[j-1],arr[j]);
		}
		else if(arr[j-2]==j+1){
			swaps+=2;
			swap(arr[j-2],arr[j-1]);
			swap(arr[j-1],arr[j]);
		}
		else return -1;
	}
return swaps;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	std::vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k=swaps(arr,n);
	if(k==-1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES\n"<<k<<endl;
	}


return 0;
}