#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int> occ;
        int del=0;
        for(int i=n-1;i>=0;i--){
            if(occ.find(nums[i]) != occ.end()){
                del=i/3+1;
                break;
            }
            occ[nums[i]]=i;
        }

        return del;
        
    }
};