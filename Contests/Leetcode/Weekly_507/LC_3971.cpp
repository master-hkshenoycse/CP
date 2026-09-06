#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n=value.size();
        auto get_cnt = [&](ll x) -> ll{
            ll cnt=0;
            for(int i=0;i<n;i++){
                if(value[i]<x)
                    continue;
                
                ll k=(value[i]-x)/decay[i]+1;
                cnt+=k;

                if(cnt>=m)
                    return cnt;
            }
            return cnt;
        };

        ll lo=0,hi=1e9,cutoff=0;

        while(hi>=lo){
            ll mid=lo+(hi-lo)/2;
            if(get_cnt(mid)>=m){
                cutoff=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        ll totSum=0,totCnt=0;

        for(int i=0;i<n;i++){
            if(value[i]<cutoff)
                continue;
            
            ll k=(value[i]-cutoff)/decay[i]+1;
            totCnt+=k;

            ll last=value[i]*1ll-(k-1)*decay[i];
            totSum=(totSum+(k*(value[i]*1ll+last))/2);
            totSum%=mod;
        }

        ll extra=totCnt-m;
        totSum=(totSum-extra*cutoff)%mod;
        totSum=(totSum+mod)%mod;
        return totSum;
    }
};