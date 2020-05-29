#include<bits/stdc++.h>
// #define deb(x) cerr<<#x<<" "<<x<<endl;

using namespace std;
// void ans(int arr[], int n, int p){
// 	int e=0;
// 	// int o=0;
// 	for(int i=0;i<n;i++){
// 		if(((__builtin_popcountll(arr[i]^p))&1)==0)
// 			e++;
// 	}
// 	cout<<e<< " "<<n-e<<endl;
// }
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int ele;
		int e=0,o=0;
		for(int i=0;i<n;i++){
			cin>>ele;
			if(!(__builtin_parity(ele)))
				e++;
			
		}
		o= n-e;
	
	for(int i=0;i<q;i++){
		int p;
		cin>>p;
		if(!(__builtin_parity(p))){
			cout<<e<<" "<<o<<endl;
		}
		else{
			cout<<o<<" "<<e<<endl;
		}
	}
}

return 0;
}