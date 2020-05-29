#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
 class Job{
 public:
 	int start,end, profit;
 };
bool comparator(Job a, Job b){
	return a.end<b.end;
}
int maxprofit(Job arr[],int n)
{
	sort(arr, arr+n,comparator);
	int dp[n+1];
	dp[0]=0;
	for(int i=0;i<n;i++){
		int maxnon=arr[i].profit;
		for(int j=i;j>=0;j--){
			if(arr[j].end<=arr[i].start){
				maxnon+= dp[j+1];
				cerr<<"y\n";
				break;
		}

		}
		deb(i)
		deb(maxnon)
		deb(arr[i].profit)
		deb(dp[i])
		cerr<<endl;
	dp[i+1]= max(maxnon, dp[i]);
	}
return dp[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	Job arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].start;
		cin>>arr[i].end;
		cin>>arr[i].profit;
	}
	cout<<maxprofit(arr, n);

return 0;
}