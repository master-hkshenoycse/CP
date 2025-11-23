#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0, len = n,ans=INT_MAX;
        for(int i=0;i<n;i++){
            int gc=0;
            if(nums[i]==1){
                cnt++;
            }
            for(int j=i;j<n;j++){
                gc=__gcd(gc,nums[j]);
                if(gc == 1){
                    ans=min(ans,(j-i)+(j-1)+(n-j)); 
                }
            }
        }

        if(ans == INT_MAX){
            ans=-1;
        }

        if(cnt>0){
            ans=min(ans,n-cnt);
        }
        return ans;
    }
};