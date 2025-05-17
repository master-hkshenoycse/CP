#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll bit[100005];
    ll pos[100005];
    ll pref[100005],suff[100005];
    void upd(ll ind,ll n,ll v){
        while(ind<=n){
            bit[ind]+=v;
            ind+=(ind & (-ind));
        }
    }
    
    ll query(ll ind){
        ll s=0;
        while(ind>0){
            s+=bit[ind];
            ind-=(ind & (-ind));
        }
        return s;
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size();
        ll ans=0;
        
        for(ll i=0;i<n;i++){
            nums1[i]++;
            pos[nums1[i]]=i+1;
        }
        
        
        for(ll i=0;i<n;i++){
            nums2[i]++;
            ll v=nums2[i];
            
            ll p=pos[v];
            
            pref[i]=query(p-1);
            
            upd(p,n,1);
        
        }
        
       
        for(ll i=1;i<=n;i++){
            bit[i]=0;
        }
        
        for(ll i=n-1;i>=0;i--){
            ll v=nums2[i];
            ll p=pos[v];
            
            suff[i]=(n-i-1)-query(p);
            
            upd(p,n,1);
        }
        
        
        
        for(ll i=0;i<n;i++){
            ans=ans+pref[i]*suff[i];
        }
        
        return ans;
        
    }
};