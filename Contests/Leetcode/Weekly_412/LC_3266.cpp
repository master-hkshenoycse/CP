#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1){
            return nums;
        }

        ll n=nums.size();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
        vector<vector<ll> >orig(n);
        for(ll i=0;i<n;i++){
            pq.push({nums[i],i});
            
        }

        set<int> index_used;
        
        vector<ll> tmp_nums;
        for(ll i=0;i<n;i++){
            tmp_nums.push_back(nums[i]*1ll);
        }

        while(index_used.size()<n and k>0){
            k--;
            auto r=pq.top();
            pq.pop();

            index_used.insert(r.second);
            tmp_nums[r.second]=tmp_nums[r.second]*1ll*multiplier;

            pq.push({tmp_nums[r.second],r.second});

        }

        ll ops_total=k/n;
        ll ops_rem=k%n;
    

        for(ll i=0;i<n;i++){
            nums[i]=(tmp_nums[i]*1ll)%mod;
            nums[i]=(nums[i]*1ll*modpow(multiplier,ops_total))%mod;
        }

        for(ll i=0;i<n;i++){
            orig[i]={tmp_nums[i],i};
        }
        sort(orig.begin(),orig.end());
        for(ll i=0;i<ops_rem;i++){
            nums[orig[i][1]]=(nums[orig[i][1]]*1ll*multiplier)%mod;
        }


        


        return nums;




    }
};