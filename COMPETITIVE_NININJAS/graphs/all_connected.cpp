
#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
set<int> universal;
bool iscon(int** graph, int v,unordered_map<int,bool>& visited, int sv){
	visited[sv]=1;
	universal.insert(sv);
	for(int i=0;i<v;i++){
		if(graph[sv][i] and !visited[i]){
			bool m = iscon(graph,v,visited,i);
		}
	}
return false;
}

int allvisited(unordered_map<int,bool>&visited,int v,std::vector<int>&newset){
	int next =-1;
	for(int i=0;i<v;i++){
		if(!visited[i])
			next=i;
		else if(universal.find(i)!=universal.end()){
			newset.insert(newset.begin(),i);
		}
	}
	
return next;
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
	int next=0;
	std::vector<std::vector<int> > master_vector;
	while(next!=-1){
		std::vector<int> newset;
		bool m=iscon(graph,V,visited,next);
		next=allvisited(visited,V,newset);
		universal.clear();
		master_vector.push_back(newset);

	}
	for(int i=0;i<master_vector.size();i++){
		for(int j=master_vector[i].size()-1;j>=0;j--){
			cout<<master_vector[i][j]<< " "; 
		}
		cout<<endl;
	}

return 0;
}