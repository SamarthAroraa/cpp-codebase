#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

// A C++ program to check if two given line segments intersect 


struct Poll 
{ 
	ll x; 
	ll y; 
}; 

// Given three colinear points p, q, r, the function checks if 
// poll q lies on line segment 'pr' 
bool onSegment(Poll p, Poll q, Poll r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	return true; 

	return false; 
} 

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
ll orientation(Poll p, Poll q, Poll r) 
{ 
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
	// for details of below formula. 
	ll val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; // colinear 

	return (val > 0)? 1: 2; // clock or counterclock wise 
} 

// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Poll p1, Poll q1, Poll p2, Poll q2) 
{ 

	// Find the four orientations needed for general and 
	// special cases 
	ll o1 = orientation(p1, q1, p2); 
	ll o2 = orientation(p1, q1, q2); 
	ll o3 = orientation(p2, q2, p1); 
	ll o4 = orientation(p2, q2, q1); 
	if(q1.x==p2.x and q1.y==p2.y){
		return 0;
	}
	if(p1.x==q2.x and p1.y==q2.y)
		return 0;
	// General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false; // Doesn't fall in any of the above cases 
} 

// Driver program to test above functions 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){


	ll n,qu;
	cin>>n>>qu;
	struct Poll points[n+1];
	for(ll i=1;i<=n;i++){
		ll ai;
		cin>>ai;
		points[i]={i,ai};
	}


while(qu--){

ll x1,x2,y;
cin>>x1>>x2>>y;
	ll xmin=min(x1,x2);
	ll xmax=max(x1,x2);

	struct Poll p={x1,y};
	struct Poll q={x2,y};

	
ll count=0;
for(ll i=1;i<n;i++){
	ll ymin=min(points[i+1].y,points[i].y);
	ll ymax=max(points[i+1].y,points[i].y);

	if(xmin>points[i+1].x or xmax<points[i].x or y>ymax or y<ymin )
		continue;
	if(doIntersect(points[i],points[i+1],p,q)){
		
		count++;
	}
}
cout<<count<<endl;
}

}
return 0;
}

