class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> dict(B.begin(),B.end());
        
        
        int n=A.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            

            for(int j=0;j<i;j++){
                if(dp[j] and dict.count(A.substr(j,i-j))){
                    dp[i]=1;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};