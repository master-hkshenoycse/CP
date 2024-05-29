#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<=1000;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=(nums[j]>=i);
            }
            
            if(c==i){
                return i;
            }
        }
        return -1;
    }
};