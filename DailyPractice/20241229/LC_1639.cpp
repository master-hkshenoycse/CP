#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[1005][26];
int dp[1005][1005];
class Solution {
public:
    ll mod=1e9+7;
    int solve(ll ind,ll k,ll l,string &target){
        
        if(ind==target.size()){
            return 1;
        }

        if(k==l){
            return 0;
        }

        if(dp[ind][k] != -1){
            return dp[ind][k];
        }

        ll res=0;
        res=solve(ind,k+1,l,target);

        if(cnt[k][target[ind]-'a']>0){
            ll c=solve(ind+1,k+1,l,target);
            c= ( c * cnt[k][target[ind]-'a']*1ll)%mod;
            res=(res+c*1ll)%mod;
        }
        
        return dp[ind][k]=res;
    }
    
    int numWays(vector<string>& words, string target) {
        ll l=words[0].size();

        for(int i=0;i<l;i++){
            for(int j=0;j<26;j++){
                cnt[i][j]=0;
            }
        }

        for(int i=0;i<l;i++){
            for(auto w:words){
                cnt[i][w[i]-'a']++;
            }
        }

        ll n=target.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                dp[i][j]=-1;
            }
        }

        return solve(0,0,l,target);





        
    }
};