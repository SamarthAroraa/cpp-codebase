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
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};
	int ddx[] = {1,0,-1,0,1,-1,-1,1};
	int ddy[] = {0,1,0,-1,1,-1,1,-1};
	#define MAXV(v) *max_element(v.begin(),v.end())
	#define MINV(v) *min_element(v.begin(),v.end())
	#define MAXA(a,n) *max_element(a,a+n)
	#define MINA(a,n) *min_element(a,a+n)
	#define REV(v) reverse(v.begin(),v.end())
	#define SUM(v) accumulate(v.begin(),v.end(),0)
	#define gcd __gcd
	#define TC(t) while (t--)


	string findMinLenStr(string str, int k) 
	{ 
	    int n = str.length(); 
	  
	    // Starting index of sliding window. 
	    int st = 0; 
	  
	    // Ending index of sliding window. 
	    int end = 0; 
	  
	    // To store count of character. 
	    int cnt[26]; 
	    memset(cnt, 0, sizeof(cnt)); 
	  
	    // To store count of distinct 
	    // character in current sliding 
	    // window. 
	    int distEle = 0; 
	  
	    // To store length of current 
	    // sliding window. 
	    int currlen; 
	  
	    // To store minimum length. 
	    int minlen = n; 
	  
	    // To store starting index of minimum 
	    // length substring. 
	    int startInd = -1; 
	  
	    while (end < n) { 
	  
	        // Increment count of current character 
	        // If this count is one then a new 
	        // distinct character is found in 
	        // sliding window. 
	        cnt[str[end] - 'a']++; 
	        if (cnt[str[end] - 'a'] == 1) 
	            distEle++; 
	  
	        // If number of distinct characters is 
	        // is greater than k, then move starting 
	        // point of sliding window forward, 
	        // until count is k. 
	        if (distEle > k) { 
	            while (st < end && distEle > k) { 
	                if (cnt[str[st] - 'a'] == 1) 
	                    distEle--; 
	                cnt[str[st] - 'a']--; 
	                st++; 
	            } 
	        } 
	  
	        // Remove characters from the beginning of 
	        // sliding window having count more than 1 
	        // to minimize length. 
	        if (distEle == k) { 
	            while (st < end && cnt[str[st] - 'a'] > 1) { 
	                cnt[str[st] - 'a']--; 
	                st++; 
	            } 
	  
	            // Comapre length with minimum length 
	            // and update if required. 
	            currlen = end - st + 1; 
	            if (currlen < minlen) { 
	                minlen = currlen; 
	                startInd = st; 
	            } 
	        } 
	  
	        end++; 
	    } 
	  
	    // Return minimum length  substring. 
	    return str.substr(startInd, minlen); 
	} 
	  
	void solveQues(){
		int t;
		cin>>t;
		TC(t){
			string s;
			cin>>s;
			// int arr[s.length()];

			// for(int i=0;i<s.length();i++){
			// 	arr[i]=s[i]-'0';
			// }
			// deb(s)
			string str="";
			FOR(i,0,s.length()){
				if(s[i]=='1'){
					str+='a';
				}
				if(s[i]=='2'){
					str+='b';
				}
				if(s[i]=='3'){
					str+='c';
				}
			}
			deb(str)
			if(str.length()<3){
				cout<<"0\n";
			}
			if(str.length()==3){
				
				if(str=="abc" or str=="bac" or str=="cab" or str=="acb" or str=="bca" or str=="cba"){
					cout<<"3\n";
				}
				else{
					cout<<"0\n";
				}
			}
			else{
				bool check=0;
				unordered_map<char, int> m;
				for(int i=0;i<str.length();i++){	
					m[str[i]]++;

				}
				if(m['a']>0 and m['b']>0 and m['c']>0){
					check=1;
				}
				if(check)
			cout<<findMinLenStr(str,3).length()<<endl;
		else cout<<"0\n";
		}
		}
		
		return;
	}


	int main(){
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		solveQues();


		 
	return 0;
	}