#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        ll n=skill.size(),m=mana.size();
        vector<ll> curr_free_time(n,0);
        ll ret=0;
        for(ll i=0;i<m;i++){
            
            ll st_req=0,ex=0;
            
            
            
            //cout<<r<<endl;
            for(ll j=0;j<n;j++){
                st_req=max(st_req,curr_free_time[j]-ex);
                ex+=skill[j]*mana[i];
            }
            
            ex=0;
            for(ll j=0;j<n;j++){
                curr_free_time[j]=st_req+skill[j]*mana[i];
                st_req+=skill[j]*mana[i];
            }
            ret=max(ret,st_req);
        }
        
        return ret;
    }
};