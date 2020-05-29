#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;

#define ll long long
using namespace std;

vector <int> longestConsecutiveIncreasingSequence(int *arr, int n){
	int global_max=0;
	int start=-1;
	int min_ind=-1;
	int start_index=INT_MAX;
	unordered_map<int , pair<bool,int> > visited;
	for(int i=0;i<n;i++){
		visited[arr[i]].first=1;
		visited[arr[i]].second=i;
	}

	for(int i=0;i<n;i++){
		int len=1;
		int fwd=0;
		int bck=0;


		if(visited[arr[i]].first){
			visited[arr[i]].first=0;
			int a=1,b=1;
			cerr<<arr[i]<<endl;
			min_ind=i;
			while(visited[arr[i]+a].first==1){
				// deb(visited[arr[i]+a])
				deb(arr[i]+a)
				fwd++;
				deb(fwd)
				visited[arr[i]+a].first=0;
				a++;
			}

			while(visited[arr[i]-b].first==1){
				// deb(visited[arr[i]-b])
				deb(arr[i]-b)
				min_ind=visited[arr[i]-b].second;
				bck++;
				deb(bck)
				visited[arr[i]-b].first=0;
				b++;
			}
			deb(min_ind)
			
			len= 1+ fwd + bck;
			deb(len)

			if(len>global_max ){
				global_max=len;
				start=arr[i]-b+1;
				start_index=min_ind;
				cerr<<"\t\t"<<start<<endl;

			}
			else if(global_max==len){
				if(min_ind<start_index){
					start=arr[i]-b+1;
					start_index=min_ind;
					cerr<<"\t\t"<<start<<endl;
				}
			}
				cerr<<endl;
			}

		}
	std::vector<int> ret;
	deb(global_max)
	deb(start_index)
	for(int i=0;i<global_max;i++){
		ret.push_back(start+i);
	}
return ret;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int * arr=  new int[n];
	for(int i=0;i< n ; i++){
		cin>>arr[i];
	}
	longestConsecutiveIncreasingSequence(arr,n);

return 0;
}