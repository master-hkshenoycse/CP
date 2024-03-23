#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        ll n=nums.size(),ans=0;
        set<pair<ll,ll> > s;
        
        for(ll i=0;i<n;i++){
            ans+=nums[i];
            s.insert({nums[i],i});
        }
        
        
        
        vector<ll> sol;
        for(auto q:queries){
            int ind=q[0];
            int k=q[1];
            
            if(s.find({nums[ind],ind}) != s.end()){
                s.erase({nums[ind],ind});
                ans-=nums[ind];
            }
            while(s.size()>0 and k--){
                ll val=(*s.begin()).first;
                ans-=val;
                s.erase(s.begin());
            }
            
            sol.push_back(ans);
        }
        return sol;
    }
};