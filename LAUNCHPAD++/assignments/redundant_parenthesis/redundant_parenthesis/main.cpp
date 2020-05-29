//
//  main.cpp
//  redundant_parenthesis
//
//  Created by Samarth Arora on 13/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

bool checkred(vector<char> str){
    int i;
    stack<char> s;
    for(i=0;i<str.size();i++){
        if(str[i] == '('){
            s.push('(');
        }
        else if(str[i]==')'){
            if(s.top()=='o'){
                s.pop();
            
            if(s.top()=='(')
                s.pop();
            else
                return 0;
            }
            else return 1;
        }
        else{
            if(s.top()!='o')
            s.push('o');
        }
    }
    return s.empty();
    
}
int main()
{
    vector<char> vec;
    string str;
    cin>>str;
    int len;
    cin>>len;
    for(int i=0;i<len;i++){
        char c;
        cin>>c;
        vec.push_back(c);
        
    }
    cout<<checkred(vec);
    
    return 0;
}
