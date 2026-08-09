#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp_l(n,2),dp_r(n,2);
        dp_l[0]=1;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp_l[i]=dp_l[i-1]+1;
            }else{
                dp_l[i]=2;
            }
        }

        int ans=2;

        dp_r[n-1]=1;
        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                dp_r[i]=dp_r[i+1]+1;
            }else{
                dp_r[i]=2;
            }
        }

        for(int i=0;i<n;i++){
            if(i)ans=max(ans,dp_l[i-1]+1);
            if(i+1<n)ans=max(ans,dp_r[i+1]+1);

            if(i && i+1<n){
                int diff=nums[i+1]-nums[i-1];
                if(diff%2==0){
                    int len=1;
                    if(i-2>=0 && nums[i-1]-nums[i-2]==diff/2)
                        len+=dp_l[i-1];
                    else 
                        len=len+1;

                    if(i+2<n && nums[i+2]-nums[i+1]==diff/2)
                        len+=dp_r[i+1];
                    else 
                        len=len+1;
                    
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};