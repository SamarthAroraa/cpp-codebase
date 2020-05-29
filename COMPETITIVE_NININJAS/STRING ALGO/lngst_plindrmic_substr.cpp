#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll countPalindromeSubstrings(char s[]) {
	ll n=strlen(s);
	ll count=n;
	ll odd=0;
	ll even=0;
	//odd loop
	for(ll i=0;i<n;i++){
		ll l=i-1,r=i+1;
		while(l>=0 and r<n and s[l]==s[r])
		{
			odd++;
			l--;
			r++;
		}
	}
	for(ll i=0;i<n;i++){
		if(s[i]==s[i+1]){
		even++;
		ll l=i-1,r=i+2;
		while(l>=0 and r<n and s[l]==s[r])
		{
			even++;
			l--;
			r++;
		}
	}
}

count+=(odd+even);
return count;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	char s[1000];
	cin>>s;
	ll tot=countPalindromeSubstrings(s) 
	cout<<tot<<endl;

return 0;
}