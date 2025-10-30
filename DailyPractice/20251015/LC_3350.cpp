#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> inc_len(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                inc_len[i]=inc_len[i+1]+1;
            }
        }

        int lo=1,hi=n/2,ans=0;

        while(hi>=lo){
            int mid=(hi+lo)/2;
            int f=0;
            for(int i=0;i<n;i++){
                if(inc_len[i]>=mid and i+mid<n and inc_len[i+mid]>=mid){
                    f=1;
                    break;
                }
            }

            if(f){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ans;
    }
};