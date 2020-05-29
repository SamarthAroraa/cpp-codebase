#include<bits/stdc++.h>
using namespace std;
unsigned long pow(long long a,long long b,long c){
	int k=1;
	unsigned long long prod=1;
	while(k<b){
		prod= (prod * a)%c;
		// cout<<prod<<endl;
		k++;
	}
	// cout<<prod<<"'";
return prod;

}
int main(){
	

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long a,b,c;
	cin>>a>>b>>c;
	// cout<<a<<b<<c;
	cout<<pow(a,b,c)%c;

return 0;
}
