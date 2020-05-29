#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;

using namespace std;
int solve_sub(int n, vector<int>arr,int i){
    long memo[n+1];
    std::vector<long> freq(1001,0);
    freq[arr[0]]++;
    // freq[arr[1]]++;
    long glomax=max(arr[0],arr[1]);
    memo[0]=0;
    memo[1]= arr[0];
    for(int i=2;i<=n;i++){
    	freq[arr[i-1]]++;

        memo[i]= max(arr[i-1]+memo[i-2], memo[i-1]);
        deb(i)
        deb(memo[i])
        deb(freq[arr[i-1]])
        glomax= max(glomax,memo[i]);
    }
    return glomax;
}

int solve(int n,vector<int>A){
  
return solve_sub(n,A,0);

}
// #include<bits/stdc++.h>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	std::vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<solve(n,A);

return 0;
}