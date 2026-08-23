#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<ll> csum_right(n,0),csum_left(n,0);
        vector<ll> closest(n);
        for(ll i=0;i<n;i++){
            closest[i]=i;
            ll dist_lef=1e18,dist_right=1e18;

            if(i-1>=0){
                dist_lef=min(dist_lef,abs(nums[i]-nums[i-1])*1ll);
            }

            if(i+1<n){
                dist_right=min(dist_right,abs(nums[i]-nums[i+1])*1ll);
            }

            if(dist_lef <= dist_right){
                closest[i]=i-1;
            }else{
                closest[i]=i+1;
            }
        }

        for(ll i=1;i<n;i++){
            csum_right[i]=csum_right[i-1]+1;
            if(closest[i-1]!=i)
                csum_right[i]=csum_right[i-1]+(nums[i]-nums[i-1]);
        }

        for(ll i=n-1;i>0;i--){
            csum_left[i-1]=csum_left[i]+1;
            if(closest[i]!=i-1)
                csum_left[i-1]=csum_left[i]+abs(nums[i-1]-nums[i]);
        }

        vector<int> sol;
        for(auto q:queries){
            int l=q[0],r=q[1];
            if(l<=r){
                sol.push_back(csum_right[r]-csum_right[l]);
            }else{
                sol.push_back(csum_left[r]-csum_left[l]);
            }
        }
        return sol;
    }
};