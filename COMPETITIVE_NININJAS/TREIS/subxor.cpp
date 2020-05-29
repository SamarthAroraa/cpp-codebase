#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class node{
public:
	node* left;
	node* right;
	int leafel;
	node(int n){
		this->leafel=n;
		this->left=NULL;
		this->right=NULL;
	}
};

void insert(node* head, int num){
	int i=31;
	node* curr= head;
	while(i>=0){
		int k= num>>i;
		curr->leafel++;
		if((k&1)==0)
		{
			if(curr->left!=NULL){
				curr= curr->left;
			}
			else{
				curr->left= new node(1);
				curr=curr->left;
			}
		}
		else{
			if(curr->right!=NULL){
				curr= curr->right;
			}
			else{
				curr->right= new node(1);
				curr=curr->right;
			}

		}
		i--;
	}
	// curr->leafel++;
}
int maxxor(node* head, int num, int k){
	node* curr= head;
	int ans=0;
	for(int i=31;i>=0;i--){
		int j= num>>i;
		int m=k>>i;
		if(m==1 and j==1){
			if(curr->right!=NULL){
				ans+=curr->right->leafel;
			}
			if(curr->left!=NULL)
			{
				curr= curr->left;
			}
			else{
				break;
			}
		}

		if(m==1 and j==0){
			if(curr->left!=NULL){
				ans+=curr->left->leafel;
			}
			if(curr->right!=NULL)
			{
				curr= curr->right;
			}
			else{
				break;
			}
		}
		if(m==0 and j==1){
			if(curr->right!=NULL)
			{
				curr= curr->right;
			}
			else{
				break;
			}

		}
		if(m==0 and j==0){
			if(curr->left!=NULL)
			{
				curr= curr->left;
			}
			else{
				break;
			}

		}

	}
return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	int arr[n];
	node* head= new node(1);
	cin>>arr[0];
	int curr=(k>arr[0]) ? 1 : 0 ;
	int prev=arr[0];
	for(int i=1;i<n;i++){
		cin>>arr[i];
		prev=prev^arr[i];
		insert(head, prev);
		curr+=maxxor(head, prev,k);
	}
	cout<<curr<<"\n";
}



return 0;
}