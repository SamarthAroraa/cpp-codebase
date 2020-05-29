#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
	set<int> unique;

	for(int i=0;i<size;i++)
		unique.insert(arr[i]);
	set<int>::iterator it;
	std::vector<int> arr2;
	for(it=unique.begin();it!=unique.end();it++){
		arr2.push_back(*it);
	}
	size= arr2.size();
    sort(arr2.begin(),arr2.end());
    for(int i=0;i<size-2;i++){
        int ele= x-arr2[i];
        for(int j=i+1;j<size-1;j++){
            int el1= ele- arr2[j];
            if( binary_search(arr2.begin()+j+1,arr2.end(), el1))
                cout<<arr2[i]<<" "<<arr2[j]<<" "<<el1<<endl;
            
        }
    }

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x;
	cin>>x;
	FindTriplet(arr,n,x);
return 0;
}