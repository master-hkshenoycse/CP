#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int asc_cnt=1,dsc_cnt=1,n=nums.size();
        for(int i=1;i<n;i++){
            asc_cnt+=(nums[i] == ((nums[i-1]+1)%n));
            dsc_cnt+=(nums[i] == ((nums[i-1]-1+n)%n));
        }
        int ret=n+5;

        if(asc_cnt==n){
            if(nums[0]==0)
                ret=min(ret,0);
            ret= min({ret,n-nums[0],nums[0]+2});
        }

        if(dsc_cnt==n){
            if(nums[0]==n-1)
                ret=min(ret,1);
            ret=min(ret,nums[0]+2);
            ret=min(ret,n-nums[n-1]+1);
        }

        
        if(ret==n+5)
            ret=-1;

        return ret;

    }
};