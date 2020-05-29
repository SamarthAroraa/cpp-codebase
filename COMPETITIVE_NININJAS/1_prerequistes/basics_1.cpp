#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen
    int n;
    cin>>n;
    int diagsum=0;
    int arr[n][n];
    //accepting matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(i==j or i==n-j-1){
                diagsum+=arr[i][j];
            }
        }
    }
    if((n & 1)!=0){
        diagsum-=arr[n/2][n/2];
    }
    
    int boundsum=0;
    //boundary sum
    //left side
    for(int i=1;i<n-1;i++){
        boundsum+=arr[i][0];
    }
    
    //right side
    for(int i=1;i<n-1;i++){
        boundsum+=arr[i][n-1];
    }
    
    //bottom side
    for(int i=1;i<n-1;i++){
        boundsum+=arr[n-1][i];
    }
    
    // top side
    for(int i=1;i<n-1;i++){
        boundsum+=arr[0][i];
    }
    cout<<boundsum+diagsum;
	return 0;
}
