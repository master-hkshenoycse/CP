
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int spf[1000005];
int run=0;
void prec(){
    if(run){
        return;
    }

    run=1;
    spf[1]=1;
        for(ll i=1;i<=1000000;i++){
            if(spf[i]==0){
                spf[i]=i;
                for(ll j=i*i;j<=1000000;j+=i){
                    if(spf[j]==0){
                        spf[j]=i;
                    }
                }
            }
        }


}
class Solution {
public:
   
    int minOperations(vector<int>& nums) {
        prec();    
        int n=nums.size();
        vector<vector<int> > dp(n+1,vector<int> (2,1e9));
        dp[1][0]=0;
        dp[1][1]=1;

        for(int i=2;i<=n;i++){
            vector<int> curr={nums[i-1],spf[nums[i-1]]};
            vector<int> prev={nums[i-2],spf[nums[i-2]]};

            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    if(curr[j] >= prev[k]){
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+j);
                    }
                }
            }
        }

        int res=min(dp[n][0],dp[n][1]);
        if(res==1e9){
            res=-1;
        }

        return res;
    }
};