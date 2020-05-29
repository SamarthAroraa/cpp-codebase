#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
std::vector<string> ans;

ll getans(string s)
{
	ll n= s.length();
	std::vector<int> dp(n+2);
	dp[0]=1;
	dp[1]=1;
	if(s[n-1]=='0')
		return 0;
	for(ll i=2;i<=n;i++){
		if(n-i>0){
			if(s[n-i]=='0')
				return 0;
		}
		dp[i]=dp[i-1]%1000000007;
		ll k= (s[n-i]-'0')*10 + (s[n-i+1]-'0');
		if(k>0 and k<=26){
			dp[i]=((dp[i-1]%1000000007)+(dp[i-2]%1000000007))%1000000007;
		}
		deb(i)
		deb(dp[i])
		deb(k)

	}
return dp[n];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string inp="";
	cin>>inp;
	while(inp!="0"){
		cout<<getans(inp)<<endl;

		cin>>inp;
	}

return 0;
}
