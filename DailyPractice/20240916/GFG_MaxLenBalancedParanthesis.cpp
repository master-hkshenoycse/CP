
#include<bits/stdc++.h>
using namespace std;
int maxLength(string str) {
        // code here
        stack<int> st;
        int n=str.size(),ans=0;
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                st.push(i);
            }else{
                if(st.size()>0){
                    int en=st.top();
                    dp[i]=i-en+1;
                    st.pop();
                    if(en-1>=0){
                        dp[i]+=dp[en-1];
                    }
                    ans=max(ans,dp[i]);
                }
            }
        }
        
        return ans;
    }