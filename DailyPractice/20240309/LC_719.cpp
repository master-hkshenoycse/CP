#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int lo=0,hi=1e6,ans=hi;

        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        while(hi>=lo){
            int mid=(hi+lo)/2;
            int cnt=0;

            //least number where cnt of pairs whose distance <= to the number

            for(int i=0;i<n;i++){
                int c=upper_bound(nums.begin(),nums.end(),nums[i]+mid)-nums.begin();
                c--;
                cnt=cnt+max(0,c-i);
            }

            if(cnt>=k){ 
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
    }
};