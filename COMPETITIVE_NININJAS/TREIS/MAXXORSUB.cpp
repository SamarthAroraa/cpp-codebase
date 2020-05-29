#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	node* left;
	node* right;
	node(){
		this->left=NULL;
		this->right=NULL;
	}
};
void insert(node* head, int num){
	int i=31;
	node* curr= head;
	while(i>=0){
		int k= num>>i;
		if((k&1)==0)
		{
			if(curr->left!=NULL){
				curr= curr->left;
			}
			else{
				curr->left= new node();
				curr=curr->left;
			}
		}
		else{
			if(curr->right!=NULL){
				curr= curr->right;
			}
			else{
				curr->right= new node();
				curr=curr->right;
			}

		}
		i--;
	}
}
int helper(node* head, int e){
	node* curr= head;
	// int globmax=INT_MIN;
	int ans=0;
	for(int i=31;i>=0;i--){
		int k= e>>i;
			

		if((k&1)!=0){
			if(curr->left!=NULL){
				ans+=(1<<i);
				curr=curr->left;
			}
			else{
				curr=curr->right;
			}
		}
		else{
			if(curr->right!=NULL){
				curr=curr->right;
				ans+=(1<<i);
			}
			else{
				curr= curr->left;
			}
		}
	}
return ans;
}

int returnmax(int arr[], int n){
	int globmax=INT_MIN;
	node* head= new node();
	int previousxor=arr[0];
	for(int i=0;i<n;i++){
		previousxor= previousxor^arr[i];
		insert(head,previousxor);
		// deb(arr[i])
		int currmax=helper(head,previousxor);
		
		globmax= max(currmax,globmax);
	}
return globmax;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<returnmax(arr,n)<<"\n";





return 0;
}