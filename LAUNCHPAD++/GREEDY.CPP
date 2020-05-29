#include<bits/stdc++.h>
#define ll long 
#define deb(x) cerr<<#x<<" "<<x<<endl;
using namespace std;
class ActivityTime{
public:
    ll start,end;
};
    bool compare(ActivityTime a, ActivityTime b){
        return a.end<b.end;
    }


long max_activities(ll starttime[],ll endtime[],int n){
    ActivityTime arr[n];
    for(int i=0;i<n;i++){
        arr[i].start=starttime[i];

        arr[i].end=endtime[i];
    }
sort(arr,arr+n,compare);
ll dynamicend=arr[0].end;
long activity_count=1;
for(int i=1;i<n;i++){
    if(arr[i].start>=dynamicend){
        dynamicend=arr[i].end;
        activity_count++;

    }
}
return activity_count;
}


    ll starttime[2000001];
    ll endtime[2000001];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    #endif

    int n;
    cin>>n;

    int i=0;
    for(auto j=0;j<n;j++){
        long long ai,bi,ti;
        cin>>ai>>bi>>ti;
        ll start=ai;
        ll end= start+ti;
        while(start<=bi and start+ti<=bi){
            starttime[i]=start;
            endtime[i]=end;
            deb(start);
            deb(end);
            start=end;
            end=start+ti;
            i++;

        }
        deb(endtime[i-1]);
        deb(bi);
        if(endtime[i-1]<bi){
            start=starttime[i-1];
            int offset=bi-endtime[i-1];
            deb(offset);
               while(offset--){
                start++;
            deb(start);

                end=start+ti;
                starttime[i]=start;
                endtime[i]=end;
                i++;
            }
        }

}
cout<<max_activities(starttime,endtime,i)<<endl;

    // int n=6;
    
    return 0;
}
















