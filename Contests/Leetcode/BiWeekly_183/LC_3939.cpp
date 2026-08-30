#include<bits/stdc++.h>
using namespace std;
#define ll long long
using vvi = vector<vector<ll> > ;
using vvvi = vector<vector<vector<ll> > >;
using vi = vector<int>;
class Solution {
public:
    int mod=1e9+7;
    vvvi dp;
    vvi adj;
    void dfs(int v,int k,vi &nums){
        dp[v][0][0]=1;
        dp[v][1][nums[v]]=1;

        for(auto to:adj[v]){
            dfs(to,k,nums);

            vvi dp2(2,vector<ll> (k,0));
            for(ll a=0;a<k;a++){
                for(ll b=0;b<k;b++){
                    ll ways=(dp[to][0][b]+dp[to][1][b])%mod;
                    dp2[0][(a+b)%k]=(dp2[0][(a+b)%k]+(ways*dp[v][0][a])%mod)%mod;
                }
            }

            for(ll a=0;a<k;a++){
                for(ll b=0;b<k;b++){
                    ll ways=dp[to][0][b];
                    dp2[1][(a+b)%k]=(dp2[1][(a+b)%k]+(ways*dp[v][1][a])%mod)%mod;
                }
            }

            dp[v][0]=dp2[0];
            dp[v][1]=dp2[1];
        }
    }
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n=nums.size();
        adj.resize(n,{});

        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);

        for(int i=0;i<n;i++)
            nums[i]%=k;
        
        dp.resize(n,vector<vector<ll> > (2,vector<ll> (k,0)));
        dfs(0,k,nums);
        ll ret=(dp[0][0][0]+dp[0][1][0]-1+mod)%mod;
        return ret;

    }
};