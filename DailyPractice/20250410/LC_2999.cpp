#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    ll dp[25][2];
    ll solve(ll ind,string &a,string &suffix,ll ti,ll limit){
        if(ind==a.size()){
            return 1;
        }
        
        if(dp[ind][ti] != -1){
            return dp[ind][ti];
        }
        
        ll res=0;
        ll dig=a[ind]-'0';
        
        if(suffix[ind]=='#'){
            
            if(ti){
                for(int i=0;i<=min(dig,limit);i++){
                    res=res+solve(ind+1,a,suffix,i==dig,limit);
                }
            }else{
                for(int i=0;i<=min(9ll,limit);i++){
                    res=res+solve(ind+1,a,suffix,0,limit);
                }
            }
            
        }else{
            
            ll sd=suffix[ind]-'0';
            
            if(sd<=limit){
                if(ti){
                    if(sd<=dig){
                        res=res+solve(ind+1,a,suffix,sd==dig,limit);
                    }
                }else{

                    res=res+solve(ind+1,a,suffix,0,limit);
                }
            }
            
        }
        
        return dp[ind][ti]=res;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        start--;
        
        string a=to_string(start);
        string b=to_string(finish);
        
        string suffix=s;
        while(suffix.size()<b.size()){
            suffix="#"+suffix;
        }
        
        cout<<suffix<<endl;
        
        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,b,suffix,1,limit);
        
        if(s.size() > a.size() or start==0){
            return ans;
        }
        
        suffix=s;
        while(suffix.size()<a.size()){
            suffix="#"+suffix;
        }
        
        memset(dp,-1,sizeof(dp));
        ans=ans-solve(0,a,suffix,1,limit);
        
        return ans;
        
        
    }
};