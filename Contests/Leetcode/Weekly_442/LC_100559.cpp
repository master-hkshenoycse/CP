#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_ops(ll l,ll r,ll st,ll en){
        return max(0ll,min(r,en)-max(l,st)+1ll);
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll ans=0;
        for(auto q:queries){
            ll l=q[0];
            ll r=q[1];
            
            ll ops_req=0;
            ll st=1,c=1;
            while(st<=r){
                ll en=st*4-1;
                ll cnt=get_ops(l,r,st,en);
                ops_req+=cnt*c;
                st=st*4;
                c++;
            }
            
            ans=ans+(ops_req+1)/2;
            
        }
        
        return ans;
    }
};