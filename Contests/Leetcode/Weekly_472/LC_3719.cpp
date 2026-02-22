#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),ret=0;

        for(int i=0;i<n;i++){
            set<int> od_,ev_;
            for(int j=i;j<n;j++){
                if(nums[j]%2){
                    od_.insert(nums[j]);
                }else{
                    ev_.insert(nums[j]);
                }

                if(od_.size() == ev_.size()){
                    ret=max(ret,j-i+1);
                }
            }
        }

        return ret;
    }
};