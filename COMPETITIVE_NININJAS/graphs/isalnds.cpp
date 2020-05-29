#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
set<int> universal;
bool iscon(int** graph, int v,unordered_map<int,bool>& visited, int sv){
	visited[sv]=1;
	// universal.insert(sv);
	for(int i=0;i<v;i++){
		if(graph[sv][i] and !visited[i]){
			bool m = iscon(graph,v,visited,i);
		}
	}
return false;
}

int allvisited(unordered_map<int,bool>&visited,int v){
	// int next =-1;
	for(int i=0;i<v;i++){
		if(!visited[i])
			return i;
		
	}
	
return -1;
}

int solve(int V,int E,vector<int>u,vector<int>v)
{
int** graph= new int*[V];
	for(int i=0;i<V;i++){
		graph[i]= new int[V];
		for(int k=0;k<V;k++){
			graph[i][k]=0;
		}
	}
	int sv,ev;
	for(int i=0;i<E;i++){
		sv=u[i]; ev= v[i];
		graph[sv-1][ev-1]=1;
		graph[ev-1][sv-1]=1;
	}
    
    unordered_map<int,bool> visited;
	int next=0;
	// std::vector<std::vector<int> > master_vector;
    int islands=0;
	while(next!=-1){
		// std::vector<int> newset;
		bool m=iscon(graph,V,visited,next);
		next=allvisited(visited,V);
		// universal.clear();
        islands++;
        
		// master_vector.push_back(newset);

	}
	
return islands;
}

int main()
{
	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
	
	
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<< solve(n,m,u,v)<<endl;
}