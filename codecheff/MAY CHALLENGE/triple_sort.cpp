#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define bitcount __builtin_popcount
#define gcd __gcd
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)
int minimize(vi& arr,int n, int k, std::vector<vi>&moves){
    set<int> unsorted;
    // int pc=0;
    set<pair<int,int> > twos;
    // unordered_map<int, bool> ndone;
    for(int i=1;i<=n;i++){
        if(arr[i]!=i ){
            if(i==arr[arr[i]]){
                if(twos.find(mp(arr[i],i))==twos.end())
                twos.insert(mp(i,arr[i]));
                // pc++;
            }
            else{
            unsorted.insert(i);
        }

            // ndone[i]=1;
    }
    }
    // cerr<<unsorted.max_size()/sizeof(int);
    // int unsorted_count=unsorted.size();
    //  pc/=2;
    // if(pc%2!=0)
    //     return -1;

    int ans=0;
    while(!unsorted.empty()){
    // cerr<<"1\n";


        // deb(unsorted.size())
        if(unsorted.size()==2)
            return -1;
        auto top= unsorted.begin();
        int f=*top;
        unsorted.erase(top);
        int s=arr[f];
        top=unsorted.find(s);
        unsorted.erase(top);
        int t=arr[arr[f]];

        if(t==f){
            t= *(unsorted.begin());
            unsorted.erase(unsorted.begin());
            if(f==t){
                t= *(unsorted.begin());
            unsorted.erase(unsorted.begin());
            }
        
        }
        else{
            
            // cerr<<"erasing:"<<arr[arr[f]];
            // deb(*unsorted.find(arr[arr[f]]))
            if(unsorted.find(arr[arr[f]])!=unsorted.end())
            unsorted.erase(unsorted.find(arr[arr[f]]));
        }
        // deb(t)
            // deb(f)
            // deb(s)
            // deb(t)
        swap(arr[f],arr[s]);
        swap(arr[f],arr[t]);
        if(f!=arr[f]){
            // cerr<<"\n"<<arr[f]<<"\n";
            unsorted.insert(f);
        }
        if(s!=arr[s]){
            // cerr<<"\n"<<arr[s]<<"\n";

            unsorted.insert(s);
        }
        if(t!=arr[t]){
            // cerr<<"\n"<<arr[t]<<"\n";

            unsorted.insert(t);
        }
        // deb(f)
        // deb(s)
        // deb(t)
        // deb(unsorted.size());
        vi v;

        v.pb(f);
        v.pb(s);
        v.pb(t);
        moves.pb(v);
        ans++;

        // cerr<<t<<" ";
        // break;
    }
    // if(((twos.size()/2)%2)!=0){
    //     return -1;
    // }
    // deb(twos.size())
    // FOREACH(k, twos){
    //     cerr<<k.fi<<" "<<k.se<<endl;
    // }
    if(twos.size()%2!=0){
        // deb(twos.size())
        return -1;
    }

     while(!twos.empty()){

        // deb()
        // deb(unsorted.size())
       if(twos.size()==1){
        return -1;
    }
        auto top= twos.begin();
        pii p1=*top;

        twos.erase(top);
        top=twos.begin();
        pii p2=*top;
        twos.erase(twos.begin());

       int f=p1.fi;
       int s=p1.se;
       int t=p2.fi;
       vi v;
       v.pb(f);
       v.pb(s);
       v.pb(t);
       swap(arr[f],arr[s]);
       swap(arr[f],arr[t]);
       moves.pb(v);

       ans++;
       s=t;
       t=p2.se;
       if(arr[f]!=s){
       swap(s,t); 
   }
       swap(arr[f],arr[s]);
       swap(arr[f],arr[t]);
       v.clear();
       v.pb(f);
       v.pb(s);
       v.pb(t);
       moves.pb(v);
       ans++;



        // cerr<<t<<" ";
        // break;
    }



    if(k>=ans)
    return ans;
return -1;

}

int main(){
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
       
        
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    TC(t){
        int n,k;
        cin>>n>>k;
        vi arr(n+1);
        FOR(i,1,n+1){
            cin>>arr[i];
        }
        // cerr<<sizeof(arr)/sizeof(int)<<endl;
        std::vector<vi> moves;
        // cout<<
        int ans=minimize(arr,n,k,moves);
        
        // cout<<ans<<endl;
        if(ans!=-1){
            ans=moves.size();
            cout<<ans<<endl;
        for(int i=0;i<moves.size();i++){
            FOR(j,0,3){
            cout<<moves[i][j]<<" ";
        }
        cout<<"\n";
        }
       
    }
    else{
        cout<<-1<<"\n";
    }
    
    
    

    }
    



     
return 0;
}