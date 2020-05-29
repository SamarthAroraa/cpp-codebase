#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class nodet{
public:
    int ss;
    int s;
    nodet(){
        ss=0;
        s=0;
    }
    
};
class nodel{
    public:
    int type;
    int update;
    nodel(){
        type=0;
        update=0;
    }
    
};

void buildtree(nodet *tree, ll s, ll e, ll ad, int arr[]){
	if(s==e){
		tree[ad].ss=(arr[s]*arr[s]);
		tree[ad].s=arr[s];
		return;
	}
	int m=(s+e)/2;
	buildtree(tree,s,m,2*ad,arr);
	buildtree(tree,m+1,e,2*ad+1,arr);
	tree[ad].ss=tree[2*ad].ss+tree[2*ad+1].ss;
	tree[ad].s=tree[2*ad].s+tree[2*ad+1].s;
	return;

}
void update(nodet *tree, nodel *lazy, ll s, ll e, ll lind, ll rind, ll val, int ad,int type){
	
	int m= (s+e)/2;
	
	if(lazy[ad].type!=0){
			// tree[ad]+=(e-s+1)*lazy[ad];
            if(lazy[ad].type==1){
                tree[ad].ss+=(lazy[ad].update*lazy[ad].update)+ 2*tree[ad].s*lazy[ad].update;
                tree[ad].s+=(e-m+1)*lazy[ad].update;
            
			if(s!=e){
				lazy[2*ad].update+=lazy[ad].update;
				lazy[2*ad].type+=lazy[ad].type;
				lazy[2*ad+1].update+=lazy[ad].update;
				lazy[2*ad+1].type+=lazy[ad].type;
				// lazy[2*ad+1]+=lazy[ad];
			}
				lazy[ad].type=0;
                lazy[ad].update=0;
		}
		else if(lazy[ad].type==2){
				tree[ad].ss=((lazy[ad].update)*(lazy[ad].update))*(e-m+1);
                tree[ad].s= (e-m+1)*lazy[ad].update;
            
			if(s!=e){
				lazy[2*ad].update+=lazy[ad].update;
				lazy[2*ad].type+=lazy[ad].type;
				lazy[2*ad+1].update+=lazy[ad].update;
				lazy[2*ad+1].type+=lazy[ad].type;
				// lazy[2*ad+1]+=lazy[ad];
			}
				lazy[ad].type=0;
                lazy[ad].update=0;
		}

}
	if(s>rind or e<lind){
		return;
	}
    
	if(s>=lind and e<=rind){
		if(type==1){
		tree[ad].ss+=val*val+2*tree[ad].s*val;
		tree[ad].s+=(e-s+1)*val;
		
	}
	else if(type==2){
		tree[ad].ss=(e-m+1)*val*val;
		tree[ad].s=(e-m+1)*val;
		
	}
		if(s!=e){
			lazy[2*ad].update+=val;
			lazy[2*ad+1].update+=val;
			lazy[2*ad+1].type=type;
			lazy[2*ad].type=type;
		}
		return;
	}

	

	update(tree,lazy,s,m, lind,  rind,  val, 2*ad,type);
	update(tree,lazy,m+1,e, lind,  rind,  val, 2*ad+1, type);
	tree[ad].ss=tree[2*ad].ss+tree[2*ad+1].ss;
	tree[ad].s= tree[2*ad].s+tree[2*ad+1].s;
	return;
}

ll query(nodet *tree, nodel*lazy, ll s,ll e, int ad, int lind, int rind){
	
	int m=(s+e)/2;
    
    
    if(lazy[ad].type!=0){
			// tree[ad]+=(e-s+1)*lazy[ad];
            if(lazy[ad].type==1){
                tree[ad].ss+=(lazy[ad].update*lazy[ad].update)+ 2*tree[ad].s*lazy[ad].update;
                tree[ad].s+=(e-m+1)*lazy[ad].update;
            
			if(s!=e){
				lazy[2*ad].update+=lazy[ad].update;
				lazy[2*ad].type+=lazy[ad].type;
				lazy[2*ad+1].update+=lazy[ad].update;
				lazy[2*ad+1].type+=lazy[ad].type;
				// lazy[2*ad+1]+=lazy[ad];
			}
				lazy[ad].type=0;
                lazy[ad].update=0;
		}
		else if(lazy[ad].type==2){
				tree[ad].ss=(lazy[ad].update*lazy[ad].update)*(e-m+1);
                tree[ad].s= (e-m+1)*lazy[ad].update;
            
			if(s!=e){
				lazy[2*ad].update+=lazy[ad].update;
				lazy[2*ad].type+=lazy[ad].type;
				lazy[2*ad+1].update+=lazy[ad].update;
				lazy[2*ad+1].type+=lazy[ad].type;
				// lazy[2*ad+1]+=lazy[ad];
			}
				lazy[ad].type=0;
                lazy[ad].update=0;
		}

}
	if(s>rind or e<lind){
		return 0;
	}
	if(s>=lind and e<=rind){
		return tree[ad].ss;
	}

	ll l= query(tree, lazy,s,m,2*ad,lind,rind);
	ll r= query(tree, lazy,m+1,e,2*ad+1,lind,rind);
	return (l+r);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	int temp=1;

	while(t--)
	{
		int n,c;
		cin>>n>>c;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		cout<<"Case "<<temp++<<":"<<endl;
		nodet* tree= new nodet[n*3];
		nodel* lazy= new nodel[n*3];
		for(int i=0;i<3*n;i++){
			lazy[i].update=0;
			lazy[i].type=0;

		}
		buildtree(tree,0,n-1,1,arr);
		deb(n)
		deb(c)
		while(c--)
		{	
			// deb(c)
			int type,l,r;
			cin>>type;
			// deb(type)

			if(type==2){
				cin>>l>>r;
				cout<<query(tree, lazy,0,n-1,1,l-1,r-1)<<endl;
			}
			else{
				if(type==0){
					type=2;
				}
				int p,q,v;
				cin>>p>>q>>v;
				update(tree,lazy,0,n-1, p-1,  q-1,  v, 1,type);
			}
		}

		delete[] lazy;
		delete[] tree;
	}

return 0;
}
