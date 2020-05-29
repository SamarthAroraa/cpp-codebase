#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

class Student{
public:
	string name;
	ll  marks;
	Student(){

	}
};

bool rankarr(Student s1, Student s2){
	return s1.marks> s2.marks;
}

void answer(std::vector<Student> list){
	ll  len= list.size();
	sort(list.begin(), list.end(), rankarr);
	for(ll  i =0 ;i < len ; i++){
		cout<<i+1<<" "<<list[i].name<<endl;
		cerr<<list[i].marks<<endl;
	}
return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  n;
	cin>>n;
	std::vector<Student> arr(n);
	for(ll  i=0; i< n; i++){
		string name;
		ll  m1,m2,m3;
		cin>>name;
		cin>>m1>>m2>>m3;
		arr[i].name= name;
		arr[i].marks= m1+m2+m3;
	}
	answer(arr);

return 0;
}