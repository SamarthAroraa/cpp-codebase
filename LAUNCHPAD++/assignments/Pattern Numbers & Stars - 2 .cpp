#include<bits/stdc++.h>
using namespace std;
void answer(int n){
	for(int i=1;i<=n;i++){
		int stars=n-i;
		for(int j=1;j<=i;j++){
			cout<<j;
		}
		for(int j=1;j<=stars;j++){
			cout<<"*";
		}
	cout<<endl;
}
return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
int n;
cin>>n;
answer(n);
return 0;
}