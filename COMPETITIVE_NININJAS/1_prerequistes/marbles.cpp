#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
int n,k,e;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    // bool flag=0;
    for(int i=0;i<n;i++){
        int sum=arr[i];
        if(sum==k)
            {	cout<<"true\n";
               
                    cout<<arr[i]<<" ";

                
            return 0;
            }
            else if(sum>k){
                continue;
            }
        for(int j=i+1;j<n;j++){
            sum+=arr[j];

            if(sum==k)
            {	cout<<"true\n";
                for(int m=i;m<=j;m++){
                    cout<<arr[m]<<" ";

                }
            return 0;
            }
            else if(sum>k){
                break;
            }
        }
    }

    cout<<"false";
return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int main() {

//     int n,k,e;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
        
//     }
    
//     for(int i=0;i<n;i++){
//         int sum=arr[i];
//         for(int j=i+1;j<n;j++){
//             sum+=arr[j];
//             if(sum==k)
//             {
//                 for(int m=i;m=j;m++){
//                     cout<<arr[m]<<" ";
//                 }
//             return 0;
//             }
//             else if(sum>k){
//                 break;
//             }
//         }
//     }
// 	return 0;// Write your code here
// }