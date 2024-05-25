#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    int cnt[2005];
    
    void rec(vector<int> &nums,int ind,int k){
        if(ind==nums.size()){
            ans++;
            return;
        }
        
        
        rec(nums,ind+1,k);
        
        if(cnt[nums[ind]+k]== 0 and (nums[ind]-k<0 or cnt[nums[ind]-k]==0)){
            cnt[nums[ind]]++;
            rec(nums,ind+1,k);
            cnt[nums[ind]]--;
        } 
        
   }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        rec(nums,0,k);
        return ans-1;
    }
};