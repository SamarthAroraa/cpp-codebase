#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void update(int index, int value, int* fenwck,int n){
	for(;index<=n;index+=(index&(-index))){
		fenwck[index]+=value;
	}
}
int query(int index, int* fnwk, int n){
	int sum=0;
	for(;index>0;index-=(index&(-index))){
		sum+=fnwk[index];
	}
	return sum;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int fenwck[n+1];
	for(int i=0;i<=n;i++)
		fenwck[i]=0;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		update(i,arr[i],fenwck,n);
	}
cout<<"SUM OF FIRST 5:"<<query(5,fenwck,n)<<endl;
cout<<"SUM of 2 to 5:"<<query(5,fenwck,n)-query(1,fenwck,n);

return 0;
}