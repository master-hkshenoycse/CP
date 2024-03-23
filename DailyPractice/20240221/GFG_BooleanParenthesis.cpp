#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countWays(int n, string s){
        // code here
        vector<char> operands,operators;
        int mod=1003;
        
        for(auto ch:s){
            if(ch=='T' or ch=='F'){
                operands.push_back(ch);
            }else{
                operators.push_back(ch);
            }
        }
        
        int sz=operands.size();
        vector<vector<int> > true_dp(sz,vector<int> (sz,0));
        vector<vector<int> > false_dp(sz,vector<int> (sz,0));
        
        for(int i=0;i<sz;i++){
            if(operands[i]=='T'){
                true_dp[i][i]=1;
            }else{
                false_dp[i][i]=1;
            }
        }
        
        for(int len=2;len<=sz;len++){
            for(int st=0;st+len-1<sz;st++){
                int en=st+len-1;
                for(int k=st;k<en;k++){
                    char op=operators[k];
                    
                    if(op=='&'){
                        true_dp[st][en]=(true_dp[st][en]+true_dp[st][k]*true_dp[k+1][en])%mod;
                        false_dp[st][en]=(false_dp[st][en]+true_dp[st][k]*false_dp[k+1][en])%mod;
                        false_dp[st][en]=(false_dp[st][en]+false_dp[st][k]*true_dp[k+1][en])%mod;
                        false_dp[st][en]=(false_dp[st][en]+false_dp[st][k]*false_dp[k+1][en])%mod;
                    }else if(op=='|'){
                        true_dp[st][en]=(true_dp[st][en]+true_dp[st][k]*true_dp[k+1][en])%mod;
                        true_dp[st][en]=(true_dp[st][en]+true_dp[st][k]*false_dp[k+1][en])%mod;
                        true_dp[st][en]=(true_dp[st][en]+false_dp[st][k]*true_dp[k+1][en])%mod;
                        false_dp[st][en]=(false_dp[st][en]+false_dp[st][k]*false_dp[k+1][en])%mod;
                    }else{
                        false_dp[st][en]=(false_dp[st][en]+true_dp[st][k]*true_dp[k+1][en])%mod;
                        true_dp[st][en]=(true_dp[st][en]+true_dp[st][k]*false_dp[k+1][en])%mod;
                        true_dp[st][en]=(true_dp[st][en]+false_dp[st][k]*true_dp[k+1][en])%mod;
                        false_dp[st][en]=(false_dp[st][en]+false_dp[st][k]*false_dp[k+1][en])%mod;
                    }
                }
                
                //cout<<st<<" "<<en<<" "<<true_dp[st][en]<<" "<<false_dp[st][en]<<endl;
                
            }
            
            
        }
        
        return true_dp[0][sz-1];
        
    }
};

/*https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1*/