//
//  main.cpp
//  Revising Quadratic Equations
//
//  Created by Samarth Arora on 29/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include  <math.h>
using namespace std;
int main()
{   signed int a,b,c;
    cin>>a>>b>>c;
    
    if(b*b==4*a*c){
        cout<<"Real and Equal"<<endl;
        cout<<(float)-b/(2*a)<<" "<<(float)-b/(2*a);
        
    }
    
    else if(b*b>4*a*c){
        cout<<"Real and Distinct"<<endl;
        float root1=(-b+pow(b*b-4*a*c,0.5))/2*a;
        float root2=(-b-pow(b*b-4*a*c,0.5))/2*a;
        if(root2>root1)
        cout<<root1<<" "<<root2<<endl;
        else
            cout<<root2<<" "<<root1<<endl;
            

    }
    else{
        cout<<"Imaginery";
    }
    
    
    return 0;
    
}
