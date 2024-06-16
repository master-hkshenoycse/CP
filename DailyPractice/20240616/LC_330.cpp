#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long ans=0,i=0,cs=0,m=nums.size();
        
        while(cs<n){
            if(i<m and nums[i]<=cs+1){
                cs=cs+nums[i]*1l;
                i++;
            }else{
                ans++;
                cs=2*cs+1l;
            }
        }

        return ans;
    }
};