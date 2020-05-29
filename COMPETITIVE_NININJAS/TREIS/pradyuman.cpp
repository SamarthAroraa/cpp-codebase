#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

class node{
public:
	int weight;
	// char c;
	bool term;
	node** map;
	node(){
		// this->c='1';
		this->term= false;
		this->weight=0;
		map=new node*[26];
		for(int i=0;i<26;i++){
			map[i]=NULL;
		}
	}
};

void insert(string s, node* head)
{	int n=s.length();
	node* curr= head;
	for(int i=0;i<n;i++){
		if(curr->map[(int)(s[i]-'a')]!=NULL){
			curr=curr->map[(int)(s[i]-'a')];

		}
		else{
			curr->map[(int)(s[i]-'a')]= new node();
			curr=curr->map[(int)(s[i]-'a')];
		}
		if(i==n-1){
				curr->term=1;
		}
	}
}

void dfs(node* head, string res){
	if(head==NULL){
		return;
	}
	if(head->term){
		cout<<res<<endl;
	}
	for(int i=0;i<26;i++){
		if(head->map[i]!=NULL){
			dfs(head->map[i],res+((char)('a' + i)));
		}
	}
}

void getresults(node* head, string s){
	int n=s.length();
	node* curr=head;
	string res="";
	for(int i=0;i<n;i++){
		if(curr->map[(int)(s[i]-'a')]!=NULL){
			curr=curr->map[(int)(s[i]-'a')];
			res+=s[i];
			// if(curr->term){
			// cout<<res<<'\n';
			// }
		}
		else{
			cout<<"No suggestions\n";
			insert(s,head);
			return;
		}
	}
	dfs(curr,res);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n;
	node* head= new node();
	for(int i=0;i<n;i++){
		string s;
		// int w;
		cin>>s;
		insert(s,head);
	}
	cin>>q;

	for(int i=0;i<q;i++){
		string search;
		cin>>search;
		// cout<<maxweight(head,search)<<"\n";
		getresults(head,search);
	}



return 0;
}