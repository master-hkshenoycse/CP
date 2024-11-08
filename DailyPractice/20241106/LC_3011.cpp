#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt_set(int n){
        int c=0;
        while(n>0){
            c++;
            n=(n & (n-1));
        }
        return c;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> s_copy=nums;
        sort(s_copy.begin(),s_copy.end());
        
        int i=0;
        while(i<n){
            int j=i;
            while(j<n and cnt_set(nums[i])==cnt_set(nums[j])){
                j++;
            }
            
            sort(nums.begin()+i,nums.begin()+j);
            
            i=j;
        }
        
        return nums==s_copy;
    }
};