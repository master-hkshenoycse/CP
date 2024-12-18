#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //ooperation 3 is optimal for only chnaging adjancent elements
    int solve(vector<int>  &cnt,int x){
        vector<int> dp(26,INT_MAX);
        dp[0]=min(abs(cnt[0]),abs(x-cnt[0]));

        for(int i=1;i<26;i++){
            dp[i]=dp[i-1]+min(cnt[i],abs(x-cnt[i]));
            int prev=0;

            if(i-2>=0){
                prev=dp[i-2];
            }

            //tramsfer required units from previous to current character
            if(cnt[i]<x){
                int carry=cnt[i-1];
                if(cnt[i-1]>=x){
                    carry=cnt[i-1]-x;      
                }
                dp[i]=min(dp[i],prev+carry+max(0,x-(cnt[i]+carry)));
                
            }

        }
        return dp[25];
    }
    int makeStringGood(string s) {
        vector<int> freq(26,0);
        int n=s.size();
        for(auto ch:s){
            freq[ch-'a']++;
        }

        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            ans=min(ans,solve(freq,i));
        }

        return ans;


    }
};