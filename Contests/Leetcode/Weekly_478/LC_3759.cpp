#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ret=0,i=n-1;

        while(i>=0){
            int cnt=0,j=i;
            while(j>=0 && nums[i]==nums[j]){
                j--;
                cnt++;
            }

            if(n-i-1 >=k ){
                ret+=cnt;
            }

            
            i=j;
        }

        return ret;
        
    }
};