//
//  main.cpp
//  class11playground
//
//  Created by Samarth Arora on 29/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<vector>


using namespace std;
int count1=0,count2=0;
int ways=0;
//string code[]={" ",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
////
////void toalpha(string str,string ans){
////
////
////    //RECURSIVe;
////    string sub=str.substr(1);
////
////    char ch=str[0]-'1'+ 'A';
////    toalpha(sub, ans+ch);
////
////
////
////}
//void keypad(string str,string ans){
//    if(str.length()==0){
//        cout<<ans<<endl;
//        return;
//    }
//
//
//    //rec
//    char c=str[0];
//    int n=c-'0';
//    string current=code[n];
//    for(int i=0;i<current.length();i++){
//        keypad(str.substr(1), ans+current[i]);
//
//    }
//
//
//}
//void perms(string str,string ans){
//    if(str.length()==0){
//        cout<<ans<<endl;
//        return;
//    }
//
//    //rec
//
//    string ros=str.substr(1);
//    for(int i=0;i<str.length();i++){
//         char curr=str[0];
//        perms(str.substr(1), ans+curr);
//        str=str.substr(1)+curr;
//    }
//
//}
//int sumstr(string ans){
//            int sum=0;
//            for(int i=0;i<ans.length();i++)
//            {
//                int n=ans[i]-'0';
//                sum+=n;
//            }
//            return sum;
//}
////
//int bordpath1(int start,int n){
//    count1++;
//    if(start==n)
//        return 1;
//    else if (start>n){
//        return 0;
//    }
//
//
//    int sum=0;
//    for(int i=1;i<=6;i++)
//    {
//        sum+=bordpath1(start+i, n);
//
//    }
//    return sum;
//}
//int bordpath2(int start,int n){
//    count2++;
//    if(start==n)
//        return 1;
//    else if (start>n){
//        return 0;
//    }
//
//
//    int sum=0;
//    int b=n-start;
//    if(b>6)
//        b=6;
//    for(int i=1;i<=b;i++)
//    {
//        sum+=bordpath2(start+i, n);
//
//    }
//    return sum;
//}
int mazesteps(int n){
    
}
int main()

{
//    string str="123";
//    gen_alpha(str, "");
//    for(int i=0;i<answers.size();i++)
//    {
//        cout<<answers[i]<<endl;
//    }
//    keypad("23", "");
//    perms("abc","");
    int  n;
    cin>>n;
//    string die;
//    die.push_back(0);
//    if(n<6){
//
//        for(int i=1;i<=n;i++){
//            char c=i+'0';
//            die+=c;
//        }
//    }
//    else{
//        for(int i=1;i<=6;i++){
//             char c=i+'0';
//            die+=c;
//        }
//    }
//    boardpath(die, "");
//    cout<<bordpath1(0, n)<<endl;
//    cout<<bordpath2(0, n)<<endl;
//    cout<<count1<<" "<<count2<<endl;
    
    return 0;
}
