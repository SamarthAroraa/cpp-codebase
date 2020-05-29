#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class event{
public:
	int first,second,i;

};
bool comparator(event a, event b){
	return a.second<b.second;
}

void update(int i, int val, int BIT[], int n){
	for(;i<=n;i+=(i&-i)){
		BIT[i]+=val;
	}
}
int value(int BIT[], int i){
	int ans=0;
	for(;i>0;i-=(i&-i)){
		ans+=BIT[i];
	}
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	// time(&start);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int q;
	cin>>q;
	event queries[q];
	for(int i=0;i<q;i++){
		cin>>queries[i].first>>queries[i].second;
		queries[i].i=i;
	}
	sort(queries,queries+q,comparator);
	int BIT[n+1];
	for(int i=0;i<=n;i++){
		BIT[i]=0;
	}
	int ans[q];
	int total=0;
	int k=0;
	int last[1000001];
	for(int i=0;i<1000001;i++){
		last[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(last[arr[i]]!=-1){
			update(last[arr[i]],-1,BIT,n);
		}
		else{
			total++;
		}
		update(i,1,BIT,n);
		last[arr[i]]=i;

		while(k<q and queries[k].second==i){
			ans[queries[k].i]=total-value(BIT, queries[k].first-1);
			k++;
		}
	}
		for(int i=0;i<q;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";


	


//code here

	// time(&end);
	// double time_taken = double(end - start); 
	// cerr << "Time taken by program is : " << fixed 
 //         << time_taken << setprecision(5); 
 //    cerr << " sec " << endl; 
return 0;
}