#include<bits/stdc++.h>
#include<unordered_map>
#define deb(x) cerr<<#x<<" "<<x<<endl;
using namespace std;

#define MAX 500 
unordered_map<long,unsigned long long> factorial_memo;

// unsigned long long factorial(long n){

// if(n<=1)
// 	return 1;
// if(factorial_memo[n]!=0){
// 	// deb(factorial_memo[n]);
// 	return factorial_memo[n];
// }
// unsigned long long ans=factorial(n-1)*n;
// factorial_memo[n]=ans;
// // deb(ans)/
// return ans;
// }
int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    // One by one multiply n with individual digits of res[] 
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
  
        // Store last digit of 'prod' in res[]   
        res[i] = prod % 10;   
  
        // Put rest in carry 
        carry  = prod/10;     
    } 
  
    // Put carry in res and increase result size 
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 
void factorial(int n) 
{ 
    int res[MAX]; 
  
    // Initialize result 
    res[0] = 1; 
    int res_size = 1; 
  
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
    for (int x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 
  	
    cout << "Factorial of given number is \n"; 
    for (int i=res_size-1; i>=0; i--) 
        cout << res[i]; 
} 
  
// This function multiplies x with the number  
// represented by res[]. 
// res_size is size of res[] or number of digits in the  
// number represented by res[]. This function uses simple  
// school mathematics for multiplication. 
// This function may value of res_size and returns the  
// new value of res_size 

  
// long combinatrix(long n,long r){
	// unsigned long long ans;
	// deb(ans)
	// ans=factorial(n+r-1)/factorial(r);
	// ans=ans/ factorial(n-1);
	// deb(factorial(r));
	// deb(factorial(n+r-1));
	// deb(factorial(n-1));

	// deb(factorial(n+r-1))
		// return ans;
// }

 int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif
	// cout<<combinatrix(22,4);
	factorial(29);
	return 0;
}