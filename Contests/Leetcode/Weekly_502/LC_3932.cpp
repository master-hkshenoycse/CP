#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int get_value(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2)res=(res*a);
            a=(a*a);
            n/=2;
        }
        return res;
    }
    int countKthRoots(int l, int r, int k) {
        if(k==1)
            return r-l+1;
        int ans=0;
        for(ll i=0;get_value(i,k)<=r;i++){
            if(get_value(i,k)>=l && get_value(i,k)<=r)
                ans++;
        }

        return ans;

    }
};