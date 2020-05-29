#include<bits/stdc++.h>
using namespace std;

bool ans(string arr[]){
	string ans1="";
	string ans2="";
	stack <char> os;

	for(int i=0;i<arr[0].length();i++){
		if(arr[0][i]=='-')
		{	i++;
			os.pop();
		}
		else if(arr[0][i]==','){
			continue;
		}
		else{
			os.push(arr[0][i]);
		}

	}
	while(!os.empty()){
		string temp= "";
		temp= temp + "," + os.top();
		ans1=temp+ans1;
		os.pop();

	}
	for(int i=0;i<arr[1].length();i++){
		if(arr[1][i]=='-')
		{	i++;
			os.pop();
		}
		else if(arr[1][i]==','){
			continue;
		}
		else{
			os.push(arr[1][i]);
		}

	}
	while(!os.empty()){
		string temp="";
		temp = temp+ "," + os.top();
		ans2=temp+ans2;
		os.pop();

	}
	ans1=ans1.substr(1);
	ans2=ans2.substr(1);
cout<<ans1<<"<-------->"<<ans2<<endl;

return ans1==ans2;
// return 0;
}
int main(int argc, char const *argv[])
{
		//test strings go in below array
		string arr[]={"a,b,c,d,-B","a,b,a,-B,c"};
		cout<<ans(arr);
		return 0;
}