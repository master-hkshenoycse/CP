
public class LC_1937 {

    class Solution {
        public long maxPoints(int[][] points) {
    
            int n=points.length;
            int m=points[0].length;
    
            long dp[][]=new long[n][m];
            long ans=-10000000000l;
    
            for(int i=0;i<m;i++){
                dp[0][i]=points[0][i];
                if(n==1){
                    ans=Math.max(ans,dp[0][i]);
                }
            }
    
            
    
            for(int i=1;i<n;i++){
                long r=-10000000000l;
                
                for(int j=0;j<m;j++){
                    dp[i][j]=-10000000000l;
                    r=Math.max(r,dp[i-1][j]+j);
                    dp[i][j]=Math.max(dp[i][j],r-j+points[i][j]);
                }
                
                r=-10000000000l;
                for(int j=m-1;j>=0;j--){
                    r=Math.max(r,dp[i-1][j]-j);
                    dp[i][j]=Math.max(dp[i][j],r+j+points[i][j]);
                    if(i==n-1){
                        ans=Math.max(ans,dp[i][j]);
                    }
                }
    
    
            }
    
            return ans;
        }
    }
    
}
