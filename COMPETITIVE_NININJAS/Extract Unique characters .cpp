#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
string unique(string parent){
	set<char> pool;
	for(int i=0; i < parent.length(); i++){
		pool.insert(parent[i]);
	}
string res="";
set<char>::iterator it;
for(it= pool.begin(); it!= pool.end() ;it++){
    res+=(*it);
}
return res;
}
char* uniqueChar(char *str){
   set<char> pool;
    int i=0;
    while( str[i]!='\0')
    {
        pool.insert(str[i]);
        i++;
    }
int s=pool.size();
char res[s];
int j=0;
set<char>::iterator it;
for(it= pool.begin(); it!= pool.end() ;it++){
    res[j]=(*it);
    j++;
}
    return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	char inp[]="Bcr$gw)TcE5S@DHTFw76";
	char * out= uniqueChar(inp);
	int i=0;
	while(out[i]!='\0'){
		cout<<*(out+i);
		i++;
	}


return 0;
}