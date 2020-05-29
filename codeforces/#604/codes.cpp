#include <bits/stdc++.h>  
// #include <vector>
// #include<iostream>
#include<unordered_map>

using namespace std;
// string beaeutiful(string inp){
// 	int n=inp.length();

// //ININT CHECK
// 	for(int i=0;i<n-1;i++){
// 		if(inp[i]!='?'){
// 			if(inp[i]==inp[i+1])
// 				return "-1";
// 		}

// 	}
// 	string ans="";
// char options[]={'a','b','c'};
// for(int i=0;i<n;i++){
// 	// cerr<<"inp[i] "<<inp[i]<<endl;
// 	if(inp[i]=='?'){
// 			// bool flag=0;

// 		for(char op: options){
// 			// cerr<<op<<" ";
// 			if(op!=ans[i-1] and op!=inp[i+1]){
// 				// { cerr<<op<<" "<<inp[i-1]<<" " <<inp[i+1]<<" "<<i<<endl;	
// 				// flag=1;
// 				ans+=op;
// 				break;
// 			}
// 		}
// 		// if(flag==0)
// 		// 	return"-1";
// 	}
// 	else{
// 		if(inp[i]==inp[i+1])
// 			return"-1";
// 		ans+=inp[i];
// 	}
// }
// return ans;

// }

void ans_B(std::vector<int> arr){
	// string ans="";
	bool beutu[arr.size()];
	beutu[0]=1;
	unordered_map<int,int> num_index;

	for (int i = 0; i < arr.size(); ++i)
	{ cerr<<i<<endl;
		num_index[arr[i]]=i;
	}
	for(int i=2;i<=arr.size();i++)
	{
		cerr<<i<<endl;
		if(beutu[i-2] and (abs(num_index[i]-num_index[i-1])==1)){
			beutu[i-1]=1;
		}
		else
			beutu[i-1]=0;
	}
	
for(int i=0;i<arr.size();i++){
	cout<<beutu[i];
}

return;
}

int main()
{
	#ifndef ONLINE_JUGDE
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
ans_B(v);
cout<<endl;


}
	return 0;

}