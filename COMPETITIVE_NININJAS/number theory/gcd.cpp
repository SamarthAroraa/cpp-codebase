#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a ,b;
	 cin>>a>>b;
	 if(a<b)
	 swap(a,b);
	 cout<<gcd(a,b);



	 
return 0;
}