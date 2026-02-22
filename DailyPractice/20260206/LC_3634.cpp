#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=n,i=0,j=0;

        for(int i=0;i<n;i++){
            while(j<n && nums[i]*1ll*k*1ll >= nums[j]*1ll){
                j++;
            }
            ans=min(ans,n-(j-i));
        }
        return ans;
    }
};