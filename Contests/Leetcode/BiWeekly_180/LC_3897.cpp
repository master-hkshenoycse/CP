#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll ret=1;
        while(n>0){
            if(n%2)
                ret=(ret * a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return ret;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int> > coll;
        for(int i=0;i<nums1.size();i++){
            coll.push_back({nums1[i],nums0[i]});
        }        

        sort(coll.begin(),coll.end(),[&](pair<int,int> &p,pair<int,int> &q){
             if (p.second == 0 && q.second == 0)
                return p.first > q.first;
            if (p.second == 0)
                return true;
            if (q.second == 0)
                return false;
            if (p.first == q.first)
                return p.second < q.second;
            return p.first > q.first;
        });

        ll n=nums1.size();
        ll c0=0,c1=0,ans=0;
        for(ll i=n-1;i>=0;i--){
            //cout<<coll[i].first<<" "<<coll[i].second<<endl;
            c0+=coll[i].second;
            
            ll mul=modpow(2,c0+c1);
            ll value=(modpow(2,coll[i].first)-1ll+mod)%mod;
            value=(value*mul)%mod;
            ans=(ans+value)%mod;
            c1+=coll[i].first;
        }

        return ans;
    }
};