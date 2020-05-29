#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int numofAP(int *arr, int N){
sort(arr,arr+N);

unordered_map<int,int> freq[N];
int ans=N+1;
for(int i=N-2;i>=0;i--){
	for(auto m:freq[i+1]){
		freq[i][m.first]= m.second;
		cerr<<freq[i][m.first]<<" "<<freq[i][m.second]<<"\n";
	}
	cerr<<"-----\n";
	for(int j=i+1;j<N;j++){
		int diff= arr[j] - arr[i];
		if(freq[i].count(diff)==0){
			freq[i][diff]=1;
			ans++;
		}
		else{
			freq[i][diff]++;
			ans+=freq[i][diff];
		}
	}
	for(auto m:freq[i]){
		cerr<<m.first<<" "<<m.second<<"\n";
	}
	cerr<<"\n";
}
return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	int * arr= new int[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	cout<<numofAP(arr,N);
	



	 
return 0;
}