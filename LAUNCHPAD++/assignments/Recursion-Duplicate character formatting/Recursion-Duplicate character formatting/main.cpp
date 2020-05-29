//
//  main.cpp
//  Recursion-Duplicate character formatting
//
//  Created by Samarth Arora on 21/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string recursive(string str){
    //base case
    if(str.length()==0)
        return str;
    
    //rec part
    char ch=str[0];
    string sr=recursive(str.substr(1));
    if(ch==sr[0]){
        string star="*";
        string str2=ch+star;
        str2+=sr;
        return str2;
}
    else
    {
        string str2=ch+sr;
        return str2;
    }
    
}
string topi(string str){
    //base cse
    if(str.length()==0)
        return str;
    //recursive case
    string st=topi(str.substr(1));
    if(str[0]=='p' and st[0]=='i'){
        return "3.14"+st.substr(1);
        
    }
    else
        return str[0]+st;
}
string removerecc(string str){
    
    if(str.length()==0)
        return str;
    string st=removerecc(str.substr(1));
    if(str[0]==st[0])
        return st;
    else
        return str[0]+st;
}

int main()
{
    string str;
    cin>>str;
    cout<<removerecc(str);
//    cout<<topi(str)<<endl;
    return 0;
}
