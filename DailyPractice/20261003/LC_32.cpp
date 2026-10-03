#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        stack<int> st;
        int ans=0;

        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                st.push(i);
            }else{
                
                if(st.size()>0){
                    int l=st.top();
                    st.pop();
                    int ex=0;
                    if(l-1>=0){
                        ex=dp[l-1];
                    }
                    dp[i]=max(dp[i],ex+(i-l+1));
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};