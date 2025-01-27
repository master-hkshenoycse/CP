#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(),ans=0,tot_sum=0;
        for(auto e:nums){
            tot_sum+=e;
        }
        
        int s=0;
        for(int i=0;i+1<n;i++){
            s+=nums[i];
            if(abs(s-(tot_sum-s))%2==0){
                ans++;
            }
        }
        
        return ans;
        
        
    }
};