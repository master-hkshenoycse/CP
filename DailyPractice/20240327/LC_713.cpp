#include<bits/stdc++.h>
using namespace std;

//skip one when iterating thru the nested loop , this will ensure that number of iterations <=32
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int ans=0,n=nums.size();

        vector<int> next_not_one(n,n);
        int nx=n;

        for(int i=n-1;i>=0;i--){
            next_not_one[i]=nx;
            if(nums[i]>1){
                nx=i;
            }
        }

        for(int i=0;i<n;i++){
            int p=1;
            for(int j=i;j<n;){
                p=p*nums[j];
                if(p>=k){
                    break;
                }
                if(nums[j] != 1){
                    ans++;
                    j++;
                }else{
                    ans+=next_not_one[j]-j;
                    j=next_not_one[j];
                }
            }
        }

        return ans;

    }
};