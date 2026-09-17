#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_val(ll n,ll s,ll m){
        ll a0=s;
        ll a1=s+m;
        ll ret=0;

        if(n%2){
            n=(n+1)/2;
            ret=s+(n-1)*m-(n-1);
        }else{
            n=n/2;
            ret=s+n*m-(n-1);
        }
        return ret;
    }
    long long maximumValue(int n, int s, int m) {
        

        //s, s+m, s+m-1, s+2*m-1,
        //s, s-1, s+m-1,
        ll ret=get_val(n,s,m);
        if(n-1>0)
            ret=max(ret,get_val(n-1,s,m)); 
        return ret;

    }
};