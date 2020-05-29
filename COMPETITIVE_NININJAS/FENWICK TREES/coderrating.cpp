#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
	std::vector<int> BIT(100001,0);

class coder{
public:
	int h;
	int a;
	int index;
	coder()
	{
		this->h=0;
		this->a=0;
		this->index=0;
	}	
};

bool comp(coder a, coder b){
	if(a.h==b.h){
		return a.a<b.a;
	}
	return a.h<b.h;
}

void update(std::vector<int>&BIT, int n,int index){

for(;index<=100000;index+=(index&(-index))){
	BIT[index]++;
	}
}

int query(std::vector<int>&BIT, int y){
	int ans=0;
	for(;y>0;y-=((y&-y))){
		ans+=BIT[y];
	}
return ans;
}
	


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	coder ratings[n+1];
	for(int i=1;i<=n;i++){
		cin>>ratings[i].a>>ratings[i].h;
		ratings[i].index=i;
		// deb(ratings[i].index)
		// deb(ratings[i].a)
		// deb(ratings[i].h)
	}
	sort(ratings+1,ratings+n+1,comp);
	for(int i=1;i<=n;i++){

	// deb(ratings[i].index)
	// 	deb(ratings[i].a)
	// 	deb(ratings[i].h)
	}

	int ans[n+1];
	for(int i=1;i<=n;){
		int end=i;
		while(end<=n and ratings[end].a==ratings[i].a and ratings[end].h==ratings[i].h){
			end++;
			// cerr<<"boobies!\n";
			// deb(ratings[i].index)
			// deb(ratings[i].a)
			// deb(ratings[i].h)
			// deb(end)
		}
		for(int j=i;j<end;j++){
			ans[ratings[j].index]=query(BIT,ratings[j].a);
			
		}
		for(int j=i;j<end;j++){
			update(BIT,n,ratings[j].a);
		}
		i=end;

	}
	for(int i=1;i<=n;i++){
		// cerr<<"SDIHIASJOAJSD\n";
		cout<<ans[i]<<endl;
	}



return 0;
}