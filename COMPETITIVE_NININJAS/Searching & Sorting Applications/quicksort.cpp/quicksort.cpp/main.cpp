//
//  main.cpp
//  quicksort.cpp
//
//  Created by Samarth Arora on 11/01/20.
//  Copyright © 2020 Samarth Arora. All rights reserved.
//

#include <iostream>

#include<algorithm>
using namespace std;

int partition(int arr[], int si, int ei){
     int count=0;
    for(int i=si+1;i<=ei;i++){
        if(arr[si]>=arr[i])
            count++;
    }
    swap(arr[si], arr[si+count]);
    int i=si,j=ei;
    while(i!=(si+count) and j!=(si+count)){
        if(arr[i]>arr[si+count] and arr[j]<arr[si+count]){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if(arr[j]<arr[si+count]){
            i++;
        }
        else {
            j--;
        }
    }
    
return (si+count);
}

void quick(int arr[], int si, int ei){
    if(si<ei){
        int c=partition(arr, si,ei);
        quick(arr, si,c-1);
        quick(arr, c+1, ei);
        
    }
    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
void quickSort(int input[], int size) {
  quick(input,0,size-1);

}
int main() {
    int arr[]={5,4,3,2,1};
    quickSort(arr, 5);
    
    return  0;
}
