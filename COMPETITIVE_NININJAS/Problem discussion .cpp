#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int mindiff(int arr[], int n, int k){
	sort(arr,arr+n);
	int small= arr[0]+k;
	int big= arr[n-1]-k;
	int base1,base2;
	if(small>big)
		swap(big,small);
	base1= big;base2=small;
	for(int i=1;i<n-1;i++){
		int sub= arr[i]-k;
		int add= arr[i]+k;
		if(sub>=small or add<=big)
			continue;
		else{
			if(add-small<=big-sub){
				big=add;
			}
			else
				small=sub;
		}

	}
// return min(big-small, base1-base2);}
return big-small;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<mindiff(arr, n,k);


return 0;
}