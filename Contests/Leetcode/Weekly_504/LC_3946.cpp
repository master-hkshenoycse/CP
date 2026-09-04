#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        map<int,int> freq_cnt;
        int min_price=INT_MAX;
        for(int i=0;i<n;i++){
            int f=items[i][0];
            for(int j=1;j*j<=f;j++){
                if(f%j==0){
                    freq_cnt[j]++;
                    if(j!=f/j)
                        freq_cnt[f/j]++;
                }
            }
            min_price=min(min_price,items[i][1]);
        }

        vector<int> dp(budget+1,INT_MIN);
        dp[0]=0;
        int ret=0;

        for(int i=0;i<n;i++){
            int cost=items[i][1];
            int gain=freq_cnt[items[i][0]];

            for(int j=budget;j>=0;j--){
                if(j+cost<=budget && dp[j]!=INT_MIN){
                    dp[j+cost]=max(dp[j+cost],dp[j]+gain);
                    ret=max(ret,dp[j+cost]+(budget-j-cost)/min_price);
                }
            }
        }
        return ret;
    }
};