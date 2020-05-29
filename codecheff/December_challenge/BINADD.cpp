#include<bits/stdc++.h>
using namespace std;

int converttodec(string binary){
    int num=0;
    int power=0;
    int len=binary.length();
    for(int i=len-1;i>=0;i--){
        if(binary[i]=='1'){
            num+=(pow(2,power));
            
            }
        power++;}
    return num;
    
}

string bin_and(string a, string b){
	string result="";
	int i=0;
	while(i<a.length() and i<b.length())
{
	int a_d= a[i]-'0';
	int b_d=b[i]-'0';
	int res=b_d*a_d;
	// cerr<<a<< " "<<b<<" ";
	// cerr<<res<<" "<<i<<endl;
	char res_c= res + '0';
	result+=res_c;
	i++;

}
// while(i<a.length()){
// 	result+=a[i];
// 	i++;

// }
// while(i<b.length()){
// 	result+=b[i];
// 	i++;
// }
return result;
}

long ans(string a, string b){
	long decimal_a=converttodec(a);
	long decimal_b=converttodec(b);
	cerr<<

	long steps=0;
	while(decimal_b>0){
			b= std::bitset<20>(decimal_b).to_string();
		a= std::bitset<20>(decimal_a).to_string();
		// cerr<<"a"<<decimal_a<<endl;
		// cerr<<"b"<<decimal_b<<endl;
		steps++;
		long u= decimal_b^decimal_a;
		// cerr<<"xnxx.com"<<std::bitset<8>(decimal_a).to_string();
	




		long v= converttodec( bin_and(a,b));
		// cerr<<"v"<<v;
		decimal_a = u;
		decimal_b = v*2;
	}


return steps;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		string a ,b;
		cin>>a>>b;
		cout<<ans(a,b)<<endl;
	}


	return 0;
}