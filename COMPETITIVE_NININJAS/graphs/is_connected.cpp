#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool iscon(int** graph, int v,unordered_map<int,bool>& visited, int sv){
	visited[sv]=1;
	for(int i=0;i<v;i++){
		if(graph[sv][i] and !visited[i]){
			bool m = iscon(graph,v,visited,i);
		}
	}
return false;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int V,E;
	cin>>V>>E;
	int** graph= new int*[V];
	for(int i=0;i<V;i++){
		graph[i]= new int[V];
		for(int k=0;k<V;k++){
			graph[i][k]=0;
		}
	}
	int sv,ev;
	for(int i=0;i<E;i++){
		cin>>sv>>ev;
		graph[sv][ev]=1;
		graph[ev][sv]=1;
	}
	unordered_map<int,bool> visited;
	bool j= iscon(graph, V,visited, 0);
	for(int i=0;i<V;i++){
		if(!visited[i]){
			cout<<"false\n";
			for(int i =0;i<V;i++)
			return 0;
		}
	}
	cout<<"true\n";
return 0;
}