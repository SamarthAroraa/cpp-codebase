#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define mod 1000000007
#define SORTV(a) sort(a.begin(),a.end())
#define eb emplace_back
#define SORTA(a,n) sort(a,a+n)
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
#define INF (int)1e9
#define EPS 1e-9
#define bitcount  __builtin_popcount
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ( (n >> b) & 1)

#define TC(t) while (t--)


int minimize(vi& arr, int n,int k, vector<int> &moves){
    FOR(i,1,n+1){
        if(arr[i]==i)
            continue;
        else{
            if(arr[arr[i]]==i){
                continue;
            }
            else{
                int f=i;
                int s=arr[i];
                int t=arr[s];
                swap(arr[f], arr[s]);
                swap(arr[f],arr[t]);
                // deb(arr[f])
                // deb(arr[s])
                // deb(arr[t])
                // std::vector<int>  v;
                moves.pb(f);
                moves.pb(s);
                moves.pb(t);
                // moves.pb(v);

            }
        }
    }
    // set<pii> twos;
    set<pii> twos;
    int t=0;
    FOR(i,1,n+1){
        if(arr[i]!=i){
            if(twos.find(mp(arr[i],i))==twos.end()){
                twos.insert(mp(i,arr[i]));
                t++;
            }
        }
    }
    if(t%2!=0)
        return -1;
    // deb(t)
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
       moves.pb(f);
       moves.pb(s);
       moves.pb(t);
       swap(arr[f],arr[s]);
       swap(arr[f],arr[t]);
       // .pb(v);

       // ans++;
       s=t;
       t=p2.se;
       if(arr[f]!=s){
       swap(s,t); 
   }
       swap(arr[f],arr[s]);
       swap(arr[f],arr[t]);
       // v.clear();
       moves.pb(f);
       moves.pb(s);
       moves.pb(t);
       // moves.pb(v);
       // ans++;



        // cerr<<t<<" ";
        // break;
    }

    return moves.size();

}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // solveQues();
    int t;
    cin>>t;
    TC(t){
        int n,k;
        cin>>n>>k;
        vi arr(n+1);
        vi moves;
        FOR(i,1,n+1){
            cin>>arr[i];
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
        int ans=minimize(arr,n,k,moves)/3;
        if(ans==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
        // deb(moves.size())
        for(int i=0;i<moves.size();i+=3){
            cout<<moves[i]<<" "<<moves[i+1]<<" "<<moves[i+2]<<endl;
        }
    }


     
return 0;
}