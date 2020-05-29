#include<iostream>
using namespace std;
void pythagoras(long long n)
{
    long long a,b,c;
    if(n==1 || n==2)
    cout<<"-1";
    else
    {
        if(n%2!=0)
        {
            long long p=((n+1)/2);
            long long q=((n-1)/2);
            a= (p+q)*(p-q);
            b= 2*p*q;
            c= ((p*p) + (q*q));
            if((c*c)==(a*a)+(b*b))
            {
                cout<<b<<" "<<c;
            }
            else
            {
                cout<<-1;
            }
        }
        else
        {
            long long p=n/2;
            long long q=1;
            a= (p+q)*(p-q);
            b= 2*p*q;
            c= ((p*p) + (q*q));
            if((c*c)==(a*a)+(b*b))
            {
                cout<<b<<" "<<c;
            }
            else
            {
                cout<<-1;
            }
        }
    }
}
int main()
{
   long long n;
   cin>>n;
   pythagoras(n);
    return 0;
}
