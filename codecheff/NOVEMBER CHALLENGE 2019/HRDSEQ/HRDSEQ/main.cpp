////
////  main.cpp
////  HRDSEQ
////
////  Created by Samarth Arora on 04/11/19.
////  Copyright © 2019 Samarth Arora. All rights reserved.
////

#include <iostream>
#include<vector>
#include <stack>
using namespace std;
//
//int loop_ans(int n){
//    int dist;
//    vector<int> freq(100,1);
//    vector<int> index(100,0);
//    stack<int> st;
//    int i=1,top;
//    st.push(0);
////    freq[0]++;
//    while (i<=n) {
//        top=st.top();
//        int f= freq[top];
//        switch(f){
//            case 0:
//                ++freq[top];
//                f= freq[top];
//
//                st.push(0);
//                break;
//            case 1:
//                ++freq[top];
//                f= freq[top];
//                index[top]=i-1;
//                st.push(0);
//                break;
//            case 2:
//                ++freq[top];
//                f= freq[top];
//                dist=i-1-index[top];
//                st.push(dist);
//                index[top]=i-1;
//                break;
//            default:
//                ++freq[top];
//                f= freq[top];
//                dist=i-1-index[top];
//                st.push(dist);
//                index[top]=i-1;
//                break;
//
//        };
//
//        i++;
//    }
//
//    return freq[top]-1;
//
//
//}
//
//int main()
//{
//    int t,n;
//    cin>>t;
//    while(t--){
//        cin>>n;
//        cout<<loop_ans(n)<<endl;
//
//    }
//    return 0;
//}

//11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
//11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
//using namespace std;
//int fib(int n){
//    if(n==1 or n==0){
//        return n;
//    }
//    return fib(n-1)+fib(n-2);}
//int main()
//{
//    cout<<fib(3);
//}
vector<int> storage(1000,-1);
int minstepsto(int n){
    if(n==1)
        return 0;
    
    
    int via3=INT_MAX;
    int via2=INT_MAX;
    
    if(n%3==0){
        if(storage[n/3]!=-1)
            via3=storage[n/3];
        else{
         via3=minstepsto(n/3);
        }
//        return sum;
    }
    if(n%2==0){
        if(storage[n/2]!=-1)
            via2=storage[n/2];
        else
         via2=minstepsto(n/2);
//        return sum;
    }
    int viaminus;
    if(storage[n-1]!=-1){
        viaminus=storage[n-1];
    }
    else
     viaminus=minstepsto(n-1);
    return min(viaminus,min(via2,via3))+1;
}

void iterative_mins(int n){
    vector<int> it(1000,-1);
    it[1]=0;
    int stp=0;
    for(int i=2;i<=n;i++){
        int min2,min3,minu=it[i-1];
        if(i&1==0)
            min2=it[i/2];
        if(i%3==0)
            min3=it[i/3];
        it[i]=min(minu,min(min2,min3));
    }
    cout<< ;
    
}



int main()
{
    cout<<minstepsto(7)<<endl;
    iterative_mins(7);
}
