// #include<bits/stdc++.h>
// #include<unordered_map> 
// #define deb(x) cerr<<#x<<" "<<x<<endl;
// #define ll long long
// using namespace std;
// int ans(std::vector<int> str){
// 	unordered_map  <int, int> m;
// 	int maxf=0;
// 	deb(str.size())
// //getting freq table
// 	for(int i=0;i<str.size();i++){
// 		m[str[i]]++;
// 		if(m[str[i]]>maxf){
// 			maxf=m[str[i]];
// 			deb(maxf)

// 		}
// 	}
// int allothers= str.size() - maxf;
// return allothers;
// }
// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// 	#endif
// 	int t;
// 	cin>>t;
// 	// cout<<"t"<<t<<endl;
// 	while(t--){
// 		int n;
// 		cin>>n;
// 		std::vector<int> str(n);

// 		for(int i=0;i<n;i++){
// 			cin>>str[i];
// 		}
// 		cout<<ans(str)<<endl;
// 	}
// return 0;
// 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> freq;
    string name="e";
    string s;
    getline(cin,s);
    istringstream iss(s);
    while(iss){
        iss>>name;
        freq[name]++;
        
    }
    bool p=false;
    for(auto name : freq){
        if(name.second>1){
            p=true;
            cout<<name.first<<" "<<name.second<<endl;
        }
    }
	return 0;
}
