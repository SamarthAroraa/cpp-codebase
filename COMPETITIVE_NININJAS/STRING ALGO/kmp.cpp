#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void pi_table(string s,int arr[],int n)
{
	arr[0]=0;
	int i=1,j=0;
	while(i<n and j<n){
		if(s[i]==s[j]){
			arr[i]=j+1;
			j++;
			i++;

		}
		else{
			if(j!=0)
			j=arr[j-1];
		else{
		arr[i++]=0;
		}

	}
}
}
	
int kmp(string text, string pattern, int arr[], int n){
	int m= text.length();
	int stin=-1;
	int i=0,j=0;
	int len=0;
	while(i<m and j<n){
		if(text[i]==pattern[j]){
			j++;
			i++;
			len++;
		}
		else{
			if(j!=0){
				j=arr[j-1];
				stin=i+1;
			}
		else{
			stin=i+1;
			i++;
		}
		}
	}
	if(j==n)
		return stin;
	else return -1;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s,text;
	// cin>>text;
	getline(cin,text,'\n');
	cin>>s;
	int arr[s.length()];
	pi_table(s,arr,s.length());
	for(int i=0;i<s.length();i++){
		cout<<arr[i]<<' ';
	}
	cout<<"\n";
	cout<<kmp(text,s,arr,s.length());


return 0;
}