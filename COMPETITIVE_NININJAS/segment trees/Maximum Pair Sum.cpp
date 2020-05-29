#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	node* left;
	node* right;
	int one, two;
	node(){
		this->left= NULL;
		this->right= NULL;
	}
};

node* buildtree(node* head, int s, int e,int arr[],int ad, node* tree){
	node * newnode= new node;
	if(s==e){
		newnode->one= arr[s];
		newnode->two=INT_MIN;
		tree[ad].one= arr[s];
		tree[ad].two=INT_MIN;
		return newnode	;
	}
	int m=(s+e)/2;
	newnode->left= buildtree(newnode->left,s,m,arr,2*ad,tree);
	newnode->right= buildtree(newnode->right,m+1,e,arr,2*ad+1,tree);
	newnode->one=max(newnode->left->one,newnode->right->one);
	newnode->two=min(max(newnode->left->two,newnode->right->one), max(newnode->left->one,newnode->
		right->two));
	tree[ad].one= newnode->one;
	tree[ad].two= newnode->two;
	return newnode;
}

pair<int,int>* query(node* tree,int s,int e, int ad,int lind , int rind){
	pair<int,int>* ret= new pair<int,int>;
	if(s>rind or e<lind)
	{
		// pair<int,int> ret;
		ret->first=INT_MIN;
		ret->second=INT_MIN;

		return ret;
	}
	if(s==e){
		ret->first=tree[ad].one;
		ret->second=INT_MIN;
	
		return ret;
	}

	if(s>=lind and e<=rind){
		// pair<int,int> ret;

		ret->first= tree[ad].one;
		ret->second= tree[ad].two;

		return ret;
	}
	int m=(s+e)/2;
	pair<int,int>*leftka=query(tree,s,m,2*ad,lind,rind);
	pair<int,int>*rightka=query(tree,m+1,e,2*ad+1,lind,rind);
	// pair<int,int> ret;
	ret->first=max(leftka->first,rightka->first);
	ret->second=min(max(leftka->second,rightka->first), max(leftka->first,rightka->second));
	
	return ret;
}
void update(int *arr, node* tree, int n,int s, int e, int ad, int index, int val){
	if(s==e and s==index){
		tree[ad].one=val;
		return;
	}
	if(s==e)
		return;
	int m= (s+e)/2;
	update(arr,tree,n,s,m,2*ad,index,val);
	update(arr,tree,n,m+1,e,2*ad+1,index,val);
	tree[ad].one= max(tree[ad*2].one, tree[ad*2+1].one);
	tree[ad].two= min(max(tree[ad*2].one,tree[ad*2+1].two),max(tree[ad*2].two,tree[ad*2+1].one));
	return;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	node* tree= new node[3*n];

	node* head= new node;

	buildtree(head, 0, n-1,arr,1,tree);
	int q;
	cin>>q;
	while(q--){
		char type;
		int l,r;
		cin>>type>>l>>r;

		if(type=='Q'){
			pair<int,int>* res=query(tree,0,n-1,1,l-1,r-1);
			cout<<res->first+res->second<<endl;
		}
		else{
			update(arr,tree,n,0,n-1,1,l,r);
		} 
	}

	// for(int i=1;i<4*n;i++){
	// 	cout<<tree[i].one<<"\t"<<tree[i].two<<endl;
	// }
	// pair<int,int>*q= query(tree,0,n-1,1,1,3);
	// cout<<q->first<<" "<<q->second<<endl;
	delete [] tree;

return 0;
}