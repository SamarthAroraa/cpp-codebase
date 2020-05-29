#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
unordered_map <int, int > mapping;
class quer{
	char type;
	int p;
};
void insert(int val,int idx, int BIT,int n){
	for(;idx<=n;idx+=(idx&-idx)){
		BIT[idx]+=val;
	}
}

int query(int idx, vector <int>& BIT, int n){
	int ans=0;
	for(;idx>0;idx-=(idx&-idx)){
		ans+=BIT[idx];
	}
	return ans;
}

void insert(int p, std::vector<int>& BIT, int n){
	if(query(mapping[p],BIT,n)==query(mapping[p]-1,BIT,n)){
		insert(1,mapping[p],BIT, n);
	}
}

void deleteelem(int p,std::vector<int>&BIT, int n){
	if(query(mapping[p],BIT,n)!=query(mapping[p]-1,BIT,n)){
		insert(-1,mapping[p],BIT,n);
	}
}
int kthsmallest(std::vector<int> BIT, int k,int n){
	// int l=1,hn,mid=(l+h)/2;
	// while(l<h){
	// 	mid=(l+h)/2;
	// 	if(query(mappign[mid,BIT,n)>k){
	// 		l=mid+1;
	// 	}
	// 	if(query(mid,BIT,n)<k)
	// 	{
	// 		h=mid-1;
	// 	}
	// 	else{
	// 		return 
	// 	}
	// }
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	int q;
	cin>>q;
	unordered_map<int,bool> occ;
	std::vector<int> elements;
	quer arr[q];
	while(q--){
		cin>>arr[i].type;
		cin>>arr[i].p;
		if(type=='I'){
			if(occ[p]==0){
				elements.push_back(p);
			}
		}

	}
	//compression
	int n=0;
	sort(elements.begin(),elements.end());
	for(int i=0;i<elements.size();i++){
		mapping[elements[i]]=i+1;
		n++;
	}

	std::vector<int> BIT(n+1,0);



	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}