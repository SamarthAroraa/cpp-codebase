#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	int a,b,i;


};
void build(node* tree, int as[],int bs[], int n, int s, int e ,int ad){
	if(s==e){
		tree[ad].a= as[e];
		tree[ad].b=bs[e];
		tree[ad].i=e;
		return;
	}
	int m=(s+e)/2;
	build(tree, as,bs,n,s,m,ad*2);
	build(tree,as,bs,n,m+1,e,2*ad+1);
	if(tree[2*ad].a!=tree[2*ad+1].a){
	if(tree[2*ad].a>tree[2*ad+1].a){
		tree[ad].a= tree[2*ad].a;
		tree[ad].b= tree[2*ad].b;
		tree[ad].i= tree[2*ad].i;

		return;
	}
	else{
		tree[ad].a= tree[2*ad+1].a;
		tree[ad].b= tree[2*ad+1].b;
		tree[ad].i= tree[2*ad+1].i;

		return;
	}
}
else if(tree[2*ad].b!=tree[2*ad+1].b){
	
		if(tree[2*ad].b<tree[2*ad+1].b){
			tree[ad].a= tree[2*ad].a;
			tree[ad].b= tree[2*ad].b;
			tree[ad].i= tree[2*ad].i;

		}
		else{
			tree[ad].a= tree[2*ad+1].a;
			tree[ad].b= tree[2*ad+1].b;
			tree[ad].i= tree[2*ad+1].i;

		}
}
else{
	if(tree[2*ad].i<tree[2*ad+1].i){
			tree[ad].a= tree[2*ad].a;
			tree[ad].b= tree[2*ad].b;
			tree[ad].i= tree[2*ad].i;

		}
		else{
			tree[ad].a= tree[2*ad+1].a;
			tree[ad].b= tree[2*ad+1].b;
			tree[ad].i= tree[2*ad+1].i;

		}
}

return;
	
}

node* query(node* tree, int s, int e, int ad,int lind, int rind){
	node* n= new node;
	if(s>rind or e<lind){
		n->a=INT_MIN;
		n->b=INT_MAX;
		n->i=INT_MAX;
		return n;
	}
	if(s>=lind and e<=rind){
		// return &tree[ad];
		n->a=tree[ad].a;
		n->b=tree[ad].b;
		n->i=tree[ad].i;
		return n;
	}
	int m=(s+e)/2;
	node* l=new node;
	node*r= new node;
	l=query(tree,s,m,ad*2,lind,rind);
	r=query(tree,m+1,e,ad*2+1,lind,rind);
		if(l->a!=r->a){
	if(l->a>r->a){
		n->a= l->a;
		n->b= l->b;
		n->i= l->i;

		// return n;
	}
	else{
		n->a= r->a;
		n->b= r->b;
		n->i= r->i;

		// return n;
	}
}
else if(l->b!=r->b){
	
		if(l->b<r->b){
			n->a= l->a;
			n->b= l->b;
			n->i= l->i;

		}
		else{
			n->a= r->a;
			n->b= r->b;
			n->i= r->i;

		}
}
else{
	if(l->i<r->i){
			n->a= l->a;
			n->b= l->b;
			n->i= l->i;

		}
		else{
			n->a= r->a;
			n->b= r->b;
			n->i= r->i;

		}
}
return n;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int as[n];
	int bs[n];
	for(int i=0;i<n;i++){
		cin>>as[i];
	}
	for(int i=0;i<n;i++){
		cin>>bs[i];
	}
	node*tree= new node[3*n];
	build(tree,as,bs,n,0,n-1,1);
	
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<query(tree,0,n-1,1,l-1,r-1)->i+1<<endl;
	}

return 0;
}