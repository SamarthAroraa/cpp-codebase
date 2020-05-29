//
//  main.cpp
//  Decimal To Octal
//
//  Created by Samarth Arora on 11/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
long long n;
string dectobin(long long n){
    string ans="";
    while(n>0){
        int rem=n%8;
        char c=rem+'0';
        ans = c + ans;
        n=n/8;
    }
    if(ans[0]=='0'){
        ans=ans.substr(1);
    }
    return ans;

}

int main()
{

    cin>>n;

    cout<<dectobin(n)<<endl;
    return 0;
}
