#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node
{
public:
	node* left;
	node* right;
 
	node(){
		this->left=NULL;
		this->right=NULL;
	}
	
};
void insert(int n, node* head){
	int i=31;
	node* curr= head;
	while(i>=0){
		int k=n>>i;
		if((k&1)==1){
			if(curr->right!=NULL){
			curr=curr->right;
		}
		else{
			curr->right= new node();
			curr=curr->right;
		}

		}
		else{
			if(curr->left!=NULL){
			curr=curr->left;
		}
		else{
			curr->left= new node();
			curr=curr->left;
		}
		}

	i--;
	}

}
int findmaxxorp(node* head, int *arr, int n){
	int max_xor=INT_MIN;
	for(int i=0;i<n;i++){
		int k=arr[i];
		// int j=30;
		node* curr=head;
		int ans=0;
		for(int j=31;j>=0;j--){
			int b=k>>j;
			if((b&1)==0){
				if(curr->right!=NULL){
					curr=curr->right;
					int k=1<<j;
					ans+=k;
				}
				else{
					curr=curr->left;
				}
			}
			else{
				if(curr->left!=NULL){
					ans+=(1<<j);
					curr=curr->left;
				}
				else{
					curr=curr->right;
				}
			}
		}
			max_xor=max(ans,max_xor);
	
	}
return max_xor;}

int main(){ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* head= new node;
	int arr[6]={8,1,2,15,10,5};
	for(int i=0;i<6;i++){
		insert(arr[i],head);
	}
	cout<<findmaxxorp(head,arr,6);


return 0;
}