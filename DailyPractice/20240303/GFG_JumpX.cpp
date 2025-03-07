#include<bits/stdc++.h>
using namespace std;

/*https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-144/problems*/

class Solution {
  public:
    
    void clear_stack(stack<int> &st){
        while(st.size()>0){
            st.pop();
        }
    }
    int minJumps(int N, vector<int> &arr) {
        // code here

        vector<int> dp(N+1,N+1),nx_gt(N,N+1),nx_ls(N,N+1),prev_gt(N,-1),prev_ls(N,-1);
        
        stack<int> st;
        for(int i=N-1;i>=0;i--){
            while(st.size()>0 and arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.size()>0){
                nx_gt[i]=st.top();
            }
            
            st.push(i);
        }
        
        clear_stack(st);
        
        for(int i=N-1;i>=0;i--){
            while(st.size()>0 and arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.size()>0){
                nx_ls[i]=st.top();
            }
            
            st.push(i);
        }
        
        clear_stack(st);
        
        for(int i=0;i<N;i++){
            while(st.size()>0 and arr[st.top()]<arr[i]){
                st.pop();
            }
            
            if(st.size()>0){
                prev_gt[i]=st.top();
            }
            st.push(i);
        }
        
        clear_stack(st);
        
        for(int i=0;i<N;i++){
            while(st.size()>0 and arr[st.top()]>arr[i]){
                st.pop();
            }
            
            if(st.size()>0){
                prev_ls[i]=st.top();
            }
            st.push(i);
        }
        
        for(int i=N-1;i>=0;i--){
            if(i==N-1){
                dp[i]=0;
                
                if(prev_gt[i]!=-1){
                    dp[prev_gt[i]]=min(dp[prev_gt[i]],dp[i]+1);
                }
                
                if(prev_ls[i]!=-1){
                    dp[prev_ls[i]]=min(dp[prev_ls[i]],dp[i]+1);
                }
                
                
            }else{
                dp[i]=min(dp[i],dp[i+1]+1);
                
                
                if(nx_gt[i]<N){
                    dp[i]=min(dp[i],dp[nx_gt[i]]+1);
                }
                
                if(nx_ls[i]<N){
                    dp[i]=min(dp[i],dp[nx_ls[i]]+1);
                }
                    
                
                if(prev_gt[i]!=-1){
                    dp[prev_gt[i]]=min(dp[prev_gt[i]],dp[i]+1);
                }
                
                if(prev_ls[i]!=-1){
                    dp[prev_ls[i]]=min(dp[prev_ls[i]],dp[i]+1);
                }
                        
                
            }

        }
        
        
        return dp[0];
        
    }
};