#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class Trio
{
public:
	ll x,y,gcd;
};

Trio extended_euc(ll a, ll b){
	if(b==0){
		Trio ans;
		ans.gcd=a;
		ans.y=0;
		ans.x=1;
		return ans;
	}
	

	Trio sm_ans=extended_euc(b,a%b);
	Trio ans;
	ans.gcd= sm_ans.gcd;
	ans.x= sm_ans.y;
	ans.y= sm_ans.x- sm_ans.y * (a/b);
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	ll a,b,d;
	cin>>a>>b>>d;
	
	// if(a<b){
	//  swap(b,a);
	// }
	Trio ans= extended_euc(b,a);
	a/=ans.gcd;
	d/=ans.gcd;
	b/=ans.gcd;
	ll y1= (d%a * (ans.x%a + a)%a)%a;
	ll n= (d/b - y1)/a;
	if(d/b - y1<0)
		n=-1;
	// deb(floor(-1/2))

	cout<<n+1<<endl;
	deb(ans.x)
	deb(y1)
	deb(ans.y)
	deb(ans.gcd)
	}



	 
return 0;
}