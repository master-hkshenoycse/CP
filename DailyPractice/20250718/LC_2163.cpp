#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        ll n=nums.size()/3;
        vector<ll> pref(3*n,0),suff(3*n,0);
        
        ll s=0;
        multiset<ll> x;
        
        for(int i=0;i<3*n;i++){
            s=s+nums[i];
            x.insert(nums[i]);
            
            if(x.size()>n){
                ll y=*(--x.end());
                x.erase(--x.end());
                s-=y;
            }
            
            pref[i]=s;
        }
        
        while(x.size()>0){
            x.erase(x.begin());
        }        
        
        s=0;
        for(int i=3*n-1;i>=0;i--){
            s=s+nums[i];
            x.insert(nums[i]);
            if(x.size()>n){
                ll y=*(x.begin());
                x.erase(x.begin());
                s-=y;
            }
            suff[i]=s;
        }
        
        ll ans=1e15;
        for(ll i=n-1;i<2*n;i++){
            ans=min(ans,pref[i]-suff[i+1]);
        }
        
        return ans;
        
        
    }
};