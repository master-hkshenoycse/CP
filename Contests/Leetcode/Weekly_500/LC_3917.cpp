#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size(),od_cnt=0,ev_cnt=0;
        vector<int> ret(n,0);

        for(int i=n-1;i>=0;i--){
            if(nums[i]%2){
                ret[i]=ev_cnt;
                od_cnt++;
            }else{
                ret[i]=od_cnt;
                ev_cnt++;
            }
        }

        return ret;
    }
};