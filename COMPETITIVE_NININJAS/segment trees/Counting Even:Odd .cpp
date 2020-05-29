#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	ll odd,even;
	node(){
		odd=0;
		even=0;
	}
};

void build(node* tree, ll ad, ll s, ll e, ll arr[]){
	if(s==e){
		tree[ad].even=0;
		tree[ad].odd=0;
		if((arr[s]&1)==0)
			tree[ad].even=1;
		else
			tree[ad].odd=1;
	return ;
}
ll m=(s+e)/2;

build(tree, ad*2,s,m,arr);
build(tree, ad*2+1,m+1,e,arr);
tree[ad].even= tree[2*ad].even+ tree[2*ad+1].even;
tree[ad].odd= tree[2*ad].odd+ tree[2*ad+1].odd;
return;

}
void update(node*tree, ll s, ll e, ll index, ll val ,ll ad,ll arr[]){
	ll m=(s+e)/2;
	if(s==e and e==index){
		tree[ad].odd=0;
		tree[ad].even=0;
		if(val%2==0)
			tree[ad].even++;
		else
			tree[ad].odd++;
		
	return;
}
	if(s==e)
	return;
if(index<=m){
	update(tree,s,m,index,val,ad*2,arr);
}
else{
	update(tree,m+1,e,index,val,ad*2+1,arr);
}
tree[ad].even= tree[2*ad].even+ tree[2*ad+1].even;
tree[ad].odd= tree[2*ad].odd+ tree[2*ad+1].odd;

}

int query1(node* tree, ll s, ll e,ll lind, ll rind, ll ad){
	if(s>rind or e<lind){
		return 0;
	}
	if(s>=lind and e<=rind){
		// n->odd= tree[ad].odd;
		return tree[ad].even;
		
	}
	ll m=(s+e)/2;
	int l;
	int r;
	l= query1(tree, s,m,lind,rind,ad*2);
	r= query1(tree,m+1,e,lind,rind,2*ad+1);
	
	return r+l;
	// return n;

}
int query2(node* tree, ll s, ll e,ll lind, ll rind, ll ad){
	if(s>rind or e<lind){
		return 0;
	}
	if(s>=lind and e<=rind){
		// n->odd= tree[ad].odd;
		return tree[ad].odd;
		
	}
	ll m=(s+e)/2;
	int l;
	int r;
	l= query2(tree, s,m,lind,rind,ad*2);
	r= query2(tree,m+1,e,lind,rind,2*ad+1);
	
	return r+l;
	// return n;

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	node* tree= new node[3*n];
	build(tree, 1,0,n-1,arr);
	ll q;
	cin>>q;
	


	while(q--){
		ll type, x,y;
		cin>>type;
		cin>>x>>y;
		if(type==0){
			update(tree,0,n-1,x-1,y,1,arr);
			
			
		}
		else{
			// node* ans=new node;
			// ans=query(tree, 0,n-1,x-1,y-1,1);
			if(type==1)
				cout<<query1(tree, 0,n-1,x-1,y-1,1)<<endl;
			else
				cout<<query2(tree, 0,n-1,x-1,y-1,1)<<endl;
			// delete ans;
		}

	}
	

return 0;
}