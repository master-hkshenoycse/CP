#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get_cnt_atmost(vector<int>& nums,int k){
        map<int,int> help;
        int cnt=0,n=nums.size(),j=0,uniq=0;

        for(int i=0;i<n;i++){
            help[nums[i]]++;
            if(help[nums[i]]==1){
                uniq++;
            }

            while(uniq>k){
                help[nums[j]]--;
                if(help[nums[j]]==0){
                    uniq--;
                }
                j++;
            }

            cnt=cnt+(i-j+1);

        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return get_cnt_atmost(nums,k)-get_cnt_atmost(nums,k-1);
    }
};