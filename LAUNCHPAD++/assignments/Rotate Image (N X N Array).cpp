#include<bits/stdc++.h>
using namespace std;

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("output.txt","w",stdout);
// 	freopen("input.txt","r",stdin);
// 	#endif
// 	int n;
// 	cin>>n;
// 	int arr[n][n];
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cin>>arr[i][j];
// 		}
// 	}
// 	for(int j=n-1;j>=0;j--){
// 		for (int i = 0; i < n; i++){
// 			cout<<arr[i][j]<<" ";
// 		}

// 		cout<<"\n";
// 	}

// }
// long maxg=-1000000000;
// long arr;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif
int m,n;
cin>>m>>n;
int arr[m][n];
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		cin>>arr[i][j];
	}
}
int i=0;
for(int j=0;j<n;j++){
	if(i==m){
		i--;
		while(i>=0){
			cout<<arr[i][j]<<", ";
			i--;
		}i++;

	}
	else if(i==0){
		while(i<m){
			cout<<arr[i][j]<<", ";
			i++;
		}
	}
}
cout<<"END";
return 0;
}









