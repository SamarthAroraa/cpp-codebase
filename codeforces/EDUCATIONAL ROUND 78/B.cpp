#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long int
using namespace std;


ll findRoots( int c) 
{ 
     // If a is 0, then equation is not quadratic, but 
     // linear 
    
    int a=1;
    int b=1;
    c=-c;
     int d  = b*b - 4*a*c; 
     double sqrt_val = sqrt(abs(d)); 
  
     if (d > 0) 
     { 
         cout << "Roots are real and different \n"; 
         cout << (double)(-b + sqrt_val)/(2*a) << "\n"
              << (double)(-b - sqrt_val)/(2*a); 
     } 
     else if (d == 0) 
     { 
         cout << "Roots are real and same \n"; 
         cout << -(double)b / (2*a); 
     } 
     
     ll retval=floor(max((double)(-b + sqrt_val)/(2*a),(double)(-b - sqrt_val)/(2*a)));
     return retval;
} 
  
// Driver code 
int main() 
{ const int j=10;
    j=10;
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
    
        int  c = 6; 
    cerr<<findRoots(c); 
    return 0; 
} 