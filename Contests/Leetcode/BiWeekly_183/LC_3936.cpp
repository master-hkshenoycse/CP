#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int exp_ind=n,ans=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                exp_ind--;
                ans++;
            }
        }

        for(int i=exp_ind;i<n;i++){
            if(nums[i]==0)
                ans--;
        }

        return ans;

    }
};