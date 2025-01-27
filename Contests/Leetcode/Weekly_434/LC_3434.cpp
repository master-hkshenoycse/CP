#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size(),curr_cnt=0;
        
        for(auto e:nums){
            if(e==k){
                curr_cnt++;
            }
        }
        
        ans=max(ans,curr_cnt);
        for(int i=-50;i<=50;i++){
            
            vector<int> gain(n,0);
            for(int j=0;j<n;j++){
                if(nums[j] !=k and nums[j]+i==k){
                    gain[j]=1;
                }else if(nums[j]==k and nums[j]+i !=k){
                    gain[j]=-1;
                }
            }
            
            
            int ms_sum=0,cs_min=0,cs=0;
            
            for(int j=0;j<n;j++){
                cs=cs+gain[j];
                ms_sum=max(ms_sum,cs-cs_min);
                cs_min=min(cs_min,cs);
            }
            
            ans=max(ans,curr_cnt+ms_sum);
            
        }
        
        return ans;
    }
};