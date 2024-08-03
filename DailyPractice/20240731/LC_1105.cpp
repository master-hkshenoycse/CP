#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n+1,1e9);
        dp[0]=0;

        for(int i=1;i<=n;i++){
            int ma=0,s=0;
            for(int j=i;j>=1;j--){
                s=s+books[j-1][0];
                ma=max(ma,books[j-1][1]);
                if(s<=shelfWidth){
                    dp[i]=min(dp[i],dp[j-1]+ma);
                }else{
                    break;
                }
            }
        }

        return dp[n];

    }
};