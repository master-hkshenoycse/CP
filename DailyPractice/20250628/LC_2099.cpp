#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> maxSubsequence(vector<int>& nums, int k) {
            
            vector<int> a,sol;
            a=nums;
            sort(a.begin(),a.end());
            reverse(a.begin(),a.end());
            int n=nums.size();
            
            map<int,int> cnt;
            for(int i=0;i<k;i++){
                cnt[a[i]]++;
            }
            
            for(int i=0;i<n;i++){
                if(cnt[nums[i]]>0){
                    sol.push_back(nums[i]);
                    cnt[nums[i]]--;
                }
            }
            
            return sol;
    
            
        }
    };