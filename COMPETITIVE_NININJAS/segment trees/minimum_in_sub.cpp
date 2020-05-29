#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void build(int* arr, int*tree, int n,int s,int e, int ad){
	if(s==e){
		tree[ad]= arr[s];
		return ;
	}
	int m= (s+e)/2;
	build(arr,tree,n,s,m,2*ad);
	build(arr,tree,n,m+1,e,2*ad+1);
	tree[ad]= min(tree[2*ad],tree[2*ad+1]);
	return; 
}
void update(int *arr, int* tree, int n,int s, int e, int ad, int index, int val){
	if(s==e and s==index){
		tree[ad]= val;
		return;
	}
	if(s==e)
		return;
	int m= (s+e)/2;
	update(arr,tree,n,s,m,2*ad,index,val);
	update(arr,tree,n,m+1,e,2*ad+1,index,val);
	tree[ad]= min(tree[ad*2], tree[ad*2+1]);
	return;
}
int query(int* tree, int n,int s, int e, int ad,int left, int right){
	if(s>right or e<left)
		return INT_MAX;
	if(s>=left and e<=right){
		return tree[ad];
	}
	return min(query(tree,n,s,(s+e)/2,2*ad,left,right),query(tree,n,(s+e)/2+1,e,2*ad+1,left,right));
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,q;
	cin>>n>>q;
	int* arr= new int[n];
	int* tree=new int[4*n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(arr,tree,n,0,n-1,1);
	while(q--){
		char type;
		 int x,y;
		cin>>type>>x>>y;
		if(type=='q')
			cout<<query(tree,n,0,n-1,1,x-1,y-1)<<endl;
		else{
			update(arr,tree,n,0,n-1,1,x-1,y);
		}
	}
	delete [] arr;
	delete [] tree;

return 0;
}