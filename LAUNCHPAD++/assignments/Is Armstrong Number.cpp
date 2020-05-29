#include<iostream>
#include<math.h>
using namespace std;

string isArm(string num){
    int len=num.length();
    long long acc=0;
    long numlong=0;
    for(int i=0;i<len;i++)
    {
        char ch=num[i]-'0';
        int n=ch;
        numlong+=n*pow(10,len-i-1);
        acc+=pow(n,3);

    }
    cout<<numlong<<endl<<acc;
    if(acc==numlong) return "true";
    else return "false";
}

int main(){
    string num;
    cin>>num;
    cout<<isArm(num);
    return 0;
}
