#include<string.h>
#include<vector>
#include<iostream>
#include<iomanip>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
// int solve(string & str, int isolations[], int n){
// 	std::vector<int> one_indexes;
// 	int last_index=0;
// 	for(int i=0;i<n;i++){
// 		if(str[i]=='1'){
// 			one_indexes.push_back(i);
// 		}
// 	}
// 	if(one_indexes.size()==0)
// 		return 0;

// 	last_index=one_indexes[0];


// }

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start); 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string arr;
		cin>>arr;
		int d;
		cin>>d;
		int isolations[d];
		for(int i=0;i<d;i++){
			cin>>isolations[i];
			isolations[i]--;
		}
		int count=0;
		std::vector<bool > boundary(n,0);
		for(int i=0;i<d;i++){
			boundary[isolations[i]-1]=1;
			// err<<"\n";
			count=0;
			// deb(isolations[i]-1)
			for(int i=0;i<n;i++){
				if(arr[i]=='1'){
					count++;
					if(i!=0){
						if(boundary[i-1]==0 and arr[i-1]!='1'){
							arr[i-1]='1';
							count++;
						}
					}
					if(i!=n-1){
						if(boundary[i]==0 and arr[i+1]!='1'){
						arr[i+1]='1';
						count++;
						i++;
					}
					
					}

				}
			}
			// deb(arr)
			// deb(count)
		}
		// int ocunt=0;
		// for(int i=0;i<n;i++){
		// 	if(arr[i]=='1')
		// 		ocunt++;
		// }
		cout<<count<<"\n";

	}
	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}


