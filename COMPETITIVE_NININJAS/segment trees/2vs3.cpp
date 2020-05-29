#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
std::vector<int> mod2(10e5,1);


void buildtree(int *tree, string str, int s, int e, int ad){
	if(s==e){
		tree[ad]=(int)(str[e]-'0');
		return;
	}
	int m= (s+e)/2;
	buildtree(tree, str,  s, m, 2*ad );
	buildtree(tree, str,  m+1, e, 2*ad+1 );
	int index= e-m;

	// if(!mod2[index])
	
	
	tree[ad]= ((tree[2*ad]*mod2[index])%3+tree[2*ad+1]%3)%3;
	return;
}

int query(int * tree, string str,int s, int e, int ad, int lind, int rind){
	if(s>rind or e<lind)
		return 0;
	if(s>=lind and e<=rind){
		return (tree[ad]*mod2[rind-e])%3;
	}
	int m= (s+e)/2;
	int r= query(tree, str, m+1, e, 2*ad+1,lind,rind);
	int l= query(tree, str, s, m, 2*ad,lind,rind);
	
	
	return(r+l)%3;
}
  void update(int* tree, int st, int en, int idx, int i,string arr)
{
    if(st == en)
    {
        tree[i] = 1;
        arr[idx] = 1;
    }
    else
    {
        ll mid = (st + en) / 2;
        if(st <= idx and idx <= mid)
        {
            update(tree,st,mid,idx,2*i, arr);
        }
        else
        {
            update(tree,mid+1,en,idx,2*i+1, arr);
        }
        tree[i] = ((tree[2*i]*mod2[en-mid]%3) + tree[2*i+1])%3;
    }
}
// void update(int *tree, int s, int e, int ind , int ad){
// 	if(s==e and s==ind){
// 			tree[ad]=1;
// 			return;
// 	}
// 	if(s==e)
// 		return;
// 	int m= (s+e)/2;
// 	if(m<=ind ){
// 		update(tree, m+1,e,ind, 2*ad+1);
		
// 	}

// 	else{
// 		update(tree, s,m,ind, 2*ad);
// 	}

// 	tree[ad]= ((tree[2*ad]*mod2[e-m])%3+tree[2*ad+1]%3)%3;
// 	return;
// }
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	string str;
	cin>>str;
	
	int *tree= new int[3*n];
	for(int i=1;i<10e5;i++){
	mod2[i]= 2*mod2[i-1]%3;
	// deb(mod2[i])
}
	buildtree(tree,str,0,n-1,1);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(!type){
			int l,r;
			cin>>l>>r;
			cout<<query(tree,str,0,n-1,1,l,r)<<endl;

		}
		else{
			int i;
			cin>>i;
			update(tree,0,n-1,i,1,str);
			
		}
	}
	// cerr<<"ans"<<query(tree, str,0,n-1,1,2,4);

return 0;
}