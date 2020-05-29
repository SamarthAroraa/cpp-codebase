#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

void getpath_bfs(int** graph, int v, int sv, int ev){
	unordered_map <int,bool> visited;
	unordered_map <int,int> mapping;
	for(int i=0;i<v;i++){
		mapping[i]=-1;
	}

	queue <int> q;
	q.emplace(sv);
	visited[sv]=1;
	mapping[sv]=-1;
	while(!q.empty()){
		int f= q.front();
		q.pop();
		for(int i=0;i<v;i++){
			if(i==f)
				continue;
			if(!visited[i] and graph[f][i]){
				visited[i]=1;
				q.emplace(i);
				mapping[i]=f;
			}

		}
	}
	if(mapping[ev]!=-1)
	{int previous=ev;
	while(previous!=-1){
		cout<<previous<< " ";
		previous= mapping[previous];
	}
}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int v,e;
	cin>>v>>e;
	int ** graph= new int*[v];
	for(int i=0;i<v;i++){
		graph[i]= new int[v];
		for(int k=0;k<v;k++){
			graph[i][k]=0;
		}
	}
	int s,en;
	for(int i=0;i<e;i++){
		cin>>s>>en;
		graph[s][en]=1;
		graph[en][s]=1;
	}
	int start, end;
	cin>>start>>end;
	getpath_bfs(graph,v,start,end);

return 0;
}