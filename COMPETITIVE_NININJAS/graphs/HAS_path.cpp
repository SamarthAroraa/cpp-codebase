#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool haspath(int ** graph, unordered_map<int,bool>& visited, int v, int sv, int ev){
	visited[sv]=1;
	if(graph[sv][ev]){

		return 1;
	}
	for(int k=0;k<v;k++){
		if(k==sv)
			continue;
		if(!visited[k] and graph[sv][k]){
		if(haspath(graph,visited,v,k,ev)){
			return true;
		}
	}
	}
return 0;
}
string getpath(int ** graph, unordered_map<int,bool>& visited, int v, int sv, int ev){
	visited[sv]=1;
	if(sv==ev){
		string s="";
		char c=(ev+'0');
		s+=(c);
	return s;
	}
	for(int k=0;k<v;k++){
		if(k==sv)
			continue;
		if(!visited[k] and graph[sv][k]){
			string path=getpath(graph,visited,v,k,ev);
			if(path!="-1"){
				char c= sv+'0';
				path= path+" "+c;
				return path;

			}
			else{
				continue;
			}

		}
	}
	return "-1";
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
	// std::vector<int> path;
	// path.push_back(start);
	unordered_map<int,bool> visited;
	// int size=0;
	// cout<<haspath(graph,visited,v,start,end)<<endl;
	string path=getpath(graph,visited,v,start,end);
	if(path!="-1"){
		// cout<<"true"<<endl;
		// for(int i=0;i<size;i++){
		cout<<path<<endl;
		// 	cout<<path[size-i-1]<<" ";
		// }
	}
	// else 
		// cout<<"false"<<endl;
return 0;
}