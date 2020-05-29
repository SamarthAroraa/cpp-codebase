//
//  main.cpp
//  卐 Ganesha's Pattern
//
//  Created by Samarth Arora on 27/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if((n&1)==0)return 0;
    int wing=n/2;
    cout<<"*";
    for(int i=0;i<wing-1;i++)cout<<" ";
    for(int i=0;i<=wing;i++)cout<<"*";
    cout<<endl;
    
    for(int i=0;i<wing-1;i++){
//        for(int j=0;j<n;j++){
            cout<<"*";
            for(int m=0;m<wing-1;m++)
                cout<<" ";
//        }
        cout<<"*";
        cout<<endl;
        
    }
    for(int i=0;i<n;i++){
        cout<<"*";
        
    }
    cout<<endl;
    for(int i=0;i<wing-1;i++){
        for(int m=0;m<wing;m++){
            cout<<" ";
        }
        cout<<"*";
        for(int m=0;m<wing-1;m++){
            cout<<" ";
        }
        cout<<"*";
        
        cout<<endl;
        
    }
    for(int i=0;i<wing;i++){
        cout<<"*";
    }
//    cout<<endl;
    cout<<"*";
    for(int m=0;m<wing-1;m++){
        cout<<" ";
    }
    cout<<"*";
    return 0;
}
