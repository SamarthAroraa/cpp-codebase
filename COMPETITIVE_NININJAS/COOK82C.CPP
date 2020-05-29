#include<bits/stdc++.h>

#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long


using namespace std;
void printq(priority_queue <ll> q)
ll  answer(std::vector<ll > arr,ll  m){
	 priority_queue <ll > q;
	 ll  n = arr.size();
	 for(ll  i=0;i<n;i++){
	 	q.push(arr[i]);
	 }
	 m--;
	 for(ll  i=0;i<m;i++){
	 	ll  t= q.top();
	 	q.pop();
	 	t/=2;
	 	if(t!=0)
	 	q.push(t);
	 }
return q.top();
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  n,m;
	cin>>n>>m;
	std::vector<ll > arr(n);
	for(ll  i=0;i<n;i++)
		cin>>arr[i];
	for(ll  i=0;i<m;i++){
	ll  q;
	cin>>q;
	cout<<answer(arr,q)<<endl;
}
return 0;
}