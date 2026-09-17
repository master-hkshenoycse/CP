#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n=target.size(),m=rules.size();
        vector<int> dp(n+1,INT_MAX);
        vector<set<int> > valid_rules_source(n+1),valid_rules_target(n+1);

        for(int i=0;i<m;i++){
            for(int j=0;j<rules[i][0].size();j++){
                if(rules[i][0][j]=='*')
                    costs[i]++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sz=rules[j][0].size();
                int cnt=0;
                for(int k=0;k<sz && i+k<n;k++){
                    if(rules[j][0][k]=='*' || source[i+k]==rules[j][0][k]){
                        cnt++;
                    }
                }


                if(cnt==sz)
                    valid_rules_source[i+sz].insert(j);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sz=rules[j][1].size();
                int cnt=0;
                for(int k=0;i+k<n && k<sz;k++){
                    if(target[i+k]==rules[j][1][k]){
                        cnt++;
                    }
                }

                
                if(cnt==sz)
                    valid_rules_target[i+sz].insert(j);
            }
        }

        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(source[i-1] == target[i-1]){
                dp[i]=dp[i-1];
            }

            for(auto ind:valid_rules_source[i]){
                if(valid_rules_target[i].find(ind) != valid_rules_target[i].end()){
                    int sz=rules[ind][0].size();
                    if(dp[i-sz]!=INT_MAX)
                        dp[i]=min(dp[i],dp[i-sz]+costs[ind]);
                }
            }
            
        }

        if(dp[n]==INT_MAX)
            dp[n]=-1;
        
        return dp[n];
           
    }
};