package Contests.Leetcode.Weekly_410;

public class LC_3251 {

    class Solution {
        public int countOfPairs(int[] nums) {
            int n=nums.length;
    
            int dp[][]=new int[n+1][1001+1];
            int mod=1000000007;
    
            for(int i=1;i<=n;i++){
                int value=nums[i-1];
                if(i==1){
                    for(int j=0;j<=value;j++){
                        dp[1][j]=1;
                    }
                }else{
                    int value_=nums[i-2];
                    for(int j=0;j<=value;j++){
                        int lo=0;
                        int hi=j;
                        hi=Math.min(hi,value_-value+j);
                        hi=Math.min(hi,value_);
                    
    
                        int csum=0;
                        if(hi>=lo){
                            csum=dp[i-1][hi];
                            if(lo-1>=0){
                                csum=(csum-dp[i-1][lo-1]+mod)%mod;
                            }
    
                        }
                        dp[i][j]=csum;
                    }
                }
    
                for(int j=1;j<=1000;j++){
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                }
    
            }
    
            return dp[n][1000];
        }
    }
    
}
