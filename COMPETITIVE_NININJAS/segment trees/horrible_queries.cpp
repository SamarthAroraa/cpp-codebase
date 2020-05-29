#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void buildtree(int *tree, int s, int e, int ad, int arr[]){
	if(s==e){
		tree[ad]=0;
		return;
	}
	int m=(s+e)/2;
	buildtree(tree,s,m,2*ad,arr);
	buildtree(tree,m+1,e,2*ad+1,arr);
	tree[ad]=tree[2*ad]+tree[2*ad+1];
	return;

}
void update(int *tree, int*lazy, int s, int e, int lind, int rind, int val, int ad){
	
	
	if(lazy[ad]!=0){
			tree[ad]+=lazy[ad];

			if(s!=e){
				lazy[2*ad]+=lazy[ad];
				lazy[2*ad+1]+=lazy[ad];
			}
				lazy[ad]=0;

			
		}

	if(s>rind or e<lind){
		return;
	}
	if(s>=lind and e<=rind){
		tree[ad]+=val;
		if(s!=e){
			lazy[2*ad]+=val;
			lazy[2*ad+1]+=val;
		}
		return;
	}

	int m= (s+e)/2;
	update(tree,lazy,s,m, lind,  rind,  val, 2*ad);
	update(tree,lazy,m+1,e, lind,  rind,  val, 2*ad+1);
	tree[ad]=tree[2*ad]+tree[2*ad+1];
	return;
}

int query(int *tree, int*lazy, int s,int e, int ad, int lind, int rind){
	if(lazy[ad]!=0){
		tree[ad]+=lazy[ad];
		if(s!=e){
				lazy[2*ad]+=lazy[ad];
				lazy[2*ad+1]+=lazy[ad];
			}
				lazy[ad]=0;


			
		}
	if(s>rind or e<lind){
		return 0;
	}
	if(s>=lind and e<=rind){
		// if(lazy[ad]!=0)
		// 	{deb(ad)
		// 		cerr<<"alert"<<endl;
		// 	}
		return tree[ad];

	}

	int m=(s+e)/2;
	int l= query(tree, lazy,s,m,2*ad,lind,rind);
	int r= query(tree, lazy,m+1,e,2*ad+1,lind,rind);
	return (l+r);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		int arr[n];
		for(int i=0;i<n;i++){
			arr[i]=0;
		}
		int* tree= new int[n*3];
		int* lazy= new int[n*3];
		for(int i=0;i<3*n;i++){
			lazy[i]=0;
		}
		buildtree(tree,0,n-1,1,arr);
		while(c--)
		{
			int type,l,r;
			cin>>type;
			if(type){
				cin>>l>>r;
				cout<<query(tree, lazy,0,n-1,1,l-1,r-1)<<endl;
			}
			else{
				int p,q,v;
				cin>>p>>q>>v;
				update(tree,lazy,0,n-1, p-1,  q-1,  v, 1);
			}

		}
		for(int i=1;i<n*3;i++){
			cerr<<tree[i]<<"\t"<<lazy[i]<<endl;
		}
		delete []tree;
		delete []lazy;

	}

return 0;
}