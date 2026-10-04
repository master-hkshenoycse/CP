#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> freq;
    bool isValid(vector<int> &nums, int l,int h){
        for(int i=1;i<=250;i++){
            if(freq[i]<=0)
                continue;
            for(int j=1;j<=500-i;j++){
                if(freq[j]<=0)
                    continue;

                if(i==j){
                    if(freq[i]>=2 && freq[i+j]>0)
                        return 0;
                }else if(freq[i+j]>0)
                    return 0;
            }
        }
        return 1;
    }
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        freq.resize(501,0);

        int ans=0,low=0,high=0;
        while(high<n){
            freq[nums[high]]++;
            if(isValid(nums,low,high)){
                ans=high-low+1;
                high++;
            }else{
                freq[nums[low]]--;
                low++;
                high++;
            }
        }
        return ans;
    }
};