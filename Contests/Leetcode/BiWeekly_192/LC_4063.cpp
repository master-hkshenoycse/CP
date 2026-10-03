#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),ret=0;
        vector<int> seenAt(k,-1);
        for(int l=0;l<n && n-l>ret;l++){
            int tot=0;
            for(int r=l;r<n;r++){
                tot=((tot+nums[r])%k+k)%k;
                seenAt[((2*nums[r])%k+k)%k]=l;
                if(tot==0 || seenAt[tot]==l)
                    ret=max(ret, r-l+1);
            }
        }
        return ret;
    }
};