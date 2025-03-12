#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxSum(vector<int>& nums, int k, int m) {
            int n=nums.size();
            
            vector<int> csum(n+1,0);
            vector<vector<int> > dp(n+1,vector<int> (k+1,-1e9));
            
            for(int i=1;i<=n;i++){
                csum[i]=csum[i-1]+nums[i-1];
            }
            
            dp[0][0]=0;
            vector<int> pref(k+1,-1e9);
            pref[0]=0;
            for(int i=1;i<=n;i++){
                dp[i][0]=0;
                for(int j=1;j<=k;j++){
                    dp[i][j]=dp[i-1][j];
                    /*for(int p=i-1;p>=0;p--){
                        if(i-p >= m){
                            dp[i][j]=max(dp[i][j],dp[p][j-1]+csum[i]-csum[p]);
                        }
                    }*/
                    if(i>=m)dp[i][j]=max(dp[i][j],pref[j-1]+csum[i]);
                }
                
                for(int j=0;j<=k;j++){
                    if(i+1-m>=0){
                        pref[j]=max(pref[j],dp[i+1-m][j]-csum[i+1-m]);
                    }
                }
            }
            
            /*for(int i=1;i<=n;i++){
                for(int j=1;j<=k;j++){
                    cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            */
            return dp[n][k];
        }
    };