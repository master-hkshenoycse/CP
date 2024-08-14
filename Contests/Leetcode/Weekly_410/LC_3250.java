package Contests.Leetcode.Weekly_410;

public class LC_3250 {

    class Solution {
        public int countOfPairs(int[] nums) {
            int mod=1000000007;
            int n=nums.length;
            int dp[][]=new int[n+1][55+1];
    
    
            for(int i=1;i<=n;i++){
                int value=nums[i-1];
                if(i==1){
                    for(int j=0;j<=value;j++){
                        dp[1][j]=1;
                    }
                }else{
    
                    for(int j=0;j<=value;j++){
                        dp[i][j]=0;
                        for(int k=0;k<=j;k++){
                            int curr_a2=value-j;
                            int prev_a2=nums[i-2]-k;
                            if(curr_a2 <= prev_a2){
                                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                            }
                        }
                    }
                }
            }
    
            int ans=0;
            for(int i=0;i<=50;i++){
                ans=(ans+ dp[n][i])%mod;
            }
    
            return ans;
    
        }
    }
    
}
