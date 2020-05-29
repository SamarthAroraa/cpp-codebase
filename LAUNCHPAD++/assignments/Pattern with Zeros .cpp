#include<bits/stdc++.h>
using namespace std;


void answer(int n){
	int zeroes=0;
	cout<<"1\n";
	for(int i=0;i<n-1;i++){
		cout<<i+2<< " ";
		for(int j=0;j<zeroes;j++){
			cout<<"0 ";
		}
		zeroes++;
		cout<<i+2<<endl;
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