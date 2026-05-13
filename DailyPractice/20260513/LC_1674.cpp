#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        
        int n=nums.size();
        int ans=2*n;
        
        vector<int> sum_cnt(2*limit+1,0);
        vector<int> ca(limit+1,0),cb(limit+1,0);
        
        for(int i=0;i<n/2;i++){
            if(nums[i]>nums[n-i-1]){
                swap(nums[i],nums[n-i-1]);
            }
            sum_cnt[nums[i]+nums[n-i-1]]++;
            ca[nums[i]]++;
            cb[nums[n-i-1]]++;
        }
        for(int i=1;i<=limit;i++){
            ca[i]+=ca[i-1];
            cb[i]+=cb[i-1];
        }
        
        n/=2;
        for(int i=1;i<=2*limit;i++){
            int ops=n-sum_cnt[i];
            if(i<=limit){
                ops=ops+(n-ca[i-1]);
            }else{
                ops=ops+cb[i-limit-1];
            }
            ans=min(ans,ops);
        }
        
        
 
        
        return ans;
    }
};