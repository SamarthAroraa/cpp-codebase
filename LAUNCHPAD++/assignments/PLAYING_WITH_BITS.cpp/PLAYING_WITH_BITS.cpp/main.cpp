//
//  main.cpp
//  PLAYING_WITH_BITS.cpp
//
//  Created by Samarth Arora on 27/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void tobin(int n,string& binary)
{
    binary+=(n%2);
    if(n>1)
        tobin(n/2,binary);
    
}

int main()

{   string binary;
    int a,b;
    int q;
    cin>>q;
    int count=0;
    while(q--){
        count=0;
        binary="";
        cin>>a>>b;
        for(int i=a;i<=b;i++){
        binary.clear();
        tobin(i,binary);
            for(int s=0;s<binary.length();s++){
                if(binary[s]==1)
                {
                    count++;
                }
            }
        }
        
        cout<<count<<endl;
        
    }
    
    return 0;
}
