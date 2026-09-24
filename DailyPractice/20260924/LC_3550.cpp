#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sod(int n){
        int s=0;
        while(n>0){
            s=s+(n%10);
            n/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(get_sod(nums[i])==i)
                return i;
        }
        return -1;
    }
};