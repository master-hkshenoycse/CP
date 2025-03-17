#include<bits/stdc++.h>
using namespace std;
int dp[11][2][2][85][85];
class Solution {
public:
    int solve(int ind,int ti,int st,int prod_mod,int rem_sum,int sum,string &s){
        if(ind==s.size()){
            return (rem_sum==0)  && (prod_mod==0);
        }
        
        if(dp[ind][ti][st][prod_mod][rem_sum] != -1){
            return dp[ind][ti][st][prod_mod][rem_sum];
        }
        
        
        int res=0;
        int d=s[ind]-'0';
        
        if(st){
                
            if(ti){
                for(int i=0;i<=d;i++){
                    if(rem_sum-i>=0)res=res+solve(ind+1,(i==d),1,(prod_mod*i)%sum,rem_sum-i,sum,s);
                }    
            }else{
                for(int i=0;i<=9;i++){
                    if(rem_sum-i>=0)res=res+solve(ind+1,0,1,(prod_mod*i)%sum,rem_sum-i,sum,s);
                }
            }
            
        }else{
            
            //don't start 
            res=res+solve(ind+1,0,0,prod_mod,rem_sum,sum,s);
            
            //start
            if(ti){
                for(int i=1;i<=d;i++){
                    if(rem_sum-i>=0)res=res+solve(ind+1,(i==d),1,(prod_mod*i)%sum,rem_sum-i,sum,s);
                }    
            }else{
                for(int i=1;i<=9;i++){
                    if(rem_sum-i>=0)res=res+solve(ind+1,0,1,(prod_mod*i)%sum,rem_sum-i,sum,s);
                }
            }
        } 
        
        return dp[ind][ti][st][prod_mod][rem_sum]=res;
    }
    int find_value(string &s){
        
        int ret=0;
        
        for(int i=1;i<=81;i++){
            memset(dp,-1,sizeof(dp));
            ret=ret+solve(0,1,0,1,i,i,s);
        }
        
        return ret;

    }
    int beautifulNumbers(int l, int r) {
        string l_str=to_string(l-1);
        string r_str=to_string(r);
        
        return find_value(r_str)-find_value(l_str);
    }
};