#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	ll temp=t;
	while(t--){
		string s;
		cin>>s;
		ll n= s.length();
		ll multiplier=1;
		stack<ll> indices;
		unordered_map<char,ll> freq;
		for(ll i=0;i<n;i++){
			if((int)s[i]>48 and (int)s[i]<58){
				indices.push(s[i]-'0');
				multiplier*=(s[i]-'0');
			}
			else if(s[i]==')'){
				ll top= indices.top();
				indices.pop();
				multiplier/=top;
			}
			else if(s[i]=='(')
				continue;
			else{
				freq[s[i]]+=(multiplier);
			}

		}
		
		for (auto m:freq)
		{
			cout<<m.first<<" "<<m.second<<"\n";
		}
		ll x=1+freq['S']-freq['N'];
		ll y=1+freq['E']-freq['W'];
		if(x<=0)
			x+=1000000000;
		else if(x>1000000000){
			x-=1000000000;
		}
		if(y<=0)
			y+=1000000000;
		else if(y>1000000000){
			y-=1000000000;
		}
		

		cout<<"Case #"<<temp-t<<": "<<y<<" "<<x<<"\n";
	}



	 
return 0;
}