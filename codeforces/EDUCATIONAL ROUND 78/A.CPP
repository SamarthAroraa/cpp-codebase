#include<bits/stdc++.h>
#include<unordered_map>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
string checkhash(string p,string h){
	int l_p=p.length();
	int l_h=h.length();
	if(l_h<l_p)
		return "NO";
	unordered_map <char,int> m_p;
	unordered_map <char,int> m_h;
	for(int i=0;i<l_p;i++){
		m_p[p[i]]++;
	}
	for(int k=0;k<l_h-l_p+1;k++){
	// cerr<<k<< ' ' <<k+l_p-1<<endl;
	for(int i=k;i < k+ l_p ; i++){

		m_h[h[i]]++;
	}
	bool flag=1;
	for(auto n:m_p){
		if(m_h[n.first]!=n.second)
			flag=0;
			// return "NO";
	}
if(flag==1){
deb(h[k]);
return "YES";

}

m_h.clear();
// m_p.clear();
}
// return "YES";
return "NO";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
	string p,h;	

	cin>>p>>h;
	cout<<checkhash(p,h)<<endl;
	}

return 0;
}