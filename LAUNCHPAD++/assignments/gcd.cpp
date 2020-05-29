#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n1,n2;
	cin>>n1>>n2;
	cout<<gcd(n1,n2);

return 0;
}