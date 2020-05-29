#include<bits/stdc++.h>
using namespace std;
string compress(std::vector<int> v){
	int n=v.size();
	string ans="";
	std::vector<bool> compressable(n,0);
	// char ch=v[0]+'0';
	ans+=to_string(v[0]);
	for (int i = 1; i < n-1; ++i)
	{		char c=ans[ans.length()-1];
	
		if(v[i]==v[i-1]+1 and v[i]==v[i+1]-1){
			//code to either ... or skip 
			if(c=='.')
				continue;
			else{
				if(c==',')
				ans=ans.substr(0,ans.length()-1);
				ans+="...";
			}
		}
		else{
			if(c!=',' and c!='.'){
				ans+=',';
			}
			// ch=v[i]+'0';
			ans= ans  + to_string(v[i])+ ",";
		}
	}
	if(v.size()>2){

	ans+=to_string(v[n-1]);
return ans;}
if(v.size()==2){

	// char c=ans[ans.length()-1];
		// cout<<c
		// if(c!=','or c!='.')
			ans+=',';
	ans+=to_string(v[n-1]);
			
}
return ans;
}

int main()

{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	cout<<compress(v)<<endl;
}
	return 0;
}
