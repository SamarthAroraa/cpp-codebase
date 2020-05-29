#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
// ll ans=0;
// ll ans2=0;

void dfs(std::vector<int>* edges,ll i, unordered_set<int>&visited, stack<int>&finished){
	visited.insert(i);

	for(ll k=0;k<edges[i].size();k++){
		ll adj=edges[i][k];
		if(visited.count(adj)==0){
			dfs(edges,adj,visited,finished);
		}
	}
	finished.push(i);
	return;
}
// void dfs2(std::vector<int>* edges,ll i, unordered_set<int>&visited, unordered_set<int>*component){
// 	visited.insert(i);
// 	component->insert(i);
// 	for(ll k=0;k<edges[i].size();k++){
// 		ll adj=edges[i][k];
// 		if(visited.count(adj)==0){
// 			dfs2(edges,adj,visited,component);
// 		}
// 	}
// 	// finished.push(i);
// 	return;
// }
ll getSCC(std::vector<int>* edgesT,std::vector<int>* edges, ll n,ll m){
	unordered_set<int> visited;
	stack<int> finished;
	ll output=INT_MAX;	
		// unordered_set<unordered_set<int>*>* output= new  unordered_set<unordered_set<int>*>();
	for(ll i=0;i<n;i++){
		if(visited.count(i)==0)
		{	deb(i+1)
			// ans++;
			dfs(edges,i,visited,finished);
			
		}

	}
			
	stack<int> dummy;
	visited.clear();
	ll ans=0;
	while(finished.size()!=0){
		ll element= finished.top();
		finished.pop();
		if(visited.count(element)==0){
			ans++;
			dfs(edges,element,visited,dummy);
		}
	}



		cerr<<endl;


return ans;
}
ll main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
	ll n,m;
	cin>>n>>m;
	std::vector<int>* edges= new std::vector<int>[n];
	std::vector<int>* edgesT= new std::vector<int>[n];

	for(ll i=0;i<m;i++){
		ll f,s;
		cin>>f>>s;
		edges[f-1].push_back(s-1);
		edgesT[s-1].push_back(f-1);


	}

	ll ans=getSCC(edgesT,edges,n,m);

	cout<<ans<<endl;

delete []edges;
delete []edgesT;
deb(ans)
ans=0;
}
return 0;
}