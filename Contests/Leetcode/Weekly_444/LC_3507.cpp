#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool is_sorted(vector<int> &nums){
            int n=nums.size();
            for(int i=1;i<n;i++){
                if(nums[i] < nums[i-1]){
                    return 0;
                }
            }
            
            return 1;
        }
        int minimumPairRemoval(vector<int>& nums) {
            int ans=0;
            while(is_sorted(nums)==0){
                int n=nums.size();
                
                int min_sum=1e8,min_ind=-1;
                for(int i=0;i+1<n;i++){
                    if(nums[i]+nums[i+1] < min_sum){
                        min_sum=nums[i]+nums[i+1];
                        min_ind=i;
                    }
                }
                
                ans++;
                vector<int> curr;
                
                for(int i=0;i<min_ind;i++){
                    curr.push_back(nums[i]);
                }
                
                curr.push_back(min_sum);
                
                for(int i=min_ind+2;i<n;i++){
                    curr.push_back(nums[i]);
                }
                
                nums=curr;
            }
            
            return ans;
    
        }
    };