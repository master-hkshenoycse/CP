#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sum(int a,int d,int n){
        int ans=2*a*n+n*(n-1)*d;
        return ans/2;
    }
    int totalMoney(int n) {
        int ncw=n/7;
        int extra_days=n%7;
        
        
        int ans=get_sum(28,7,ncw);
        ans+=get_sum(ncw+1,1,extra_days);
        
        return ans;
        
        
        
    }
};