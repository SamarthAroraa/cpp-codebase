#include<bits/stdc++.h>
#include<algorithm>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

class Time
{
public:
	int time;
	char mode;

// public:
	Time(){
		time=0;
		mode='n';
	}
	// ~Time();
	
};
bool compare(Time t1, Time t2){
	return t1.time<t2.time;
}
int overlaps(std::vector<int> a_times, std::vector<int> d_times){
	int n_a= a_times.size();
	int n_b= d_times.size();
	std::vector<int>::iterator it;
	Time timeline[n_a + n_b];
	int size=0;
	for(it= a_times.begin();it!= a_times.end();it++){
		timeline[size].time=*it;
		timeline[size].mode='a';
		size++;
}
for(it= d_times.begin();it!= d_times.end();it++){
		timeline[size].time=*it;
		timeline[size].mode='d';
		size++;
}

sort(timeline,timeline+size,compare);
// for(int i=0;i<size;i++){
// 	cerr<<timeline[i].time<<" "<<timeline[i].mode<<endl;
// }
// return 1;
int current=0;
int overlaps=-1;
for(int i=0;i<size;i++){
if(timeline[i].mode=='a'){
	current++;
}
else{
	current--;
}
overlaps= max( overlaps , current); 
}

cerr<<overlaps;
return overlaps;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

int n;
cin>>n;
std::vector<int> a_times(n);
std::vector<int> d_times(n);
for(int i=0;i<n;i++){
	cin>>a_times[i];
}
for(int i=0;i<n;i++){
	cin>>d_times[i];
}
int test= overlaps(a_times,d_times);
cout<<test;

return 0;
}