#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int ans(int n)
{
	ll ul= pow(10,n);
	ll sum=0;
	int verdict=-1;
	ll a;
	cin>>a;
	ll s= 2*ul + a;
	cout<<s<<endl;
	fflush(stdout);
	ll b,c,d,e;
	cin>>b;
	c= ul - b;
	cout<<c<<endl;
	fflush(stdout);
	cin>>d;
	 e= ul- d;
	cout<<e<<endl;
	fflush(stdout);
	sum= a+b+c+d+e;
	cin>>verdict;
	deb(sum)
	deb(s)
	return verdict;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int j= ans(n);
	}

return 0;
}