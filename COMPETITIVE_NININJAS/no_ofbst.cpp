#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int nbst(int n){
	int bst[n+1];
	bst[0]=1;
	bst[1]=1;
	for(int i=2;i<=n;i++){
		int sum=0;
		for(int k=1;k<=i;k++){
			sum+=(bst[k-1]*bst[i-k]);
		}
		bst[i]=sum;
		deb(i)
		deb(bst[i])
	}
	return bst[n];


}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	cout<<nbst(n);

return 0;
}