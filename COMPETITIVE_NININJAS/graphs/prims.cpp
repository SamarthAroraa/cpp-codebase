#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll getminv(bool visited[],ll v,ll weight[]){
	ll minv=-1;
	for(ll i=0;i<v;i++){
		if(!visited[i] and ((minv==-1) or weight[minv]>weight[i])){
			minv=i;
		}
	}
return minv;
}

void prims(ll v,int**graph,ll e){
	bool visited[v];
	ll parent[v];
	ll weight[v];
	for(ll i=0;i<v;i++){
		// parent[i]=0;
		weight[i]=INT_MAX;
	}
	parent[0]=-1;
	weight[0]=0;
	for(ll i=0;i<v-1;i++){
		ll minv= getminv(visited,v,weight);
		visited[minv]=1;
		for(ll i=0;i<v;i++){
			if(i==minv)
				continue;
			if(graph[i][minv]!=0 && !visited[i]){
				if(weight[i]>graph[minv][i]){
					parent[i]= minv;
					weight[i]= graph[minv][i];
				}
			}
		}
	}
	// recursive(v,e,graph,source,visited,parent,weight);
	for(ll i=1;i<v;i++){
		if(i<=parent[i])
		cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
	else
		cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;

	}
	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll v,e;
	cin>>v>>e;

	ll **graph= new int*[v];
	for(ll i=0;i<v;i++){
		graph[i]= new int[v];
	}
	for(ll i=0;i<v;i++){
		for(ll j=0;j<v;j++){
			graph[i][j]=0;
		}
	}
	for(ll i=0;i<e;i++){
		ll f,s,w;
		cin>>f>>s>>w;
		graph[s][f]=w;
		graph[f][s]=w;
	}
	prims(v,graph,e);
	// mst(graph,v,e);
for(ll i=0;i<v;i++){
		delete [] graph[i];
	}
	delete[] graph;

return 0;
}