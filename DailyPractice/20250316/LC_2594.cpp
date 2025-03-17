#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    ll get_val(ll ul,ll r){
        ll lo=0,hi=1e6,ans=0;
        
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            
            if(r*mid*mid<=ul){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
    ll chk(vector<ll> &v,ll mid,ll cars){
        ll curr=0;
        
        for(auto e:v){
            
            curr=curr+get_val(mid,e);
           
            if(curr>=cars){
                return 1;
            }
        }
        return (curr>=cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll n=ranks.size();
        vector<ll> vals;
        for(ll i=0;i<n;i++){
            vals.push_back(ranks[i]);
            
        }
        
        //sort(vals.begin(),vals.end());
        
        ll lo=0,hi=1e14,ans=hi;
     
       
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            
            if(chk(vals,mid,cars)){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};