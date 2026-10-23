#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int i=0,n=nums.size(),len=0;

        while(i<n){
            int j=i;
            len++;
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            i=j;
        }
    
        return n-len;
    }
};