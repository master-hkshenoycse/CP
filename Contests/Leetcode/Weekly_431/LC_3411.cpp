#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size(),ans=1;
        
        for(int i=0;i<n;i++){
            int prod=1,lc=1,gc=0;

            for(int j=i;j<n;j++){
                prod=prod*nums[j];
                lc=(lc * nums[j])/__gcd(nums[j],lc);
                gc=__gcd(gc,nums[j]);

                if(prod==lc*gc){
                    ans=max(ans,j-i+1);
                }

                if(prod > lc*gc){
                    break;
                }
            }
        }

        return ans;
        

    }
};