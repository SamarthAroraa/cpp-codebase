//
//  main.cpp
//  PHCUL
//
//  Created by Samarth Arora on 08/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
//long long x1=0,x2=0,y1=0,y2=0,x3,y3;

float  dist(long long x1,long long y1,long long x2,long long y2){
    long long x=abs(x1-x2);
    long long y=abs(y1-y2);
    return pow(x*x+y*y,0.5);
}
class Info{
public:
    long long x,y;
    float dist;
    Info(){
        x=-1;
        y=-1;
        dist=10e9;
    }
    void display(){
        //cout<<'\n'<<x<<" "<<y<<" "<<dist<<endl;
    }
};

Info  min_from_set(vector<long long> x1, vector<long long> y1, long long x,long long y)
{
    long long s=x1.size();
    Info I;
    float min=INT_MAX;
    
    for(long long i=0;i<s;i++){
        //cout<<"\nmindata\n"<<x<<" "<<y<<" " <<x1[i]<<" "<<y1[i];
        float d= dist(x1[i],y1[i],x,y);
        //cout<<" "<<d<<" "<<endl;
        if(d<min){
            I.dist=d;
            I.x=x1[i];
            I.y=y1[i];
            min=d;
        }
        }
    
    return I;
    
}


int main(){
    long long t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        long long n,m,k;
        cin>> n>> m>> k;
        vector<long long> nset_x(n); vector<long long> nset_y(n);
         vector<long long> kset_x(k); vector<long long> kset_y(k);
         vector<long long> mset_x(m); vector<long long> mset_y(m);
        nset_x.clear(); nset_y.clear();
        mset_x.clear(); mset_y.clear();
        kset_x.clear();kset_y.clear();
        
        for(long long i=0;i<n;i++){
            long long x1,y1;
            cin>>x1>>y1;
            nset_x.push_back(x1);
            nset_y.push_back(y1);
        }
        for (long long i=0; i<m; i++) {
            long long x2, y2;
            cin>>x2>>y2;
            mset_x.push_back(x2);
            mset_y.push_back(y2);
            
        }
        for (long long i=0; i<k; i++) {
            long long x3, y3;
            cin>>x3>>y3;
            kset_x.push_back(x3);
            kset_y.push_back(y3);
            
        }
//        float total=0,T1=0,T2=0;
//        Info one, two, three,temp1,temp2,temp3,temp4;
////        one=min(min_from_set(nset_x, nset_y, x, y).dist, min_from_set(mset_x, mset_y, x, y).dist);
//
////        total+=one.dist;
//        temp1=min_from_set(nset_x, nset_y, x, y);
//        temp1.display();
//
//        temp2=min_from_set(mset_x, mset_y, x, y);
//        temp2.display();
//        if(temp1.dist>temp2.dist)
//        {  one=temp2;
//            temp3=temp1;
//        //cout<<"a-->"<<temp1.dist<<" "<<temp2.dist;
//        }
//        else {
//            one=temp1;
//            temp3=temp2;
//            //cout<<"b-->"<<temp1.dist<<" "<<temp2.dist;
//        }
//        total+=one.dist;
//        T1+=temp3.dist;
//
//        if(temp1.dist>temp2.dist)
//        {//cout<<"\nc";
//        two=min_from_set(nset_x, nset_y, temp2.x, temp2.y);
//            temp4=min_from_set(mset_x, mset_y, temp3.x, temp3.y);
//            total+=two.dist;
//            T1+=temp4.dist;
//
//
//        }
//        else{
//            //cout<<"\nd";
//            two=min_from_set(mset_x, mset_y, temp1.x, temp1.y);
//            //cout<<"\n!!";
//            two.display();
//            temp4=min_from_set(nset_x, nset_y, temp3.x, temp3.y);
//            total+=two.dist;
//            T1+=temp4.dist;
//        }
//        three=min_from_set(kset_x, kset_y, two.x, two.y);
//        Info four;
//        four=min_from_set(kset_x, kset_y, temp4.x, temp4.y);
//        total+=three.dist;
//        T1+=four.dist;
//        //cout<<x<<" "<<y;
//        one.display();
//        two.display();
//        three.display();
//        float finala=min(T1,total);
//        cout<<setprecision(12)<<finala<<endl;
//        nset_x.clear(); nset_y.clear();
//        mset_x.clear(); mset_y.clear();
//        kset_x.clear();kset_y.clear();
        float min1=INT_MAX,min2=INT_MAX;
        long long x1,y1,x2,y2,x3,y3;
        float distance=0;
        for(int i=0;i<n;i++){
             distance=0;
            x1=nset_x[i];
             y1=nset_y[i];
            distance+=dist(x1, y1, x, y);
            for(int j=0;j<m;j++){
                 x2=mset_x[j];
                 y2=mset_y[j];
                distance+=dist(x2,y2,x1,y1);
                for(int l=0;l<k;l++){
                     x3=kset_x[l];
                     y3=kset_y[l];
                    distance+=dist(x3,y3,x2,y2);
                    if(distance<min2){
                        //cout<<x1<<"--"<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<distance<<endl;
                        min2=distance;
                    }
                    distance-=dist(x3,y3,x2,y2);
                    
                }
                distance-=dist(x2,y2,x1,y1);
            }
//        if(distance<min1)
//            min1=distance;
//            cout<<x1<<"--"<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<distance<<endl;

            distance-=dist(x1, y1, x, y);
            
        }
        distance=0;
        for(int i=0;i<m;i++){
            distance=0;
             x1=mset_x[i];
             y1=mset_y[i];
            float d0=dist(x1, y1, x, y);
            distance+=d0;
            //cout<<"->"<<d0<<endl;
            for(int j=0;j<n;j++){
                x2=nset_x[j];
                 y2=nset_y[j];
                float moo=dist(x2,y2,x1,y1);
                distance+=moo;
                //cout<<"->"<<moo<<endl;
                for(int l=0;l<k;l++){
                    x3=kset_x[l];
                    y3=kset_y[l];
                    float noo=dist(x3,y3,x2,y2);
                    distance+=noo;
                    //cout<<"->"<<noo<<endl;
                    if(distance<min2){
                        //cout<<x1<<"--"<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<distance<<endl;
                        min2=distance;
                    }
                    distance-=noo;
                    
                }
                distance-=moo;
            }
            distance-=d0;
            }
            
//            Info one=min_from_set(nset_x, nset_y, x, y);
//            Info two=min_from_set(mset_x, mset_y, x, y);
//            for(int i=0)
            
        cout<<setprecision(12)<<min(min1,min2)<<endl;
    }
    
    return 0;
}

