#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans=0,i=0,n=nums.size();
        while(i<n){
            if(nums[i]>maxK || nums[i]<minK){
                i++;
            }else{
                ll cnt=0,j=i;
                while(j<n && nums[j]>=minK && nums[j]<=maxK){
                    cnt++;
                    j++;
                }
                ans=ans+(cnt*cnt+cnt)/2ll;
                i=j;
            }
        }
        return ans;
    }
};