////
////  main.cpp
////  Survivor
////
////  Created by Samarth Arora on 16/11/19.
////  Copyright © 2019 Samarth Arora. All rights reserved.
////
//
////#include <iostream>
////using namespace std;
////
////unsigned long long josephus(unsigned long long n, int k)
////{
////  if (n == 1)
////    return 1;
////  else
////    /* The position returned by josephus(n - 1, k) is adjusted because the
////       recursive call josephus(n - 1, k) considers the original position
////       k%n + 1 as position 1 */
////    return (josephus(n - 1, k) + k-1) % n + 1;
////}
////unsigned long long nextPowerOf2(unsigned long long n)
////{
////    unsigned long long count = 0;
////
////    // First n in the below condition
////    // is for the case where n is 0
////    if (n && !(n & (n - 1)))
////        return n;
////
////    while( n != 0)
////    {
////        n >>= 1;
////        count += 1;
////    }
////
////    return 1 << count;
////}
////
////unsigned long long gun(int n){
////    unsigned long long p=nextPowerOf2(n)-1- 2*(nextPowerOf2(n)-1-n);
////    return p;
////
////
////}
////int main()
////{int t;
////    cin>>t;
////    while(t--){
////    int n;
////    cin>>n;
////    cout<<josephus(n, 2)<<endl;
////    }
////}
//// A recursive C++ program for partition problem
//#include <iostream>
//using namespace std;
//
//// A utility function that returns true if there is
//// a subset of arr[] with sun equal to given sum
//bool isSubsetSum (int arr[], int n, int sum)
//{
//    // Base Cases
//    if (sum == 0)
//        return true;
//    if (n == 0 && sum != 0)
//        return false;
//
//    // If last element is greater than sum, then
//    // ignore it
//    if (arr[n-1] > sum)
//    return isSubsetSum (arr, n-1, sum);
//
//    /* else, check if sum can be obtained by any of
//        the following
//        (a) including the last element
//        (b) excluding the last element
//    */
//    return isSubsetSum (arr, n-1, sum) ||
//        isSubsetSum (arr, n-1, sum-arr[n-1]);
//}
//
//// Returns true if arr[] can be partitioned in two
//// subsets of equal sum, otherwise false
//bool findPartiion (int arr[], int n)
//{
//    // Calculate sum of the elements in array
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    sum += arr[i];
//
//    // If sum is odd, there cannot be two subsets
//    // with equal sum
//    if (sum%2 != 0)
//    return false;
//
//    // Find if there is subset with sum equal to
//    // half of total sum
//    return isSubsetSum (arr, n, sum/2);
//}
//
//// Driver program to test above function
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--){
//        int n;
//        cin>>n;
//        int arr[n];
//        for(int i=0;i<n;i++){
//            cin>>arr[i];
//        }
//    
//    if (findPartiion(arr, n) == true)
//        cout << "YES"<<endl;
//    else
//        cout << "NO"<<endl;
//    }
//    return 0;
//}
//
//// This code is contributed by rathbhupendra
