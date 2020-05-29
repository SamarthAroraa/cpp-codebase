//
//  main.cpp
//  Basic Calculator
//
//  Created by Samarth Arora on 27/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    char ch='0';
    while(1){
    cin>>ch;
        if(ch=='X' or ch=='x')
            break;
    int a,b;
    switch (ch) {
        case '+':
            cin>>a>>b;

            cout<<a+b<<endl;
            break;
        case '-':
            cin>>a>>b;

            cout<<a-b<<endl;
            break;
        case '*':
            cin>>a>>b;

            cout<<a*b<<endl;
            break;
        case '/':
            cin>>a>>b;

            if(b!=0)
            cout<<a/b<<endl;
            break;
        case '%':
            cin>>a>>b;

            if(b!=0)
            cout<<a%b<<endl;
            break;
        default:
            cout<<"Invalid operation. Try again."<<endl;
            break;
    }
    }
    return 0;}
