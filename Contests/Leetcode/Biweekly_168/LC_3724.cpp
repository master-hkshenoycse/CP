#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll ex=1e18,ret=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            ret=ret+abs(nums1[i]-nums2[i]);
            int lo=min(nums1[i],nums2[i]);
            int hi=max(nums1[i],nums2[i]);
            if(nums2[n]>=lo && nums2[n]<=hi){
                ex=min(ex,1ll);
            }else{
                ex=min(ex,abs(lo-nums2[n])*1ll+1);
                ex=min(ex,abs(hi-nums2[n])*1ll+1);
            }
        }
        

        ret+=ex;
        return ret;
    
    }
};