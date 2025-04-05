#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int ans=1,n=nums.size();
            
            
            for(int i=0;i<n;i++){
                int cnt=1,curr_or=nums[i],j=i+1;
                while(j<n){
                    if((curr_or & nums[j])){
                        break;
                    }
                    cnt++;
                    curr_or=(curr_or | nums[j]);
                    j++;
                    ans=max(ans,cnt);
                    
                }
            }
            return ans;
        }
    };