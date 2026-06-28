#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll vis[101][101][101], dp[101][101][101];
    ll solve(ll i,ll j,ll k,vector<int>&a,vector<int> &b){
        ll n=a.size(),m=b.size();
        if(i==n && j==m){
            if(k==0) return 0;
            return -1e18;
        }

        if(vis[i][j][k] != -1)
            return dp[i][j][k];
        
        ll ret=-1e18;
        vis[i][j][k]=1;
        
        if(i<n)
            ret=max(ret,solve(i+1,j,k,a,b));
        
        if(j<m)
            ret=max(ret,solve(i,j+1,k,a,b));
        
        if(k>0 && i<n && j<m)
            ret=max(ret,a[i]*1ll*b[j]*1ll+solve(i+1,j+1,k-1,a,b));

        return dp[i][j][k]=ret;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n=nums1.size(),m=nums2.size();
        memset(vis,-1,sizeof(vis));
        
        return solve(0,0,k,nums1,nums2);
    }
};