#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int temp;
	cin>>t;
	temp=t;
	while(t--){
		int n;
		cin>>n;
		int p=0;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		for(int i=1;i<n-1;i++)
		{
			if(arr[i]> arr[i-1] and arr[i]>arr[i+1]){
				p++;
				deb(arr[i])
			}
		}
	cout<<"Case #"<<temp-t<<": "<<p<<"\n";
	}
	



	 
return 0;
}