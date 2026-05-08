#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll solve(vector<int> &prices, int l,int r,int k){
        int n=prices.size();
        vector<array<ll,3>  >f(k+2,{LLONG_MIN/2,LLONG_MIN/2,LLONG_MIN/2});

        for(int j=1;j<=k+1;j++){
            f[j][0]=0;
        }

        for(int i=l;i<r;i++){
            ll p=prices[i%n];
            for(int j=k+1;j>0;j--){
                f[j][0]=max(f[j][0],max(f[j][1]+p,f[j][2]-p));
                f[j][1]=max(f[j][1],f[j-1][0]-p);
                f[j][2]=max(f[j][2],f[j-1][0]+p);
            }
        }

        return f[k+1][0];
    }
    long long maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int max_i = ranges::max_element(nums)-nums.begin();
        return max(solve(nums,max_i,max_i+n,k),solve(nums,max_i+1,max_i+1+n,k));
    }
};