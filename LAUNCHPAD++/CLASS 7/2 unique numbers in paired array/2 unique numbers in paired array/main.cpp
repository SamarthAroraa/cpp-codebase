//
//  main.cpp
//  2 unique numbers in paired array
//
//  Created by Samarth Arora on 08/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int arr[]={7,2,2,3,4,4};
    int xornum=arr[0];
    for(int i=1;i<6;i++){
        xornum=arr[i]^xornum;
    }
    int tempxor=xornum;
    int setbit=0;
    while(xornum!=0){
        if((xornum&1)==1){
            break;
        }
        xornum=xornum>>1;
        setbit++;
        
    }
    int partialxor=0;
    for(int i=0;i<6;i++){
        int k=arr[i];
        for(int j=0;j<setbit;j++){
            k=k>>1;
        }
        if((k&1)==1){
            if(partialxor==0){
                partialxor=arr[i];
            continue;
            }
            else{
                partialxor=partialxor^arr[i];
            }
        }
    }
    cout<<partialxor<<endl;
    cout<<(partialxor^tempxor)<<endl;
    
    return 0;
}

