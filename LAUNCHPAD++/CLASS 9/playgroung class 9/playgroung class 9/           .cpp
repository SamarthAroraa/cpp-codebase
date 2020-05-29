//
//  main.cpp
//  playgroung class 9
//
//  Created by Samarth Arora on 21/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
bool inc=0;
using namespace std;
//FACTORIAL RECURSIVE

//int factorial(int n){
//    if(n==1)
////        return 1;
////    int fact1=factorial(n-1)*n;
////    return fact1;
////}
////int main()
////{
////    cout<<factorial(6);
////    return 0;
////
////}
//
//// POWER RECURSION
//
////int power(int n,int p){
////    //base case
////    //here, variation is only in variable  p not in variable n
////    if(p==0)
////        return 1;
////    int ans=power(n,p-1)*n;
////    return ans;
////}
////int main()
////{
////    int n,p;
////    cin>>n>>p;
////    cout<<power(n, p);
////    return 0;
////}
////SUM TILL N
//
//int sum(int n){
//    if(n==1)
//        return 1;
//    int sum1=sum(n-1)+n;
//    return sum1;
//
//    }
//void printD(int n){
//    if(n==0)
//        return;
//
//    cout<<n<<endl;
//    printD(n-1);
//    return;
//}
//
//
//void printi(int n){
//    if(n==0){
//        return;
//    }
//    cout<<n<<endl;
//    printi(n-1);
//    cout<<n<<endl;
//    return;
//    }

//int lsearch(int arr[],int ind,int sitem, int size){
//    //returns first index
//    if(ind==size){
//        return -1;
//    }
//
//    //recursive part
//    if(arr[ind]==sitem)
//        return ind;
//    else
//        return lsearch(arr, ind+1, sitem, size);
//}
int lsearch(int arr[],int ind,int sitem, int size){
    
    //returns LAST index
    if(ind==size){
        return -1;
    }
    
    //recursive part
    int x = lsearch(arr, ind+1, sitem, size);
    if(x ==-1 ){
        if(arr[ind]==sitem)
            return ind;
        else return -1;
    }
    else
        return x;
        }

//int lsearch(int arr[],int ind,int sitem, int size){
//    //return last index at which found or else -1
//
//    if(ind==-1){
//        return -1;
//    }
//
//    //recursive part
//    if(arr[ind]==sitem)
//        return ind;
//    else
//        return lsearch(arr, ind-1, sitem, size);
//}
//

int main()
{
    
//    cout<<sum(n);
//    printD(n);
//    printi(n);
    int arr[]={1,2,3,4,6,3,6,11};
    cout<<lsearch(arr, 6, 6, 8)<<endl;
    cout<<lsearch(arr, 6, 98, 8)<<endl;
    return 0;
}
