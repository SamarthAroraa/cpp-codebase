#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	int bps,bss,sum,maxsum;
};

void buildtree(node*tree,int n, int arr[], int s, int e,int ad){
	if(s==e){
		// if(arr[s]<0){
		// 	tree[ad].bps=0;
		// 	tree[ad].bss=0;
		// 	tree[ad].sum=0;
		// 	tree[ad].maxsum=0;	
		// }
		// else{
			tree[ad].bps=arr[s];
			tree[ad].bss=arr[s];
			tree[ad].sum=arr[s];
			tree[ad].maxsum=arr[s];
			if(arr[s]<0)
				tree[ad].maxsum=0;
		// }
	return;
	}

	int m= (s+e)/2;
	buildtree(tree,n,arr,s,m,ad*2);
	buildtree(tree,n,arr,m+1,e,ad*2+1);
	tree[ad].bps= max(tree[2*ad].bps, tree[2*ad].sum+tree[2*ad+1].bps);
	tree[ad].bss= max(tree[2*ad+1].bss,tree[2*ad+1].sum+ tree[2*ad].bss);
	tree[ad].sum= tree[2*ad].sum+tree[2*ad+1].sum;
	tree[ad].maxsum= max(tree[ad*2].maxsum, max(tree[ad*2+1].maxsum,max(tree[2*ad].sum+tree[2*ad+1].bps,max(tree[2*ad+1].sum+tree[2*ad].bss,tree[2*ad].bss+tree[2*ad+1].bps))));
}


node* query(node*tree, int s , int e, int ad,int lind, int rind){
	node* newn= new node;
	if(s>rind or e<lind){
		newn->bps=INT_MIN;
		newn->bss=INT_MIN;
		newn->sum=INT_MIN;
		newn->maxsum=INT_MIN;
		return newn;
	}
	if(s>=lind and e<=rind){
		return &tree[ad];

	}
	int m=(s+e)/2;
	node* l=query(tree,s,m,ad*2,lind,rind);
	node *r=query(tree,m+1,e,ad*2+1,lind,rind);
	newn->bps= max(l->bps, l->sum+r->bps);
	newn->bss=max(r->bss,r->sum+ l->bss);
	newn->sum=l->sum+r->sum;
	newn->maxsum=max(l->maxsum, max(r->maxsum,max(l->sum+r->bps,max(r->sum+l->bss,l->bss+r->bps))));
return newn;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int arr[n];
	node* tree= new node[3*n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	buildtree(tree,n,arr,0,n-1,1);
	for(int i=0;i<n*3;i++){
		cout<<tree[i].maxsum<<" ";
	}
	cout<<query(tree,0,n-1,1,1,2)->maxsum;

return 0;
}