//program to find minimum spanning tree
#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class edge
{
public:
	int s, d, w;
	edge(){
		s=-1;d=-1;w=0;
	}

	
};
// void print(int** tree, int v, int s,bool visited[])
// {
// 	visited[s]=1;
// 	cout<<s<<"->";
// 	for(int i=0;i<v;i++){
// 		if(i==s){
// 			continue;
// 		}
// 		if(tree[i][s]!=0 and !visited[i]){
// 			print(tree,v,i,visited);
// 		}
// 	}
// return;
// }

bool comparator(edge a , edge b){
	return a.w<b.w;
}

int getparent(int s, int parent[]){
	int a= parent[s];
	while(a!=s){
		s= parent[s];
		a=parent[s];
	}
return a;	
}
void mst(edge graph[],int v, int e){
	int count=0;
	sort(graph,graph+e,comparator);
	// for(int i=0;i<e;i++){
	// 	cout<<graph[i].s<<" "<<graph[i].d<<" "<<graph[i].w<<endl;
	// }
	int parent[v];
	for(int i=0;i<v;i++){
		parent[i]=i;
	}
	
	

	

	int source=0;
	for(int i=0;i<e;i++){
		int s= graph[i].s;
		int d= graph[i].d;
		int s_p= getparent(s, parent);
		int d_p= getparent(d, parent);
		if(s_p!=d_p){
			count++;
			
			parent[s_p]=d_p;
			// tree[s][d]=graph[i].w;
			// tree[d][s]=graph[i].w;
			cout<<s<<" "<<d<<" "<<graph[i].w<<endl;
			source=d_p;
			// for(int i=0;i<v;i++){
			// 	deb(i)deb(parent[i])
			// }

		}
		if(count==v)
		break;

	}
	
	// bool visited[v];
	// deb(source)
	// print(tree, v,  source,visited);

}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int v,e;
	cin>>v>>e;

	edge graph[e];
	for(int i=0;i<e;i++){
		cin>>graph[i].s>>graph[i].d>>graph[i].w;
	}
	mst(graph,v,e);

return 0;
}