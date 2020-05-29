#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

bool div30(string num){
	ll n= num.length();
	ll sum=0;
	bool zero=0;
	bool two=0;
	for(ll i=0;i<n;i++){
		ll digit= num[i]-'0';
		if(num[i]=='0' and zero==0){
			zero=1;
		}
		else if((digit&1)==0){
			two=1;
		}
		sum+= (num[i]-'0');
	}
	return(!(sum%3) && zero && two);
}
string checker(string num){
	if(div30(num))
		return "red";
	return "cyan";
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n;
	cin>>n;

	for(ll i=0;i<n;i++){
		string s;
		cin>>s;
		cout<<checker(s)<<endl;
	}

return 0;
}