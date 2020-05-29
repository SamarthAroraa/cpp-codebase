#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int min_salary(int n, int csal[], int asal[],int cap, int as){
	if(n==0)
		return 0;
	if(as-cap==0){
		return asal[0]+min_salary(n-1,csal+1,asal+1, cap,as+1);
	}
	else if(as-cap==n){
		return csal[0]+min_salary(n-1,csal+1,asal+1, cap+1,as);
	}
	else if(as-cap<0) {
		return asal[0]+min_salary(n-1,csal+1,asal+1, cap,as+1);
	
	}
	else{
		return min(asal[0]+min_salary(n-1,csal+1,asal+1, cap,as+1),
			csal[0]+min_salary(n-1,csal+1,asal+1, cap+1,as));
	}
}
int min_salary_dp(int n, int csal[], int asal[]){
	int cap=0; int asal=0;
	int dp[n/2+1][n/2+1];
	dp[0][0]= asal[0];
	for(int i=0;i<=n/2;i++){
		dp[i][0]= asal[]
	}

	for(int i=1;i<=n;i++){
		if(as-cap==0)
		{
			dp[as++][cap][i]=asal[i-1]+dp[]
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	int csal[n],asal[n];
	for(int i=0;i<n;i++){
		cin>>csal[i]>>asal[i];
	}
	cout<<min_salary(n, csal,asal,0,0);
return 0;
}