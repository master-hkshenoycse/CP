#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll ans=0;

        ll l=100,r=99;
        for(ll i=4;i<=18;i++){
            ll curr=(i-1)/3;
            l*=10;
            r=l*10-1;
            if(l>n)
                break;
            ans=ans+(min(r,n)-l+1)*curr;
        }
        return ans;
    }
};