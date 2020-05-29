//
//  main.cpp
//  INGEN01
//
//  Created by Samarth Arora on 16/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>

using namespace std;
string decode(string inp){
    //A101 Z132
    int s=inp.size();
    string decoded="";
    for (int i=0; i<s; i++) {
        if(inp[i]==' ')
            decoded+=inp.sub;
            
    }
    cout<<decoded<<endl;
    for(int i=0;i<s;i++){
        if((int)decoded[i]>=113)
            decoded[i]=decoded[i]-12;
        else
        {
            int offset=(int)decoded[i]-101;
            offset=12 - offset;
            offset=132- offset;
            char ch=(char)offset;
            decoded[i]=ch;
            
        }
            
                               
    }
    cout<<decoded<<endl;
    for(int i=0;i<s-1;i++){
        if(decoded[i]=='Q' and decoded[i+1]=='Q')
        {
            decoded[i]=' ';
            decoded.erase(decoded.begin()+i+1);
            i++;
        }
    }
    return decoded;
    
}

int main()
{
    string test;
    cin>>test;
    cout<<decode(test);
    return 0;
}
