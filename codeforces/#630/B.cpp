#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class color{
public:
	int c;
	int count;
	color(){
		this->c=0;
		this->count=0;
	}
};
int __gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return __gcd(b,a);
}
void solve(int arr[], int n){
	color colors[n];
	
	
	int m=1;
	for(int i=0;i<n;i++){
		int count=0;
		for(int j=i+1;j<n;j++){
			if(__gcd(arr[i],arr[j])>1)
				count++;
		}
		for(int j=i-1;j>=0;j--){
			if(__gcd(arr[i],arr[j])>1)
				count++;
		}
		for(int j=i+1;j<n;j++){
			if(__gcd(arr[i],arr[j])>1){
				if(colors[j].c==0){
					colors[j].c=m;
				}
				else{
					if(colors[j].count<count and colors[j].count!=1){
						colors[j].c=m;
						colors[j].count=count;
					}
				}
			}
		}
		for(int j=i-1;j>=0;j--){
				if(__gcd(arr[i],arr[j])>1 ){
				if(colors[j].c==0){
					colors[j].c=m;
				}
				else{
					if(colors[j].count<count and colors[j].count!=1){
						colors[j].c=m;
						colors[j].count=count;
					}
				}
			}
		}
		m++;
	}
	int g=0;
	unordered_set<int> seet;
	int l=INT_MAX,mx=INT_MIN;
	for(int i=0;i<n;i++){
		if(seet.count(colors[i].c)==0){
			mx=max(colors[i].c,mx);
			l=min(colors[i].c,l);
			seet.insert(colors[i].c);
			g++;
		}
	}
	cout<<g<<"\n";
	for(int i=0;i<n;i++){
		cout<<colors[i].c-(mx-l)<<" ";
	}
	cout<<"\n";
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
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		solve(arr,n);
	}


return 0;
}