#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


        int T;
        cin >> T;

        while(T--)
        {
            int n;
            cin >> n;

            int arr[n];

            for(int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            int ctr = 0;

            int j;

            for(j = 0; j < n; j++)
            {
                if(arr[j] == 0)
                {
                    ctr++;
                }
                else
                {
                    break;
                }
            }

            if(j != n)

                for(j = n-1; j >= 0; j--)
                {
                    if(arr[j] == 0)
                    {
                        ctr++;
                    }
                    else
                    {
                        break;
                    }
                }
               if(n-ctr==0)
               	ctr--;
            cout << n - ctr << endl;
        }

        return 0;
    }

