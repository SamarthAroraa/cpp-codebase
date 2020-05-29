// C++ program to evaluate area of a polygon using
// shoelace formula
#include<vector>
#include<string>
#include<math.h>
#include<iostream>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


    


// (X[i], Y[i]) are coordinates of i'th point.
double polygonArea(vector<int> X, std::vector<int> Y, int n)
{
    
    double area = 0.0;
 // int X,Y;
    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i; // j is previous vertex to i
    }

    // Return absolute value
    return abs(area / 2.0);
}

// Driver program to test above function
int main()
{
    int t;
    cin>>t;
    char* str;

    while(t--){
        cin>>str;
    // std::vector< pair<int,int> >  coordinates;
    std::vector<int> X;
    std::vector<int> Y;
    int x=0,y=0;
    long n= strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]=='R')
            x++;
        else if(str[i]=='L')
            x--;
        else if(str[i]=='U')
            y++;
        else if(str[i]=='D')
            y--;
    // coordinates.push(make_pair(x,y));
        X.push_back(x);
        Y.push_back(y);
    }
    

    // int n = strlen(s);

    cout << polygonArea(X,Y, n);
    }
return 0;
}

