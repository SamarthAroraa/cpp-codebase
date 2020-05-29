
#include <bits/stdc++.h>

using namespace std;

int main()
{	
	#ifndef O_J
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

int t;
cin>>t;
string str;
while(t--){
	cin>>str;
	vector<int> leftbrack;
	vector<int> rightbrack;
	for(int i=0;i<str.length();i++){
		if(str[i]=='(')
		{
			leftbrack.push_back(i);
		}
		else if(str[i]==')'){
			rightbrack.push_back(i);
		}
	} 
	int lconsc=0, rconsc=0;
	if(leftbrack.size()!=rightbrack.size()){
		cout<<"Unbalanced!";
		continue;
	}
	for(int i=0;i<leftbrack.size()-1;i++){
		if(leftbrack[i]-leftbrack[i+1]==1 or leftbrack[i]-leftbrack[i+1]==-1)
		{
			lconsc++;
			i++;
		}
	}
	for(int i=0;i<leftbrack.size()-1;i++){
		if(rightbrack[i]-rightbrack[i+1]==1 or rightbrack[i]-rightbrack[i+1]==-1)
		{
			rconsc++;
			i++;
		}
	}
	if(rconsc==lconsc and rconsc!=0){
		cout<<"Duplicate"<<rconsc<<lconsc<<endl;

	}
	else 
	cout<<"Not Duplicates"<<rconsc<<lconsc<<endl;
	str.clear();
	leftbrack.clear();
	rightbrack.clear();

}


return 0;
}