#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        int i=0;
        
        while(i<n){
            int c=0,j=i;
            while(j<n and nums[i]==nums[j]){
                j++;
                c++;
            }
            
            if(c==1){
                tmp.push_back(nums[i]);
            }else{
                tmp.push_back(nums[i]);
                tmp.push_back(nums[i]);
            }
            i=j;
        }
        nums=tmp;
        n=nums.size();
        int ans=1;
        vector<vector<int> > dp(n,vector<int> (2,1));
        
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    for(int p=i-2;p<=i-1;p++){
                        if(p<0){
                            continue;
                        }
                        if(nums[p]+k+1==nums[i]+j){
                            dp[i][j]=max(dp[i][j],dp[p][k]+1);
                            ans=max(ans,dp[i][j]);
                        }
                    }
                }
            }
        
        }
        
        return ans;
    }
};