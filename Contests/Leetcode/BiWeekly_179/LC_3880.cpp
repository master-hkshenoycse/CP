#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int prev_1=-1,prev_2=-1,n=nums.size();
        int ret=n+1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(prev_2 != -1)
                    ret=min(ret,i-prev_2);
                prev_1=i;
            }

            if(nums[i]==2){
                if(prev_1 != -1)
                    ret=min(ret,i-prev_1);
                prev_2=i;
            }
        }

        if(ret==n+1)
            ret=-1;

        return ret;
    }
};