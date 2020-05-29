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
	while(1){
	cin>>n;
	if(n==0)
		return 0;
	cin>>m;
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
	// set<int> sinks;
	std::vector<std::vector<int> > sinks;
	unordered_set<unordered_set<int>* >*scc=getSCC(edgesT,edges,n,m);
	unordered_set<unordered_set<int>* >::iterator it1=scc->begin();
	std::vector<int> v;
	while(it1!=scc->end()){
		unordered_set<int>* component = *it1; 
		unordered_set<int>::iterator it2= component->begin();
		// deb(scc->size())
		while(it2!=component->end()){
			ll curr= *it2;
			// deb(curr)
			bool flag=0;
			for(ll o=0;o<edges[curr].size();o++){
				if(component->count(edges[curr][o])==0){
					deb(edges[curr][o])
					deb(curr)
					flag=1;
					break;

				}
			}
			if(flag==1){
				v.clear();
				break;
			}
			else{
				v.push_back(curr);
			}

			it2++;
		}
		

		// cout<<endl;
		sinks.push_back(v);
		v.clear();
		delete component;
		it1++;
	}

	std::vector<int> sorted;
	for(ll i=0;i<sinks.size();i++){
		for(ll j=0;j<sinks[i].size();j++){
			sorted.push_back(sinks[i][j]);
			// cout<<sinks[i][j]+1<< " ";
		}
		// cout<<endl;
	}
	sort(sorted.begin(),sorted.end());
	for(ll i=0;i<sorted.size();i++){
		cout<<sorted[i]+1<<" ";
	}
	cout<<endl;
	// sort(sinks.begin(),sinks.end());
	delete scc;
delete []edges;
delete []edgesT;
}
return 0;
}