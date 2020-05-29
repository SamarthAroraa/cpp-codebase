#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

class node{
public:
	int weight;
	// char c;
	node** map;
	node(){
		// this->c='1';
		this->weight=0;
		map=new node*[26];
		for(int i=0;i<26;i++){
			map[i]=NULL;
		}
	}
};

void insert(string s, node* head,int weight)
{	int n=s.length();
	node* curr= head;
	for(int i=0;i<n;i++){
		if(curr->map[(int)(s[i]-'a')]!=NULL){
			curr=curr->map[(int)(s[i]-'a')];
			if(curr->weight<weight){
				curr->weight=weight;
			}
		}
		else{
			curr->map[(int)(s[i]-'a')]= new node();
			curr=curr->map[(int)(s[i]-'a')];
			// curr->c= s[i];
			curr->weight=weight;
		}
	}
}

int maxweight(node* head, string search){
	int n=search.length();
	int maxwt=-1;
	node* curr= head;
	for(int i=0;i<n;i++){
		if(curr->map[search[i]-'a']!=NULL){
			curr=curr->map[search[i]-'a'];
			maxwt=curr->weight;
		}
		else{
			return -1;
		}
	}
return maxwt;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	node* head= new node();
	for(int i=0;i<n;i++){
		string s;
		int w;
		cin>>s>>w;
		insert(s,head,w);
	}
	for(int i=0;i<q;i++){
		string search;
		cin>>search;
		cout<<maxweight(head,search)<<"\n";
	}



return 0;
}