//
//  main.cpp
//  Hollow Rhombus Pattern
//
//  Created by Samarth Arora on 28/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int breadth=n-2,initspace=n-1,k,i;
    for(i=0;i<n;i++){
        k=0;
//        while(k<2*n-1){
            for(int b=0;b<initspace;b++){
                cout<<" ";
            }
            if(i==0 or i==n-1){
                for(int b=0;b<n;b++){
                    cout<<"*";
                }
            }
            else{cout<<"*";
                for(int b=0;b<breadth;b++){
                    cout<<" ";
                }
                cout<<"*";
            }
//            k++;
            initspace--;
        cout<<endl;
        }
    
    
    return 0;
}

