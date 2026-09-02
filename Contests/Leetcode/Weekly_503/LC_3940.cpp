#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i=0, n=nums.size();
        vector<int> ret;
        
        while(i<n){
            int j=i,cnt=0;
            while(j<n && nums[i]==nums[j]){
                cnt++;
                j++;
            }
            cnt=min(cnt,k);
            while(cnt--)
                ret.push_back(nums[i]);
            
            i=j;
        }
        return ret;
    }
};