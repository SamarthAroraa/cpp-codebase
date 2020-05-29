////
////  main.cpp
////  CYPNOV03
////
////  Created by Samarth Arora on 18/11/19.
////  Copyright © 2019 Samarth Arora. All rights reserved.
////
//
#include <iostream>
#include <vector>
#include<stack>
using namespace std;
//
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    vector<int>
//}
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//int main(){
//    int n;
//    cin>>n;
//    int o=0,e=0;
//    for(int i=0;i<n;i++)
//    {
//         long el;
//        cin>>el;
//        if((el%2)==0)
//        e++;
//        else
//        o++;
//
//    }
////    cout<<e<<o;
//    if((n%2)==0)
//    {
//        if(e==o)
//        cout<<"DL"<<endl;
//        else cout<<"DETAIN"<<endl;
//    }
//    else {
//        if(abs(e-o)==1 or e==o){
//            std::cout << "DL" << '\n';
//        }
//        else cout<<"DETAIN"<<endl;
//
//
//    }
//return 0;}

//int maxnuts(vector<char> field, int n,int k){
//    int nuts=0;
//    for(int i=0;i<n;i++){
//        int lowerb,upperb;
//        if(field[i]=='S'){
//            upperb=n-1;
//            if(i+k<n)
//                upperb=i+k;
//            lowerb=0;
//            if(i-k>=0)
//                lowerb=i-k;
//
//            for(int j=lowerb;j<=upperb;j++){
//                if(field[j]=='N'){
//                    nuts++;
//                    field[j]='O';
//                    break;
//                }
//            }
//        }
//
//    }
//    return nuts;}
//
//int main(){
//    int t;
//    cin>>t;
//
//    while (t--) {
//        int n,k;
//         cin>>k;
//        cin>>n;
//        vector<char> field(n);
//
//
//        for(int i=0;i<n;i++){
//
//            cin>>field[i];
//        }
//        cout<<maxnuts(field, n, k)<<endl;
//
//    }
//}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v;
     int first, second;
    cin>>first>>second;
    vector<int> mi={first,second};
    int sz=1;
    v.push_back(mi);
    for(int i=1;i<m;i++){
       
        cin>>first;
        cin>>second;
        bool flag= false;
        for(int j=0;j<sz;j++){
            int mo;
            for( mo=0;mo<v[j].size();mo++){
                
                if(v[j][mo]==first or v[j][mo]==second){
                    v[j].push_back(first);
                    v[j].push_back(second);
                    flag=true;
                    break;
                }
                
            }
                        }
        if(flag==false)
        mi.clear();
        mi={first,second};
        v.push_back(mi);
        sz++;
//        break;
    }

            
        
    
    cout<<v.size();
    return 0;
}

