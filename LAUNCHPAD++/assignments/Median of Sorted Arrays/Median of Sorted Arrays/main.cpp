//
//  main.cpp
//  Median of Sorted Arrays
//
//  Created by Samarth Arora on 31/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

int* merge(int arr1[],int arr2[],int n){
    int i=0,j=0;
    int k=0;
    int mrged[2*n];
    int* first=mrged;
    while(k<2*n and j<n and i<n){
        if(arr1[i]>=arr2[j]){
            mrged[k]=arr2[j];
            j++;
            
        }
        else{
            mrged[k]=arr1[i];
            i++;
            
        }
        
        k++;
        
    }
    
    return first;
}



int main()
{
    int n;
    int* arr=nullptr;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
        
    }
    arr=merge(arr1,arr2,n);
    float  median=(*(arr + n)+*(arr+(n-1)))/2;
    cout<<median;
    
    
    return 0;
}


