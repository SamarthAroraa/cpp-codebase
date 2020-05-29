#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
#define MAAX (long long)1000001
#define mod (ll)1000000007
unordered_map<string, int> mapping;
ll factorial[MAAX];
ll xir[]={1,-1,1,-1,2,-2,2,-2};
ll yir[]={2,2,-2,-2,1,1,-1,-1};
void dfs(bool visited[], vector< vector<int> > edges, ll i , unordered_set<int>* component){
	visited[i]=1;
	component->insert(i);
	// deb(i)

	for(ll k=0;k<edges[i].size();k++){
		if(!visited[edges[i][k]]){
			dfs(visited, edges,edges[i][k],component);

		}
	}
return;
}
unordered_set<unordered_set<int>*>* getconnected(vector<vector<int> >edges, ll m,ll n){
	bool visited[n];
	unordered_set<unordered_set<int>* > * res= new unordered_set<unordered_set<int>* > ();
	for(ll i=0;i<n;i++){
		visited[i]=0;
	}
	for(ll i=0;i<n;i++){
		if(!visited[i]){
			unordered_set<int> * component= new unordered_set<int>();
			dfs(visited, edges,i,component);
			res->insert(component);
		}
	}
return res;
}

int main(){
// unordered_map<string, int> present;
	// unordered_map<string,bool> v;

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	factorial[0]=1;
	for(ll i=1;i<MAAX;i++){
		// deb(i%mod)
		factorial[i]=((i%mod)*(factorial[i-1]%mod))%mod;
		// cerr<<factorial[i]<<endl;
	}

	ll t;

	cin>>t;
	while(t--){
		ll n,m,q;
		cin>>n>>m>>q;
		std::vector<std::vector<int> > edges;
		for(ll i=0;i<q;i++){
			std::vector<int> v;
			edges.push_back(v);
		}

		string arr[q];
		for(ll i=0;i<q;i++){
			arr[i]="";
		}
		for(ll i=0;i<q;i++){
			char c1,c2;
			cin>>c1>>c2;
			string str=""
			;
			str+=c1;
			str+=" ";
			str+=c2;

			arr[i]=str;
			// present[str]=true;


			mapping[arr[i]]=i;
			// v[arr[i]]=1;

		}
		// cout<<mapping.size();
		// cout<<"\n"<<q;
		
		// cout<<endl;
		ll e=0;
		for(ll i=0;i<q;i++){
			ll x=arr[i][0]-'0';
			ll y=arr[i][2]-'0';
			for(ll k=0;k<8;k++){
				ll cx=x+xir[k];
				ll cy=y+yir[k];
				// deb(arr[i][0])
				
				if(cx<1 or cy<1 or cx>n or cy>m){
					
					continue;
				}
				string check="";
				check= check + (char)(cx+'0') + " "+ (char)(cy+'0');
				unordered_map<string,int>:: iterator  it=mapping.find(check);
				
				if(it!=mapping.end()){
				

					edges[mapping[arr[i]]].push_back(mapping[check]);
					e++;
				}
			}

		}
		e=e/2;
		
		unordered_set<unordered_set<int>*>* res= new unordered_set<unordered_set<int>*>();
		res= getconnected(edges,e,edges.size());
		
		ll ans=1;
		for(auto n:*res){
			
		ans=((ans%mod)*(factorial[n->size()]%mod))%mod;

		// cout<<endl;
		}
		
		cout<<ans<<"\n";
		delete res;
		mapping.clear();
	
	}

return 0;
}