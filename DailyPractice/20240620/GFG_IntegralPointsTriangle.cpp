#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
  
    ll get_boundary_points(ll *p,ll *q){
        ll diff_x=abs(p[0]-q[0]);
        ll diff_y=abs(p[1]-q[1]);
        return __gcd(diff_x,diff_y)-1;
    }
    
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        
        ll boundary_points=get_boundary_points(p,q)+get_boundary_points(q,r)+get_boundary_points(p,r)+3;
        
        ll area_2=abs(p[0]*(q[1]-r[1])+q[0]*(r[1]-p[1])+r[0]*(p[1]-q[1]));
        
        ll points=(area_2-boundary_points+2)/2;
        
        return points;
    }
};