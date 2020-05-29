#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	node* left;
	node* right;

	int val;
	node(){
		this->left=NULL;
		this->right=NULL;
		val=0;
	}
};

node* buildtree(int arr[], int s,int e,int tree[],int address){
	node* returning= new node;
	if(s>=e){
		returning->val= arr[s];
		tree[address]=arr[s];
		return returning; 
	}
	int mid= floor((double)(s+e)/2);
deb(mid)
deb(s)
deb(e)
cerr<<endl;
	returning->left= buildtree(arr,s,mid,tree,address*2 );
	returning->right= buildtree(arr, mid+1, e,tree, address*2+1);
	returning->val= returning->left->val+returning->right->val;
	tree[address]=returning->val;
	return returning;

}

void printtree(node* head){
	if(head==NULL)
		return;
	cout<<head->val<< " ";

	printtree(head->left);
	printtree(head->right);
	return;
}
void update(int newval, int index, node* head,int tree[],int address,int start, int end){
	if(start==end and start==index){
		head->val=newval;
		tree[address]= newval;
		return;
	}
	int mid= (start+end)/2;
	if(index<=mid){
		update(newval,index,head->left,tree,address*2,start,mid);
		
	}
	else{
		update(newval,index,head->right,tree,address*2+1,mid+1,end);
		
	}
	head->val= head->left->val+head->right->val;
	tree[address]= head->val;
}

int query(int lind, int rind, node* head,int s, int e){
	if(head==NULL)
		return 0;
	int m=(s+e)/2;
	
	if(s>=lind and e<=rind){
		return head->val;
	}
	else if((s>=lind and e>=rind)){
		return query(lind,rind,head->right,m+1,e)+query(lind,rind,head->left,s,m);
	}
	else if(s<=lind and e<=rind){
		return query(lind,rind,head->right,m+1,e)+query(lind,rind,head->left,s,m);
	}
	// if(s>rind or e<lind)
	return 0;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int arr[]={1,2,3};
	int n= sizeof(arr)/sizeof(int);
	int * segment= new int[2*n];

	node* head = new node;
 head=buildtree(arr,0,n-1,segment,1);
 // printtree(head);
 for(int i=1;i<2*n;i++){
 	cout<<segment[i]<<" ";
 }
 cout<<endl;
 update(5,1,head,segment,1,0,n-1);
 for(int i=1;i<2*n;i++){
 	cout<<segment[i]<<" ";
 }
 cout<<"\n"<<query(1,1,head,0,n-1);

return 0;
}