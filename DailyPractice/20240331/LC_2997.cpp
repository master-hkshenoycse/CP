#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll nextmi[100005],nextma[100005];
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll j=0,ans=0,n=nums.size();
        nextmi[n]=n,nextma[n]=n;
        for(int i=n-1;i>=0;i--){
            nextmi[i]=nextmi[i+1];
            nextma[i]=nextma[i+1];
            
            if(nums[i]==minK)nextmi[i]=i;
            if(nums[i]==maxK)nextma[i]=i;
        }
        
        for(ll i=0;i<n;i++){
            if(nums[i]>=minK and nums[i]<=maxK){
                j=max(j,i);
                while(j<n and nums[j]>=minK and nums[j]<=maxK){
                    j++;
                }
                
                if(max(nextmi[i],nextma[i])<j){
                    ans=ans+j-max(nextmi[i],nextma[i]);
                }
            
            }
        }
        
        return ans;
        
        
        
        
        
        
    }
};