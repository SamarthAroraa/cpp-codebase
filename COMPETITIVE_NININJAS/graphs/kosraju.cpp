#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

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
void dfs2(std::vector<int>* edges,ll i, unordered_set<int>&visited, unordered_set<int>*component){
	visited.insert(i);
	component->insert(i);
	for(ll k=0;k<edges[i].size();k++){
		ll adj=edges[i][k];
		if(visited.count(adj)==0){
			dfs2(edges,adj,visited,component);
		}
	}
	// finished.push(i);
	return;
}
unordered_set<unordered_set<int>* >*getSCC(std::vector<int>* edgesT,std::vector<int>* edges, ll n,ll m){
	unordered_set<int> visited;
	stack<int> finished;
	unordered_set<unordered_set<int>*>* output= new  unordered_set<unordered_set<int>*>();
	for(ll i=0;i<n;i++){
		if(visited.count(i)==0)
		{
			dfs(edges,i,visited,finished);
		}
	}
	visited.clear();
	while(finished.size()!=0){
		ll element = finished.top();
		finished.pop();
		if(visited.count(element)==0){
			unordered_set<int> * component= new unordered_set<int>();
			dfs2(edgesT,element,visited,component);
			output->insert(component);
		}
	}
return output;
}
ll main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
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
	// for(ll i=0;i<n;i++){
	// 	cout<<i+1<<" ";
	// 	for(ll j=0;j<edges[i].size();j++){
	// 		cout<<edges[i][j]+1<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"***************\n";
	unordered_set<unordered_set<int>* >*scc=getSCC(edgesT,edges,n,m);
	unordered_set<unordered_set<int>* >::iterator it1=scc->begin();
	while(it1!=scc->end()){
		unordered_set<int>* component = *it1; 
		unordered_set<int>::iterator it2= component->begin();
		// deb(scc->size())
		while(it2!=component->end()){
			cout<<*it2+1<<" ";
			it2++;
		}
		cout<<endl;
		delete component;
		it1++;
	}
	delete scc;
delete []edges;
delete []edgesT;
return 0;
}