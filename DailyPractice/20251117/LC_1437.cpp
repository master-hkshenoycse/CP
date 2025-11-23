#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int las_one=-1000000;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(i-las_one-1<k)return 0;
                las_one=i;
            }
        }
        return 1;
    }
};