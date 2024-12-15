#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mark[100005];
    long long findScore(vector<int>& nums) {
        ll n=nums.size(),ans=0;
        
        set<vector<ll> > x;
        for(ll i=0;i<n;i++){
            mark[i]=0;
            x.insert({nums[i],i});
        }
        
        while(x.size()>0){
            auto it=*x.begin();
            x.erase(it);
            ll v=it[0];
            ll ind=it[1];
            
            ans=ans+v;
            
            mark[ind]=1;
            if(ind-1>=0){
                mark[ind-1]=1;
                if(x.find({nums[ind-1],ind-1}) != x.end()){
                    x.erase({nums[ind-1],ind-1});
                }
            }
            
            if(ind+1<n){
                mark[ind+1]=1;
                
                if(x.find({nums[ind+1],ind+1}) != x.end()){
                    x.erase({nums[ind+1],ind+1});
                }
            }
        }
        
        return ans;
        
    
    }
};