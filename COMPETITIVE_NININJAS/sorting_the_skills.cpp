#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

bool merge(long long  arr[], long long  l, long long  m, long long  r) 
{ 
    long long  i, j, k; 
    long long  n1 = m - l + 1; 
    long long  n2 =  r - m; 
  
    /* create temp arrays */
    long long  L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    if(n1>1 or n2>1)
    	{
    		if(abs(L[n1-1]-R[0])!=1)
    			return false;
    	}
  
    /* Merge the temp arrays back long long o arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
    	
    	
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    
}
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
return true;} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
bool mergesort(long long  l, long long  r, long long  arr[]){
	if(l<r){
		long long  m= (l+r)/2;
		mergesort(l,m,arr);
		mergesort(m+1,r,arr);
		bool res=merge(arr,l,m,r);
		if(!res)
			return false;

	}
return true;	
}

int  main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    long long  t;
    cin>>t;
    long long  k=0; 
    while(t--){
    k++;

	long long  n;
    cin>>n;
    long long  input[n];

    for(long long  i=0;i<n;i++){
        cin>>input[i];

    }
    bool m= mergesort(0, n-1,input);
    if(k==6){
        cerr<<n<<endl;
    for(long long  i=0;i<n;i++){
        cerr<<input[i]<<" ";

    }
    cerr<<endl;
}
m=true;
    for(int i=1;i<n;i++){
        if(input[i]<input[i-1])
            m=false;

    }
if(m)
    cout<<"Yes"<<endl;
else
{
        cout<<"No"<<endl;
    }
}

return 0;
}