#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> occ;
        int sum=0,j=0,ret=n+1;
        for(int i=0;i<n;i++){
            if(occ[nums[i]]==0){
                sum+=nums[i];
            }
            occ[nums[i]]++;

            while(sum>=k){
                occ[nums[j]]--;
                if(occ[nums[j]]==0)
                    sum-=nums[j];
                ret=min(ret,i-j+1);
                j++;
            }
        }

        if(ret >n )
            ret=-1;

        return ret;

    }
};