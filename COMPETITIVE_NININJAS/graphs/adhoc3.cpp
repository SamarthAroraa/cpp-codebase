#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void bfs(bool** graph, unordered_map<int,bool>&visited, int v,int sv){
	queue<int> q;
	q.emplace(sv);
	visited[sv]=1;
	while(!q.empty()){
	int k= q.front();
	q.pop();
	cout<<k<<" ";
	// visited[k]=1;
	for(int i=0;i<v;i++){
		if(i==k)
			continue;
		if(graph[k][i]){
			if(!visited[i]){
				q.emplace(i);
				visited[i]=1;
			}
		}
	}

}

for(int i=0;i<v;i++){
            if(visited[i]==0){
            	bfs(graph,visited,v,i);    
            }
    }
}

bool has_path(bool** graph,unordered_map<int,bool>&visited, int v,int sv,int ev){
	if(sv==ev)
		return true;
	visited[sv]=1;
	for(int i=0;i<v;i++){
		if(i==sv)
			continue;
		if(graph[sv][i] and visited[i]!=1){
			if(i==ev)
				return 1;
			else if(has_path(graph,visited,v,i,ev)){
				return true;
				// break;
			}
		}
	}
return false;
}
int main(){
	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
	
	int v,e;
	cin>>v>>e;
    
	bool **graph= new bool*[v];
	for(int i=0;i<v;i++){
		graph[i]= new bool[v];
		for(int j=0;j<v;j++){
			graph[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		graph[f][s]=1;
		graph[s][f]=1;
	}
	unordered_map<int,bool> visited;
	bfs(graph,visited,v,0);
    for(int i=0;i<v;i++){
        delete [] graph[i];
    }
    cout<<"\n"<<has_path(graph,visited,v,0,1);
    cout<<"\n"<<has_path(graph,visited,v,0,3);
    delete[] graph;
return 0;
}