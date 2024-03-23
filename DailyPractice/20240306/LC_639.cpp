#include<bits/stdc++.h>
using namespace std;
//check on alphabets created dp(i,j)=number of ways that first i charcaters are parsed and end at jth alphabet//

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int mod=1e9+7;
        vector<vector<int> > dp(n,vector<int> (27,0));
        
        if(s[0]=='*'){
            for(int i=1;i<=9;i++){
                dp[0][i]=1;
            }
        }else{
            if(s[0]>'0')dp[0][s[0]-'0']=1;
        }

        for(int i=1;i<n;i++){

            int sum=0;
            for(int j=1;j<=26;j++){
                sum=(sum+dp[i-1][j])%mod;
            }

            if(s[i]=='*'){
                
                for(int j=1;j<=9;j++){
                    dp[i][j]=sum;
                }

                for(int j=1;j<=2;j++){
                    for(int k=1;k<=9;k++){
                        int v=j*10+k;
                        if(v>=10 and v<=26){
                            dp[i][v]=(dp[i][v]+dp[i-1][j])%mod;
                        }
                    }
                }
            }else{
                int d=s[i]-'0';
                
                if(d==0){
                    dp[i][10]=dp[i-1][1];
                    dp[i][20]=dp[i-1][2];

                }else{

                    dp[i][d]=sum;
                    for(int j=1;j<=2;j++){
                        int v=j*10+d;
                        if(v>=10 and v<=26){
                            dp[i][v]=(dp[i][v]+dp[i-1][j])%mod;
                        }
                    }
                }
            }
            
        }

        int ans=0;
        for(int i=1;i<=26;i++){
            ans=(ans+dp[n-1][i])%mod;
        }

        return ans;
    }
};