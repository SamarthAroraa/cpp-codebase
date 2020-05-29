#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

void dfs(bool visited[], std::vector<int>* edges, int i , unordered_set<int>* component){
	visited[i]=1;
	component->insert(i);
	deb(i)

	for(int k=0;k<edges[i].size();k++){
		if(!visited[edges[i][k]]){
			dfs(visited, edges,edges[i][k],component);

		}
	}
return;
}
unordered_set<unordered_set<int>* >*getconnected(std::vector<int>* edges, int m,int n){
	bool visited[n];
	unordered_set<unordered_set<int>* > * res= new unordered_set<unordered_set<int>* > ();
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			unordered_set<int> * component= new unordered_set<int>();
			dfs(visited, edges,i,component);
			res->insert(component);
		}
	}
return res;
}

bool ans(int v, int e, std::vector<int> p, std::vector<int> q,std::vector<int>* edges){
	unordered_set<unordered_set<int>* >* res = getconnected(edges,e,v);
	unordered_set<unordered_set<int>* >::iterator it1= res->begin();
	for(auto n : *res){
		for(auto k : *n){
			cerr<<k<<" ";
		}
	cerr<<"\n";
}

	while(it1!=res->end()){
		unordered_set<int>* curr= *it1;
		unordered_set<int> a;
		unordered_set<int> b;
		unordered_set<int> :: iterator it2= curr->begin();
		while(it2!=curr->end()){
			int index = *it2;
			a.insert(p[index]);
			b.insert(q[index]);
			// cerr<<p[index]<< " "<<q[index]<<" "<<*it2<<endl;
			it2++;
		}
		if(a!=b)
		{
			return 0;
		}



		it1++;
	}
return 1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>>v>>e;
		std::vector<int> p(v);
		std::vector<int> q(v);
		for(int i=0;i<v;i++){
			cin>>p[i];
		}
		for(int i=0;i<v;i++){
			cin>>q[i];
		}
		std::vector<int>* edges= new std::vector<int>[v];
		for(int i=0;i<e;i++){
			int j,k;
			cin>>j>>k;

			edges[j-1].push_back(k-1);
			edges[k-1].push_back(j-1);

		}
		if(ans(v,e,p,q,edges)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}

	}


return 0;
}