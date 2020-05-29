#include <bits/stdc++.h>

#include <math.h>
#include<vector>
using namespace std;

bool sieve[1000001];
int main()

{
   
   for(long long int i=0;i<=1000001;i++)sieve[i]=0;
   sieve[0] = 1;
   sieve[1] = 1;
   for(long long int i=2;i<=1000001;i++)
   {
       if(sieve[i]==0)
       {

           for(long long int j=i*i;j<=1000001;j+=i)
           {
               sieve[j]=1;
           }
       }
   }
   long long int n;
   cin>>n;
   if(sieve[n]==0){
       cout<<"Prime"<<endl;

   }
   else
   cout<<"Not Prime"<<endl;

   return 0;
}
