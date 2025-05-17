#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int ans=0,n=nums.size();
            
            set<int> x,req;
            for(auto e:nums){
                req.insert(e);
            }
            
            for(int i=0;i<n;i++){
                set<int> x;
                for(int j=i;j<n;j++){
                    x.insert(nums[j]);
                    if(x.size()==req.size()){
                        ans++;
                    }
                }
            }
            
            return ans;
        }
    };