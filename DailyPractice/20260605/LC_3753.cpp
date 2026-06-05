#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    map<vector<ll>,pair<ll,ll> > dp;
    pair<ll,ll> solve(ll ind,ll p1,ll p2,ll st,ll ti,string &s){
        if(ind==s.size())
            return {0,1};
        
        if(dp.find({ind,p1,p2,st,ti}) != dp.end())
            return dp[{ind,p1,p2,st,ti}];
        
        ll tot_wave=0;
        ll tot_cnt=0;

        ll max_d=ti?(s[ind]-'0'):9;
        
        for(ll i=0;i<=max_d;i++){
            ll nx_tight = (ti && (i==max_d));
            ll nx_st = (st || (i>0));
            ll np1=-1,np2=-1;
            if(st == 0){
                if(nx_st){
                    np1=i;
                }
            }else{
                np2=p1;
                np1=i;
            }

            pair<ll,ll> tmp = solve(ind+1, np1, np2, nx_st, nx_tight, s);
            tot_wave+=tmp.first;
            tot_cnt+=tmp.second;

            if(p1 !=-1 && p2 != -1){
                if(p1 < p2 &&  p1 < i){
                    tot_wave+=tmp.second;
                }else if(p1 > p2 && p1 > i){
                    tot_wave+=tmp.second;
                }
            }

        }
        return dp[{ind,p1,p2,st,ti}] = {tot_wave,tot_cnt};
    }

    ll get_sol(ll num){
        
        dp.clear();
        string n1=to_string(num);
        ll ret=solve(0,-1,-1,0,1,n1).first;
    
        return ret;
    }
    long long totalWaviness(long long num1, long long num2) {
        return get_sol(num2)-get_sol(num1-1);
    }
};