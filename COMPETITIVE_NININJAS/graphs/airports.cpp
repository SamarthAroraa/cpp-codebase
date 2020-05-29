#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class  edge
{
public:
	 int x, y ,c;	
	 edge(int x,int y,int c){
	 	this->x=x;
	 	this->y=y;
	 	this->c=c;
	 }
};

int getparent(int parent[], int i){
	// deb(i)
	while(parent[i]!=i){
		i=parent[i];
	}
	// deb(i)
	return i;
}
bool comparator(edge a, edge b){
	return a.c<b.c;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	int k;
	cin>>t;
	k=t;
	while(t--){
		int n,m,a;
		cin>>n>>m>>a;
		std::vector<edge> roads;
		int parent[n];
		for(int i=0;i<n;i++){
			parent[i]=i;
		}
		// edges[n][n];
		for(int i=0;i<m;i++){
			int x,y,c;
			cin>>x>>y>>c;
			x--;y--;
			// edges[x][y]=c;
			// edges[y][x]=c;
			edge e(x,y,c);
			if(c<a){
				roads.push_back(e);
			}
			// roads[i].x=x;
			// roads[i].y=y;
			// roads[i].c=c;
		}
		m= roads.size();
		int cost=0;
		sort(roads.begin(),roads.end(),comparator);
		for (int i = 0; i < m; ++i)
		{
			if(roads[i].c>=a){
				break;
			}
			if(getparent(parent,roads[i].x)==getparent(parent,roads[i].y)){
				continue;
			}
			cost+=roads[i].c;
			int p= min(getparent(parent,roads[i].x),getparent(parent,roads[i].y));
		deb(roads[i].y)
		deb(roads[i].x)
		deb(getparent(parent,roads[i].x))
		deb(getparent(parent,roads[i].y))
			parent[roads[i].y]=p;
			parent[roads[i].x]=p;
		
		}
		int z=0;
		for(int i=0;i<n;i++){
		 cerr<<i<<" '"<<parent[i]<<"\n";
			if(parent[i]==i){
				cost+=a;
				z++;
			
			}
		}
		cout<<"Case #"<<k-t<<": "<<cost<<" "<<z<<"\n";
	}

return 0;
}