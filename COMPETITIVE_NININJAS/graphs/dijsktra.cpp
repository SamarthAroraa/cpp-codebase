#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll int
using namespace std;
int getminv(int distance[], bool visited[], int v){
	int minv=-1;
	for(int i=0;i<v;i++){
		if(!visited[i] and ((minv==-1) or distance[i]<distance[minv])){
			minv=i;
		}
	}
return minv;
}
void dij(int ** graph, int s, int v){
	bool visited[v];
	int distance[v];
	for(int i=0;i<v;i++){
		distance[i]=INT_MAX;
	}
	distance[0]=0;

	for(int i=0;i<v-1;i++){
		int minv= getminv(distance,visited,v);
		// deb(minv)
		visited[minv]=1;
		for(int j=0;j<v;j++){
			if(j==minv)
				continue;
			if(graph[j][minv]!=0 and !visited[j]){
			// cerr<<1<<endl;

				// deb(distance[j])
			if(distance[j]>distance[minv]+ graph[minv][j]){
				distance[j]= distance[minv]+graph[minv][j];
			}
		}
		}
	}

	for(int i=0;i<v;i++){
		cout<<i<< " "<<distance[i]<<endl;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int v,e;
	cin>>v>>e;

	int **graph= new int*[v];
	for(int i=0;i<v;i++){
		graph[i]= new int[v];
	}
	for(int i=0;i<v;i++){
		for(ll j=0;j<v;j++){
			graph[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int f,s,w;
		cin>>f>>s>>w;
		graph[s][f]=w;
		graph[f][s]=w;
	}
	dij(graph,0,v);
	// mst(graph,v,e);
for(ll i=0;i<v;i++){
		delete [] graph[i];
	}
	delete[] graph;


return 0;
}